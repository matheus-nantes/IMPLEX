#include <time.h>
#include "biblioteca.h"

#define BILLION  1000000000.0


int main(){

    int inc,fim,stp,rpt;
    float media = 0;

    printf("Informe o valor de início para n: ");
    scanf("%d",&inc);

    printf("Informe o valor de fim para n: ");
    scanf("%d",&fim);

    printf("Informe o intervalo: ");
    scanf("%d",&stp);

    printf("Informe a quantidade de repetições: ");
    scanf("%d",&rpt);


    int* vetor, *vetorS,*vetorI,*vetorM,*vetorH,*vetorQ,*vetorC;

 
    printf("[[RANDOM]]\n");
    printf("    n    Selection   Insertion   Merge       Heap          Quick      Counting\n");
    for(int n = inc; n <= fim; n+=stp){
        time_t insertionI, insertionF, selectionI, selectionF;
        //geração do vetor
        printf("  %d    ",n);
        media = 0;
        vetor = calloc(n, sizeof(int));
        vetorS = calloc(n, sizeof(int));
        vetorI = calloc(n, sizeof(int));
        vetorM = calloc(n, sizeof(int));
        vetorH = calloc(n, sizeof(int));
        vetorQ = calloc(n, sizeof(int));
        vetorC = calloc(n, sizeof(int));
        gerarAleatorios(n, vetor);
        for(int i = 0; i < n; i++){
            vetorS[i] = vetor[i];
            vetorI[i] = vetor[i];
            vetorM[i] = vetor[i];
            vetorH[i] = vetor[i];
            vetorQ[i] = vetor[i];
            vetorC[i] = vetor[i];
        }

        

        //ordenações
        //selection
        selectionI  = clock();
        for(int i = 0; i < rpt; i++){
            SelectionSort(n, vetorS);
            gerarAleatorios(n, vetor);
        }
        selectionF = clock();
        media = (double)(selectionF - selectionI)/CLOCKS_PER_SEC;
        media = media/rpt;
        printf("%f      ",media);

        //insertion
        insertionI = clock();
        for(int i = 0; i < rpt; i++){
            InsertionSort(n, vetorI);
        }
        insertionF = clock();
        media = (double)(insertionF-insertionI)/CLOCKS_PER_SEC;
        media /= rpt;
        printf("%f     ",media);


        
        printf("\n");
    }


    printf("\n[[REVERSE]]");
    printf("    n    Selection   Insertion   Merge       Heap          Quick      Counting\n");
    for(int n = inc; n <= fim; n+=stp){
        time_t insertionI, insertionF, selectionI, selectionF;
        //geração do vetor
        printf("  %d    ",n);
        gerarReverso(n, vetor);
        for(int i = 0; i < n; i++){
            vetorS[i] = vetor[i];
            vetorI[i] = vetor[i];
            vetorM[i] = vetor[i];
            vetorH[i] = vetor[i];
            vetorQ[i] = vetor[i];
            vetorC[i] = vetor[i];
        }

        //ordenações

        selectionI = clock();
        SelectionSort(n, vetorS);
        selectionF = clock();
        printf("%f      ",(double)(selectionF-selectionI)/CLOCKS_PER_SEC);


        insertionI = clock();
        InsertionSort(n, vetorI);
        insertionF = clock();
        printf("%f      ",(double)(insertionF-insertionI)/CLOCKS_PER_SEC);




        
        printf("\n");
    }


    printf("\n[[SORTED]]");
    printf("    n    Selection   Insertion   Merge       Heap          Quick      Counting\n");
    for(int n = inc; n <= fim; n+=stp){
        time_t insertionI, insertionF, selectionI, selectionF;
        //geração do vetor
        printf("  %d    ",n);
        gerarOrdenado(n, vetor);
        for(int i = 0; i < n; i++){
            vetorS[i] = vetor[i];
            vetorI[i] = vetor[i];
            vetorM[i] = vetor[i];
            vetorH[i] = vetor[i];
            vetorQ[i] = vetor[i];
            vetorC[i] = vetor[i];
        }

        //ordenações

        selectionI = clock();
        SelectionSort(n, vetorS);
        selectionF = clock();
        printf("%f      ",(double)(selectionF-selectionI)/CLOCKS_PER_SEC);

        insertionI = clock();
        InsertionSort(n, vetorI);
        insertionF = clock();
        printf("%f      ",(double)(insertionF-insertionI)/CLOCKS_PER_SEC);




        
        printf("\n");
    }

    printf("\n[[NEARLY SORTED]]\n");
    printf("    n    Selection   Insertion   Merge       Heap          Quick      Counting\n");
    for(int n = inc; n <= fim; n+=stp){
        time_t insertionI, insertionF, selectionI, selectionF;
        //geração do vetor
        printf("  %d    ",n);
        gerarQuaseOrdenado(n, vetor);
        for(int i = 0; i < n; i++){
            vetorS[i] = vetor[i];
            vetorI[i] = vetor[i];
            vetorM[i] = vetor[i];
            vetorH[i] = vetor[i];
            vetorQ[i] = vetor[i];
            vetorC[i] = vetor[i];
        }

        //ordenações

        selectionI = clock();
        SelectionSort(n, vetorS);
        selectionF = clock();
        printf("%f      ",(double)(selectionF-selectionI)/CLOCKS_PER_SEC);

        insertionI = clock();
        InsertionSort(n, vetorI);
        insertionF = clock();
        printf("%f      ",(double)(insertionF-insertionI)/CLOCKS_PER_SEC);




        printf("\n");
    }

    return 0;
}