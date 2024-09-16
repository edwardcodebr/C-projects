#include <stdio.h>

#define NUM_QUESTOES 8
#define NUM_ALUNOS 10
#define NOTA_MINIMA 6

int calcularnota(char gabarito[ ], char respostas[ ]){
    int nota = 0;
    for ( int i = 0 ; i < NUM_QUESTOES ; i++)
    {
        if (gabarito [ i ] == respostas [ i ] )
        {
            nota++;
        }
        
    }
    return nota;
}

float calcularaprovacao( int notas [ ] )
{
    int alunosaprovados = 0;
    for ( int i = 0 ; i < NUM_ALUNOS ; i++)
    {
        if ( notas [ i ] >= NOTA_MINIMA )
        {
            alunosaprovados++;
        }
        
    }
    return ((float) alunosaprovados / NUM_ALUNOS) * 100; 
}

int main()
{
    char gabarito[NUM_QUESTOES] = {'A','B','C','D','E','A','B','C'};
    char respostas[NUM_ALUNOS] [NUM_QUESTOES] = { {'A','B','C','D','E','A','B','C'} , {'A','B','C','D','E','A','B','C'} , {'A','B','C','D','E','A','B','C'} , {'A','B','C','D','E','A','B','C'} , {'A','B','C','D','E','A','B','C'} , {'A','B','C','D','E','A','B','C'} , {'A','B','C','D','E','A','B','C'} , {'A','B','C','D','E','A','B','C'} , {'A','B','C','D','E','A','B','C'} , {'A','B','C','D','E','A','B','C'}};
    int notas[NUM_ALUNOS];

    printf("notes of students\n");
    for ( int i = 0 ; i < NUM_ALUNOS ; i++)
    {
        notas[ i ] = calcularnota ( gabarito, respostas [ i ]);
        printf("Student %d: %d point(s).\n", i + 1, notas[i]);
    }

    float porcetagemaprovacao = calcularaprovacao(notas);
    printf("Porcetage aproved: %.2f%%\n", porcetagemaprovacao);
    return 0;
}