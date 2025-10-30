/*
Ejemplo 3 de uso de estructuras en C con funciones
Autor: Tu Nombre
Fecha: 2024-06-15
Descripción: Este programa define una estructura para representar un estudiante, permite ingresar y mostrar sus datos utilizando
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

// Declaración de variables
struct Estudiante estudiante1;
struct Estudiante estudiante2;

// Funciones para ingresar y mostrar datos
void ingresarDatos(struct Estudiante *estudiante) {
    printf("Ingrese el nombre del estudiante: ");
    fgets(estudiante->nombre, sizeof(estudiante->nombre), stdin);
    estudiante->nombre[strcspn(estudiante->nombre, "\n")] = '\0';

    printf("Ingrese la edad del estudiante: ");
    scanf("%d", &estudiante->edad);

    printf("Ingrese el promedio del estudiante: ");
    scanf("%f", &estudiante->promedio);
    getchar(); // Limpiar el buffer de entrada
}

// Función para mostrar los datos del estudiante
void mostrarDatos(struct Estudiante estudiante) {
    printf("\nDatos del Estudiante:\n");
    printf("Nombre: %s\n", estudiante.nombre);
    printf("Edad: %d\n", estudiante.edad);
    printf("Promedio: %.2f\n", estudiante.promedio);
}

// Función principal
int main() {
    ingresarDatos(&estudiante1);
    mostrarDatos(estudiante1);

    return 0;
}