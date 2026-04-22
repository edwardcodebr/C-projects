#include <stdlib.h>
#include <time.h>
#include "utils.h"

void gerar_vetor(unsigned int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 65536;
    }
}

void copiar_vetor(unsigned int origem[], unsigned int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}
