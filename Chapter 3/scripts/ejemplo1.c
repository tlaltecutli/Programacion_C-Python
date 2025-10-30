/*
 Ejemplo 1: Gestión de calificaciones de estudiantes
 
 Este programa permite ingresar las calificaciones de un grupo de estudiantes,
 valida que los datos sean correctos, y luego calcula y muestra un resumen
 estadístico que incluye el promedio, la calificación más alta y más baja,
 y el número de estudiantes aprobados y reprobados.
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_ESTUDIANTES 30
#define MIN_CALIFICACION 0
#define MAX_CALIFICACION 100

int main() {
    int calificaciones[MAX_ESTUDIANTES];
    int num_estudiantes;
    int suma = 0;
    float promedio;
    
    // Validar número de estudiantes
    do {
        printf("¿Cuántos estudiantes hay? (1-%d): ", MAX_ESTUDIANTES);
        scanf("%d", &num_estudiantes);
        
        if (num_estudiantes < 1 || num_estudiantes > MAX_ESTUDIANTES) {
            printf("Error: Número inválido de estudiantes.\n");
        }
    } while (num_estudiantes < 1 || num_estudiantes > MAX_ESTUDIANTES);
    
    // Leer calificaciones con validación
    printf("\nIngrese las calificaciones (%d-%d):\n", MIN_CALIFICACION, MAX_CALIFICACION);
    for (int i = 0; i < num_estudiantes; i++) {
        do {
            printf("Estudiante %d: ", i + 1);
            scanf("%d", &calificaciones[i]);
            
            if (calificaciones[i] < MIN_CALIFICACION || calificaciones[i] > MAX_CALIFICACION) {
                printf("Error: Calificación debe estar entre %d y %d.\n", 
                       MIN_CALIFICACION, MAX_CALIFICACION);
            }
        } while (calificaciones[i] < MIN_CALIFICACION || calificaciones[i] > MAX_CALIFICACION);
        
        suma += calificaciones[i];
    }
    
    // Calcular estadísticas
    promedio = (float)suma / num_estudiantes;
    
    // Encontrar máximo y mínimo
    int max = calificaciones[0], min = calificaciones[0];
    int pos_max = 0, pos_min = 0;
    
    for (int i = 1; i < num_estudiantes; i++) {
        if (calificaciones[i] > max) {
            max = calificaciones[i];
            pos_max = i;
        }
        if (calificaciones[i] < min) {
            min = calificaciones[i];
            pos_min = i;
        }
    }
    
    // Mostrar resultados
    printf("\n=== RESUMEN ESTADÍSTICO ===\n");
    printf("Número de estudiantes: %d\n", num_estudiantes);
    printf("Suma total: %d puntos\n", suma);
    printf("Promedio: %.2f\n", promedio);
    printf("Calificación más alta: %d (Estudiante %d)\n", max, pos_max + 1);
    printf("Calificación más baja: %d (Estudiante %d)\n", min, pos_min + 1);
    
    // Contar aprobados y reprobados
    int aprobados = 0, reprobados = 0;
    for (int i = 0; i < num_estudiantes; i++) {
        if (calificaciones[i] >= 60) {
            aprobados++;
        } else {
            reprobados++;
        }
    }
    
    printf("Estudiantes aprobados: %d (%.1f%%)\n", 
           aprobados, (float)aprobados / num_estudiantes * 100);
    printf("Estudiantes reprobados: %d (%.1f%%)\n", 
           reprobados, (float)reprobados / num_estudiantes * 100);
    
    return 0;
}