#include <stdio.h>

int main(void) {
    int choice;
    float temperature, converted;

    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        converted = (temperature * 9/5) + 32;
        printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, converted);
    }
    else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        converted = (temperature - 32) * 5/9;
        printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, converted);
    }
    else {
        printf("Invalid choice! Please select 1 or 2.\n");
    }

    return 0;
}