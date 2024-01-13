#include <stdio.h>
int main()
{
    int x, y, z;
    printf("write three numbers for what is biggest number\n");
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);
    if(x > y && x > z)
    {
        printf("%d is biggest\n", &x);
    }
    else
    {
        if(y > x && y > z)
        {
            printf("%d is biggest\n", y);
        }
        else
        {
            if(z > x && z> y)
            {
                printf("%d is biggest", z);
            }
        }
    }

    system("PAUSE");
    return 0;
}