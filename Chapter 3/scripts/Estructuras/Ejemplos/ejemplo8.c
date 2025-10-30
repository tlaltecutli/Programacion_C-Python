/*
ejemplo8.c
Ejemplo de uso de estructuras anidadas en C
Autor: Tu Nombre
Fecha: 2024-06-15
Descripción: Este programa define estructuras anidadas para representar un estudiante y su dirección, y muestra
cómo acceder a los campos de las estructuras.
*/
#include <stdio.h>
#include <string.h>

struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Persona {
    char nombre[50];
    struct Fecha nacimiento;
    struct Fecha ingreso;
};

struct Direccion {
    char calle[50];
    int numero;
    char colonia[50];
    char ciudad[50];
    char estado[50];
    char pais[50];
};

struct Estudiante {
    struct Persona info_personal;
    struct Direccion direccion;
    float promedio;
};

int main() {
    struct Estudiante estudiante;

    // Asignación de datos
    strcpy(estudiante.info_personal.nombre, "Ana Pérez");
    estudiante.info_personal.nacimiento.dia = 15;
    estudiante.info_personal.nacimiento.mes = 6;
    estudiante.info_personal.nacimiento.anio = 2000;
    estudiante.info_personal.ingreso.dia = 1;
    estudiante.info_personal.ingreso.mes = 9;
    estudiante.info_personal.ingreso.anio = 2018;

    strcpy(estudiante.direccion.calle, "Av. Siempre Viva");
    estudiante.direccion.numero = 742;
    strcpy(estudiante.direccion.colonia, "Springfield");
    strcpy(estudiante.direccion.ciudad, "Springfield");
    strcpy(estudiante.direccion.estado, "Illinois");
    strcpy(estudiante.direccion.pais, "USA");

    estudiante.promedio = 9.5;

    // Impresión de datos
    printf("Nombre: %s\n", estudiante.info_personal.nombre);
    printf("Fecha de Nacimiento: %02d/%02d/%04d\n",
           estudiante.info_personal.nacimiento.dia,
           estudiante.info_personal.nacimiento.mes,
           estudiante.info_personal.nacimiento.anio);
    printf("Fecha de Ingreso: %02d/%02d/%04d\n",
           estudiante.info_personal.ingreso.dia,
           estudiante.info_personal.ingreso.mes,
           estudiante.info_personal.ingreso.anio);
    printf("Dirección:\n");
    printf("  Calle: %s, No: %d\n", estudiante.direccion.calle, estudiante.direccion.numero);
    printf("  Colonia: %s\n", estudiante.direccion.colonia);
    printf("  Ciudad: %s\n", estudiante.direccion.ciudad);
    printf("  Estado: %s\n", estudiante.direccion.estado);
    printf("  País: %s\n", estudiante.direccion.pais);
    printf("Promedio: %.2f\n", estudiante.promedio);

    return 0;
}