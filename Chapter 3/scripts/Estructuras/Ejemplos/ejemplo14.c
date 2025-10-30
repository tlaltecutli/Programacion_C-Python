/*
ejemplo14.c
Pasar Estructuras por Referencia en C
Autor: Tu Nombre
Fecha: 2024-06-15
Descripción: Este programa define una estructura para representar un estudiante, permite ingresar y mostrar sus datos utilizando
funciones que reciben la estructura por referencia.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

void modificar_promedio(struct Estudiante *est, float nuevo_promedio) {
    est->promedio = nuevo_promedio;
}

void mostrar_estudiante_ref(struct Estudiante *est) {
    printf("Nombre: %s\n", est->nombre);
    printf("Edad: %d\n", est->edad);
    printf("Promedio: %.2f\n", est->promedio);
}

int main() {
    struct Estudiante estudiante = {"Carmen", 21, 7.5};
    modificar_promedio(&estudiante, 8.2);
    mostrar_estudiante_ref(&estudiante);
    return 0;
}   
