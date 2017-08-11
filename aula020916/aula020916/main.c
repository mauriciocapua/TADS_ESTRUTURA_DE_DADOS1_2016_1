/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Mauricio Capua
 *
 * Created on 2 de Setembro de 2016, 21:34
 */
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Lse *lp = (Lse *) malloc(sizeof (Lse));
    inicializa_lista(lp);
    printf("Lista inicializada!!\n");

    Pessoa *pnovo = novaPessoa(); //cria novo elemento
    insereFim(lp, pnovo); //insere elemento
    printf("Elemento inserido \n");

    insereInicio(lp, novaPessoa()); //cria e insere elemento
    printf("Elemento inserido \n");

    mostraLista(lp);
    return (EXIT_SUCCESS);
}

