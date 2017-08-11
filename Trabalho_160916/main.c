/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Mauricio Capua
 *
 * Created on 16 de Setembro de 2016, 10:56
 */

#include <stdio.h>
#include <stdlib.h>

#include "funcoes.h"

/*
 * 
 */
int main(int argc, char** argv) {


    int opcao = -1;
    Lista locados[10];
    Lista livres[10];
    inicializa_lista(locados);
    inicializa_lista(livres);

    while (opcao != 0) {
        system("clear");
        printf("1-Livres\n2-Locados\n0-sair\nInforme o numero da opção desejada: ");
        scanf("%u", &opcao);

        switch (opcao) {
            case 1:
                system("clear");
                do {
                    printf("1-Listar\n2-Adicionar\n3-Remover\n4-Locar\n5-voltar\nInforme o numero da opção desejada: ");
                    scanf("%u", &opcao);

                    switch (opcao) {
                        case 1:
                            mostraLista(livres);
                            break;
                        case 2:
                            if (insereInicio(livres, novaVeiculo()) == 1) {
                                printf("Veículo inserido em livres!");
                            } else printf("Inválido!");
                            break;
                        case 3:
                            if (removePosicao(livres, buscaElemento(livres)) != NULL) {
                                printf("Veiculo removido em livres");
                            } else printf("Inválido!");
                            break;
                        case 4:
                            transferir(livres, locados, buscaElemento(livres));
                            break;
                    }
                    printf("\n");
                } while (opcao != 5);
                break;
            case 2:
                system("clear");
                do {
                    printf("1-Listar\n2-Adicionar\n3-Remover\n4-Devolver\n5-voltar\nInforme o numero da opção desejada: ");
                    scanf("%u", &opcao);

                    switch (opcao) {
                        case 1:
                            mostraLista(locados);
                            break;
                        case 2:
                            if (insereInicio(locados, novaVeiculo()) == 1) {
                                printf("Veículo inserido em locados!");
                            } else printf("Inválido!");
                            break;
                        case 3:
                            if (removePosicao(locados, buscaElemento(locados)) != NULL) {
                                printf("Veiculo removido em livres");
                            } else printf("Inválido!");
                            break;
                        case 4:
                            transferir(locados, livres, buscaElemento(locados));
                            break;

                    }
                    printf("\n");
                } while (opcao != 4);
                break;
        }


    }
    return (EXIT_SUCCESS);
}
