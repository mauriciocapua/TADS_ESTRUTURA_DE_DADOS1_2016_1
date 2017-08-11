/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   locadora.h
 * Author: Mauricio Capua
 *
 * Created on 26 de Agosto de 2016, 10:35
 */

#ifndef LOCADORA_H
#define LOCADORA_H

#include "libcliente.h"
#include "libdvd.h"
#include "time.h"




#ifdef __cplusplus
extern "C" {
#endif

    typedef struct locacao {
        int cod;
        Cliente *cliente;
        Dvd *dvd;
        int dia;
        int mes;
    } Locacao;

    void InicializaLocacao(Locacao *locacao, int contador) {
        for (int i = 0; i < contador; i++) {
            (locacao + i)->cod = -1;
            (locacao + i)->cliente = NULL;
            (locacao + i)->dvd = NULL;
            //  (locacao + i)->dia = 0;
            //   (locacao + i)->mes = 0;

        }
    }

    void AdicionaLocacao(Locacao *p, int codigoLocacao, Cliente *cliente, Dvd *dvd) {

        p->cod = codigoLocacao;
        p->cliente = cliente;
        p->dvd = dvd;
        p->dvd->status = 1;

        int aux;
        printf("informe o dia:");
        scanf("%u", &aux);
        p->dia = aux;
        printf("informe o mes:");
        scanf("%u", &aux);
        p->mes = aux;

        printf("Locacao %d do filme %s para cliente %s na data %d/%d\n", p->cod, p->dvd->titulo, p->cliente->nome, p->dia, p->mes);

    }

    int BuscaPosicaoLocacao(Locacao *locacao, int contador) {
        int posicao = -1;
        for (int i = 0; i < contador; i++) {
            if (locacao[i].cod == -1) {
                posicao = i;
                return posicao;
            }
        }
    }

    void MostrarLocacoes(Locacao *locacao, int contador) {
        for (int i = 0; i < contador; i++) {
            if ((locacao + i)->cod != -1) {
                //printf("locacao n=%d cliente =%s dvd =%s dia = %d mes = %d \n", (locacao + i)->cod, (locacao + i)->cliente->nome, (locacao + i)->dvd->titulo, (locacao + i)->dia, (locacao + i)->mes);
                printf("locacao n=%d cliente =%s dvd =%s \n", (locacao + i)->cod, (locacao + i)->cliente->nome, (locacao + i)->dvd->titulo);
            }
        }
    }

    void Devolucao(Locacao *locacao, int contador, int dia, int mes) {
        int codigo;
        printf("informe o codigo para devolucao: ");
        scanf("%d", &codigo);
        for (int i = 0; i < contador; i++) {
            if ((locacao + i)->cod == codigo) {
                (locacao + i)->cod = -1;
                Pagamento((locacao + i)->dia, (locacao + i)->mes, dia, mes);
                (locacao + i)->cliente = NULL;
                (locacao + i)->dvd->status = 0;
                (locacao + i)->dvd = NULL;
                (locacao + i)->dia = 0;
                (locacao + i)->mes = 0;
                printf("devolucao efetuada\n");
            }
        }
    }

    void Pagamento(int dialocado, int meslocado, int diaatual, int mesatual) {
        struct tm start_date;
        struct tm end_date;
        time_t start_time, end_time;
        double seconds;

        start_date.tm_hour = 0;
        start_date.tm_min = 0;
        start_date.tm_sec = 0;
        start_date.tm_mon = meslocado;
        start_date.tm_mday = dialocado;
        start_date.tm_year = 2016;

        end_date.tm_hour = 0;
        end_date.tm_min = 0;
        end_date.tm_sec = 0;
        end_date.tm_mon = mesatual;
        end_date.tm_mday = diaatual;
        end_date.tm_year = 2016;

        start_time = mktime(&start_date);
        end_time = mktime(&end_date);

        seconds = difftime(end_time, start_time);

        printf("Valor devido: %.2f reais\n", 2.65 * (seconds / 86400));
    }


#ifdef __cplusplus
}
#endif

#endif /* LOCADORA_H */

