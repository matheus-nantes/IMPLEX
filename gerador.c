#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "biblioteca.h"

void gerarAleatorios(int tamanho, int * vetor){

    srand(time(NULL));

    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand() % tamanho*1.5;
    }
    // for(int i = 0; i < tamanho; i++){
    //     printf("%d - ",vetor[i]);
    // }
}

void gerarReverso(int tamanho, int * vetor){
    srand(time(NULL));

    vetor[tamanho-1] = rand() % 10;
    for(int i = 2; i <= tamanho; i++){
        vetor[tamanho-i] = vetor[tamanho-i+1] + rand()%10;
    }
    // printf("----ALEAT----- + %d - %d\n",vetor[0], vetor[tamanho-1]);
}

void gerarOrdenado(int tamanho, int * vetor){
    srand(time(NULL));

    vetor[0] = rand() % 10;
    for(int i = 1; i < tamanho; i++){
        vetor[i] = vetor[i-1] + rand()%10;
    }
    // printf("----ALEAT----- + %d - %d\n",vetor[0], vetor[tamanho-1]);
}

void gerarQuaseOrdenado( int tamanho, int *vetor){
    srand(time(NULL));
    
    int aux, p1, p2;
    gerarOrdenado(tamanho, vetor);
    for(int i = 0; i < tamanho/16.65; i++){//com uma margem de erro de 2% pra cima. Em um vetor de 100 elementos, preciso realizar 6 trocas para "bagunçar" em 12% meu vetor(cada troca move dois elementos), logo, 100/13,65 é aproximadamente 6, que é a quantidade de trocas que serão realizadas
        p1 = rand()%tamanho;
        p2 = rand()%tamanho;
        while(p1 == p2)
            p2 = rand()%tamanho;
        aux = vetor[p1];
        vetor[p1] = vetor[p2];
        vetor[p2] = aux;
    }
}
