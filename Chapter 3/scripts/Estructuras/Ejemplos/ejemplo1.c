/*
Ejemplo de uso de estructuras en C
Autor: Tu Nombre
Fecha: 2024-06-15
Descripción: Este programa define una estructura para representar un estudiante y permite ingresar y mostrar sus datos.
*/
#include <stdio.h>
#include <string.h>

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    char carrera[30];
};


int main() {
    struct Estudiante estudiante1;

    printf("Ingrese el nombre del estudiante: ");
    fgets(estudiante1.nombre, sizeof(estudiante1.nombre), stdin);
    estudiante1.nombre[strcspn(estudiante1.nombre, "\n")] = '\0';

    printf("Ingrese la edad del estudiante: ");
    scanf("%d", &estudiante1.edad);

    printf("Ingrese el promedio del estudiante: ");
    scanf("%f", &estudiante1.promedio);

    printf("Ingrese la carrera del estudiante: ");
    fgets(estudiante1.carrera, sizeof(estudiante1.carrera), stdin);
    estudiante1.carrera[strcspn(estudiante1.carrera, "\n")] = '\0';
    printf("\nDatos del Estudiante:\n");
    printf("Nombre: %s\n", estudiante1.nombre);
    printf("Edad: %d\n", estudiante1.edad);
    printf("Promedio: %.2f\n", estudiante1.promedio);
    printf("Carrera: %s\n", estudiante1.carrera);

    return 0;
}