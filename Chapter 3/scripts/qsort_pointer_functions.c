#include <stdio.h>
#include <stdlib.h>

// Función de comparación para ordenamiento ascendente
int comparar_ascendente(const void *a, const void *b) {
    int int_a = *(int*)a;
    int int_b = *(int*)b;
    return int_a - int_b;  // Negativo si a < b, 0 si a == b, positivo si a > b
}

// Función de comparación para ordenamiento descendente
int comparar_descendente(const void *a, const void *b) {
    return comparar_ascendente(b, a);  // Invertir el orden
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Arreglo original: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    // Ordenar ascendente
    qsort(arr, n, sizeof(int), comparar_ascendente);
    printf("Orden ascendente: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    // Ordenar descendente
    qsort(arr, n, sizeof(int), comparar_descendente);
    printf("Orden descendente: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}