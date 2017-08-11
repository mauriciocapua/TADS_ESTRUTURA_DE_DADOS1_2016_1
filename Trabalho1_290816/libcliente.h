/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   libcliente.h
 * Author: Mauricio Capua
 *
 * Created on 26 de Agosto de 2016, 21:02
 */

#ifndef LIBCLIENTE_H
#define LIBCLIENTE_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>
#include <string.h>

    typedef struct cliente {
        int cod;
        char nome[10];
        char end[20];
    } Cliente;

    void InicializaCliente(Cliente *clientes, int contador) {
        for (int i = 0; i < contador; i++) {
            (clientes + i)->cod = -1;
            strcpy((clientes + i)->nome, "");
            strcpy((clientes + i)->end, "");
        }
    }

    void AdicionaCliente(Cliente *p, int codigoCliente) {
        p->cod = codigoCliente;
        printf("digite o nome pessoa: ");
        scanf("%s", p->nome);
        printf("digite o endereco: ");
        scanf("%s", p->end);
        printf("Cliente %s adicionado\n", p->nome);
    }

    int BuscaPosicaoCliente(Cliente *cliente, int contador) {
        int posicao = -1;
        for (int i = 0; i < contador; i++) {
            if (cliente[i].cod == -1) {
                posicao = i;
                return posicao;
            }
        }
    }

    void MostrarClientes(Cliente *clientes, int contador) {
        for (int i = 0; i < contador; i++) {
            if ((clientes + i)->cod != -1) {

                printf("cliente n=%d nome =%s endereco =%s \n", (clientes + i)->cod, (clientes + i)->nome, (clientes + i)->end);
                //printf("cliente n=%d nome =%s\n", (clientes + i)->cod, (clientes + i)->nome);
            }
        }
    }

    void DeleteCliente(Cliente *clientes, int contador) {
        int codigo;
        printf("informe o codigo para deletar: \n");
        scanf("%d", &codigo);
        for (int i = 0; i < contador; i++) {
            if ((clientes + i)->cod == codigo) {
                (clientes + i)->cod = -1;
                //*(clientes + i)->nome = NULL;
                //*(clientes + i)->end = NULL;
                strcpy((clientes + i)->nome, "");
                strcpy((clientes + i)->end, "");
                printf("cliente deletado\n");
            }
        }
    }

    int RetornaCliente(Cliente *clientes, int contador) {
        int posicao = -1;
        int codigo;
        printf("informe o codigo do cliente: ");
        scanf("%d", &codigo);
        for (int i = 0; i < contador; i++) {
            if (clientes[i].cod == codigo) {
                posicao = i;
                return posicao;
            }
        }
    }

#ifdef __cplusplus
}
#endif

#endif /* LIBCLIENTE_H */

