#include <stdio.h>

int calc_duration(int hinicio, int hfim, int minicio, int mfim)
{
    int minutos_in = hinicio * 60 + minicio;
    int minutos_fim = hfim * 60 + mfim;
    
    if(minutos_fim < minutos_in)
    {
        int duracao = minutos_fim - minutos_in;
        return duracao;
    }
}

int main()
{
    int hinicio, hfim, minicio, mfim;

    printf("write the begin hour (hh mm):\n");
    scanf("%d %d", &hinicio, &minicio);
    printf("write the end hour (hh mm):\n");
    scanf("%d %d", &hfim, &mfim);

    int duracao = calc_duration(hinicio, minicio, hfim, mfim);
    printf("the duration of game is: %d minutes\n", duracao);
    return 0;
}