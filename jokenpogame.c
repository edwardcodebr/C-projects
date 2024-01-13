/*Carlos Eduardo Correa Queiroz, Josue Henrique e Thiago Cordeiro.*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    int resp, rep, obj1, obj2, score1 = 0, score2 = 0, rock = 1, paper = 2, scissor = 3;
    while (1)
    {
    printf("game created by: Carlos Eduardo, Josue henrique and Thiago cordeiro\n");
    printf("Welcome to jo, ken, po!\n");
    printf("menu\n");
    printf("\n1 - play\n2 - exit\n3 - ranking\n");
    scanf("%d", &resp);
    switch (resp)
    {
    case 2:
    {
        printf("closing\n");
        exit(0); /*exit menu*/
    }
    case 3:
    {
        printf("ranking\n");
        printf("%d points to player 1\n", score1);
        printf("%d points to player 2\n", score2);
        printf("\n");
        continue;
    }
    }
    while (1)
    {
        printf("1 - rock\n2 - paper\n3 - scissor\n");
        printf("player 1 turn\n");
        scanf("%d", &obj1);
        printf("player 2 turn\n");
        scanf("%d", &obj2);
        if (obj1 == rock && obj2 == paper/* condition */)
        {
            printf("player 2 win\n");/* code */
            score2++; 
        }
        if (obj1 == scissor && obj2 == rock/* condition */)
        {
            printf("player 2 win\n");/* code */
            score2++;
        }
        if (obj1 == paper && obj2 == scissor/* condition */)
        {
            printf("player 2 win\n");/* code */
            score2++;
        }
        if (obj2 == rock && obj1 == paper/* condition */)
        {
            printf("player 1 win\n");/* code */
            score1++;
        }
        if (obj2 == scissor && obj1 == rock/* condition */)
        {
            printf("player 1 win\n");/* code */
            score1++;
        }
        if (obj2 == paper && obj1 == scissor/* condition */)
        {
            printf("player 1 win\n");/* code */
            score1++;
        }
        if (obj1 == rock && obj2 == rock/* condition */)
        {
            printf("draw\n");/* code */
        }
        if (obj1 == paper && obj2 == paper/* condition */)
        {
            printf("draw\n");/* code */
        }
        if (obj1 == scissor && obj2 == scissor/* condition */)
        {
            printf("draw\n");/* code */
        }
        printf("player 1: %d\n", score1); 
        printf("player 2: %d\n", score2);/*score's players*/
        printf("\n\n");/*espace*/        
        printf("do you need stop?(1 for yes/2 for continue)\n");
        scanf("%d", &rep);
        if (rep == 1/*condition*/)
        {
            printf("thank you for playing with us.\n");/* code */
            printf("created by: Carlos Eduardo, Josue Henrique and Thiago Cordeiro\n");
            exit(0);
        }
        else{
        continue; /*continue playing with data save*/
        }
        
    }
    }
system("PAUSE");
return 0;
}