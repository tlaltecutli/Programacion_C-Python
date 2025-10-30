/*
 * Sistema de Gestión de Notas
 * Este programa permite ingresar las notas de varios estudiantes en diferentes materias,
 * calcular promedios y mostrar un reporte detallado.
 * Autor: Zeus Tlaltecutli
 * Fecha: 2024-06-15
 */


#include <stdio.h>
#include <string.h>

#define MAX_ESTUDIANTES 10
#define MAX_MATERIAS 5
#define MAX_NOMBRE 50

int main() {
    float notas[MAX_ESTUDIANTES][MAX_MATERIAS];
    char nombres[MAX_ESTUDIANTES][MAX_NOMBRE];
    char materias[MAX_MATERIAS][MAX_NOMBRE] = {
        "Matemáticas", "Física", "Química", "Historia", "Literatura"
    };
    
    int num_estudiantes, num_materias = 5;
    
    printf("=== SISTEMA DE GESTIÓN DE NOTAS ===\n");
    printf("Número de estudiantes (1-%d): ", MAX_ESTUDIANTES);
    scanf("%d", &num_estudiantes);
    
    // Leer nombres de estudiantes
    printf("\nIngrese los nombres de los estudiantes:\n");
    for (int i = 0; i < num_estudiantes; i++) {
        printf("Estudiante %d: ", i + 1);
        scanf(" %[^\n]", nombres[i]);  // Leer línea completa incluyendo espacios
    }
    
    // Leer notas
    printf("\nIngrese las notas (0-100):\n");
    for (int i = 0; i < num_estudiantes; i++) {
        printf("\nNotas para %s:\n", nombres[i]);
        for (int j = 0; j < num_materias; j++) {
            do {
                printf("  %s: ", materias[j]);
                scanf("%f", &notas[i][j]);
                if (notas[i][j] < 0 || notas[i][j] > 100) {
                    printf("  Error: Nota debe estar entre 0 y 100.\n");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 100);
        }
    }
    
    // Calcular y mostrar estadísticas
    printf("\n=== REPORTE DE CALIFICACIONES ===\n");
    printf("%-15s", "Estudiante");
    for (int j = 0; j < num_materias; j++) {
        printf("%-12s", materias[j]);
    }
    printf("%-10s\n", "Promedio");
    
    for (int i = 0; i < num_estudiantes; i++) {
        printf("%-15s", nombres[i]);
        float suma = 0;
        
        for (int j = 0; j < num_materias; j++) {
            printf("%-12.1f", notas[i][j]);
            suma += notas[i][j];
        }
        
        float promedio = suma / num_materias;
        printf("%-10.1f\n", promedio);
    }
    
    // Calcular promedios por materia
    printf("\nPromedios por materia:\n");
    for (int j = 0; j < num_materias; j++) {
        float suma = 0;
        for (int i = 0; i < num_estudiantes; i++) {
            suma += notas[i][j];
        }
        printf("%-15s: %.1f\n", materias[j], suma / num_estudiantes);
    }
    
    return 0;
}