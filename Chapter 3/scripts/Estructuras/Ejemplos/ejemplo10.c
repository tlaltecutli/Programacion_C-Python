/*
ejemplo10.c
Ejemplo Declaración de Arrays de Estructuras en C
Autor: Tu Nombre
Fecha: 2024-06-15
Descripción: Este programa define una estructura para representar un estudiante y declara un array de estructuras.
*/

#include <stdio.h>
#include <string.h>

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

int main() {
    struct Estudiante estudiantes[3];
    // Asignación de datos a cada estudiante
    strcpy(estudiantes[0].nombre, "Luis");
    estudiantes[0].edad = 20;
    estudiantes[0].promedio = 8.5;
    strcpy(estudiantes[1].nombre, "Marta");
    estudiantes[1].edad = 22;
    estudiantes[1].promedio = 9.0;
    strcpy(estudiantes[2].nombre, "Carlos");
    estudiantes[2].edad = 21;
    estudiantes[2].promedio = 7.8;
    // Impresión de los datos de cada estudiante
    for (int i = 0; i < 3; i++) {
        printf("Estudiante %d:\n", i + 1);
        printf("Nombre: %s\n", estudiantes[i].nombre);
        printf("Edad: %d\n", estudiantes[i].edad);
        printf("Promedio: %.2f\n\n", estudiantes[i].promedio);
    }
    return 0;
}