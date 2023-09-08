#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

void troca(int vetor[], int i, int j)
{
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

// retorna o pivô
int particiona(int vetor[], int inicio, int fim)
{
	int pivo, indice, i;
	
	pivo = vetor[fim];
	indice = inicio;
	
	for(i = inicio; i < fim; i++)
	{
		if(vetor[i] <= pivo)
		{
			troca(vetor, i, indice);
			indice++;
		}
	}
	
	troca(vetor, indice, fim);

	return indice;
}

// método auxiliar para escoleher um pivô aleatório para evitar o pior caso do quicksort
int particiona_random(int vetor[], int inicio, int fim)
{
	int indice = (rand() % (fim - inicio + 1)) + inicio;
	troca(vetor, indice, fim);
	return particiona(vetor, inicio, fim);
}

void QuickSort(int vetor[], int inicio, int fim)
{
	if(inicio < fim)
	{
		int indice = particiona_random(vetor, inicio, fim);

		QuickSort(vetor, inicio, indice - 1);
		QuickSort(vetor, indice + 1, fim);
	}
}