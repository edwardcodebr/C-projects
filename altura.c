#include <stdio.h>

void processaltura() 
{
    float altura [ 5 ];
    float soma = 0, media;
    int b_media = 0, up_media = 0, mediano = 0;
    for ( int i = 0 ; i < 5 ; i++)
    {
        printf("write the height's woman %d:\n", i + 1);
        scanf("%f", &altura [ i ]);
        soma += altura [ i ];
    }

    media = soma / 5;

    for ( int i = 0 ; i < 5 ; i++)
    {
        if ( altura [ i ] < media){
        b_media++;
        }else
        if ( altura [ i ] > media){
            up_media++;
        }else{
            mediano++;
        }
    }

    printf("numbers of woman minor height %d\n", b_media);
    printf("numbers of woman biggest height %d\n", up_media);
    printf("numbers of woman in medium height %d\n", mediano);
}

int main()
{
    processaltura();
    return 0;
}