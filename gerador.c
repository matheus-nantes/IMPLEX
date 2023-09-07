#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "biblioteca.h"

void gerarAleatorios(int tamanho, int * vetor){

    srand(time(NULL));

    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand() % (int)(tamanho*1.5);
    }
}

void gerarReverso(int tamanho, int * vetor){
    srand(time(NULL));
    int acrescimo = 0;
    vetor[tamanho-1] = rand() % 11;
    for(int i = 2; i <= tamanho; i++){
        acrescimo = rand()%10;
        if(acrescimo == 0){
            acrescimo = rand()%10;
        }
        vetor[tamanho-i] = vetor[tamanho-i+1] + acrescimo;
    }
}

void gerarOrdenado(int tamanho, int * vetor){
    srand(time(NULL));
    int acrescimo = 0;

    vetor[0] = rand() % 10;
    for(int i = 1; i < tamanho; i++){
        acrescimo = rand()%10;
        if(acrescimo == 0){
            acrescimo = rand()%11;
        }
        vetor[i] = vetor[i-1] + acrescimo;
    }
}

void gerarQuaseOrdenado( int tamanho, int *vetor){
    srand(time(NULL));
    
    int aux, p1, p2;
    gerarOrdenado(tamanho, vetor);
    for(int i = 0; i < tamanho/20; i++){
        p1 = rand()%tamanho;
        p2 = rand()%tamanho;

        while((p1 != 0 && vetor[p1] < vetor[p1-1]) || (p1 != tamanho-1 && vetor[p1] > vetor[p1+1]) || p1 == p2)
            p1 = rand()%tamanho;

        while((p2 != 0 && vetor[p2] < vetor[p2-1])|| (p2 != tamanho-1 && vetor[p2] > vetor[p2+1]) || p1 == p2)
            p2 = rand()%tamanho;

        aux = vetor[p1];
        vetor[p1] = vetor[p2];
        vetor[p2] = aux;
    }
}
