#include <stdio.h>
int main ()
{
    int not1, not2, not3, media;
    printf("Digite a primeira nota.\n");
    scanf("%d", &not1);
    printf("Digite a segunda nota.\n");
    scanf("%d", &not2);
    printf("Digite a ultima nota.\n");
    scanf("%d", &not3);
    media = (not1 + not2 + not3)/3;
    if (media > 6 && media <= 10)
    {
        printf("aprovado.\n");
    } 
    else{
        printf("reprovado");
    }
    return 0;
}