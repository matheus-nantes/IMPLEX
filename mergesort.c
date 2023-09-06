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

    // Funde os vetores temporários de volta em vetor[left..right]
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

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }

    // Libera a memória dos vetores temporários
    free(L);
    free(R);
}

// Função principal do MergeSort
void MergeSort(int *vetor, int left, int right) {
    if (left < right) {
        // Encontra o ponto médio do vetor
        int mid = left + (right - left) / 2;

        // Ordena a metade esquerda
        MergeSort(vetor, left, mid);

        // Ordena a metade direita
        MergeSort(vetor, mid + 1, right);

        // Funde as duas metades ordenadas
        merge(vetor, left, mid, right);
    }
}