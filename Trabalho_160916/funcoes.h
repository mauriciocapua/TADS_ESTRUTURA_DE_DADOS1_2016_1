/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcoes.h
 * Author: Mauricio Capua
 *
 * Created on 16 de Setembro de 2016, 10:57
 */

#ifndef FUNCOES_H
#define FUNCOES_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>

    typedef struct veiculo {
        int codigo;
        char modelo[30];
        char placa[10];
        struct veiculo *prox;
    } Veiculo;

    typedef struct lista {
        Veiculo *primeiro;
        Veiculo *ultimo;
        int tamanho;
    } Lista;

    void inicializa_lista(Lista *l) { //primeira função
        l->primeiro = NULL;
        l->ultimo = NULL;
        l->tamanho = 0;
    }

    Veiculo* novaVeiculo() { //aloca espaço para uma Veiculo
        Veiculo *novo = (Veiculo *) malloc(sizeof (Veiculo));
        if (!novo) {
            printf("Sem Memoria disponivel!\n");
            exit(0);
        }
        printf("Novo codigo: ");
        scanf("%d", &novo->codigo);
        printf("Novo modelo: ");
        scanf("%s", novo->modelo);
        printf("Novo placa: ");
        scanf("%s", novo->placa);
        novo->prox = NULL;
        return novo; //retorna o endereço da Veiculo criada
    }

    int insereFim(Lista *l, Veiculo *novo) {
        novo->prox = NULL;
        if (l->primeiro == NULL)
            l->primeiro = novo;
        else {
            l->ultimo->prox = novo;
        }
        l->ultimo = novo;
        l->tamanho++;
        organizarLista(l, 0);
        return 1;
    }

    int insereInicio(Lista *l, Veiculo *novo) {
        if (l->primeiro == NULL)
            l->ultimo = novo;
        else {
            novo->prox = l->primeiro;
        }
        l->primeiro = novo;
        l->tamanho++;
        organizarLista(l, 0);
        return 1;
    }

    int insereNaPosicao(Lista *l, Veiculo *novo, int posicao) {
        if (l->tamanho < posicao) {
            return 0;
        } else if (posicao == 0) {
            insereInicio(l, novo);
            return 1;
        } else if (l->tamanho == posicao) {
            insereFim(l, novo);
            return 1;
        }

        Veiculo *tmp = l->primeiro;

        for (int i = 0; i < l->tamanho; i++) {
            tmp = tmp->prox;
            i++;
        }

        novo->prox = tmp->prox;
        tmp->prox = novo;
        l->tamanho++;
        organizarLista(l, 0);
        return 1;
    }

    int buscaElemento(Lista *l) {
        char modelo[30];
        printf("Digite o modelo do carro:");
        scanf("%s", modelo);

        Veiculo *tmp = l->primeiro;

        for (int i = 0; i < l->tamanho; i++) {
            if (strcmp(tmp->modelo, modelo) == 0) {
                return i;
            }
            tmp = tmp->prox;
            i++;
        }
        printf("Veiculo nao encontrado");
        return -1;
    }

    void mostraLista(Lista *l) {
        if (l->tamanho == 0) {
            printf("Lista Vazia!\n");
            return;
        }
        Veiculo *tmp = l->primeiro;

        for (int i = 0; i < l->tamanho; i++) {
            printf("codigo= %d, modelo = %s e placa = %s\n ",
                    tmp->codigo, tmp->modelo, tmp->placa);
            tmp = tmp->prox;
        }

    }

    Veiculo* retiraInicio(Lista *l) {
        Veiculo *tmp;
        if (l->primeiro == NULL) {
            printf("Lista ja esta vazia\n");
            return NULL;
        } else {
            if (l->primeiro == l->ultimo) {
                l->primeiro = NULL;
                l->ultimo = NULL;
            } else {
                tmp = l->primeiro;
                l->primeiro = tmp->prox;
                tmp->prox = NULL;
            }

            l->tamanho--;
        }
        return tmp;
    }

    Veiculo* removeFim(Lista *l) {
        Veiculo *tmp = l->primeiro;
        if (l->tamanho == 0) {
            return NULL;
        } else if (l->tamanho == 1) {
            tmp->prox = NULL;
            l->primeiro = NULL;
            l->ultimo = NULL;
            l->tamanho = 0;
            return tmp;
        }

        while (tmp->prox != l->ultimo) {
            tmp = tmp->prox;
        };
        tmp->prox = NULL;
        l->ultimo = tmp;
        l->tamanho--;
        return tmp;
    }

    Veiculo* removePosicao(Lista *l, int posicao) {
        if (l->tamanho < posicao) {
            printf("Posicao invalida \n");
            return 0;
        } else if (posicao == 0) {
            return retiraInicio(l);
        } else if (l->tamanho == posicao) {
            return removeFim(l);
        } else if (posicao == -1) {
            return 0;
        }
        Veiculo *tmp = l->primeiro;
        for (int i = 0; i < posicao; i++) {
            tmp = tmp->prox;
        }
        tmp->prox = tmp->prox->prox;
        l->tamanho--;
    }

    Veiculo* retornarVeiculo(Lista *l, int posicao) {
        Veiculo *tmp = l->primeiro;

        if (posicao > l->tamanho) {
            return NULL;
        }
        int contador = 0;
        while (contador < posicao) {
            tmp = tmp->prox;
            contador++;
        }
        return tmp;

    }

    void organizarLista(Lista *l, int posicao) {
        if ((posicao + 1) < l->tamanho) {
            Veiculo *tmp = retornarVeiculo(l, posicao);
            Veiculo *tmpProximo = retornarVeiculo(l, posicao + 1);
            if (strcmp(tmp->modelo, tmpProximo->modelo) == 1) {
                Veiculo *aux = tmpProximo->prox;
                if (posicao == 0) {
                    tmpProximo->prox = tmp;
                    l->primeiro = tmpProximo;
                    tmp->prox = aux;
                } else {
                    Veiculo *tmpanterior = retornarVeiculo(l, posicao - 1);
                    tmpProximo->prox = tmp;
                    tmp->prox = aux;
                    tmpanterior->prox = tmpProximo;
                }
                if (posicao + 2 == l->tamanho) {
                    l->ultimo = tmp;
                }
                organizarLista(l, posicao + 1);
            }
        }
    }

    void transferir(Lista *fonte, Lista *destino, int posicao) {
        removePosicao(fonte, posicao);
        insereInicio(destino, retornarVeiculo(fonte, posicao));
    }




#ifdef __cplusplus
}
#endif

#endif /* FUNCOES_H */

