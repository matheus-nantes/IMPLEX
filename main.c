#include <time.h>
#include <sys/time.h>
#include "biblioteca.h"

#define BILLION  1000000000.0


int main(){

    int inc,fim,stp,rpt;
    double media = 0, mediaS = 0, mediaI = 0, mediaM = 0, mediaH = 0, mediaQ = 0, mediaC = 0;

    FILE * tabela;
    FILE * selectionRandom, *selectionReverse, *selectionSorted,*selectionNearly;
    FILE * insertionRandom, *insertionReverse, *insertionSorted,*insertionNearly;
    FILE * mergeRandom, *mergeReverse, *mergeSorted,*mergeNearly;
    FILE * heapRandom, *heapReverse, *heapSorted,*heapNearly;
    FILE * quickRandom, *quickReverse, *quickSorted,*quickNearly;
    FILE * countingRandom, *countingReverse, *countingSorted,*countingNearly;

    printf("Informe o valor de inicio para n: ");
    scanf("%d",&inc);

    printf("Informe o valor de fim para n: ");
    scanf("%d",&fim);

    printf("Informe o intervalo: ");
    scanf("%d",&stp);

    printf("Informe a quantidade de repeticoes: ");
    scanf("%d",&rpt);


    int* vetor, *vetorS,*vetorI,*vetorM,*vetorH,*vetorQ,*vetorC;

 
    tabela = fopen("tabela.txt","w");
    fprintf(tabela,"[[RANDOM]]\n");
    printf("\n[[RANDOM]]\n");
    selectionRandom = fopen("selectionRandom.txt","w");
    insertionRandom = fopen("insertionRandom.txt","w");
    mergeRandom = fopen("mergeRandom.txt","w");
    heapRandom = fopen("heapRandom.txt","w");
    quickRandom = fopen("quickRandom.txt","w");
    countingRandom = fopen("countingRandom.txt","w");

    printf("    n       Selection     Insertion     Merge         Heap          Quick         Counting\n");
    fprintf(tabela,"    n       Selection     Insertion     Merge         Heap          Quick         Counting\n");
    for(int n = inc; n <= fim; n+=stp){
        struct timeval insertionI, insertionF, selectionI, selectionF,mergeI,mergeF, heapI, heapF, quickI, quickF, countI, countF;
        char aux[10];
        sprintf(aux, "%6d", n);
        printf("  %s    ",aux);
        fprintf(tabela,"  %s    ",aux);
        
        //geração do vetor
        media = 0;
        vetor = calloc(n, sizeof(int));
        vetorS = calloc(n, sizeof(int));
        vetorI = calloc(n, sizeof(int));
        vetorM = calloc(n, sizeof(int));
        vetorH = calloc(n, sizeof(int));
        vetorQ = calloc(n, sizeof(int));
        vetorC = calloc(n, sizeof(int));
        mediaS = 0;
        mediaI = 0; 
        mediaM = 0;
        mediaH = 0;
        mediaQ = 0;
        mediaC = 0;
        for(int i = 0; i < rpt; i++){
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
            SelectionSort(n, vetorS);
            gettimeofday(&selectionF,NULL);
            mediaS += (((selectionF.tv_sec - selectionI.tv_sec) * 1000000) + (selectionF.tv_usec -selectionI.tv_usec))/1000000.0;

            //insertion
            gettimeofday(&insertionI,NULL);
            InsertionSort(n, vetorI);
            gettimeofday(&insertionF,NULL);
            mediaI += (((insertionF.tv_sec - insertionI.tv_sec) * 1000000) + (insertionF.tv_usec - insertionI.tv_usec))/1000000.0;


            //Merge
            gettimeofday(&mergeI,NULL);
            MergeSort(vetorM, 0, n-1);
            gettimeofday(&mergeF,NULL);
            mediaM += (((mergeF.tv_sec - mergeI.tv_sec) * 1000000) + (mergeF.tv_usec - mergeI.tv_usec))/1000000.0;

            //Heap
            gettimeofday(&heapI,NULL);
            HeapSort(n, vetorH);
            gettimeofday(&heapF,NULL);
            mediaH += (((heapF.tv_sec - heapI.tv_sec) * 1000000) + (heapF.tv_usec - heapI.tv_usec))/1000000.0;

            //Quick
            gettimeofday(&quickI, NULL);
            QuickSort(vetorQ, 0, n-1);
            gettimeofday(&quickF, NULL);
            mediaQ += (((quickF.tv_sec - quickI.tv_sec)*1000000)+(quickF.tv_usec-quickI.tv_usec))/1000000.0;

            //Counting
            gettimeofday(&countI, NULL);
            countingSort(vetorC, n);
            gettimeofday(&countF, NULL);
            mediaC += (((countF.tv_sec - countI.tv_sec)*1000000)+(countF.tv_usec-countI.tv_usec))/1000000.0;
        }
        printf("%lf      ",mediaS/rpt);
        printf("%lf      ",mediaI/rpt);
        printf("%lf      ",mediaM/rpt);
        printf("%lf      ",mediaH/rpt);
        printf("%lf      ",mediaQ/rpt);
        printf("%lf      ",mediaC/rpt);

        fprintf(tabela,"%lf      ",mediaS/rpt);
        fprintf(tabela, "%lf      ",mediaI/rpt);
        fprintf(tabela, "%lf      ",mediaM/rpt);
        fprintf(tabela, "%lf      ",mediaH/rpt);
        fprintf(tabela, "%lf      ",mediaQ/rpt);
        fprintf(tabela,"%lf      ",mediaC/rpt);

        fprintf(selectionRandom,"%d %f\n",n,mediaS/rpt);
        fprintf(insertionRandom,"%d %f\n",n,mediaI/rpt);
        fprintf(mergeRandom,"%d %f\n",n,mediaM/rpt);
        fprintf(heapRandom,"%d %f\n",n,mediaH/rpt);
        fprintf(quickRandom,"%d %f\n",n,mediaQ/rpt);
        fprintf(countingRandom,"%d %f\n",n,mediaC/rpt);
        
        printf("\n");
        fprintf(tabela,"\n");

        free(vetor);
        free(vetorS);
        free(vetorI);
        free(vetorM);
        free(vetorH);
        free(vetorQ);
        free(vetorC);
    }

    fclose(selectionRandom);
    fclose(insertionRandom);
    fclose(heapRandom);
    fclose(quickRandom);
    fclose(countingRandom);
    fclose(selectionRandom);

    fprintf(tabela, "\n[[REVERSE]]\n");
    printf("\n[[REVERSE]]\n");

    selectionReverse = fopen("selectionReverse.txt","w");
    insertionReverse = fopen("insertionReverse.txt","w");
    mergeReverse = fopen("mergeReverse.txt","w");
    heapReverse = fopen("heapReverse.txt","w");
    quickReverse = fopen("quickReverse.txt","w");
    countingReverse = fopen("countingReverse.txt","w");
    printf("    n       Selection     Insertion     Merge         Heap          Quick         Counting\n");
    fprintf(tabela,"    n       Selection     Insertion     Merge         Heap          Quick         Counting\n");
    for(int n = inc; n <= fim; n+=stp){
        struct timeval insertionI, insertionF, selectionI, selectionF,mergeI,mergeF, heapI, heapF, quickI, quickF, countI, countF;
        char aux[10];
        sprintf(aux, "%6d", n);
        printf("  %s    ",aux);
        fprintf(tabela,"  %s    ",aux);
        
        //geração do vetor
        vetor = calloc(n, sizeof(int));
        vetorS = calloc(n, sizeof(int));
        vetorI = calloc(n, sizeof(int));
        vetorM = calloc(n, sizeof(int));
        vetorH = calloc(n, sizeof(int));
        vetorQ = calloc(n, sizeof(int));
        vetorC = calloc(n, sizeof(int));
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
        fprintf(tabela,"%lf      ",media);
        fprintf(selectionReverse,"%d %f\n",n,media);

        //Insertion
        gettimeofday(&insertionI,NULL);
        InsertionSort(n, vetorI);
        gettimeofday(&insertionF,NULL);
        media = (((insertionF.tv_sec - insertionI.tv_sec) * 1000000) + (insertionF.tv_usec - insertionI.tv_usec))/1000000.0;
        printf("%lf      ",media);
        fprintf(tabela,"%lf      ",media);
        fprintf(insertionReverse,"%d %f\n",n,media);

        //Merge
        gettimeofday(&mergeI,NULL);
        MergeSort(vetorM, 0, n-1);
        gettimeofday(&mergeF,NULL);
        media = (((mergeF.tv_sec - mergeI.tv_sec) * 1000000) + (mergeF.tv_usec - mergeI.tv_usec))/1000000.0;
        printf("%lf      ",media);
        fprintf(tabela,"%lf      ",media);
        fprintf(mergeReverse,"%d %f\n",n,media);

        //Heap
        gettimeofday(&heapI,NULL);
        HeapSort(n, vetorH);
        gettimeofday(&heapF,NULL);
        media = (((heapF.tv_sec - heapI.tv_sec) * 1000000) + (heapF.tv_usec - heapI.tv_usec))/1000000.0;
        printf("%lf      ",media);
        fprintf(tabela,"%lf      ",media);
        fprintf(heapReverse,"%d %f\n",n,media);

        //Quick
        gettimeofday(&quickI,NULL);
        QuickSort(vetorQ, 0, n-1);
        gettimeofday(&quickF,NULL);
        media = (((quickF.tv_sec - quickI.tv_sec) * 1000000) + (quickF.tv_usec - quickI.tv_usec))/1000000.0;
        printf("%lf      ",media);
        fprintf(tabela,"%lf      ",media);
        fprintf(quickReverse,"%d %f\n",n,media);

        //Counting
        gettimeofday(&countI,NULL);
        countingSort(vetorC, n);
        gettimeofday(&countF,NULL);
        media = (((countF.tv_sec - countI.tv_sec) * 1000000) + (countF.tv_usec - countI.tv_usec))/1000000.0;
        printf("%lf      ",media);
        fprintf(tabela,"%lf      ",media);
        fprintf(countingReverse,"%d %f\n",n,media);

        printf("\n");
        fprintf(tabela,"\n");

        free(vetor);
        free(vetorS);
        free(vetorI);
        free(vetorM);
        free(vetorH);
        free(vetorQ);
        free(vetorC);
    }
    fclose(selectionReverse);
    fclose(insertionReverse);
    fclose(heapReverse);
    fclose(quickReverse);
    fclose(countingReverse);
    fclose(selectionReverse);


    fprintf(tabela,"\n[[SORTED]]\n");
    printf("\n[[SORTED]]\n");

    selectionSorted = fopen("selectionSorted.txt","w");
    insertionSorted = fopen("insertionSorted.txt","w");
    mergeSorted = fopen("mergeSorted.txt","w");
    heapSorted = fopen("heapSorted.txt","w");
    quickSorted = fopen("quickSorted.txt","w");
    countingSorted = fopen("countingSorted.txt","w");

    printf("    n       Selection     Insertion     Merge         Heap          Quick         Counting\n");
    fprintf(tabela,"    n       Selection     Insertion     Merge         Heap          Quick         Counting\n");
    for(int n = inc; n <= fim; n+=stp){
        struct timeval insertionI, insertionF, selectionI, selectionF,mergeI,mergeF, heapI, heapF, quickI, quickF, countI, countF;
        char aux[10];
        sprintf(aux, "%6d", n);
        printf("  %s    ",aux);
        fprintf(tabela,"  %s    ",aux);
        
        //geração do vetor
        vetor = calloc(n, sizeof(int));
        vetorS = calloc(n, sizeof(int));
        vetorI = calloc(n, sizeof(int));
        vetorM = calloc(n, sizeof(int));
        vetorH = calloc(n, sizeof(int));
        vetorQ = calloc(n, sizeof(int));
        vetorC = calloc(n, sizeof(int));
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
        fprintf(tabela,"%lf      ",media);
        fprintf(selectionSorted,"%d %f\n",n,media);

        //Insertion
        gettimeofday(&insertionI,NULL);
        InsertionSort(n, vetorI);
        gettimeofday(&insertionF,NULL);
        media = (((insertionF.tv_sec - insertionI.tv_sec) * 1000000) + (insertionF.tv_usec - insertionI.tv_usec))/1000000.0;
        printf("%lf      ",media);
        fprintf(tabela,"%lf      ",media);
        fprintf(insertionSorted,"%d %f\n",n,media);

        //Merge
        gettimeofday(&mergeI,NULL);
        MergeSort(vetorM, 0, n-1);
        gettimeofday(&mergeF,NULL);
        media = (((mergeF.tv_sec - mergeI.tv_sec) * 1000000) + (mergeF.tv_usec - mergeI.tv_usec))/1000000.0;
        printf("%lf      ",media);
        fprintf(tabela,"%lf      ",media);
        fprintf(mergeSorted,"%d %f\n",n,media);

        //Heap
        gettimeofday(&heapI,NULL);
        HeapSort(n, vetorH);
        gettimeofday(&heapF,NULL);
        media = (((heapF.tv_sec - heapI.tv_sec) * 1000000) + (heapF.tv_usec - heapI.tv_usec))/1000000.0;
        printf("%lf      ",media);
        fprintf(tabela,"%lf      ",media);
        fprintf(heapSorted,"%d %f\n",n,media);

        //Quick
        gettimeofday(&quickI,NULL);
        QuickSort(vetorQ, 0, n-1);
        gettimeofday(&quickF,NULL);
        media = (((quickF.tv_sec - quickI.tv_sec) * 1000000) + (quickF.tv_usec - quickI.tv_usec))/1000000.0;
        printf("%lf      ",media);
        fprintf(tabela,"%lf      ",media);
        fprintf(quickSorted,"%d %f\n",n,media);

        //Counting
        gettimeofday(&countI,NULL);
        countingSort(vetorC, n);
        gettimeofday(&countF,NULL);
        media = (((countF.tv_sec - countI.tv_sec) * 1000000) + (countF.tv_usec - countI.tv_usec))/1000000.0;
        printf("%lf      ",media);
        fprintf(tabela,"%lf      ",media);
        fprintf(countingSorted,"%d %f\n",n,media);
        
        printf("\n");
        fprintf(tabela,"\n");
        

        
        free(vetor);
        free(vetorS);
        free(vetorI);
        free(vetorM);
        free(vetorH);
        free(vetorQ);
        free(vetorC);
    }
    fclose(selectionSorted);
    fclose(insertionSorted);
    fclose(mergeSorted);
    fclose(heapSorted);
    fclose(quickSorted);
    fclose(countingSorted);

    printf("\n[[NEARLY SORTED]]\n");
    fprintf(tabela, "\n[[NEARLY SORTED]]\n");

    selectionNearly = fopen("selectionNearly.txt","w");
    insertionNearly = fopen("insertionNearly.txt","w");
    mergeNearly = fopen("mergeNearly.txt","w");
    heapNearly = fopen("heapNearly.txt","w");
    quickNearly = fopen("quickNearly.txt","w");
    countingNearly = fopen("countingNearly.txt","w");

    printf("    n       Selection     Insertion     Merge         Heap          Quick         Counting\n");
    fprintf(tabela,"    n       Selection     Insertion     Merge         Heap          Quick         Counting\n");
    for(int n = inc; n <= fim; n+=stp){
        struct timeval insertionI, insertionF, selectionI, selectionF,mergeI,mergeF, heapI, heapF, quickI, quickF, countI, countF;
        char aux[10];
        sprintf(aux, "%6d", n);
        printf("  %s    ",aux);
        fprintf(tabela, "  %s    ",aux);
        
        //geração do vetor
        vetor = calloc(n, sizeof(int));
        vetorS = calloc(n, sizeof(int));
        vetorI = calloc(n, sizeof(int));
        vetorM = calloc(n, sizeof(int));
        vetorH = calloc(n, sizeof(int));
        vetorQ = calloc(n, sizeof(int));
        vetorC = calloc(n, sizeof(int));
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
        fprintf(tabela, "%lf      ",media);
        fprintf(selectionNearly,"%d %f\n",n,media);

        //Insertion
        gettimeofday(&insertionI,NULL);
        InsertionSort(n, vetorI);
        gettimeofday(&insertionF,NULL);
        media = (((insertionF.tv_sec - insertionI.tv_sec) * 1000000) + (insertionF.tv_usec - insertionI.tv_usec))/1000000.0;
        printf("%lf      ",media);
        fprintf(tabela, "%lf      ",media);
        fprintf(insertionNearly,"%d %f\n",n,media);

        //Merge
        gettimeofday(&mergeI,NULL);
        MergeSort(vetorM, 0, n-1);
        gettimeofday(&mergeF,NULL);
        media = (((mergeF.tv_sec - mergeI.tv_sec) * 1000000) + (mergeF.tv_usec - mergeI.tv_usec))/1000000.0;
        printf("%lf      ",media);
        fprintf(tabela, "%lf      ",media);
        fprintf(mergeNearly,"%d %f\n",n,media);

        //Heap
        gettimeofday(&heapI,NULL);
        HeapSort(n, vetorH);
        gettimeofday(&heapF,NULL);
        media = (((heapF.tv_sec - heapI.tv_sec) * 1000000) + (heapF.tv_usec - heapI.tv_usec))/1000000.0;
        printf("%lf      ",media);
        fprintf(tabela, "%lf      ",media);
        fprintf(heapNearly,"%d %f\n",n,media);

        //Quick
        gettimeofday(&quickI,NULL);
        QuickSort(vetorQ, 0, n-1);
        gettimeofday(&quickF,NULL);
        media = (((quickF.tv_sec - quickI.tv_sec) * 1000000) + (quickF.tv_usec - quickI.tv_usec))/1000000.0;
        printf("%lf      ",media);
        fprintf(tabela, "%lf      ",media);
        fprintf(quickNearly,"%d %f\n",n,media);

        //Counting
        gettimeofday(&countI,NULL);
        countingSort(vetorC, n);
        gettimeofday(&countF,NULL);
        media = (((countF.tv_sec - countI.tv_sec) * 1000000) + (countF.tv_usec - countI.tv_usec))/1000000.0;
        printf("%lf      ",media);
        fprintf(tabela, "%lf      ",media);
        fprintf(countingNearly,"%d %f\n",n,media);


        printf("\n");
        fprintf(tabela,"\n");



        free(vetor);
        free(vetorS);
        free(vetorI);
        free(vetorM);
        free(vetorH);
        free(vetorQ);
        free(vetorC);
    }
    fclose(selectionNearly);
    fclose(insertionNearly);
    fclose(mergeNearly);
    fclose(heapNearly);
    fclose(quickNearly);
    fclose(countingNearly);
    fclose(tabela);

    return 0;
}