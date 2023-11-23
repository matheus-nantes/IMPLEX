//matheus nantes rezende da silva
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct cel {
    int *arestas;
    int cor;  // A cor para BFS (0 = branco, 1 = cinza, 2 = preto)
    int d;    // A distância para BFS
    int pi;   // O pai para BFS
};

typedef struct {
    int front, rear;
    int *items;
} Fila;

void inicializarFila(Fila *fila, int numVertices) {
    fila->front = -1;
    fila->rear = -1;
    fila->items = (int*) calloc(numVertices, sizeof(int));
}

int estaVazia(Fila *fila) {
    return fila->front == -1;
}

void enfileirar(Fila *fila, int vertice, int numVertices) {
    if (fila->rear == numVertices) {
        printf("Erro: Fila cheia\n");
        return;
    }

    if (fila->front == -1) {
        fila->front = 0;
    }

    fila->rear++;
    fila->items[fila->rear] = vertice;
}

int desenfileirar(Fila *fila) {
    int item;
    if (estaVazia(fila)) {
        printf("Erro: Fila vazia\n");
        return -1;
    } else {
        item = fila->items[fila->front];
        fila->front++;

        if (fila->front > fila->rear) {
            fila->front = fila->rear = -1;
        }

        return item;
    }
}

void BFS(struct cel *vertices, int numVertices, int s) {
    Fila Q;
    inicializarFila(&Q, numVertices);

    for (int u = 0; u < numVertices; u++) {
        vertices[u].cor = 0;   // BRANCO
        vertices[u].d = -1;
        vertices[u].pi = -1;
    }

    vertices[s].cor = 1; // CINZA
    vertices[s].d = 0;
    vertices[s].pi = -1;

    enfileirar(&Q, s, numVertices);

    while (!estaVazia(&Q)) {
        int u = desenfileirar(&Q);

        for (int v = 0; v < numVertices; v++) {
            if (vertices[u].arestas[v] && vertices[v].cor == 0) {
                vertices[v].cor = 1;        // CINZA
                vertices[v].d = vertices[u].d + 1;
                vertices[v].pi = u;
                enfileirar(&Q, v, numVertices);
            }
        }

        vertices[u].cor = 2; // PRETO
    }
}

int lancamentoMoedaTendenciosa(double probabilidadeCara) {
    double numeroAleatorio = (double)(rand() % 101); // Gerando um número aleatório entre 0 e 100
    probabilidadeCara = probabilidadeCara * 100;
    if (numeroAleatorio < probabilidadeCara) {// por exemplo, se a probabilidade for 0.1, e os valores possíveis para numeroAleatorio são números entre 0 e 1, há 10% de chance do número estar entre 0 e 0.1
        return 1; // conecta
    } else {
        return 0; // não conecta
    }
}

int main() {
    srand(time(NULL));
    int ini, fim, stp;
    float p;
    FILE * ptr;

    ptr = fopen("tabela.txt","w");
    

    scanf("%d", &ini);
    scanf("%d", &fim);
    scanf("%d", &stp);
    scanf("%f", &p);

    printf("V\tE\tgmin\tgmax\tgmed\tdiam\n-----------------------------------------------\n");
    fprintf(ptr,"\tV\t\tE\tgmin\tgmax\tgmed\tdiam\n-----------------------------------------------\n");


    for (int i = ini; i <= fim; i += stp) {//determina n de vértices
        int contArestas = 0;
        struct cel *v  = (struct cel *)calloc(i, sizeof(struct cel));

        //contrói a matriz de adjacências

        for (int j = 0; j < i; j++) {//para cada vértice
            v[j].arestas = (int *)calloc(i, sizeof(int));//aloca uma "lista de adjacências"

            for (int k = 0; k <= j; k++) {//para cada elemento da lista de adjacência determina se "há ligação ou não"
                if (j != k) {
                    if (lancamentoMoedaTendenciosa(p)) {
                        v[j].arestas[k] = 1;
                        v[k].arestas[j] = 1;
                        contArestas++;
                    } else {
                        v[j].arestas[k] = 0;
                    }
                }
            }
        }

        //se desejar visualizar como ficou a matriz de adjacências, descomente o bloco seguinte

        // printf("\nMatriz de adjacência:\n");
        // for (int j = 0; j < i; j++) {
        //     for (int k = 0; k < i; k++) {
        //         printf("%d ", v[j].arestas[k]);
        //     }
        //     printf("\n");
        // }


        //cálculo do diâmetro com BFS

        int diametro = 0;
        // Executa BFS para cada vértice e encontra as distâncias
        for(int o = 0; o < i; o++){//para cada vértice
            BFS(v, i, o);//executa BFS
            for(int p = 0; p < i; p++){//para cada distância atualizada pelo BFS em relação ao vértice vigente
                if(v[p].d > diametro)//se a distância for a maior
                    diametro = v[p].d;//atualiza
            }

            // Se quiser visualizar as informações após BFS para cada vértice, descomente o seguinte bloco

            // printf("\nInformações após BFS no vértice --%d--:\n", o);
            // for (int j = 0; j < i; j++) {
            //     printf("Vertice %d: Cor %d, Distancia %d, Pai %d\n", j, v[j].cor, v[j].d, v[j].pi);
            // }
        }

        //cálculo do parâmetros solicitados (maior, menor e média)

        int maior, menor;
        double media = 0.0;
        int grau = 0;
        
        for(int m = 0; m < i; m++){//para cada vértice
            grau = 0;

            for(int n = 0; n < i; n++){//percorro a matriz de adjacência em linha e coluna
                if(v[m].arestas[n])//percorrendo linhas
                    grau++;
                if(v[n].arestas[m])//percorrendo colunas
                    grau++;
            }
            grau = grau/2;//como olhei linha e coluna inteira, e a matriz é espelhada, devo dividir para obter o valor real
            if(m == 0){//se for o primeiro vértice, pegamos os valores para ter uma refência para comparação
                maior = grau;
                menor = grau;
            }
            if(grau > maior)
                maior = grau;
            if(grau < menor)
                menor = grau; 
            media += grau;
        }

        media = media / i;


        printf("%d\t%d\t%d\t%d\t%.1lf\t%d\n", i, contArestas, menor, maior, media, diametro);
        fprintf(ptr,"%4d\t%4d\t%4d\t%4d\t%3.2lf\t%4d\n", i, contArestas, menor, maior, media, diametro);


        //liberação de memória

        // Libera a memória alocada para as arestas
        for(int j = 0; j < i; j++) {
            free(v[j].arestas);
        }
        // Libera a memória alocada para os vértices
        free(v);

    }
    fclose(ptr);
    return 0;
}
