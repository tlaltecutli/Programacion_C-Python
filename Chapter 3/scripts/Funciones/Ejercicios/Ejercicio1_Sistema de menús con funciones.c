/*
Ejercicio 1 - Sistema de menús con funciones en C
Este programa implementa un sistema de menús que permite al usuario seleccionar entre varias operaciones matemáticas
como suma, resta y multiplicación. Cada operación está implementada como una función separada.
*/

#include <stdio.h>
#include <stdlib.h>

// Funciones del menú
void opcion_suma() {
    int a, b;
    printf("Ingrese dos números: ");
    scanf("%d %d", &a, &b);
    printf("Resultado: %d + %d = %d\n", a, b, a + b);
}

void opcion_resta() {
    int a, b;
    printf("Ingrese dos números: ");
    scanf("%d %d", &a, &b);
    printf("Resultado: %d - %d = %d\n", a, b, a - b);
}

void opcion_multiplicacion() {
    int a, b;
    printf("Ingrese dos números: ");
    scanf("%d %d", &a, &b);
    printf("Resultado: %d * %d = %d\n", a, b, a * b);
}

void mostrar_menu() {
    printf("\n=== CALCULADORA ===\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicación\n");
    printf("4. Salir\n");
    printf("Seleccione una opción: ");
}

int main() {
    // Array de punteros a funciones del menú
    void (*opciones[])() = {opcion_suma, opcion_resta, opcion_multiplicacion};
    
    int seleccion;
    
    do {
        mostrar_menu();
        scanf("%d", &seleccion);
        
        if (seleccion >= 1 && seleccion <= 3) {
            opciones[seleccion - 1]();
        } else if (seleccion == 4) {
            printf("¡Hasta luego!\n");
        } else {
            printf("Opción inválida. Intente de nuevo.\n");
        }
        
    } while (seleccion != 4);
    
    return 0;
}