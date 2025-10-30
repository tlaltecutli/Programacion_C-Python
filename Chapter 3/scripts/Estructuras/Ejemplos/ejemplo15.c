/*
ejemplo15.c
Funciones que Retornan Estructuras en C
Autor: Tu Nombre
Fecha: 2024-06-15
Descripción: Este programa define una estructura para representar un punto en 2D y una función que
retorna una estructura.
*/

#include <stdio.h>

struct Punto {
    int x;
    int y;
};

struct Punto crear_punto(int x, int y) {
    struct Punto p;
    p.x = x;
    p.y = y;
    return p;
}

struct Punto sumar_puntos(struct Punto p1, struct Punto p2) {
    struct Punto resultado;
    resultado.x = p1.x + p2.x;
    resultado.y = p1.y + p2.y;
    return resultado;
}

int main() {
    struct Punto p1 = crear_punto(3, 4);
    struct Punto p2 = crear_punto(1, 2);
    struct Punto suma = sumar_puntos(p1, p2);
    printf("Suma: (%d, %d)\n", suma.x, suma.y);
    return 0;
}
