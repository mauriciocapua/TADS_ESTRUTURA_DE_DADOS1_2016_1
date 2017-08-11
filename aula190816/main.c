/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Mauricio Capua
 *
 * Created on 19 de Agosto de 2016, 19:31
 */

#include <stdio.h>
#include <stdlib.h>
#include "bib.h"
#include <time.h>

typedef struct nametype {
    int cod;
    char first [10];
    char last [20];
    int idade;
} pessoa;

/*
 * 
 */
void leCliente(pessoa *p, int c) {
    p->cod = c;
    printf("Digite o nome pessoa %d:", c);
    scanf("%s %s", p->first, p->last);
    printf("Informe a idade:");
    scanf("%d", &p->idade);
}

void Pagamento() {
    struct tm start_date;
    struct tm end_date;
    time_t start_time, end_time;
    double seconds;

    start_date.tm_hour = 0;
    start_date.tm_min = 0;
    start_date.tm_sec = 0;
    start_date.tm_mon = 8;
    start_date.tm_mday = 1;
    start_date.tm_year = 2016;

    end_date.tm_hour = 0;
    end_date.tm_min = 0;
    end_date.tm_sec = 0;
    end_date.tm_mon = 8;
    end_date.tm_mday = 29;
    end_date.tm_year = 2016;

    start_time = mktime(&start_date);
    end_time = mktime(&end_date);

    seconds = difftime(end_time, start_time);

    printf("Valor devido: %.2f reais\n", 2.65 * (seconds / 86400));
}

int main(int argc, char** argv) {
    Pagamento();
    /* printf("\n Estrutura em c - nomes\n");
     pessoa pcli [1];
     int c = 1, i;
     for (i = 0; i < 1; i++) {
         pcli[i].cod = c;
         printf("digite o nome pessoa %d: ", c);
         scanf("%s %s", pcli[i].first, pcli[i].last);
         printf("informe a idade: ");
         scanf("%d", &pcli[i].idade);
         c++;
     }

     for (i = 0; i < 1; i++) {
         printf("cliente n=%d nome =%s e sobrenome =%s idade=%d\n", pcli[i].cod, pcli[i].first, pcli[i].last, pcli[i].idade);

     }*/
    return (EXIT_SUCCESS);
}

