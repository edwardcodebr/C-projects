#include <stdio.h>
#include <stdlib.h>

int a, b, c;
void cadastro();
void saida();

int main()
{


void cadastro();
    printf("digite o lado a de um triangulo\n");
    scanf("%d", &a);
    printf("digite o lado b de um triangulo\n");
    scanf("%d", &b);
    printf("digite o lado c de um triangulo\n");
    scanf("%d", &c);


void saida();
        if(a == b && a == c && b == c)
        {
            printf("iguais\n");
        }
        if(a == b || a == c || b == c)
        {
            printf("dois lados iguais\n");
        }
        if(a != b && a != c && b != c)
        {
            printf("lados diferentes\n");
        }
}

