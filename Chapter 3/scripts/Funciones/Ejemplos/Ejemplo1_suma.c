/*
Ejemplo 1 - Función para sumar dos números usando C 
*/

#include <stdio.h>

// Declaración de función (prototipo)
int sumar(int a, int b);

int main() {
    int resultado = sumar(5, 3);
    printf("La suma es: %d\n", resultado);
    return 0;
}

// Definición de función
int sumar(int a, int b) {
    return a + b;
}