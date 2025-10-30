/*
Ejemplo 1 de estructuras en C
Autor: Tu Nombre
Fecha: 2024-06-15
Descripción: Este programa define una estructura para representar un punto en 2D y calcula la distancia entre dos puntos.
*/
#include <stdio.h>
#include <math.h>

// Definición de la estructura Punto
struct Punto {
    float x;
    float y;
};
// Función para calcular la distancia entre dos puntos
float distancia(struct Punto p1, struct Punto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    // Declaración e inicialización de dos puntos
    struct Punto punto1 = {3.0, 4.0};
    struct Punto punto2 = {7.0, 1.0};

    // Cálculo de la distancia entre los dos puntos
    float dist = distancia(punto1, punto2);

    // Impresión del resultado
    printf("La distancia entre los puntos (%.2f, %.2f) y (%.2f, %.2f) es: %.2f\n",
           punto1.x, punto1.y, punto2.x, punto2.y, dist);

    return 0;
}
