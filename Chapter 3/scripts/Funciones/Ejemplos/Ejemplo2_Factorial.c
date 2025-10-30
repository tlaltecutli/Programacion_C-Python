/*
Ejemplo 2 - Función para calcular el factorial de un número usando C

El factorial de un número n (denotado como n!) es el producto de todos los enteros positivos desde 1 hasta n.
Por ejemplo, 5! = 5 × 4 × 3 × 2 × 1 = 120.

*/
#include <stdio.h>
#include <time.h>

// Factorial recursivo
unsigned long long factorial_recursivo(int n) {
    // Validación de entrada para números negativos
    if (n < 0) {
        return 0; // Indicador de error
    }
    // Caso base
    if (n <= 1) {
        return 1;
    }
    // Caso recursivo
    return (unsigned long long)n * factorial_recursivo(n - 1);
}

// Factorial iterativo (para comparación)
unsigned long long factorial_iterativo(int n) {
    // Validación de entrada para números negativos
    if (n < 0) {
        return 0; // Indicador de error
    }
    
    unsigned long long resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    int numero = 50; // Aumentado para calcular un factorial más grande
                     // Nota: El factorial crece muy rápido. 20! es el máximo para unsigned long long.

    clock_t start, end;
    double cpu_time_used;

    // Validar que el número sea válido
    if (numero < 0) {
        printf("Error: No se puede calcular el factorial de un número negativo.\n");
        return 1;
    }
    
    if (numero > 20) {
        printf("Advertencia: El factorial de números mayores a 20 puede causar overflow.\n");
    }

    // --- Medir tiempo de la función recursiva ---
    printf("Calculando factorial(%d) con el método recursivo...\n", numero);
    start = clock();
    unsigned long long resultado_recursivo = factorial_recursivo(numero);
    end = clock();
    
    if (resultado_recursivo == 0 && numero < 0) {
        printf("Error en el cálculo recursivo.\n");
        return 1;
    }
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("El factorial de %d (recursivo) es: %llu\n", numero, resultado_recursivo);
    printf("Tiempo de ejecución (recursivo): %f segundos\n\n", cpu_time_used);

    // --- Medir tiempo de la función iterativa ---
    printf("Calculando factorial(%d) con el método iterativo...\n", numero);
    start = clock();
    unsigned long long resultado_iterativo = factorial_iterativo(numero);
    end = clock();
    
    if (resultado_iterativo == 0 && numero < 0) {
        printf("Error en el cálculo iterativo.\n");
        return 1;
    }
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("El factorial de %d (iterativo) es: %llu\n", numero, resultado_iterativo);
    printf("Tiempo de ejecución (iterativo): %f segundos\n", cpu_time_used);

    // Verificar que ambos resultados son iguales
    if (resultado_recursivo == resultado_iterativo) {
        printf("\n✓ Ambos métodos producen el mismo resultado.\n");
    } else {
        printf("\n✗ Los resultados difieren. Revisar implementación.\n");
    }

    return 0;
}