/*
Ejercicio 3: Procesador de Nombres
Escribe un programa en C que gestione una lista de nombres. El programa debe permitir:
    - Agregar nombres a la lista (máximo 50 nombres).
    - Mostrar todos los nombres almacenados.
    - Ordenar los nombres alfabéticamente.
    - Buscar un nombre específico y mostrar su posición en la lista.
    - Mostrar estadísticas como el nombre más largo, el más corto y la longitud promedio de los nombres.
    - Formatear los nombres para que la primera letra de cada nombre y apellido esté en mayúscula y el resto en minúscula.
El programa debe manejar adecuadamente la entrada de datos y mostrar los resultados de manera clara y organizada.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOMBRES 50
#define MAX_LONGITUD 30

void formatear_nombre(char *nombre) {
    // Convertir a minúsculas
    for (int i = 0; nombre[i] != '\0'; i++) {
        nombre[i] = tolower(nombre[i]);
    }
    
    // Capitalizar primera letra de cada palabra
    int nueva_palabra = 1;
    for (int i = 0; nombre[i] != '\0'; i++) {
        if (isalpha(nombre[i]) && nueva_palabra) {
            nombre[i] = toupper(nombre[i]);
            nueva_palabra = 0;
        } else if (isspace(nombre[i])) {
            nueva_palabra = 1;
        }
    }
}

void ordenar_nombres(char nombres[][MAX_LONGITUD], int cantidad) {
    char temp[MAX_LONGITUD];
    
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = i + 1; j < cantidad; j++) {
            if (strcmp(nombres[i], nombres[j]) > 0) {
                strcpy(temp, nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], temp);
            }
        }
    }
}

int buscar_nombre(char nombres[][MAX_LONGITUD], int cantidad, const char *buscar) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], buscar) == 0) {
            return i;
        }
    }
    return -1;
}

void mostrar_estadisticas(char nombres[][MAX_LONGITUD], int cantidad) {
    if (cantidad == 0) {
        printf("No hay nombres para analizar.\n");
        return;
    }
    
    int longitud_total = 0;
    int longitud_max = 0, longitud_min = MAX_LONGITUD;
    char nombre_mas_largo[MAX_LONGITUD] = "";
    char nombre_mas_corto[MAX_LONGITUD] = "";
    
    for (int i = 0; i < cantidad; i++) {
        int len = strlen(nombres[i]);
        longitud_total += len;
        
        if (len > longitud_max) {
            longitud_max = len;
            strcpy(nombre_mas_largo, nombres[i]);
        }
        
        if (len < longitud_min) {
            longitud_min = len;
            strcpy(nombre_mas_corto, nombres[i]);
        }
    }
    
    printf("\n=== ESTADÍSTICAS ===\n");
    printf("Total de nombres: %d\n", cantidad);
    printf("Longitud promedio: %.2f caracteres\n", (float)longitud_total / cantidad);
    printf("Nombre más largo: %s (%d caracteres)\n", nombre_mas_largo, longitud_max);
    printf("Nombre más corto: %s (%d caracteres)\n", nombre_mas_corto, longitud_min);
}

int main() {
    char nombres[MAX_NOMBRES][MAX_LONGITUD];
    int cantidad = 0;
    int opcion;
    
    do {
        printf("\n=== PROCESADOR DE NOMBRES ===\n");
        printf("1. Agregar nombre\n");
        printf("2. Mostrar todos los nombres\n");
        printf("3. Ordenar nombres alfabéticamente\n");
        printf("4. Buscar nombre\n");
        printf("5. Mostrar estadísticas\n");
        printf("6. Salir\n");
        printf("Nombres actuales: %d/%d\n", cantidad, MAX_NOMBRES);
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1: {
                if (cantidad >= MAX_NOMBRES) {
                    printf("Lista llena. No se pueden agregar más nombres.\n");
                    break;
                }
                
                printf("Ingrese un nombre: ");
                scanf(" %[^\n]", nombres[cantidad]);  // Leer con espacios
                formatear_nombre(nombres[cantidad]);
                cantidad++;
                printf("Nombre agregado y formateado.\n");
                break;
            }
            
            case 2: {
                if (cantidad == 0) {
                    printf("No hay nombres para mostrar.\n");
                } else {
                    printf("\n=== LISTA DE NOMBRES ===\n");
                    for (int i = 0; i < cantidad; i++) {
                        printf("%d. %s\n", i + 1, nombres[i]);
                    }
                }
                break;
            }
            
            case 3: {
                if (cantidad == 0) {
                    printf("No hay nombres para ordenar.\n");
                } else {
                    ordenar_nombres(nombres, cantidad);
                    printf("Nombres ordenados alfabéticamente.\n");
                }
                break;
            }
            
            case 4: {
                if (cantidad == 0) {
                    printf("No hay nombres para buscar.\n");
                } else {
                    char buscar[MAX_LONGITUD];
                    printf("Ingrese nombre a buscar: ");
                    scanf(" %[^\n]", buscar);
                    formatear_nombre(buscar);
                    
                    int pos = buscar_nombre(nombres, cantidad, buscar);
                    if (pos != -1) {
                        printf("Nombre '%s' encontrado en posición %d.\n", buscar, pos + 1);
                    } else {
                        printf("Nombre '%s' no encontrado.\n", buscar);
                    }
                }
                break;
            }
            
            case 5:
                mostrar_estadisticas(nombres, cantidad);
                break;
                
            case 6:
                printf("¡Hasta luego!\n");
                break;
                
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 6);
    
    return 0;
}