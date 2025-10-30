/*
ejemplo6.c
Ejemplo de asignación y lectura de campos en una estructura en C
Autor: Tu Nombre
Fecha: 2024-06-15
Descripción: Este programa muestra cómo asignar y leer los campos de una estructura en C.

*/
#include <stdio.h>
#include <string.h>

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

int main() {
    struct Estudiante est;
    // Asignación
    strcpy(est.nombre, "María");
    est.edad = 21;
    est.promedio = 9.2;
    // Lectura
    printf("Nombre: %s\n", est.nombre);
    printf("Edad: %d\n", est.edad);
    printf("Promedio: %.2f\n", est.promedio);
    return 0;
}