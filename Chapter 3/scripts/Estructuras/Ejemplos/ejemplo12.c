/*
ejemplo12.c
Manipulación de Arrays de Estructuras en C
Autor: Tu Nombre
Fecha: 2024-06-15
Descripción: Este programa define una estructura para representar un estudiante, declara un array de estructuras,
y permite ingresar y mostrar los datos de múltiples estudiantes utilizando funciones.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOMBRE 50

struct Estudiante {
    char nombre[MAX_NOMBRE];
    int edad;
    float promedio;
};

int main() {
    struct Estudiante grupo[3];
    
    // Llenar array de estructuras
    for (int i = 0; i < 3; i++) {
        printf("Ingrese datos del estudiante %d:\n", i + 1);
        printf("Nombre: ");
        scanf("%s", grupo[i].nombre);
        printf("Edad: ");
        scanf("%d", &grupo[i].edad);
        printf("Promedio: ");
        scanf("%f", &grupo[i].promedio);
        getchar(); // Limpiar el buffer de entrada
    }

    // Mostrar datos
    for (int i = 0; i < 3; i++) {
        printf("Estudiante %d: %s, %d años, promedio: %.2f\n",
            i + 1, grupo[i].nombre, grupo[i].edad, grupo[i].promedio);
    }
    return 0;
}   