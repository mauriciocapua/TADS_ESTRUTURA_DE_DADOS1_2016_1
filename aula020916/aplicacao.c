#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void main(void){
    Lse *lp = (Lse * ) malloc (sizeof(Lse));
    inicializa_lista(lp);
    printf("Lista inicializada!!\n");

    Pessoa *pnovo = novaPessoa(); //cria novo elemento
    insereFim(lp, pnovo); //insere elemento
    printf ("Elemento inserido \n");

    insereInicio(lp, novaPessoa()); //cria e insere elemento
    printf ("Elemento inserido \n");

    mostraLista(lp);

}
