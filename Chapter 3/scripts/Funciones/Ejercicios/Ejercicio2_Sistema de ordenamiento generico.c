/*
Ejercicio 2 - Sistema de ordenamiento genérico en C
Este programa implementa un sistema de ordenamiento genérico que puede ordenar arrays de diferentes tipos de datos
utilizando punteros a funciones para la comparación. Se incluyen ejemplos de ordenamiento de enteros y strings.
*/

#include <stdio.h>
#include <string.h>

// Función de intercambio genérica
void intercambiar(void *a, void *b, size_t tamaño) {
    char temp[tamaño];
    memcpy(temp, a, tamaño);
    memcpy(a, b, tamaño);
    memcpy(b, temp, tamaño);
}

// Ordenamiento burbuja genérico
void ordenamiento_burbuja(void *arr, int n, size_t tamaño_elemento, 
                         int (*comparar)(const void *, const void *)) {
    char *array = (char *)arr;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            void *elem1 = array + j * tamaño_elemento;
            void *elem2 = array + (j + 1) * tamaño_elemento;
            
            if (comparar(elem1, elem2) > 0) {
                intercambiar(elem1, elem2, tamaño_elemento);
            }
        }
    }
}

// Funciones de comparación
int comparar_enteros(const void *a, const void *b) {
    int int_a = *(const int *)a;
    int int_b = *(const int *)b;
    return int_a - int_b;
}

int comparar_strings(const void *a, const void *b) {
    const char *str_a = *(const char **)a;
    const char *str_b = *(const char **)b;
    return strcmp(str_a, str_b);
}

// Funciones de impresión
void imprimir_enteros(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void imprimir_strings(char *arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Ejemplo con enteros
    int numeros[] = {64, 34, 25, 12, 22, 11, 90};
    int n_numeros = sizeof(numeros) / sizeof(numeros[0]);
    
    printf("Números originales: ");
    imprimir_enteros(numeros, n_numeros);
    
    ordenamiento_burbuja(numeros, n_numeros, sizeof(int), comparar_enteros);
    
    printf("Números ordenados: ");
    imprimir_enteros(numeros, n_numeros);
    
    // Ejemplo con strings
    char *palabras[] = {"banana", "manzana", "cereza", "durazno", "uva"};
    int n_palabras = sizeof(palabras) / sizeof(palabras[0]);
    
    printf("\nPalabras originales: ");
    imprimir_strings(palabras, n_palabras);
    
    ordenamiento_burbuja(palabras, n_palabras, sizeof(char *), comparar_strings);
    
    printf("Palabras ordenadas: ");
    imprimir_strings(palabras, n_palabras);
    
    return 0;
}