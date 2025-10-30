/*
Ejemplo 3 - Función para calcular la secuencia de Fibonacci usando C
La secuencia de Fibonacci es una serie de números donde cada número es la suma de los dos anteriores.
Comienza con 0 y 1, y los siguientes números son 1, 2, 3, 5, 8, 13, etc.
Por ejemplo, el 10º número en la secuencia de Fibonacci es 55.
*/

#include <stdio.h>
#include <time.h>

// Fibonacci recursivo (ineficiente)
int fibonacci_recursivo(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
}

// Fibonacci iterativo (más eficiente)
int fibonacci_iterativo(int n) {
    if (n <= 1) return n;
    
    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int numero = 40; // Aumentado para una diferencia de tiempo más notable

    clock_t start, end;
    double cpu_time_used;

    // --- Medir tiempo de la función recursiva ---
    printf("Calculando Fibonacci(%d) con el método recursivo...\n", numero);
    start = clock();
    int resultado_recursivo = fibonacci_recursivo(numero);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("El %dº número de Fibonacci (recursivo) es: %d\n", numero, resultado_recursivo);
    printf("Tiempo de ejecución (recursivo): %f segundos\n\n", cpu_time_used);

    // --- Medir tiempo de la función iterativa ---
    printf("Calculando Fibonacci(%d) con el método iterativo...\n", numero);
    start = clock();
    int resultado_iterativo = fibonacci_iterativo(numero);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("El %dº número de Fibonacci (iterativo) es: %d\n", numero, resultado_iterativo);
    printf("Tiempo de ejecución (iterativo): %f segundos\n", cpu_time_used);

    return 0;
}