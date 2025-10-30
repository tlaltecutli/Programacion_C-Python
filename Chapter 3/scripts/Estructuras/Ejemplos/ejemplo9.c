/*
ejemplo9.c
Ejemplo de estructuras anidadas en C
Autor: Tu Nombre
Fecha: 2024-06-15
Descripción: Este programa define estructuras anidadas para representar un estudiante y su dirección, y muestra
cómo acceder a los campos de las estructuras a través de un puntero.
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

int main() {
    struct Persona empleado;
    
    strcpy(empleado.nombre, "Ana García");
    empleado.nacimiento.dia = 15;
    empleado.nacimiento.mes = 3;
    empleado.nacimiento.anio = 1990;

    empleado.ingreso.dia = 1;
    empleado.ingreso.mes = 9;
    empleado.ingreso.anio = 2020;

    printf("Empleado: %s\n", empleado.nombre);
    printf("Nacimiento: %d/%d/%d\n", 
       empleado.nacimiento.dia,
       empleado.nacimiento.mes,
       empleado.nacimiento.anio);
    return 0;
}