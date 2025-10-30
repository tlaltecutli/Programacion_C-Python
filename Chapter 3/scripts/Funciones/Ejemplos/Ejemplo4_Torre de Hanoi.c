/*
Ejemplo 4 - Función para resolver el problema de las Torres de Hanoi usando C

El problema de las Torres de Hanoi es un clásico problema de recursión. Consiste en mover una pila de discos de una varilla a otra, 
siguiendo ciertas reglas.

Reglas:
1. Solo se puede mover un disco a la vez.
2. Un disco más grande no puede colocarse sobre un disco más pequeño.
3. Solo se puede mover el disco que está en la parte superior de una pila.

*/

#include <stdio.h>

// Función para resolver el problema de las Torres de Hanoi
void hanoi(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mover disco 1 de %c a %c\n", origen, destino);
        return;
    }
    
    hanoi(n - 1, origen, auxiliar, destino);
    printf("Mover disco %d de %c a %c\n", n, origen, destino);
    hanoi(n - 1, auxiliar, destino, origen);
}


int main() {
    int num_discos = 3; // Puedes cambiar este valor para probar con más discos
    hanoi(num_discos, 'A', 'C', 'B'); // A, B y C son los nombres de las varillas
    return 0;
}
