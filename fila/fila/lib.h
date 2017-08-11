
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>

typedef struct Usuario
{
    char nome[20];
    char login[20];
    char senha[20];
} Usuario;

typedef struct Acesso
{
    struct Usuario *usuario;
    int *hora;
    int *minuto;
    int *segundo;
    struct Acesso *proximo;
    int tipo;
} Acesso;

typedef struct Fila
{
    struct Acesso *inicio;
    struct Acesso *fim;
    int quantidade;
} Fila;

void inicializaUsuario(Usuario *usuario)
{
    strcpy(usuario->nome, "");
    strcpy(usuario->login, "");
    strcpy(usuario->senha, "");
}

void inicializaAcesso(Acesso *acesso)
{
    acesso->usuario = NULL;
    acesso->hora=NULL;
    acesso->minuto=NULL;
    acesso->segundo=NULL;
    acesso->proximo = NULL;
    acesso->tipo = -1;
}


void inicializaFila(Fila *fila)
{
    fila->fim = NULL;
    fila->inicio = NULL;
    fila->quantidade = 0;
}

void criarUsuario (Usuario *usuario)
{

    printf("Digite o nome do usuario\n");
    scanf("%s", &usuario->nome);
    printf("Digite o login do usuario\n");
    scanf("%s", &usuario->login);
    printf("Digite a senha do usuario\n");
    scanf("%s", &usuario->senha);

}

Acesso* criarAcesso(Usuario *usuario, int tipo)
{
    time_t rawtime;
    time (&rawtime);
    struct tm *tm_struct = localtime(&rawtime);

    Acesso *acesso = (Acesso *)malloc(sizeof(Acesso));
    inicializaAcesso(acesso);
    acesso->usuario = usuario;


    acesso->hora = localtime(&rawtime)->tm_hour;
    acesso->minuto =  localtime(&rawtime)->tm_min;
    acesso->segundo =  localtime(&rawtime)->tm_sec;
    acesso->tipo = tipo;

    return acesso;
}

void inserirNaFila(Fila *fila, Acesso *acesso)
{
    if (fila->inicio ==NULL)
    {
        fila->inicio = acesso;
    }
    else
    {
        fila->fim->proximo = acesso;
    }
    fila->fim = acesso;
    fila->quantidade++;
}

void mostrarUsuarios(Fila *fila)//funcionando
{
    if(fila->quantidade==0)
    {
        printf("fila vazia");
        return;
    }
    Acesso *tmp;
//    inicializaAcesso(tmp);
    tmp = fila->inicio;
    do
    {
        printf("Nome: %s\n", tmp->usuario->nome);
        tmp = tmp->proximo;
    }
    while(tmp!=NULL);
}

void mostrarUsuariosDiferentes(Fila *fila)
{
     if(fila->quantidade==0)
    {
        printf("fila vazia");
        return;
    }
    Fila *filaAux = (Fila *)malloc(sizeof(Fila));
    filaAux = fila;

    Acesso *acesso_tmp;
    acesso_tmp = fila->inicio;

    Acesso *acesso_tmpsub;
    acesso_tmpsub = filaAux->inicio;

    printf("Nome: %s\n", acesso_tmp->usuario->nome);
    acesso_tmp = acesso_tmp->proximo;
    do
    {
        int flag = NULL;
        do
        {
            flag = strcmp (acesso_tmpsub->usuario->login,acesso_tmp->usuario->login);
            acesso_tmpsub = acesso_tmpsub->proximo;
        }
        while(acesso_tmpsub!=NULL);
        if(flag!=0)
        {
            printf("Nome: %s\n", acesso_tmp->usuario->nome);
        }
        acesso_tmp = acesso_tmp->proximo;
    }
    while(acesso_tmp!=NULL);

}

void mostrarAcessos(Fila *fila)//funcionando
{
    if(fila->quantidade==0)
    {
        printf("fila vazia");
        return;
    }
    Acesso *tmp;
//    inicializaAcesso(tmp);
    tmp = fila->inicio;
    do
    {
        printf("Nome: %s - Data:%d:%d:%d\n", tmp->usuario->login,(tmp->hora),tmp->minuto,tmp->segundo);
        tmp = tmp->proximo;
    }
    while(tmp!=NULL);
}
