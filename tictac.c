#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char tabuleiro[3][3];
char player = 'X';

void iniciar()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            tabuleiro[i][j] = ' ';
        }
    }
}

void displaytabuleiro()
{
    printf("\n");
    printf("%c | %c | %c\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("---|---|---\n");
    printf("%c | %c | %c\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("---|---|---\n");
    printf("%c | %c | %c\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf("\n");
}

int ganhou()
{
    int i;

    // Verificar linhas e colunas
    for (i = 0; i < 3; i++)
    {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
            return 1;
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ')
            return 1;
    }

    // Verificar diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ')
        return 1;
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
        return 1;

    return 0;
}

int cheio()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (tabuleiro[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

void chooseplayer()
{
    player = (player == 'X') ? 'O' : 'X';
}

void movimentojogador()
{
    int lin, col;
    do
    {
        printf("Jogador %c, escolha linha (1-3) e coluna (1-3)\n", player);
        printf("Linha: ");
        scanf("%d", &lin);
        lin--;
        printf("Coluna: ");
        scanf("%d", &col);
        col--;
    } while (lin < 0 || lin >= 3 || col < 0 || col >= 3 || tabuleiro[lin][col] != ' ');
    tabuleiro[lin][col] = player;
}

void computador()
{
    int lin, col;
    srand(time(0));
    do
    {
        lin = rand() % 3;
        col = rand() % 3;
    } while (tabuleiro[lin][col] != ' ');

    printf("NPC jogou em: linha %d, coluna %d\n", lin + 1, col + 1);
    tabuleiro[lin][col] = player;
}

int main()
{
    int venceu = 0;

    iniciar();

    while (!venceu && !cheio())
    {
        displaytabuleiro();

        if (player == 'X')
        {
            movimentojogador();
        }
        else
        {
            computador();
        }

        venceu = ganhou();
        if (!venceu)
        {
            chooseplayer();
        }
    }

    displaytabuleiro();

    if (venceu)
    {
        printf("Jogador %c venceu!\n", player);
    }
    else
    {
        printf("Empate!\n");
    }

    return 0;
}
