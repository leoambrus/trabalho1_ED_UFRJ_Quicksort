#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define capacidade_inicial 500

// Função de particionamento
int particiona(int V[], int inicio, int fim) {
    int numppivot;
    int ppivot;
    int pivot;
    int i, j, temp;

    // Gere um índice aleatório
    numppivot = rand() % (fim - inicio + 1) + inicio;

    // Pegue o valor do índice aleatório do vetor
    ppivot = numppivot;
    pivot = V[ppivot];
    V[numppivot] = V[inicio];
    V[inicio] = pivot;
    i = inicio;
    j = fim + 1; // Corrigindo o j para fim + 1

    while (1) {
        do {
            i++;
        } while (V[i] < pivot && i <= fim);

        do {
            j--;
        } while (V[j] > pivot);

        if (i < j) {
            temp = V[i];
            V[i] = V[j];
            V[j] = temp;
        } else {
            break;
        }
    }

    V[inicio] = V[j];
    V[j] = pivot;
    return j;
}

// Função QuickSort
void quicksort(int V[], int inicio, int fim) {
    // Gera números aleatórios
    srand(time(NULL));

    if (inicio < fim) {
        int pos = particiona(V, inicio, fim);
        quicksort(V, inicio, pos - 1);
        quicksort(V, pos + 1, fim);
    }
}


int main() {
    int *V = NULL;  // Inicialmente, o vetor está vazio
    int tamanho = 0;    // Tamanho atual do vetor
    int capacidade = capacidade_inicial;
    int numero;
    int i = 0;
    //para rodar no site do claudson tem que tirar os printf desnecessários como digite os numeros e vetor ordenado

    printf("Digite numeros (Ctrl+Z para encerrar):\n");

    V = (int *)malloc(capacidade * sizeof(int));
    if (V == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    while (scanf("%d", &numero) != EOF) {
        // Se o tamanho do vetor for maior que a capacidade eu dobro o tamanho do mesmo
        if (tamanho == capacidade) {
            capacidade *= 2;
            V = (int *)realloc(V, capacidade * sizeof(int));
        }


        // Armazenar o número no vetor
        V[tamanho] = numero;
        tamanho++;
    }

    // Ordenar o vetor com o QuickSort
    quicksort(V, 0, tamanho - 1);

    printf("Vetor Ordenado:\n");
    for (i ; i < tamanho; i++) {
        printf("%d\n", V[i]);
    }

    // Liberar a memória alocada
    free(V);

    return 0;
}
