#include <stdio.h>

int main(){
    int vetora[10], vetorb[10], vetorinter[20];
    int i, j = 0;
    printf("write 10 numbers for prime vector:\n");
    for (i = 0 ; i < 10 ; i ++){
        printf("Element %d:", i + 1);
        scanf("%d", &vetora[i]);
    }

    printf("write 10 numbers for second vector:\n");
    for(i = 0 ; i < 10 ; i++){
        printf("Element %d:", i + 1);
        scanf("%d", &vetorb[i]);
    }

    for (i = 0; i < 10 ; i++){
        vetorinter[j++] = vetora[i];
        vetorinter[j++] = vetorb[i];
    }

    printf("\nThe vector result of intercalation.\n");
    for (i = 0 ; i < 20 ; i++){
        printf("%d", vetorinter[i]);
    }
    printf("\n");
    return 0;
}