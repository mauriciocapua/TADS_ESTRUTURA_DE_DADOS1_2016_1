#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void vetFill(int vet[], int vetSize)
{
    int i, cod;
    srand(time(NULL));
    for(i=0; i<vetSize; i++)
    {
        cod = rand() % 51;
        if(cod<25)
        {
            vet[i] = cod+65;
        }
        else
        {
            vet[i] = cod+97-25;
        }
//		printf("%c - ", vet[i]);
    }
}

void vetCopy(int vet[],int vet2[], int vetSize)
{
    int i;
    for(i=0; i<vetSize; i++)
    {
        vet2[i] = vet[i];
    }
}

void vetPrint(int vet[], int vetSize)
{
    int i;
    for(i=0; i<vetSize; i++)
    {
        printf("%c - ",vet[i]);
    }
}

void bubbleSort(int array[], int n)
{
    int c, d, swap;
    for (c = 0 ; c < ( n - 1 ); c++)
    {
        for (d = 0 ; d < n - c - 1; d++)
        {
            if (array[d] > array[d+1])
            {
                swap = array[d];
                array[d] = array[d+1];
                array[d+1] = swap;
            }
        }
    }
}
void shellSort(int vet[], int n)
{
    int i, j, increment, temp;

    increment = 3;
    while (increment > 0)
    {
        for (i=0; i < n; i++)
        {
            j = i;
            temp = vet[i];
            while ((j >= increment) && (vet[j-increment] > temp))
            {
                vet[j] = vet[j - increment];
                j = j - increment;
            }
            vet[j] = temp;
        }
        if (increment/2 != 0)
            increment = increment/2;
        else if (increment == 1)
            increment = 0;
        else
            increment = 1;
    }
}



int hashing(int ascii, int n) //calculo da posicao
{
    return ascii % n;
}

void vetCopyHash(int vet[], int vet2[], int vetSize, int mod)
{
    int i,aux;
    for(i=0; i<vetSize; i++)
    {
        if(vet2[hashing(vet[i],mod)] != NULL)
        {
            for(aux=0; aux<vetSize; aux++)
            {
                if(vet2[aux]==NULL)
                {
                    vet2[aux] = vet[i];
                    break;
                }
            }
        }
        else
        {
            vet2[hashing(vet[i],mod)] = vet[i];
        }

    }
}

int buscaHash(int vet[], int vetSize, char caracter, int mod)
{
    int i,aux;

    if(vet[hashing((int)caracter,mod)] == caracter)
    {
        return vet[hashing((int)caracter,mod)];
    }
    else
    {
        for(aux=0; aux<vetSize; aux++)
        {
            if(vet[aux]==caracter)
            {
                return vet[aux];
            }
        }
    }
}

int buscaVetor(int vet[], int vetSize, char caracter)
{
    int i;

    for(i=0; i<vetSize; i++)
    {
        if(vet[i] == caracter)
        {
            return i;
        }
    }
}


