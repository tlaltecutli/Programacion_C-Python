/*
Ejercicio 1: Analizador de Texto Completo (Versión Optimizada)
Programa que analiza texto completo contando caracteres, palabras, líneas,
vocales, consonantes, dígitos, espacios y signos de puntuación.
Incluye validaciones y manejo de errores mejorado.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_TEXTO 10000      // Aumentado para textos más largos
#define MAX_LINEA 1000       // Buffer más grande para líneas largas

// Estructura para almacenar estadísticas del texto
typedef struct {
    int caracteres_totales;
    int caracteres_sin_espacios;
    int palabras;
    int lineas;
    int vocales;
    int consonantes;
    int digitos;
    int espacios;
    int puntuacion;
} EstadisticasTexto;

/**
 * Verifica si un carácter es una vocal
 */
bool es_vocal(char c) {
    char vocal = tolower(c);
    return (vocal == 'a' || vocal == 'e' || vocal == 'i' || 
            vocal == 'o' || vocal == 'u');
}

/**
 * Inicializa la estructura de estadísticas
 */
void inicializar_estadisticas(EstadisticasTexto *stats) {
    stats->caracteres_totales = 0;
    stats->caracteres_sin_espacios = 0;
    stats->palabras = 0;
    stats->lineas = 0;
    stats->vocales = 0;
    stats->consonantes = 0;
    stats->digitos = 0;
    stats->espacios = 0;
    stats->puntuacion = 0;
}

/**
 * Analiza el texto y calcula todas las estadísticas
 */
void analizar_texto(const char *texto, EstadisticasTexto *stats) {
    if (texto == NULL || stats == NULL) {
        return;
    }
    
    inicializar_estadisticas(stats);
    
    bool en_palabra = false;
    bool texto_vacio = true;
    
    // Contar caracteres totales
    stats->caracteres_totales = strlen(texto);
    
    // Si el texto no está vacío, cuenta al menos una línea
    if (stats->caracteres_totales > 0) {
        stats->lineas = 1;
        texto_vacio = false;
    }
    
    // Procesar cada carácter
    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];
        char c_lower = tolower(c);
        
        // Contar líneas
        if (c == '\n') {
            stats->lineas++;
            en_palabra = false;  // Fin de palabra al cambiar de línea
        }
        
        // Contar palabras (secuencias de caracteres no espaciadores)
        if (!isspace(c)) {
            if (!en_palabra) {
                stats->palabras++;
                en_palabra = true;
            }
        } else {
            en_palabra = false;
        }
        
        // Clasificar caracteres
        if (isalpha(c)) {
            stats->caracteres_sin_espacios++;
            if (es_vocal(c_lower)) {
                stats->vocales++;
            } else {
                stats->consonantes++;
            }
        } else if (isdigit(c)) {
            stats->caracteres_sin_espacios++;
            stats->digitos++;
        } else if (isspace(c)) {
            stats->espacios++;
        } else {
            // Signos de puntuación y caracteres especiales
            stats->caracteres_sin_espacios++;
            stats->puntuacion++;
        }
    }
    
    // Ajustar conteo si el texto termina sin salto de línea
    if (stats->caracteres_totales > 0 && texto[stats->caracteres_totales - 1] != '\n') {
        // El texto no termina en nueva línea, pero sí cuenta como línea
    }
}

/**
 * Muestra las estadísticas del análisis de manera organizada
 */
void mostrar_resultados(const EstadisticasTexto *stats) {
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║           ANÁLISIS DE TEXTO            ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║ Estadísticas Generales:                ║\n");
    printf("║   • Total de caracteres: %13d ║\n", stats->caracteres_totales);
    printf("║   • Número de palabras:  %13d ║\n", stats->palabras);
    printf("║   • Número de líneas:    %13d ║\n", stats->lineas);
    printf("║                                        ║\n");
    printf("║ Clasificación de Caracteres:           ║\n");
    printf("║   • Vocales:            %14d ║\n", stats->vocales);
    printf("║   • Consonantes:        %14d ║\n", stats->consonantes);
    printf("║   • Dígitos:            %14d ║\n", stats->digitos);
    printf("║   • Espacios:           %14d ║\n", stats->espacios);
    printf("║   • Signos puntuación:  %14d ║\n", stats->puntuacion);
    printf("║                                        ║\n");
    printf("║ Promedios:                             ║\n");
    
    if (stats->palabras > 0) {
        float promedio_chars = (float)stats->caracteres_sin_espacios / stats->palabras;
        printf("║   • Chars por palabra:  %14.2f ║\n", promedio_chars);
        
        float promedio_total = (float)stats->caracteres_totales / stats->palabras;
        printf("║   • Chars totales/pal.: %14.2f ║\n", promedio_total);
    } else {
        printf("║   • Chars por palabra:      No aplicable ║\n");
    }
    
    if (stats->lineas > 0) {
        float promedio_palabras_linea = (float)stats->palabras / stats->lineas;
        printf("║   • Palabras por línea: %14.2f ║\n", promedio_palabras_linea);
    }
    
    printf("╚════════════════════════════════════════╝\n");
}

/**
 * Lee el texto completo desde la entrada estándar
 */
int leer_texto(char *texto, int max_size) {
    printf("Ingrese el texto a analizar:\n");
    printf("(Presione Ctrl+D en Linux/Mac o Ctrl+Z en Windows para terminar)\n");
    printf("(O termine con una línea que contenga solo un punto '.')\n\n");
    
    int pos = 0;
    char linea[MAX_LINEA];
    bool primer_linea = true;
    
    while (fgets(linea, sizeof(linea), stdin)) {
        // Verificar si es la línea de terminación
        if (strcmp(linea, ".\n") == 0) {
            break;
        }
        
        int len = strlen(linea);
        
        // Verificar espacio disponible
        if (pos + len >= max_size - 1) {
            printf("\n⚠️  Advertencia: Texto truncado (excede %d caracteres)\n", max_size);
            texto[max_size - 1] = '\0';
            return max_size - 1;
        }
        
        // Copiar línea al buffer
        strcpy(texto + pos, linea);
        pos += len;
        primer_linea = false;
    }
    
    texto[pos] = '\0';
    return pos;
}

/**
 * Función principal
 */
int main() {
    char *texto = malloc(MAX_TEXTO);
    if (texto == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria\n");
        return 1;
    }
    
    EstadisticasTexto stats;
    
    printf("╔═══════════════════════════════════════════════════╗\n");
    printf("║          ANALIZADOR DE TEXTO COMPLETO             ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n\n");
    
    int longitud = leer_texto(texto, MAX_TEXTO);
    
    if (longitud == 0) {
        printf("\n❌ No se ingresó texto para analizar.\n");
    } else {
        printf("\n✅ Texto capturado (%d caracteres). Analizando...\n", longitud);
        
        analizar_texto(texto, &stats);
        mostrar_resultados(&stats);
        
        // Mostrar una muestra del texto si es muy largo
        if (longitud > 100) {
            printf("\n📄 Muestra del texto (primeros 100 caracteres):\n");
            printf("\"");
            for (int i = 0; i < 100 && texto[i] != '\0'; i++) {
                if (texto[i] == '\n') {
                    printf("\\n");
                } else {
                    printf("%c", texto[i]);
                }
            }
            printf("...\"\n");
        } else {
            printf("\n📄 Texto analizado:\n\"%s\"\n", texto);
        }
    }
    
    free(texto);
    return 0;
}