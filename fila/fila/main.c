#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

int main()
{

    Usuario *usuario1 = (Usuario *)malloc(sizeof(Usuario));
    Usuario *usuario2 = (Usuario *)malloc(sizeof(Usuario));
    Usuario *usuario3 = (Usuario *)malloc(sizeof(Usuario));

    strcpy(usuario1->login,"root");
    strcpy(usuario1->senha,"root");
    strcpy(usuario1->nome,"Joao");

    strcpy(usuario2->login,"maria");
    strcpy(usuario2->senha,"123123");
    strcpy(usuario2->nome,"Maria");

    strcpy(usuario3->login,"admin");
    strcpy(usuario3->senha,"salada");
    strcpy(usuario3->nome,"Mifael");

    Fila *listaDeAcessos = (Fila *)malloc(sizeof(Fila));
    inicializaFila(listaDeAcessos);

    inserirNaFila(listaDeAcessos,criarAcesso(usuario1,1));
    inserirNaFila(listaDeAcessos,criarAcesso(usuario2,1));
    inserirNaFila(listaDeAcessos,criarAcesso(usuario3,1));
    inserirNaFila(listaDeAcessos,criarAcesso(usuario1,1));

    int opcao=-1;

    do
    {
        printf("1-Adicionar\n2-Deletar\n3-listar\n4-voltar\nInforme o numero da opção desejada: ");
        scanf("%u", &opcao);
        switch(opcao)
        {
        case 1:
            inserirNaFila(listaDeAcessos,criarAcesso(usuario1,1));
            break;
        }
    }
    while(opcao!=4);


    mostrarAcessos(listaDeAcessos);
//        printf("Lista de usuarios:\n");
//        mostrarUsuarios(listaDeAcessos);
//    mostrarUsuariosDiferentes(listaDeAcessos); NÃO FUNCIONA


    return (EXIT_SUCCESS);
}
