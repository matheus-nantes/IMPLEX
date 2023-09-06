#include "biblioteca.h"

// Função para encontrar o valor máximo no vetor
int findMax(int vetor[], int tamanho) {
    int max = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > max) {
            max = vetor[i];
        }
    }
    return max;
}

// Função de ordenação Counting Sort
void countingSort(int vetor[], int tamanho) {
    int max = findMax(vetor, tamanho);
    int *count = (int *)calloc(max + 1, sizeof(int)); // Cria um vetor de contagem com base no valor máximo

    // Conta a ocorrência de cada elemento
    for (int i = 0; i < tamanho; i++) {
        count[vetor[i]]++;
    }

    int k = 0; // Índice do vetor original
    // Reconstrói o vetor ordenado com base no vetor de contagem
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            vetor[k] = i;
            k++;
            count[i]--;
        }
    }

    free(count); // Libera a memória alocada para o vetor de contagem
}