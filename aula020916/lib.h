#include <stdio.h>
#include <stdlib.h>
// Estrututa para Elementos
typedef struct pessoa{
    char  nome[100];
    int idade;
    int matricula;
    struct pessoa *prox;    //ponteiro prox
}Pessoa;

// Estrutura da lista;
typedef struct lista{
    Pessoa *primeiro;
    Pessoa *ultimo;
    int np;
}Lse;

void inicializa_lista(Lse *l){  //primeira função
    l->primeiro = NULL;
    l->ultimo = NULL;
    l->np = 0;
}

Pessoa* novaPessoa(){   //aloca espaço para uma pessoa
	Pessoa *novo = (Pessoa *)malloc(sizeof(Pessoa));
    if(!novo){
        printf("Sem Memoria disponivel!\n");
        exit(0);
    }
    printf("Novo aluno - Nome: ");
    scanf ("%s",novo->nome);
    printf("Novo aluno - Idade: ");
    scanf("%d", &novo->idade);
	printf("Novo aluno - Matricula: ");
    scanf("%d", &novo->matricula);
    return novo;     //retorna o endereço da pessoa criada
}


void insereFim(Lse *l, Pessoa *novo){    
    novo->prox = NULL;
    if(l->primeiro == NULL)
        l->primeiro = novo;
    else{
        l->ultimo->prox = novo;
    }
    l->ultimo = novo;
    l->np++;
}

void insereInicio(Lse *l, Pessoa *novo){     
    if(l->primeiro == NULL)
        l->ultimo = novo;
    else{
        novo->prox = l->primeiro;
    }
    l->primeiro = novo;
    l->np++;
}


void mostraLista(Lse *l){
    if (l->np == 0){
        printf("Lista Vazia!\n\n");
        return ;
    }
    Pessoa *tmp = l->primeiro;
    do{
        printf("Nome= %s, idade = %d e matricula = %d\n ",
        	        tmp->nome, tmp->idade,tmp->matricula);
        tmp = tmp->prox;
    } while(tmp != NULL);

}
/*
void insereComeco(lista *l, pessoa *novo){
   
     
}

void insereMeio(lista *l, pessoa *novo, int index){
   
  
}

int removeFim(lista *l){
   
}

int removeMeio(lista *l, int index){
    
}


*/

