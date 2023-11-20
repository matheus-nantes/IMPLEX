#include <iostream>
#include "biblioteca.h"
#include <time.h>

int main() {
  srand(time(NULL));
  int inc, fim, stp,valorN = 0, valorG = 0;
  double tempoN = 0, tempoG = 0, percent = 100.00;
  FILE * tabela, *dinamicoTempo, *dinamicoValor, *gulosotempo, *gulosoValor;
  char aux1[10], aux2[10];
  scanf("%d",&inc);
  scanf("%d",&fim);
  scanf("%d",&stp);
  tabela = fopen("tabela.txt","w");
  dinamicoTempo = fopen("dinamicotempo.txt","w");
  dinamicoValor = fopen("dinamicoValor.txt","w");
  gulosotempo = fopen("gulosotempo.txt","w");
  gulosoValor = fopen("gulosoValor.txt","w");

  fprintf(tabela, "    n   |   vDP  |    tDP   | vGreedy |  tGreedy |   %%\n");
  while(percent >= 90){
    for(int i = inc; i <= fim; i += stp){
      sprintf(aux1,"%7d",i);
      fprintf(tabela,"%s |", aux1);
      int * valores = (int *) calloc (i,sizeof(int));
      gerarValores(i, valores);//vai de 1 até n
      

      cortaTora(valorN, tempoN, i, valores);
      sprintf(aux1,"%7d", valorN);
      sprintf(aux2,"%7f",tempoN);
      fprintf(tabela, "%s | %s |",aux1, aux2);
      fprintf(dinamicoTempo,"%d %.6lf\n",i, tempoN);
      fprintf(dinamicoValor,"%d %d\n",i, valorN);
      

      cortaToraGuloso(valorG, tempoG, i, valores);
      sprintf(aux1,"%7d",valorG);
      sprintf(aux2,"%7f",tempoG);
      fprintf(tabela, " %s | %s | ",aux1, aux2);
      fprintf(gulosotempo,"%d %.6lf\n",i, tempoG);
      fprintf(gulosoValor,"%d %d\n",i, valorG);
    
      free(valores);
      if(valorN != 0)
        percent = ((1.0*valorG)/valorN)*100.00;
      fprintf(tabela,"%3.2lf\n",percent);
      
    }
  } 

  printf("acabou\n");

  

}