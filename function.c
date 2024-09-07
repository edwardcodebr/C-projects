#include <stdio.h>
#define TAM 10

void vector_insert(int vector[]){
    for (int i = 0 ; i < TAM ; i++){
        printf("write the %dº number integer:", i+1);
        scanf("%d", &vector[i]);
    }

}

int uniao(int X[], int Y[], int union_res[]){
    int i,j,k = 0, existe;
    for (i = 0 ; i < TAM ; i++){
        union_res[k++] = X[i];
    }

    for (i = 0 ; i < TAM ; i++){
        existe = 0;
        for (j = 0 ; j < TAM ; j++){
            if (Y[i] == X[j]){
                existe = 1;
                break;
            }

        }
        if (!existe){
            union_res[k++] = Y[i];
        }

    }

    return k;
}

int diferent( int X[], int Y[], int dif_res[]){
    int i,j,k=0,existe;
    for (i = 0; i < TAM ; i++){
        existe = 0;
        for (j = 0 ; j <TAM ; j++){
            if (X[i] == Y[j]){
                existe = 1;
                break;
            }

        }
        if (!existe){
            dif_res[k++] = X[i];
        }

    }

    return k;
}

int intersection(int X[], int Y[], int inter_res[]){
    int i,j,k=0;
    for (i = 0 ; i < TAM; i++)
    {
        for (j = 0 ; j < TAM ; j++)
        {
            if (X[i] == Y[j])
            {
                inter_res[k++] = X[i];
                break;
            }
            
        }
        
    }
    
    return k;
}

int main(){
    int X[TAM], Y[TAM], union_res[2*TAM], dif_res[TAM], soma[TAM], produto[TAM], inter_res[TAM];
    int tamanho_union, tamanho_dif, tamanho_inter;
    
    printf("insert in the vector X:\n");
    vector_insert(X);
    printf("insert in the vector Y:\n");
    vector_insert(Y);

    tamanho_union = uniao(X,Y,union_res);

    tamanho_dif = diferent(X, Y, dif_res);

    for (int i = 0 ; i < TAM ; i++){
        soma[i] = X[i] + Y[i];
    }

    for (int i = 0; i < TAM; i++)
    {
        produto[i] = X[i]* Y[i];
    }

    tamanho_inter = intersection(X,Y, inter_res);
    
    printf("\nResults\n");
    
    printf("a) Union of X with Y:");
    for (int i = 0; i < tamanho_union; i++)
    {
        printf("%d", union_res[i]);
    }
    printf("\n");

    printf("b) Diferent with X and Y:");
    for (int i = 0; i < tamanho_dif; i++)
    {
        printf("%d", dif_res[i]);
    }
    printf("\n");

    printf("c) the sum in the X and Y:");
    for (int i = 0; i < TAM; i++)
    {
        printf("%d", soma[i]);
    }
    printf("\n");

    printf("d) product of the X and Y:");
    for (int i = 0; i < TAM; i++)
    {
        printf("%d", produto[i]);
    }
    printf("\n");
    
    printf("e) intersection with X and Y:");
    for (int i = 0; i < tamanho_inter; i++)
    {
        printf("%d", inter_res[i]);
    }
    printf("\n");

    return 0;
}