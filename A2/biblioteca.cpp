#include "biblioteca.h"
#include <time.h>

struct densidade{
  int tamanho;
  double densidade;
};

void gerarValores(int tamanho,int * valores){
    for(int i = 0; i < tamanho; i++){
      valores[i] = (rand()%10)+1;
      //printf("%d = R$%d | ",i+1,valores[i]);
    }
     //printf("----\n");
  }


int maxCorteTora(int valores[], int tamanhoTora, int memo[]) {
  int tamanhoMaior = 0;
    if (tamanhoTora <= 0) {
        return 0;
    }
    if (memo[tamanhoTora] != -1) {//se já foi calculado o melhor valor para este tamanho de tora, n precisa recalcular
        return memo[tamanhoTora];
    }

    int maxValor = 0;

    for (int i = 1; i <= tamanhoTora; i++) {//se não foi calculado, busca o maior lucro possível
            int valorAtual = valores[i-1] + maxCorteTora(valores, tamanhoTora - i, memo);
            if (valorAtual > maxValor) {
                maxValor = valorAtual;
                tamanhoMaior = i;
        }
    }

    memo[tamanhoTora] = maxValor;
    //printf(" %d = %d + ",tamanhoTora, maxValor);

    return maxValor;
}


void cortaTora(int &valor, double &tempo, int tamanhoTora, int * valores){
  int * memoria = (int *) calloc(tamanhoTora+1, sizeof(int));
  
  for(int i = 0; i <= tamanhoTora; i++){
    memoria[i] = -1;
  }
  clock_t inicio = clock();
  valor = maxCorteTora(valores, tamanhoTora,memoria);
  clock_t fim = clock();
  tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

  free(memoria);
  }




void trocar(densidade *a, densidade *b) {
    densidade * temp = (densidade*) calloc(1,sizeof(densidade));
    temp->densidade = a->densidade;
    temp->tamanho = a->tamanho;
    a->densidade = b->densidade;
    a->tamanho = b->tamanho;
    b->densidade = temp->densidade;
    b->tamanho = temp->tamanho;
}

int particionar(struct densidade arr[], int baixo, int alto) {
    double pivo = arr[alto].densidade;
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (arr[j].densidade < pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quicksort(struct densidade arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto);

        quicksort(arr, baixo, pi - 1);
        quicksort(arr, pi + 1, alto);
    }
}


void cortaGuloso(int &valor, int tamanhoTora,int * valores, densidade * dense, int position){//em dense[] as densidades estão ordenadas de forma crescente, logo começamos com position na última posição válida deste vetor
   if(tamanhoTora > 0){//se ainda há o que ser cortado
     if(dense[position].tamanho <= tamanhoTora){//se for possível retirar da tora atual o tamanho com maior densidade
        valor += valores[dense[position].tamanho - 1];//soma o valor obtido
        tamanhoTora -= dense[position].tamanho;//reduz o tamanho disponível para corte
        cortaGuloso(valor,tamanhoTora,valores,dense,position);//chama novamente
      }
      else{//procura a próxima maior densidade retirável da tora
        cortaGuloso(valor,tamanhoTora,valores,dense,position-1);
      }
    }
   else{return;}
}
void cortaToraGuloso(int &valor, double &tempo, int tamanhoTora, int * valores){
  valor = 0;
  densidade * dense = (densidade *) calloc(tamanhoTora, sizeof(densidade));
  for(int i = 0; i < tamanhoTora; i++){
    dense[i].tamanho = i+1;//guardamos o respectivo tamanho de tal densidade
    dense[i].densidade = valores[i] / (dense[i].tamanho*1.0);//calculamos a densidade
  }
  quicksort(dense, 0, tamanhoTora-1);
  clock_t inicio = clock();
  cortaGuloso(valor, tamanhoTora,valores, dense, tamanhoTora-1);
  clock_t fim = clock();
  tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
}
