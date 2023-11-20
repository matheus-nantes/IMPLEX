#include "biblioteca.h"

int findMax(int vetor[], int tamanho) {
    int max = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > max) {
            max = vetor[i];
        }
    }
    return max;
}

void countingSort(int vetor[], int tamanho) {
    int max = findMax(vetor, tamanho);
    int *count = (int *)calloc(max + 1, sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        count[vetor[i]]++;
    }

    int k = 0; 
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            vetor[k] = i;
            k++;
            count[i]--;
        }
    }

    free(count);
}