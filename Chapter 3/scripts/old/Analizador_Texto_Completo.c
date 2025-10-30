/*
Ejercicio 1: Analizador de Texto Completo
Escribe un programa en C que lea un texto completo (varias líneas) y realice un análisis detallado del mismo. 
El programa debe contar y mostrar:
    - Número total de caracteres (incluyendo espacios y signos de puntuación).
    - Número total de palabras.
    - Número total de líneas.
    - Número de vocales y consonantes.
    - Número de dígitos.
    - Número de espacios y signos de puntuación.
    - Promedio de caracteres por palabra.
El programa debe manejar adecuadamente la entrada de texto y mostrar los resultados de manera clara y organizada.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXTO 1000

void analizar_texto(const char *texto) {
    int caracteres = strlen(texto);
    int palabras = 0;
    int lineas = 1;  // Al menos una línea
    int vocales = 0, consonantes = 0;
    int digitos = 0, espacios = 0, puntuacion = 0;
    int en_palabra = 0;
    
    printf("\n=== ANÁLISIS DE TEXTO ===\n");
    
    for (int i = 0; texto[i] != '\0'; i++) {
        char c = tolower(texto[i]);
        
        // Contar líneas
        if (texto[i] == '\n') {
            lineas++;
        }
        
        // Contar palabras
        if (!isspace(texto[i])) {
            if (!en_palabra) {
                palabras++;
                en_palabra = 1;
            }
        } else {
            en_palabra = 0;
        }
        
        // Clasificar caracteres
        if (isalpha(c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vocales++;
            } else {
                consonantes++;
            }
        } else if (isdigit(c)) {
            digitos++;
        } else if (isspace(c)) {
            espacios++;
        } else {
            puntuacion++;
        }
    }
    
    // Mostrar resultados
    printf("Total de caracteres: %d\n", caracteres);
    printf("Palabras: %d\n", palabras);
    printf("Líneas: %d\n", lineas);
    printf("Vocales: %d\n", vocales);
    printf("Consonantes: %d\n", consonantes);
    printf("Dígitos: %d\n", digitos);
    printf("Espacios: %d\n", espacios);
    printf("Signos de puntuación: %d\n", puntuacion);
    
    if (palabras > 0) {
        printf("Promedio de caracteres por palabra: %.2f\n", 
               (float)(caracteres - espacios) / palabras);
    }
}

int main() {
    char texto[MAX_TEXTO];
    
    printf("Ingrese un texto (terminar con Enter en línea vacía):\n");
    
    // Leer texto completo
    int pos = 0;
    char linea[200];
    
    while (fgets(linea, sizeof(linea), stdin) && strcmp(linea, "\n") != 0) {
        int len = strlen(linea);
        if (pos + len < MAX_TEXTO - 1) {
            strcpy(texto + pos, linea);
            pos += len;
        } else {
            printf("Texto demasiado largo.\n");
            break;
        }
    }
    texto[pos] = '\0';
    
    if (strlen(texto) > 0) {
        analizar_texto(texto);
    } else {
        printf("No se ingresó texto.\n");
    }
    
    return 0;
}