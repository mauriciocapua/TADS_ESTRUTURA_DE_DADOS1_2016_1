/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: Mauricio Capua
 *
 * Created on 26 de Agosto de 2016, 10:35
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libcliente.h"
#include "libdvd.h"
#include "locadora.h"

/*
 *
 */
int main(int argc, char** argv)
{

    int dia = 29;
    int mes = 8;
    int opcao = -1;
    Cliente clientes [10];
    int contadorVetorClientes = sizeof (clientes) / sizeof (Cliente); // tamanho do vetor
    int codigoCliente = 3;
    InicializaCliente(&clientes, contadorVetorClientes);

    clientes[0].cod = 1;
    strcpy(clientes[0].nome, "roger");
    strcpy(clientes[0].end, "that");

    clientes[1].cod = 2;
    strcpy(clientes[1].nome, "fulano");
    strcpy(clientes[1].end, "endereco fulano");

    Dvd dvds[10];
    int contadorVetorDvds = sizeof (dvds) / sizeof (Dvd); // tamanho do vetor
    int codigoDvd = 3;
    InicializaDvd(&dvds, contadorVetorDvds);

    dvds[0].cod = 1;
    strcpy(dvds[0].titulo, "rei leao");
    dvds[0].ano = 1994;

    dvds[1].cod = 2;
    strcpy(dvds[1].titulo, "filme2");
    dvds[1].ano = 2004;

    Locacao locacoes[10];
    int contadorVetorLocacoes = sizeof (locacoes) / sizeof (Locacao); // tamanho do vetor
    int codigoLocacoes = 1;
    InicializaLocacao(&locacoes, contadorVetorLocacoes);

    while (opcao != 0)
    {
        system("clear");
        printf("1-Clientes\n2-DVDs\n3-Locacoes\n0-sair\nInforme o numero da opção desejada: ");
        scanf("%u", &opcao);

        switch (opcao)
        {
        case 1:
            system("clear");
            do
            {
                printf("1-Adicionar\n2-Deletar\n3-listar\n4-voltar\nInforme o numero da opção desejada: ");
                scanf("%u", &opcao);

                switch (opcao)
                {
                case 1:
                    if ((BuscaPosicaoCliente(&clientes, contadorVetorClientes)) != -1 && (BuscaPosicaoCliente(&clientes, contadorVetorClientes)) < contadorVetorClientes)
                    {
                        int posicao = BuscaPosicaoCliente(&clientes, contadorVetorClientes);
                        AdicionaCliente(&clientes[posicao], codigoCliente);
                        codigoCliente++;
                    }
                    else printf("Não e possivel adicionar mais clientes, vetor cheio\n");
                    break;
                case 2:
                    DeleteCliente(&clientes, contadorVetorClientes);
                    break;
                case 3:
                    MostrarClientes(&clientes, contadorVetorClientes);
                    break;
                }
                printf("\n");
            }
            while (opcao != 4);
            break;
        case 2:
            system("clear");
            do
            {
                printf("1-Adicionar\n2-Deletar\n3-listar\n4-voltar\nInforme o numero da opção desejada: ");
                scanf("%u", &opcao);

                switch (opcao)
                {
                case 1:
                    if ((BuscaPosicaoDVD(&dvds, contadorVetorDvds)) != -1 && (BuscaPosicaoDVD(&dvds, contadorVetorDvds)) < contadorVetorDvds)
                    {
                        int posicao = BuscaPosicaoDVD(&dvds, contadorVetorDvds);
                        AdicionaDvd(&dvds[posicao], codigoDvd);
                        codigoDvd++;
                    }
                    else printf("Não e possivel adicionar mais dvds, vetor cheio\n");
                    break;
                case 2:
                    DeleteDvd(&dvds, contadorVetorDvds);
                    break;
                case 3:
                    MostrarDvds(&dvds, contadorVetorDvds);
                    break;
                }
                printf("\n");
            }
            while (opcao != 4);
            break;
        case 3:
            system("clear");
            do
            {
                printf("1-Adicionar\n2-Devolucao\n3-Listar\n4-voltar\nInforme o numero da opção desejada: ");
                scanf("%u", &opcao);

                switch (opcao)
                {
                case 1:
                    if ((BuscaPosicaoLocacao(&locacoes, contadorVetorLocacoes)) != -1 && (BuscaPosicaoLocacao(&locacoes, contadorVetorLocacoes)) < contadorVetorLocacoes)
                    {
                        int posicaolocacao = BuscaPosicaoLocacao(&locacoes, contadorVetorLocacoes);
                        int posicaocliente = RetornaCliente(&clientes, contadorVetorClientes);
                        int posicaodvd = RetornaDvd(&dvds, contadorVetorDvds);
                        if (dvds[posicaodvd].status == 1)
                        {
                            printf("Este dvd já esta locado, não é possivel efetuar uma nova locação");
                        }
                        else
                        {
                            AdicionaLocacao(&locacoes[posicaolocacao], codigoLocacoes, &clientes[posicaocliente], &dvds[posicaodvd]);
                            codigoLocacoes++;
                        }
                    }
                    else printf("Não e possivel adicionar mais locacoes, vetor cheio\n");
                    break;
                case 2:
                    Devolucao(&locacoes, contadorVetorLocacoes, dia, mes);
                    break;
                case 3:
                    MostrarLocacoes(&locacoes, contadorVetorLocacoes);
                    break;
                }
                printf("\n");
            }
            while (opcao != 4);
            break;
        }


    }
    return (EXIT_SUCCESS);
}

