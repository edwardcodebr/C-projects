#include <stdio.h>

int eh_bissexto( int year )
{
    if ( ( year % 400 == 0) || ( year % 4 == 0 && year % 100 != 0))
    {
        return 1;
    } else
    {
        return 0;
    }
}

int days_of_mounth ( int mounth, int year )
{
    switch (mounth)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return eh_bissexto(year) ? 29 : 28;
    
    default:
        return 0;
    }
}

int date_days( int day, int mounth, int year )
{
    int total_days = 0;

    for ( int i = 0; i < year; i++ )
    {
        total_days += eh_bissexto(i) ? 366 : 365;
    }

    for ( int i = 1 ; i < mounth ; i++ )
    {
        total_days += days_of_mounth(i, year);
    }
    
    total_days += day;

    return total_days;
}

int main()
{
    int day1, mounth1, year1;
    int day2, mounth2, year2;

    printf("write the first data (dd/mm/yyyy):");
    scanf("%d/%d/%d", &day1, &mounth1, &year1);

    printf("write the second data (dd/mm/yyyy):");
    scanf("%d/%d/%d", &day2, &mounth2, &year2);

    int total_days1 = date_days(day1, mounth1, year1);
    int total_days2 = date_days(day2, mounth2, year2);

    int diferent = total_days2 - total_days1;

    printf("The diference with dates is: %d days\n", diferent);

    return 0;
}