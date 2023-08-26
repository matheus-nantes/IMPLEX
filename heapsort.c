#include <stdio.h>
#include "biblioteca.h"

void heapify(int arr[], int tamanho, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < tamanho && arr[esquerda] > arr[maior])
        maior = esquerda;

    if (direita < tamanho && arr[direita] > arr[maior])
        maior = direita;

    if (maior != i) {
        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;

        heapify(arr, tamanho, maior);
    }
}

void HeapSort(int tamanho, int *vetor) {
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        heapify(vetor, tamanho, i);

    for (int i = tamanho - 1; i > 0; i--) {
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;

        heapify(vetor, i, 0);
    }
}