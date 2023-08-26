#include <time.h>
#include <sys/time.h>
#include "biblioteca.h"

#define BILLION  1000000000.0


int main(){

    int inc,fim,stp,rpt;
    double media = 0;

    printf("Informe o valor de inicio para n: ");
    scanf("%d",&inc);

    printf("Informe o valor de fim para n: ");
    scanf("%d",&fim);

    printf("Informe o intervalo: ");
    scanf("%d",&stp);

    printf("Informe a quantidade de repeticoes: ");
    scanf("%d",&rpt);


    int* vetor, *vetorS,*vetorI,*vetorM,*vetorH,*vetorQ,*vetorC;
    FILE *selec, *insert, *merge, *heap, *quick, *count;

 
    printf("\n[[RANDOM]]\n");
    printf("    n       Selection      Insertion     Merge        Heap          Quick      Counting\n");
    for(int n = inc; n <= fim; n+=stp){
        struct timeval insertionI, insertionF, selectionI, selectionF,mergeI,mergeF, heapI, heapF, quickI, quickF, countI, countF;
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
        gettimeofday(&selectionI,NULL);
        for(int i = 0; i < rpt; i++){
            SelectionSort(n, vetorS);
            gerarAleatorios(n, vetorS);
        }
        gettimeofday(&selectionF,NULL);
        media = (((selectionF.tv_sec - selectionI.tv_sec) * 1000000) + (selectionF.tv_usec -selectionI.tv_usec))/1000000.0;
        media = media/rpt;
        printf("%lf      ",media);

        //insertion
        gettimeofday(&insertionI,NULL);
        for(int i = 0; i < rpt; i++){
            InsertionSort(n, vetorI);
            gerarAleatorios(n, vetorI);
        }
        gettimeofday(&insertionF,NULL);
        media = (((insertionF.tv_sec - insertionI.tv_sec) * 1000000) + (insertionF.tv_usec - insertionI.tv_usec))/1000000.0;
        media /= rpt;
        printf("%lf     ",media);

        //Merge
        gettimeofday(&mergeI,NULL);
        for(int i = 0; i < rpt; i++){
            MergeSort(n, vetorM);
            gerarAleatorios(n, vetorM);
        }
        gettimeofday(&mergeF,NULL);
        media = (((mergeF.tv_sec - mergeI.tv_sec) * 1000000) + (mergeF.tv_usec - mergeI.tv_usec))/1000000.0;
        media /= rpt;
        printf("%lf     ",media);

        //Heap
        gettimeofday(&heapI,NULL);
        for(int i = 0; i < rpt; i++){
            HeapSort(n, vetorH);
            gerarAleatorios(n, vetorH);
        }
        gettimeofday(&heapF,NULL);
        media = (((heapF.tv_sec - heapI.tv_sec) * 1000000) + (heapF.tv_usec - heapI.tv_usec))/1000000.0;
        media /= rpt;
        printf("%lf     ",media);
        
        printf("\n");
    }


    printf("\n[[REVERSE]]\n");
    printf("    n       Selection      Insertion     Merge        Heap          Quick      Counting\n");
    for(int n = inc; n <= fim; n+=stp){
        struct timeval insertionI, insertionF, selectionI, selectionF,mergeI,mergeF, heapI, heapF, quickI, quickF, countI, countF;
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

        //Selection
        gettimeofday(&selectionI,NULL);
        SelectionSort(n, vetorS);
        gettimeofday(&selectionF,NULL);
        media = (((selectionF.tv_sec - selectionI.tv_sec) * 1000000) + (selectionF.tv_usec -selectionI.tv_usec))/1000000.0;
        printf("%lf      ",media);

        //Insertion
        gettimeofday(&insertionI,NULL);
        InsertionSort(n, vetorI);
        gettimeofday(&insertionF,NULL);
        media = (((insertionF.tv_sec - insertionI.tv_sec) * 1000000) + (insertionF.tv_usec - insertionI.tv_usec))/1000000.0;
        printf("%lf      ",media);

        //Merge
        gettimeofday(&mergeI,NULL);
        MergeSort(n, vetorM);
        gettimeofday(&mergeF,NULL);
        media = (((mergeF.tv_sec - mergeI.tv_sec) * 1000000) + (mergeF.tv_usec - mergeI.tv_usec))/1000000.0;
        printf("%lf      ",media);

        //Heap
        gettimeofday(&heapI,NULL);
        HeapSort(n, vetorH);
        gettimeofday(&heapF,NULL);
        media = (((heapF.tv_sec - heapI.tv_sec) * 1000000) + (heapF.tv_usec - heapI.tv_usec))/1000000.0;
        printf("%lf      ",media);
        
        printf("\n");
    }


    printf("\n[[SORTED]]\n");
    printf("    n       Selection      Insertion     Merge        Heap          Quick      Counting\n");
    for(int n = inc; n <= fim; n+=stp){
        struct timeval insertionI, insertionF, selectionI, selectionF,mergeI,mergeF, heapI, heapF, quickI, quickF, countI, countF;
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

        //Selection
        gettimeofday(&selectionI,NULL);
        SelectionSort(n, vetorS);
        gettimeofday(&selectionF,NULL);
        media = (((selectionF.tv_sec - selectionI.tv_sec) * 1000000) + (selectionF.tv_usec -selectionI.tv_usec))/1000000.0;
        printf("%lf      ",media);

        //Insertion
        gettimeofday(&insertionI,NULL);
        InsertionSort(n, vetorI);
        gettimeofday(&insertionF,NULL);
        media = (((insertionF.tv_sec - insertionI.tv_sec) * 1000000) + (insertionF.tv_usec - insertionI.tv_usec))/1000000.0;
        printf("%lf      ",media);

        //Merge
        gettimeofday(&mergeI,NULL);
        MergeSort(n, vetorM);
        gettimeofday(&mergeF,NULL);
        media = (((mergeF.tv_sec - mergeI.tv_sec) * 1000000) + (mergeF.tv_usec - mergeI.tv_usec))/1000000.0;
        printf("%lf      ",media);

        //Heap
        gettimeofday(&heapI,NULL);
        HeapSort(n, vetorH);
        gettimeofday(&heapF,NULL);
        media = (((heapF.tv_sec - heapI.tv_sec) * 1000000) + (heapF.tv_usec - heapI.tv_usec))/1000000.0;
        printf("%lf      ",media);


        
        printf("\n");
    }

    printf("\n[[NEARLY SORTED]]\n");
    printf("    n       Selection      Insertion     Merge        Heap          Quick      Counting\n");
    for(int n = inc; n <= fim; n+=stp){
        struct timeval insertionI, insertionF, selectionI, selectionF,mergeI,mergeF, heapI, heapF, quickI, quickF, countI, countF;
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

       //Selection
        gettimeofday(&selectionI,NULL);
        SelectionSort(n, vetorS);
        gettimeofday(&selectionF,NULL);
        media = (((selectionF.tv_sec - selectionI.tv_sec) * 1000000) + (selectionF.tv_usec -selectionI.tv_usec))/1000000.0;
        printf("%lf      ",media);

        //Insertion
        gettimeofday(&insertionI,NULL);
        InsertionSort(n, vetorI);
        gettimeofday(&insertionF,NULL);
        media = (((insertionF.tv_sec - insertionI.tv_sec) * 1000000) + (insertionF.tv_usec - insertionI.tv_usec))/1000000.0;
        printf("%lf      ",media);

        //Merge
        gettimeofday(&mergeI,NULL);
        MergeSort(n, vetorM);
        gettimeofday(&mergeF,NULL);
        media = (((mergeF.tv_sec - mergeI.tv_sec) * 1000000) + (mergeF.tv_usec - mergeI.tv_usec))/1000000.0;
        printf("%lf      ",media);

        //Heap
        gettimeofday(&heapI,NULL);
        HeapSort(n, vetorH);
        gettimeofday(&heapF,NULL);
        media = (((heapF.tv_sec - heapI.tv_sec) * 1000000) + (heapF.tv_usec - heapI.tv_usec))/1000000.0;
        printf("%lf      ",media);



        printf("\n");




    }
    
        free(vetor);
        free(vetorS);
        free(vetorI);
        free(vetorM);
        free(vetorH);
        free(vetorQ);
        free(vetorC);

    return 0;
}