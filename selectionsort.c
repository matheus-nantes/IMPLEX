#include <stdio.h>
#include "biblioteca.h"

void SelectionSort(int tamanho, int * vetor){
    int  menor,aux;
    for(int i = 0; i < tamanho-1; i++){
        menor = i;
        for(int j = i+1; j < tamanho; j++){
            if(vetor[j] < vetor[menor]){
                menor = j;
            }
        }
        if(menor != i){
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
}