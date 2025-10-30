/*
ejemplo5.c
Ejemplo de inicialización de estructuras en C
Autor: Tu Nombre
Fecha: 2024-06-15
Descripción: Este programa muestra diferentes formas de inicializar una estructura en C.
*/

struct Punto {
    int x;
    int y;
};

// Inicialización ordenada
struct Punto p1 = {10, 20};

// Inicialización con designadores (C99)
struct Punto p2 = {.x = 5, .y = 15};
struct Punto p3 = {.y = 25, .x = 35}; // Orden no importa

#include <stdio.h>

int main() {
    printf("Punto 1: (%d, %d)\n", p1.x, p1.y);
    printf("Punto 2: (%d, %d)\n", p2.x, p2.y);
    printf("Punto 3: (%d, %d)\n", p3.x, p3.y);
    return 0;
}