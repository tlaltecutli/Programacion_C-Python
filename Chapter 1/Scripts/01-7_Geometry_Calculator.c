#include <stdio.h>
#include <math.h>

#define PI 3.14159

// Function prototypes
void calculateCircle(void);
void calculateRectangle(void);
void calculateTriangle(void);

int main(void) {
    int choice;
    
    do {
        printf("\nGeometry Calculator\n");
        printf("1. Circle\n");
        printf("2. Rectangle\n");
        printf("3. Triangle\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: calculateCircle(); break;
            case 2: calculateRectangle(); break;
            case 3: calculateTriangle(); break;
            case 4: printf("Goodbye!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void calculateCircle(void) {
    float radius, area, perimeter;
    
    printf("Enter radius: ");
    scanf("%f", &radius);
    
    area = PI * radius * radius;
    perimeter = 2 * PI * radius;
    
    printf("Circle Area: %.2f\n", area);
    printf("Circle Perimeter: %.2f\n", perimeter);
}

void calculateRectangle(void) {
    float length, width, area, perimeter;
    
    printf("Enter length: ");
    scanf("%f", &length);
    printf("Enter width: ");
    scanf("%f", &width);
    
    area = length * width;
    perimeter = 2 * (length + width);
    
    printf("Rectangle Area: %.2f\n", area);
    printf("Rectangle Perimeter: %.2f\n", perimeter);
}

void calculateTriangle(void) {
    float base, height, side1, side2, area, perimeter;
    
    printf("Enter base: ");
    scanf("%f", &base);
    printf("Enter height: ");
    scanf("%f", &height);
    printf("Enter side 1: ");
    scanf("%f", &side1);
    printf("Enter side 2: ");
    scanf("%f", &side2);
    
    area = 0.5 * base * height;
    perimeter = base + side1 + side2;
    
    printf("Triangle Area: %.2f\n", area);
    printf("Triangle Perimeter: %.2f\n", perimeter);
}