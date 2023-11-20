#include "biblioteca.h"

void merge(int *vetor, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Cria vetores temporários
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copia os dados para os vetores temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = vetor[left + i];
    for (j = 0; j < n2; j++)
        R[j] = vetor[mid + 1 + j];

    // Junta os vetores de volta
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void MergeSort(int *vetor, int left, int right) {
    if (left < right) {
        // Encontra o ponto médio do vetor
        int mid = left + (right - left) / 2;

        MergeSort(vetor, left, mid);
        MergeSort(vetor, mid + 1, right);
        // Junta as  metades ordenadas
        merge(vetor, left, mid, right);
    }
}