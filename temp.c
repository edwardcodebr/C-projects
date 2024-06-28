#include <stdio.h>

typedef struct {
    float fahrenheit;
    float celsius;
} temp;

void conversaofah(temp *tempef) {
    tempef->fahrenheit = (tempef->celsius * 9.0 / 5.0) + 32.0;
}

void conversaocel(temp *tempef) {
    tempef->celsius = (tempef->fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    temp temperature;
    int choice;
    
    printf("Welcome to the temperature converter\nPlease, enter the function:\n1 - Enter Celsius\n2 - Enter Fahrenheit\n");
    scanf("%d", &choice);
    
    switch (choice) {
    case 1:
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature.celsius);
        conversaofah(&temperature);
        printf("Temperature in Fahrenheit: %.2f\n", temperature.fahrenheit);
        break;
    
    case 2:
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature.fahrenheit);
        conversaocel(&temperature);
        printf("Temperature in Celsius: %.2f\n", temperature.celsius);
        break;
    
    default:
        printf("Invalid choice\n");
        break;
    }

    return 0;
}