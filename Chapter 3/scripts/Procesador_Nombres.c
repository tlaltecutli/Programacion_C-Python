/*
Ejercicio 3: Procesador de Nombres - Versión Optimizada
Programa en C que gestiona una lista de nombres con funcionalidades completas:
    - Agregar nombres a la lista (máximo 50 nombres)
    - Mostrar todos los nombres almacenados
    - Ordenar los nombres alfabéticamente
    - Buscar un nombre específico y mostrar su posición
    - Mostrar estadísticas completas
    - Formatear nombres correctamente
    - Eliminar nombres de la lista
    - Validación robusta de entrada
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_NOMBRES 50
#define MAX_LONGITUD 50
#define BUFFER_SIZE 100

// Función mejorada para limpiar el buffer de entrada
void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Función mejorada para leer cadenas de forma segura
int leer_cadena_segura(char *buffer, int size, const char *prompt) {
    printf("%s", prompt);
    
    if (fgets(buffer, size, stdin) == NULL) {
        return 0;  // Error de lectura
    }
    
    // Eliminar el salto de línea si existe
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
        len--;
    }
    
    // Verificar si la entrada está vacía
    if (len == 0) {
        return 0;
    }
    
    // Verificar si la línea fue truncada
    if (len == size - 1 && buffer[len - 1] != '\0') {
        limpiar_buffer();  // Limpiar el resto de la entrada
    }
    
    return 1;  // Éxito
}

// Función mejorada para formatear nombres
void formatear_nombre(char *nombre) {
    if (nombre == NULL || strlen(nombre) == 0) return;
    
    // Eliminar espacios al inicio y al final
    char *inicio = nombre;
    while (isspace(*inicio)) inicio++;
    
    if (*inicio == '\0') {
        strcpy(nombre, "");
        return;
    }
    
    char *final = inicio + strlen(inicio) - 1;
    while (final > inicio && isspace(*final)) final--;
    *(final + 1) = '\0';
    
    // Mover el contenido sin espacios iniciales
    if (inicio != nombre) {
        memmove(nombre, inicio, strlen(inicio) + 1);
    }
    
    // Convertir a minúsculas y capitalizar primera letra de cada palabra
    int nueva_palabra = 1;
    for (int i = 0; nombre[i] != '\0'; i++) {
        if (isalpha(nombre[i])) {
            if (nueva_palabra) {
                nombre[i] = toupper(nombre[i]);
                nueva_palabra = 0;
            } else {
                nombre[i] = tolower(nombre[i]);
            }
        } else if (isspace(nombre[i])) {
            nueva_palabra = 1;
            // Reemplazar múltiples espacios con uno solo
            if (i > 0 && isspace(nombre[i-1])) {
                memmove(&nombre[i], &nombre[i+1], strlen(&nombre[i+1]) + 1);
                i--;
            }
        }
    }
}

// Función optimizada para ordenar nombres (algoritmo más eficiente)
void ordenar_nombres(char nombres[][MAX_LONGITUD], int cantidad) {
    if (cantidad <= 1) return;
    
    // Algoritmo de ordenamiento mejorado (similar a quicksort para arrays pequeños)
    for (int i = 0; i < cantidad - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < cantidad; j++) {
            if (strcasecmp(nombres[j], nombres[min_idx]) < 0) {  // Comparación insensible a mayúsculas
                min_idx = j;
            }
        }
        if (min_idx != i) {
            char temp[MAX_LONGITUD];
            strcpy(temp, nombres[i]);
            strcpy(nombres[i], nombres[min_idx]);
            strcpy(nombres[min_idx], temp);
        }
    }
}

// Función mejorada de búsqueda con comparación insensible a mayúsculas
int buscar_nombre(char nombres[][MAX_LONGITUD], int cantidad, const char *buscar) {
    for (int i = 0; i < cantidad; i++) {
        if (strcasecmp(nombres[i], buscar) == 0) {
            return i;
        }
    }
    return -1;
}

// Nueva función para eliminar nombres
int eliminar_nombre(char nombres[][MAX_LONGITUD], int *cantidad, int posicion) {
    if (posicion < 0 || posicion >= *cantidad) {
        return 0;  // Posición inválida
    }
    
    // Mover todos los elementos hacia arriba
    for (int i = posicion; i < *cantidad - 1; i++) {
        strcpy(nombres[i], nombres[i + 1]);
    }
    
    (*cantidad)--;
    return 1;  // Éxito
}

// Función mejorada para mostrar estadísticas
void mostrar_estadisticas(char nombres[][MAX_LONGITUD], int cantidad) {
    if (cantidad == 0) {
        printf("\n⚠️  No hay nombres para analizar.\n");
        return;
    }
    
    int longitud_total = 0;
    int longitud_max = 0, longitud_min = MAX_LONGITUD;
    char nombre_mas_largo[MAX_LONGITUD] = "";
    char nombre_mas_corto[MAX_LONGITUD] = "";
    int contador_palabras = 0;
    
    for (int i = 0; i < cantidad; i++) {
        int len = strlen(nombres[i]);
        longitud_total += len;
        
        // Contar palabras en el nombre
        int palabras_en_nombre = 0;
        int en_palabra = 0;
        for (int j = 0; nombres[i][j] != '\0'; j++) {
            if (!isspace(nombres[i][j]) && !en_palabra) {
                palabras_en_nombre++;
                en_palabra = 1;
            } else if (isspace(nombres[i][j])) {
                en_palabra = 0;
            }
        }
        contador_palabras += palabras_en_nombre;
        
        if (len > longitud_max) {
            longitud_max = len;
            strcpy(nombre_mas_largo, nombres[i]);
        }
        
        if (len < longitud_min) {
            longitud_min = len;
            strcpy(nombre_mas_corto, nombres[i]);
        }
    }
    
    printf("\n📊 === ESTADÍSTICAS DETALLADAS ===\n");
    printf("📝 Total de nombres: %d\n", cantidad);
    printf("📏 Longitud promedio: %.2f caracteres\n", (float)longitud_total / cantidad);
    printf("📈 Nombre más largo: '%s' (%d caracteres)\n", nombre_mas_largo, longitud_max);
    printf("📉 Nombre más corto: '%s' (%d caracteres)\n", nombre_mas_corto, longitud_min);
    printf("🔤 Promedio de palabras por nombre: %.2f\n", (float)contador_palabras / cantidad);
    printf("📊 Capacidad utilizada: %.1f%%\n", ((float)cantidad / MAX_NOMBRES) * 100);
}

// Función para mostrar el menú
void mostrar_menu(int cantidad) {
    printf("\n🎯 === PROCESADOR DE NOMBRES ===\n");
    printf("1️⃣  Agregar nombre\n");
    printf("2️⃣  Mostrar todos los nombres\n");
    printf("3️⃣  Ordenar nombres alfabéticamente\n");
    printf("4️⃣  Buscar nombre\n");
    printf("5️⃣  Eliminar nombre\n");
    printf("6️⃣  Mostrar estadísticas\n");
    printf("7️⃣  Salir\n");
    printf("📋 Nombres actuales: %d/%d\n", cantidad, MAX_NOMBRES);
    printf("🔸 Seleccione una opción (1-7): ");
}

// Función para validar entrada numérica
int leer_opcion() {
    int opcion;
    char buffer[10];
    
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return -1;
    }
    
    if (sscanf(buffer, "%d", &opcion) != 1) {
        return -1;
    }
    
    return opcion;
}

int main() {
    char nombres[MAX_NOMBRES][MAX_LONGITUD];
    int cantidad = 0;
    int opcion;
    
    printf("🎉 ¡Bienvenido al Procesador de Nombres!\n");
    printf("📝 Puede almacenar hasta %d nombres de máximo %d caracteres cada uno.\n", 
           MAX_NOMBRES, MAX_LONGITUD - 1);
    
    do {
        mostrar_menu(cantidad);
        opcion = leer_opcion();
        
        switch (opcion) {
            case 1: {
                if (cantidad >= MAX_NOMBRES) {
                    printf("\n❌ Lista llena. No se pueden agregar más nombres.\n");
                    break;
                }
                
                char temp[BUFFER_SIZE];
                if (leer_cadena_segura(temp, sizeof(temp), "\n📝 Ingrese un nombre completo: ")) {
                    formatear_nombre(temp);
                    
                    if (strlen(temp) == 0) {
                        printf("❌ Nombre inválido. Intente nuevamente.\n");
                        break;
                    }
                    
                    // Verificar si el nombre ya existe
                    if (buscar_nombre(nombres, cantidad, temp) != -1) {
                        printf("⚠️  El nombre '%s' ya existe en la lista.\n", temp);
                        break;
                    }
                    
                    strcpy(nombres[cantidad], temp);
                    cantidad++;
                    printf("✅ Nombre '%s' agregado y formateado correctamente.\n", temp);
                } else {
                    printf("❌ Error al leer el nombre. Intente nuevamente.\n");
                }
                break;
            }
            
            case 2: {
                if (cantidad == 0) {
                    printf("\n📋 No hay nombres para mostrar.\n");
                } else {
                    printf("\n📋 === LISTA DE NOMBRES ===\n");
                    for (int i = 0; i < cantidad; i++) {
                        printf("%3d. %s\n", i + 1, nombres[i]);
                    }
                    printf("───────────────────────────────\n");
                    printf("Total: %d nombre%s\n", cantidad, cantidad != 1 ? "s" : "");
                }
                break;
            }
            
            case 3: {
                if (cantidad == 0) {
                    printf("\n📋 No hay nombres para ordenar.\n");
                } else {
                    ordenar_nombres(nombres, cantidad);
                    printf("\n✅ Nombres ordenados alfabéticamente.\n");
                }
                break;
            }
            
            case 4: {
                if (cantidad == 0) {
                    printf("\n📋 No hay nombres para buscar.\n");
                } else {
                    char buscar[MAX_LONGITUD];
                    if (leer_cadena_segura(buscar, sizeof(buscar), "\n🔍 Ingrese nombre a buscar: ")) {
                        formatear_nombre(buscar);
                        
                        int pos = buscar_nombre(nombres, cantidad, buscar);
                        if (pos != -1) {
                            printf("✅ Nombre '%s' encontrado en posición %d.\n", buscar, pos + 1);
                        } else {
                            printf("❌ Nombre '%s' no encontrado.\n", buscar);
                        }
                    } else {
                        printf("❌ Error al leer el nombre.\n");
                    }
                }
                break;
            }
            
            case 5: {
                if (cantidad == 0) {
                    printf("\n📋 No hay nombres para eliminar.\n");
                } else {
                    // Mostrar lista numerada
                    printf("\n📋 === NOMBRES DISPONIBLES ===\n");
                    for (int i = 0; i < cantidad; i++) {
                        printf("%3d. %s\n", i + 1, nombres[i]);
                    }
                    
                    printf("\n🗑️  Ingrese el número del nombre a eliminar (1-%d): ", cantidad);
                    int num_eliminar = leer_opcion();
                    
                    if (num_eliminar >= 1 && num_eliminar <= cantidad) {
                        char nombre_eliminado[MAX_LONGITUD];
                        strcpy(nombre_eliminado, nombres[num_eliminar - 1]);
                        
                        if (eliminar_nombre(nombres, &cantidad, num_eliminar - 1)) {
                            printf("✅ Nombre '%s' eliminado correctamente.\n", nombre_eliminado);
                        } else {
                            printf("❌ Error al eliminar el nombre.\n");
                        }
                    } else {
                        printf("❌ Número inválido.\n");
                    }
                }
                break;
            }
            
            case 6:
                mostrar_estadisticas(nombres, cantidad);
                break;
                
            case 7:
                printf("\n👋 ¡Gracias por usar el Procesador de Nombres!\n");
                printf("🎯 Se procesaron un total de %d nombre%s.\n", 
                       cantidad, cantidad != 1 ? "s" : "");
                break;
                
            default:
                printf("\n❌ Opción inválida. Por favor seleccione una opción del 1 al 7.\n");
        }
        
        // Pausa para que el usuario pueda leer el resultado
        if (opcion != 7 && opcion >= 1 && opcion <= 6) {
            printf("\nPresione Enter para continuar...");
            while (getchar() != '\n');
        }
        
    } while (opcion != 7);
    
    return 0;
}