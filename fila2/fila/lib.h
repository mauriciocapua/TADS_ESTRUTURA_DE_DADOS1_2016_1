#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Usuario
{
    int id;
    char nome [100];
    struct data *data;
    struct hora *login;
    struct hora *logout;
    struct Usuario *proximo;
} Usuario;

typedef struct Fila
{
    struct Usuario *inicio;
    struct Usuario *fim;
    int quantidade;
} Fila;

void inicializaFila(Fila *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->quantidade = 0;
}
typedef struct hora
{
    int hora;
    int minuto;
    int seg;
} hora;
typedef struct data
{
    int dia;
    int mes;
    int ano;
} data;

Usuario* inicializaUsuario(int id, char nome[100])
{
    time_t agora;
    agora = time(NULL);
    Usuario *usuario = (Usuario *)malloc(sizeof(Usuario));
    data *datatmp = (data *)malloc(sizeof(data));
    hora *horatmp = (hora *)malloc(sizeof(hora));

    if(!usuario)
    {
        printf("Sem Memoria disponivel!\n");
        exit(1);
    }
    usuario->id = id;
    int i;
    strcpy(usuario->nome, nome);

    datatmp->dia = localtime(&agora)->tm_mday;
    datatmp->mes = localtime(&agora)->tm_mon;
    datatmp->ano = localtime(&agora)->tm_year;
    usuario->data = datatmp;
    horatmp->hora = localtime(&agora)->tm_hour;
    horatmp->minuto = localtime(&agora)->tm_min;
    horatmp->seg = localtime(&agora)->tm_sec;
    usuario->login = horatmp;



    usuario->logout = NULL;
    usuario->proximo = NULL;
    return usuario;
}

Usuario * copiaUsuario(Usuario *usuario)
{
    Usuario *nova = (Usuario *)malloc(sizeof(Usuario));
    if(!nova)
    {
        printf("Sem Memoria disponivel!\n");
        exit(1);
    }
    int id;
    id= usuario->id;
    char nome[50];
    strcpy(nome, usuario->nome);
    nova->id = id;
    strcpy(nova->nome,nome);

    nova->login = NULL;
    nova->logout = NULL;
    nova->proximo = NULL;
    return nova;
}

void insereUsuario(Fila *fila, Usuario *usuario)
{
    usuario->proximo = NULL;
    if(fila->inicio == NULL)
    {
        fila->inicio = usuario;
    }
    else
    {
        fila->fim->proximo = usuario;
    }
    fila->fim = usuario;
    fila->quantidade++;
}

Usuario * removeInicio(Fila *fila)
{
    if(fila->inicio == NULL)
    {
        return (NULL);
    }
    else
    {
        Usuario *usuario = fila->inicio;
        fila->quantidade--;
        fila->inicio = fila->inicio->proximo;
        return(usuario);
    }
}

void mostraAcessos(Fila *fila)//ok
{
    if(fila->quantidade == 0)
    {
        printf("Fila vazia! \n\n");
        return;
    }
    Usuario *tmp = fila->inicio;
    do
    {
        if(tmp->logout != NULL)
        {
            printf("\nNome = %s, Login: %d:%d:%d, logout: %d:%d:%d\n", tmp->nome, tmp->login->hora,tmp->login->minuto, tmp->login->seg, tmp->logout->hora,tmp->logout->minuto, tmp->logout->seg);

        }
        else
        {
            printf("\nNome = %s, Login: %d:%d:%d\n", tmp->nome,  tmp->login->hora,tmp->login->minuto, tmp->login->seg);
        }
        tmp = tmp->proximo;
    }
    while(tmp != NULL);
}

int testaIgual(Fila *fila, Usuario *usuario) //ok
{
    Usuario *tmp1 = fila->inicio;
    int flag = 0;
    int i;
    for (i = 0; i < fila->quantidade; i++)
    {
        if(strcmp(tmp1->nome, usuario->nome) == 0)
        {
            flag++;
        }
        tmp1 = tmp1->proximo;
    }
    if(flag>1)
    {
        return 0;
    }
    else
    {

        return 1;
    }
}

