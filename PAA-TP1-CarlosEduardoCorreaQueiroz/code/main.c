#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "sorts.h"
#include "utils.h"

#define REP 50

double medir_merge(unsigned int arr[], int n) {
    clock_t inicio = clock();
    mergeSort(arr, 0, n-1);
    return (double)(clock() - inicio) / CLOCKS_PER_SEC;
}

double medir_heap(unsigned int arr[], int n) {
    clock_t inicio = clock();
    heapSort(arr, n);
    return (double)(clock() - inicio) / CLOCKS_PER_SEC;
}

double medir_quick(unsigned int arr[], int n) {
    clock_t inicio = clock();
    quickSort(arr, 0, n-1);
    return (double)(clock() - inicio) / CLOCKS_PER_SEC;
}

double calcular_desvio(double tempos[], double media) {
    double soma = 0;
    for (int i = 0; i < REP; i++) {
        soma += pow(tempos[i] - media, 2);
    }
    return sqrt(soma / REP);
}

int main() {
    srand(time(NULL));

    int tamanhos[] = {10000, 100000, 1000000};
    int num = 3;

    FILE *f = fopen("resultados.csv", "w");
    fprintf(f, "N,Merge,Merge_DP,Heap,Heap_DP,Quick,Quick_DP\n");

    for (int t = 0; t < num; t++) {
        int n = tamanhos[t];

        unsigned int *base = malloc(n * sizeof(unsigned int));
        unsigned int *copia = malloc(n * sizeof(unsigned int));

        double temposM[REP], temposH[REP], temposQ[REP];

        for (int i = 0; i < REP; i++) {
            gerar_vetor(base, n);

            copiar_vetor(base, copia, n);
            temposM[i] = medir_merge(copia, n);

            copiar_vetor(base, copia, n);
            temposH[i] = medir_heap(copia, n);

            copiar_vetor(base, copia, n);
            temposQ[i] = medir_quick(copia, n);
        }

        double mediaM=0, mediaH=0, mediaQ=0;

        for (int i = 0; i < REP; i++) {
            mediaM += temposM[i];
            mediaH += temposH[i];
            mediaQ += temposQ[i];
        }

        mediaM /= REP;
        mediaH /= REP;
        mediaQ /= REP;

        double dpM = calcular_desvio(temposM, mediaM);
        double dpH = calcular_desvio(temposH, mediaH);
        double dpQ = calcular_desvio(temposQ, mediaQ);

        fprintf(f, "%d,%f,%f,%f,%f,%f,%f\n",
                n, mediaM, dpM, mediaH, dpH, mediaQ, dpQ);

        free(base);
        free(copia);
    }

    fclose(f);
    return 0;
}
