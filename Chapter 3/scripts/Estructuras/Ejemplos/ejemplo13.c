/*
ejemplo13.c
Estructuras y Funciones
Autor: Tu Nombre
Fecha: 2024-06-15
Descripción: Este programa define una estructura para representar un libro, permite ingresar y mostrar sus datos utilizando
funciones.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

void mostrar_estudiante(struct Estudiante est) {
    printf("Nombre: %s\n", est.nombre);
    printf("Edad: %d\n", est.edad);
    printf("Promedio: %.2f\n", est.promedio);
}

int main() {
    // Uso
    struct Estudiante estudiante = {"Luis", 23, 8.9};
    struct Estudiante *ptr_est;
    struct Estudiante est = {"Pedro", 23, 8.8};

    mostrar_estudiante(estudiante);  // Se copia toda la estructura

    ptr_est = &est;

    // Acceso a través de puntero
    printf("Nombre: %s\n", ptr_est->nombre);
    printf("Edad: %d\n", ptr_est->edad);
    printf("Promedio: %.2f\n", ptr_est->promedio);

    return 0;
}