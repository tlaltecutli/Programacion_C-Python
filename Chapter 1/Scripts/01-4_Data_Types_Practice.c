#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    // Declaring and initializing variables of different data types
    int integer = 42;
    float floating = 3.14159f;
    double doubleNum = 3.14159265359;
    char character = 'A';

    // Printing values
    printf("Values:\n");
    printf("Integer: %d\n", integer);
    printf("Float: %f\n", floating);
    printf("Double: %lf\n", doubleNum);
    printf("Character: %c\n\n", character);

    // Printing sizes of each data type
    printf("Sizes in bytes:\n");
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of char: %zu bytes\n\n", sizeof(char));

    // Printing ranges of each data type
    printf("Ranges:\n");
    printf("Int range: %d to %d\n", INT_MIN, INT_MAX);
    printf("Float range: %e to %e\n", FLT_MIN, FLT_MAX);
    printf("Double range: %e to %e\n", DBL_MIN, DBL_MAX);
    printf("Char range: %d to %d\n", CHAR_MIN, CHAR_MAX);

    return 0;
}