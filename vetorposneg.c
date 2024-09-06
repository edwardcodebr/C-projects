#include <stdio.h>

int main(){
    int vetor[8], pos[8], neg[8];
    int i, pos_count = 0, neg_count = 0;

    printf("write 8 numbers integers:\n");
    for (i = 0; i < 8 ; i ++){
        printf("Number %d", i + 1);
        scanf("%d", &vetor[i]);

        if (vetor[i] >= 0){
            pos[pos_count] = vetor[i];
            pos_count++;
        }else{
            neg[neg_count] = vetor[i];
            neg_count++;
        }
    }

    printf("\nVector positives:\n");
    for (i = 0 ; i < pos_count ; i++){
        printf("%d\n", pos[i]);
    }
    
    printf("\nVector negative:\n");
    for (i = 0 ; i < neg_count ; i++){
        printf("%d\n", neg[i]);
    }
    
    return 0;
}