/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Mauricio Capua
 *
 * Created on 12 de Agosto de 2016, 19:23
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int i = 5;

void funcao() {
    int i = 10;
    printf("na funcao i = %d \n", i);
}

int main(int argc, char** argv) {
    /*printf("no main i = %d \n" , i);
    funcao();
    printf("alterado i = %d" , i);*/

    /*int x2 = 10;
    int *px;
    px = &x2;
    
    printf("x =%d endereço = %p",x2,px);*/

    void troca(int *i, int *j) {
        int temp;
        temp = *i;
        *i = *j;
        *j = temp;
    }

    int a = 10, b = 15;
    troca(&a, &b);
    printf("\n Troca A= %d e B= %d \n", a, b);
    
    return (EXIT_SUCCESS);
}

