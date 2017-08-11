#include "lib.h"

void main()
{

    int i, vetSize=5000, mod=4999;
    int vet[vetSize], vet2[vetSize], vetAux[vetSize];
    clock_t tempoInicial, tempoFinal;
    clock_t ciclosBubble;
    clock_t ciclosShell;
    clock_t ciclosHashing;
    clock_t ciclosBuscaVetor;

    vetFill(vet,vetSize);

    vetCopy(vet,vet2,vetSize);
    vetCopy(vet,vetAux,vetSize);

    ///////////////////////////////////////////////////////////
//
    tempoInicial = clock();
    bubbleSort(vet, vetSize);
    tempoFinal = clock();
    ciclosBubble = (double)(tempoFinal - tempoInicial);
    printf("Ciclos BubbleSort: %ld\n", ciclosBubble);

//    vetPrint(vet, vetSize);

    ////////////////////////////////////////////////////////////
//
    tempoInicial = clock();
    shellSort(vet2, vetSize);
    tempoFinal = clock();
    ciclosShell = (double)(tempoFinal - tempoInicial);
    printf("Ciclos ShellSort: %ld\n", ciclosShell);

//    vetPrint(vet2, vetSize);

    ////////////////////////////////////////////////////////////

    int vet3[vetSize];
    for(i=0; i<vetSize; i++)
    {
        vet3[i] = NULL;
    }

    tempoInicial = clock();
    vetCopyHash(vetAux, vet3,vetSize,mod);
    tempoFinal = clock();
    ciclosHashing = (double)(tempoFinal - tempoInicial);
    printf("Ciclos criacao Hashing: %ld\n", ciclosHashing);

//    vetPrint(vet3,vetSize);

    char caracter;

    printf("informe o caracter para busca: \n");
    scanf("%c", &caracter);

    int posicao;

    tempoInicial = clock();
    posicao = buscaVetor(vet, vetSize, caracter);
    tempoFinal = clock();
    ciclosBuscaVetor = (double)(tempoFinal - tempoInicial);
    printf("Ciclos busca: %ld\n posicao = %d\n", ciclosBuscaVetor, posicao);

    tempoInicial = clock();
    posicao = buscaHash(vet3, vetSize, caracter, mod);
    tempoFinal = clock();
    ciclosHashing = (double)(tempoFinal - tempoInicial);
    printf("Ciclos busca Hash: %ld \n posicao = %d\n", ciclosHashing, posicao);

}
