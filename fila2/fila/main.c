#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    Fila *listaDeAcessos = (Fila *)malloc(sizeof(Fila));
    inicializaFila(listaDeAcessos);

    int id=0;
//    insereUsuario(listaDeAcessos,inicializaUsuario(id++,"Joao"));
//    insereUsuario(listaDeAcessos,inicializaUsuario(id++,"Maria"));
//    insereUsuario(listaDeAcessos,inicializaUsuario(id++,"Katchau"));
//    insereUsuario(listaDeAcessos,inicializaUsuario(id++,"Joao"));

    int status=0;
    int menu=-1;
    char nome [100];

    int h=0;
    int m=0;
    int s=0;

    int dia=1;
    int mes=1;
    int ano=1;

    while (menu != 0)
    {
        if(status== 1)
        {
            printf("\n1-Mostrar Lista de Acessos\n2-Mostrar Usuarios\n3-Mostrar Apos Hora\n4-Mostrar usuario\n5-Remover Acessos\n6- Fazer Logout\n");
            scanf("%d", &menu);
            switch (menu)
            {
            case 1:
                mostraAcessos(listaDeAcessos);//ok
                break;
            case 2:
                mostraUsuarios(listaDeAcessos);//ok
                break;
            case 3:
                printf("Informe o horario no formato: hora:minuto:segundo\n");
                scanf("%d:%d:%d",&h,&m,&s);
                mostraAposHora(listaDeAcessos, h,m,s);//ok
                h=0;
                m=0;
                s=0;
                break;
            case 4:
                printf("Qual nome do usuario deseja buscar? \n");
                scanf("%s", &nome);
                mostraUmUsuario(listaDeAcessos, nome);
                break;
            case 5:
                printf("Informe a data no formato: dia/mes/ano\n");
                scanf("%d/%d/%d",&dia,&mes,&ano);
                removerAcessosData(listaDeAcessos,dia,mes,ano);//ok
                mostraAcessos(listaDeAcessos);
                h=0;
                m=0;
                s=0;
                break;
            case 6:
                printf("Qual nome do usuario para logout? \n");
                scanf("%s", &nome);
                logout(listaDeAcessos, nome);
                status = 0;
                break;
            }
        }
        else
        {
            printf("\n1-Listar acessos\n2-Fazer Login\n");
            scanf("%d", &menu);
            switch (menu)
            {
            case 1:
                mostraAcessos(listaDeAcessos);
                break;
            case 2:
                printf("Informe o nome para logar\n");
                scanf("%s", &nome);
                insereUsuario(listaDeAcessos,inicializaUsuario(id++,nome));
                status = 1;
                break;
            default:

                printf("Usuario invalido\n");
                break;
                break;
            }
        }

    }

    return 0;
}
