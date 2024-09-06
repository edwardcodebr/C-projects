#include <stdio.h>
#include <stdbool.h>

// Função para verificar se um número é primo
bool ehPrimo(int num) {
    if (num <= 1) return false; // Números menores ou iguais a 1 não são primos
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false; // Se o número for divisível por i, não é primo
    }
    return true;
}

int main() {
    int vetor[9];
    int i;

    // Entrada de números no vetor
    printf("Write 9 numbers integers:\n");
    for (i = 0; i < 9; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Verificar e exibir números primos e suas posições
    printf("\nNumber primos and your positions:\n");
    for (i = 0; i < 9; i++) {
        if (ehPrimo(vetor[i])) {
            printf("Number primo: %d na posição: %d\n", vetor[i], i);
        }
    }

    return 0;
}
