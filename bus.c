#include <stdio.h>

#define TOTAL_POLTRONAS 24

void mapper( int janela [ ] , int corredor [ ] )
{
    printf("Map's ocupation of bus:\n");
    printf("\nWindows:\n");
    
    for ( int i = 0 ; i < TOTAL_POLTRONAS ; i++ )
    {
        printf("%d - %s\n" , i + 1 , janela [ i ] == 0 ? "Safe" : "Ocupied");
    }

    printf("\nCorridor\n");
    for ( int i = 0 ; i < TOTAL_POLTRONAS ; i++ )
    {
        printf("%d - %s\n" , i + 1 , corredor [ i ] == 0 ? "Safe" : "Ocupied");
    }
}

int lotbus ( int janela [ ] , int corredor [ ] )
{
    for ( int i = 0 ; i < TOTAL_POLTRONAS ; i++ )
        {
        if ( janela [ i ] == 0 || corredor [ i ] == 0)
        {
            return 0;
        }
            
    }
    return 1;
}

void send_ticket (int janela [ ] , int corredor [ ] )
{
    if ( lotbus ( janela , corredor ) )
    {
        printf("LOTTED\n");
        return;
    }
    
    int choose , poltrona;
    printf("Do you want choose in windows(1) or corridor(2)?");
    scanf("%d", &choose);

    if ( choose != 1 && choose != 2 )
    {
        printf("invalid choose\n");
        return;
    }

    printf("Write the assent number ( 1 to 24 ):\n");
    scanf("%d", &poltrona);

    if ( poltrona < 1 || poltrona > TOTAL_POLTRONAS )
    {
        printf("Number invalid\n");
        return;
    }
    
    if ( choose == 1 ) {
        if ( janela [ poltrona - 1 ] == 0)
        {
            janela [ poltrona - 1 ] = 1;
            printf("excelent\n");
        }else
        {
            printf("ocuppied\n");
        }
    } else
    {
        if (corredor [ poltrona - 1 ] == 0)
        {
            corredor [ poltrona - 1] = 1;
            printf("excelent");
        }else
        {
            printf("ocuppied\n");
        }
        
    }

}

int main()
{
    int janela [ TOTAL_POLTRONAS ] = {0};
    int corredor[ TOTAL_POLTRONAS ] = {0};
    int choose;
    while (1)
    {
        printf("\nMENU\n1 - send ticket.\n2 - MAP of bus occupied.\n3 - Close\nchoose the option\n");
        scanf("%d", &choose);
        
        switch (choose)
        {
        case 1:
            send_ticket(janela,corredor);
            break;
        case 2:
            mapper(janela,corredor);
            break;
        case 3:
            printf("bye :)\n");
            return 0;
        default:
            printf("invalid\n");
            break;
        }
        
    }
    return 0;
}