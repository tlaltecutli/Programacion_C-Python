/*
ejemplo11.c
Ejemplo Inicialización de Arrays de Estructuras en C
Autor: Tu Nombre
Fecha: 2024-06-15
Descripción: Este programa define una estructura para representar un estudiante y declara e inicializa un array de estructuras.

*/
#include <stdio.h>
#include <string.h>

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

// Con designadores
struct Estudiante grupo[] = {
    {.nombre = "Juan", .edad = 20, .promedio = 8.5},
    {.nombre = "María", .edad = 19, .promedio = 9.0},
    {.nombre = "Pedro", .edad = 21, .promedio = 7.8}
};

int main() {
    // Impresión de los datos de cada estudiante
    for (int i = 0; i < 3; i++) {
        printf("Estudiante %d:\n", i + 1);
        printf("Nombre: %s\n", grupo[i].nombre);
        printf("Edad: %d\n", grupo[i].edad);
        printf("Promedio: %.2f\n\n", grupo[i].promedio);
    }
    return 0;
}
