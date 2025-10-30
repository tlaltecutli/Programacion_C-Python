/*
Ejercicio 3 - Calculadora de expresiones con funciones en C
Este programa implementa una calculadora simple que puede evaluar expresiones matemáticas básicas
utilizando funciones para cada operación. Soporta suma, resta, multiplicación y división.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Estructura para operaciones
typedef struct {
    char simbolo;
    int precedencia;
    int (*funcion)(int, int);
} Operacion;

// Funciones de operaciones
int sumar_op(int a, int b) { return a + b; }
int restar_op(int a, int b) { return a - b; }
int multiplicar_op(int a, int b) { return a * b; }
int dividir_op(int a, int b) { return b != 0 ? a / b : 0; }

// Array de operaciones disponibles
Operacion operaciones[] = {
    {'+', 1, sumar_op},
    {'-', 1, restar_op},
    {'*', 2, multiplicar_op},
    {'/', 2, dividir_op}
};

int num_operaciones = sizeof(operaciones) / sizeof(operaciones[0]);

// Buscar operación por símbolo
Operacion* buscar_operacion(char simbolo) {
    for (int i = 0; i < num_operaciones; i++) {
        if (operaciones[i].simbolo == simbolo) {
            return &operaciones[i];
        }
    }
    return NULL;
}

// Evaluador simple de expresiones (solo para números de un dígito)
int evaluar_expresion(char *expresion) {
    int resultado = expresion[0] - '0'; // Primer número
    
    for (int i = 1; i < strlen(expresion); i += 2) {
        char op_simbolo = expresion[i];
        int siguiente_numero = expresion[i + 1] - '0';
        
        Operacion *op = buscar_operacion(op_simbolo);
        if (op != NULL) {
            resultado = op->funcion(resultado, siguiente_numero);
        }
    }
    
    return resultado;
}

int main() {
    char expresion[100];
    
    printf("Calculadora simple (solo números de un dígito)\n");
    printf("Operaciones disponibles: +, -, *, /\n");
    printf("Ejemplo: 5+3*2-1\n");
    printf("Ingrese una expresión: ");
    
    if (fgets(expresion, sizeof(expresion), stdin)) {
        // Remover salto de línea
        expresion[strcspn(expresion, "\n")] = 0;
        
        int resultado = evaluar_expresion(expresion);
        printf("Resultado de '%s' = %d\n", expresion, resultado);
    }
    
    return 0;
}