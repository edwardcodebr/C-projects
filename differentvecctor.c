#include <stdio.h>

int comparevector ( int A[], int B[], int size )
{
    for ( int i = 0 ; i < size ; i++){
        if (A[i] != B[i])
        {
            return 0;
        }
        
    }

    return 1;
}

int main()
{
    int A[5] = {1,2,3,4,5};
    int B[5] = {1,2,3,4,5};

    int result = comparevector(A,B,5);

    if ( result == 1)
    {
        printf("equals.\n");
    }else
    {
        printf("different\n");
    }
    
    return 0;
}