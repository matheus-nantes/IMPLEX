#include <stdio.h>
#include "biblioteca.h"

void merge(int v[], int esq, int meio, int dir) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = v[esq + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[meio + 1 + j];

    int i = 0, j = 0, k = esq;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int tamanho, int *vetor) {
    if (tamanho > 1) {
        int meio = tamanho / 2;

        int esq[meio];
        int dir[tamanho - meio];

        for (int i = 0; i < meio; i++)
            esq[i] = vetor[i];
        for (int i = meio; i < tamanho; i++)
            dir[i - meio] = vetor[i];

        MergeSort(meio, esq);
        MergeSort(tamanho - meio, dir);

        merge(vetor, 0, meio - 1, tamanho - 1);
    }
}

