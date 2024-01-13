#include <stdio.h>
#include <math.h>
int main()
{
    int x, y, calc, soma, soma2, resp;
    while(1)
    {
    printf("digite um numero\n");
    scanf("%d", &x);
    printf("digite outro numero\n");
    scanf("%d", &y);
    printf("digite um numero para operacao\n");
    printf("1 - soma\n");
    printf("2 - subtracao\n");
    printf("3 - multiplicacao\n");
    printf("4 - divisao\n");
    printf("5 - potenciacao\n");
    printf("6 - raiz\n");
    scanf("%d", &calc);
    switch(calc)
    {
        case 1:
        soma = x + y;
        printf("%d + %d = %d\n", x, y, soma);
        break;
        case 2:
        soma = x - y;
        printf("%d - %d = %d\n", x, y, soma);
        break;
        case 3:
        soma = x * y;
        printf("%d X %d = %d\n", x, y, soma);
        break;
        case 4:
        soma = x / y;
        printf("%d / %d = %d\n", x, y, soma);
        break;
        case 5:
        soma = pow(x,y);
        printf("%d^%d = %d\n", x, y, soma);
        break;
        case 6:
        soma = sqrt(x);
        soma2 = sqrt(y);
        printf("raiz de %d = %d\n", x, soma);
        printf("raiz de %d = %d\n", y, soma2);
    }
    printf("deseja continuar?\n");
    printf("1 para sim, 2 para nao\n");
    scanf("%d", &resp);
    if(resp == 2)
    {
        printf("desligando\n");
        break;
    }
    }
    system("PAUSE");
    return 0;
}