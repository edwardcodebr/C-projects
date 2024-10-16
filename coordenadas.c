#include <stdio.h>

int found_coordinates(int A[], int size, int X)
{
    for ( int i = 0 ; i < size ; i++ )
    {
        if ( A[i] == X )
        {
            return i;
        }
    
    }
    return -1;
}

int main()
{
    int A[5] = {10,20,30,40,50};
    int X = 30;
    int position = found_coordinates(A,5,X);
    printf("Coordenate's X: %d\n", position);
    return 0;
}