void mostraUsuarios(Fila *fila)//ok
{
    Fila *fila2 = (Fila *)malloc(sizeof(Fila));
    inicializaFila(fila2);
    Usuario *tmpsub = fila2->inicio;

    if(fila->quantidade == 0)
    {
        printf("Fila vazia! \n\n");
        return;
    }

    if(fila->quantidade==1)
    {
        Usuario *tmp = fila->inicio;
        printf("Nome: %s\n",tmp->nome);
    }
    else
    {
        Usuario *tmp = fila->inicio;
        do
        {
            if(testaIgual(fila, tmp)==1)
            {
                insereUsuario(fila2,copiaUsuario(tmp));
                printf("Nome: %s\n",tmp->nome);
            }
            tmp = tmp->proximo;
        }
        while(tmp != NULL);
    }
}



void mostraAposHora(Fila *fila, int h, int m, int s)
{

    if(fila->quantidade == 0)
    {
        printf("Fila vazia! \n\n");
        return;
    }


    Usuario *tmp = fila->inicio;
    do
    {
        if(h <= tmp->login->hora && m <= tmp->login->minuto && s <=tmp->login->seg)
        {
            if(tmp->logout != NULL)
            {
                printf("\n Nome = %s, Login: %d:%d:%d, logout: %d:%d:%d\n", tmp->nome, tmp->login->hora,tmp->login->minuto, tmp->login->seg, tmp->logout->hora,tmp->logout->minuto, tmp->logout->seg);

            }
            else
            {
                printf("\n Nome = %s, Login: %d:%d:%d\n", tmp->nome,  tmp->login->hora,tmp->login->minuto, tmp->login->seg);
            }

        }
        tmp = tmp->proximo;
    }
    while(tmp != NULL);
}


void removerAcessosData(Fila *fila,int d, int m, int a)
{
    Usuario *tmp = fila->inicio;
    if(fila->quantidade == 0)
    {
        printf("Fila vazia! \n\n");
        return;
    }
    do
    {
        if(d <= tmp->data->dia && m <= tmp->data->mes && a <= tmp->data->ano)
        {
            printf("Nome removido: %s\n",removeInicio(fila)->nome);
        }
        tmp = tmp->proximo;
    }
    while(tmp != NULL);
}



void logout(Fila *fila, char nome [100])
{
    time_t agora;
    agora = time(NULL);
    Usuario *tmp = fila->inicio;

    data *datatmp = (data *)malloc(sizeof(data));
    hora *horatmp = (hora *)malloc(sizeof(hora));
    if(fila->quantidade == 0)
    {
        printf("Fila vazia! \n\n");
        return;
    }
    int i;
    for (i = 0; i < fila->quantidade; i++)
    {
        if(tmp->nome == nome)
        {
            horatmp->hora = localtime(&agora)->tm_hour;
            horatmp->minuto = localtime(&agora)->tm_min;
            horatmp->seg = localtime(&agora)->tm_sec;
            tmp->logout = horatmp;

        }
        tmp = tmp->proximo;
    }
}

void mostraUmUsuario(Fila *fila, char nome [100])
{
    if(fila->quantidade == 0)
    {
        printf("Fila vazia! \n\n");
        return;
    }
    Usuario *tmp = fila->inicio;
    do
    {
        if(strcmp(tmp->nome, nome) == 0 )
        {
            if(tmp->logout != NULL)
            {
                printf("\n Nome = %s, Login: %d:%d:%d, logout: %d:%d:%d\n", tmp->nome, tmp->login->hora,tmp->login->minuto, tmp->login->seg, tmp->logout->hora,tmp->logout->minuto, tmp->logout->seg);

            }
            else
            {
                printf("\n Nome = %s, Login: %d:%d:%d\n", tmp->nome,  tmp->login->hora,tmp->login->minuto, tmp->login->seg);
            }
        }
        tmp = tmp->proximo;
    }
    while(tmp != NULL);
}



