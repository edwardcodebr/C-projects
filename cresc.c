#include <stdio.h>
#define TAMANHO 10

void orden(int vector[], int size){
    int i, j, temp;
    for (i = 0 ; i < size - 1 ; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
            
        }
        
    }
}

int main(){
    int numbers[TAMANHO];
    int i;

    printf("Write 10 numbers integers:\n");
    for(i = 0 ; i < TAMANHO ; i++)
    {
        scanf("%d", &numbers[i]);
    }

    orden(numbers, TAMANHO);

    printf("vector ordened:\n");
    for (i = 0; i < TAMANHO; i++)
    {
        printf("%d", numbers[i]);
    }
    
    return 0;
}