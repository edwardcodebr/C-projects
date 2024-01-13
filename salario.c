#include <stdio.h>
int main()
{
    int sal, total;
    printf("write your salary\n");
    scanf("%d", &sal);
    total = sal + (sal * 0.2);
    printf("your salary is %d\n", total);
    system("PAUSE");
    return 0;
}