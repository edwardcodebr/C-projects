#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100
#define NUM_ALUNOS 25  // Número total de alunos por turma

// Estrutura para armazenar os dados do aluno
typedef struct {
    int matricula;
    float av1, av2, av3;
} Aluno;

// Função para calcular a média ponderada de três notas
float calcular_media(float av1, float av2, float av3, int peso1, int peso2, int peso3) {
    return (av1 * peso1 + av2 * peso2 + av3 * peso3) / (peso1 + peso2 + peso3);
}

int main() {
    FILE *saida = fopen("resultado.txt", "w");
    if (!saida) {
        perror("Erro ao criar o arquivo de resultado");
        return 1;
    }

    // Dados simulados de alunos, com matrícula e notas (av1, av2, av3)
    Aluno alunos[NUM_ALUNOS] = {
        {20240121, 7.5, 8.0, 6.5}, {20240122, 6.0, 5.5, 7.0}, {20240123, 8.5, 9.0, 9.5},
        {20240124, 5.5, 6.0, 5.0}, {20240125, 7.0, 6.8, 7.2}, {20240126, 6.5, 6.0, 7.0},
        {20240127, 4.5, 5.0, 6.0}, {20240128, 7.8, 7.5, 8.0}, {20240129, 9.0, 8.5, 9.2},
        {20240130, 5.0, 5.5, 4.8}, {20240131, 6.3, 6.5, 7.0}, {20240132, 7.0, 6.7, 7.5},
        {20240133, 6.2, 6.8, 6.0}, {20240134, 5.8, 5.5, 5.9}, {20240135, 7.3, 7.0, 6.8},
        {20240136, 6.8, 7.2, 6.5}, {20240137, 8.0, 7.8, 8.2}, {20240138, 5.0, 5.2, 5.3},
        {20240139, 6.8, 7.0, 7.5}, {20240140, 7.5, 7.8, 7.9}, {20240141, 8.2, 8.0, 8.5},
        {20240142, 5.4, 5.0, 5.2}, {20240143, 6.5, 7.0, 6.3}, {20240144, 7.9, 8.0, 8.3},
        {20240145, 6.1, 6.3, 6.0}, {20240146, 8.7, 8.5, 8.8}
    };

    int peso1 = 3, peso2 = 3, peso3 = 4;  // Pesos das notas (AV1, AV2, AV3)
    float media_minima = 6.0;  // Média mínima para aprovação

    int alunos_aprovados = 0;
    float soma_medias = 0.0;
    float maior_media = 0.0;
    float menor_media = 10.0;

    // Processando os alunos
    for (int i = 0; i < NUM_ALUNOS; i++) {
        Aluno aluno = alunos[i];
        float media = calcular_media(aluno.av1, aluno.av2, aluno.av3, peso1, peso2, peso3);

        soma_medias += media;

        // Verifica a aprovação
        if (media >= media_minima) {
            alunos_aprovados++;
        }

        // Atualiza maior e menor média
        if (media > maior_media) maior_media = media;
        if (media < menor_media) menor_media = media;

        // Exibe os dados do aluno no arquivo de saída
        fprintf(saida, "Matrícula: %d, Média: %.2f, Notas: %.2f, %.2f, %.2f\n", aluno.matricula, media, aluno.av1, aluno.av2, aluno.av3);
    }

    // Calculando estatísticas da turma
    float media_turma = soma_medias / NUM_ALUNOS;
    float percentual_aprovacao = (float)alunos_aprovados / NUM_ALUNOS * 100;

    // Escreve as estatísticas no arquivo de saída
    fprintf(saida, "\nEstatísticas da turma\n");
    fprintf(saida, "Número de alunos: %d\n", NUM_ALUNOS);
    fprintf(saida, "Alunos aprovados: %d (%.2f%%)\n", alunos_aprovados, percentual_aprovacao);
    fprintf(saida, "Média da turma: %.2f\n", media_turma);
    fprintf(saida, "Maior média: %.2f\n", maior_media);
    fprintf(saida, "Menor média: %.2f\n", menor_media);

    fclose(saida);
    printf("Estatísticas geradas no arquivo resultado.txt\n");

    return 0;
}
