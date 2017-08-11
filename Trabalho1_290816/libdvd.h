/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   libdvd.h
 * Author: Mauricio Capua
 *
 * Created on 26 de Agosto de 2016, 21:03
 */
#include <string.h>

#ifndef LIBDVD_H
#define LIBDVD_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct dvd {
        int cod;
        char titulo[10];
        int ano;
        int status; //0 = livre 1 = locado
    } Dvd;

    void InicializaDvd(Dvd *dvd, int contador) {
        for (int i = 0; i < contador; i++) {
            (dvd + i)->cod = -1;
            strcpy((dvd + i)->titulo, "");
            (dvd + i)->status = 0;
            (dvd + i)->ano = 0;
        }
    }

    void AdicionaDvd(Dvd *p, int codigoDvd) {
        p->cod = codigoDvd;
        printf("digite o titulo do dvd: ");
        scanf("%s", p->titulo);
        int aux;
        printf("digite o ano do dvd: ");
        scanf("%d", &p->ano);
        printf("Dvd adicionado %s adicionado\n", p->titulo);
    }

    int BuscaPosicaoDVD(Dvd *dvd, int contador) {
        int posicao = -1;
        for (int i = 0; i < contador; i++) {
            if (dvd[i].cod == -1) {
                posicao = i;
                return posicao;
            }
        }
    }

    void MostrarDvds(Dvd *dvd, int contador) {
        for (int i = 0; i < contador; i++) {
            if ((dvd + i)->cod != -1) {
                //printf("cliente n=%d nome =%s endereco =%s \n", (clientes + i)->cod, (clientes + i)->nome, (clientes + i)->end);
                if ((dvd + i)->status == 0) {
                    printf("dvd n= %d titulo = %s ano= %d status = livre \n", (dvd + i)->cod, (dvd + i)->titulo, (dvd + i)->ano);
                } else printf("dvd n= %d titulo = %s ano= %d status = locado \n", (dvd + i)->cod, (dvd + i)->titulo, (dvd + i)->ano);

            }
        }
    }

    void DeleteDvd(Dvd *dvd, int contador) {
        int codigo;
        printf("informe o codigo para deletar: \n");
        scanf("%d", &codigo);
        for (int i = 0; i < contador; i++) {
            if ((dvd + i)->cod == codigo) {
                (dvd + i)->cod = -1;
                strcpy((dvd + i)->titulo, "");
                (dvd + i)->ano = -1;
                (dvd + i)->status = 0;
                printf("dvd deletado\n");
            }
        }
    }

    int RetornaDvd(Dvd *dvds, int contador) {
        int posicao = -1;
        int codigo;
        printf("informe o codigo do dvd: ");
        scanf("%d", &codigo);
        for (int i = 0; i < contador; i++) {
            if (dvds[i].cod == codigo) {
                posicao = i;
                return posicao;
            }
        }
    }

#ifdef __cplusplus
}
#endif

#endif /* LIBDVD_H */

