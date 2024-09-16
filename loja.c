#include <stdio.h>

#define TAMANHO 10

int main(){
    float precos[TAMANHO], v_total, v_geral = 0, comissao;
    int quants[TAMANHO], mais_vendido = 0, posicao_mais_vendido = 0;
    for (int i = 0 ; i < TAMANHO ; i++){
        printf("write the valour of objects %d: R$", i+1);
        scanf("%f", &precos[i]);

        printf("write the quantities solds of object %d:", i+1);
        scanf("%d", &quants[i]);
    }

    printf("\nRelatory of solds\n");
    printf("Object\tQuantities\tUnitary valour\tTotal valour");

    for(int i = 0 ; i < TAMANHO; i++){
        v_total = precos[i] * quants[i];
        printf("%d\t%d\t\tR$ %.2f\t\tR$ %.2f\n", i+1, quants[i], precos[i], v_total);
        v_geral += v_total;

        if (quants[i] > mais_vendido){
            mais_vendido = quants[i];
            posicao_mais_vendido = i;
        }
    }
    comissao = v_geral * 0.05;

    printf("\ngeneral valour of solds: R$%.2f\n", v_geral);
    printf("commission: R$%.2f\n", comissao);

    printf("most solded object: %d with %d unitities (position in vetor: %d)\n", posicao_mais_vendido +1, mais_vendido, posicao_mais_vendido + 1);
    return 0;
}