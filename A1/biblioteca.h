#include <stdio.h>
#include <stdlib.h>

void gerarAleatorios(int tamanho, int * vetorAleatorio);

void gerarReverso(int tamanho, int * vetor);

void gerarOrdenado(int tamanho, int * vetor);

void gerarQuaseOrdenado(int tamanho, int * vetor);

//ordenação
void InsertionSort(int tamanho, int *vetor);

void SelectionSort(int tamanho, int * vetor);

void MergeSort(int *vetor, int left, int right);

void HeapSort(int tamanho, int *vetor);

void QuickSort(int *vetor, int low, int high);

void countingSort(int vetor[], int tamanho);