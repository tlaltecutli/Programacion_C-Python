/*
Ejercicio 2: Sistema de Inventario con Matrices (Versión Optimizada)
Desarrolla un programa en C que gestione el inventario de productos en varias 
sucursales de una tienda. Utiliza una matriz para almacenar la cantidad de cada 
producto en cada sucursal.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PRODUCTOS 10
#define MAX_SUCURSALES 5
#define MAX_NOMBRE 50

typedef struct {
    char nombre[MAX_NOMBRE];
    int codigo;
} Producto;

// Función para limpiar el buffer de entrada
void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Función para convertir string a minúsculas
void a_minusculas(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Función para mostrar el inventario completo
void mostrar_inventario(int inventario[][MAX_SUCURSALES], Producto productos[], 
                       int num_productos, int num_sucursales) {
    printf("\n=================== INVENTARIO ACTUAL ===================\n");
    printf("%-20s", "Producto");
    
    for (int j = 0; j < num_sucursales; j++) {
        printf("Suc%-4d", j + 1);
    }
    printf("Total\n");
    
    // Línea separadora
    printf("%-20s", "--------------------");
    for (int j = 0; j < num_sucursales; j++) {
        printf("-------");
    }
    printf("-------\n");
    
    // Mostrar datos de cada producto
    for (int i = 0; i < num_productos; i++) {
        printf("%-20s", productos[i].nombre);
        int total_producto = 0;
        
        for (int j = 0; j < num_sucursales; j++) {
            printf("%-7d", inventario[i][j]);
            total_producto += inventario[i][j];
        }
        printf("%-7d\n", total_producto);
    }
    
    // Línea separadora
    printf("%-20s", "--------------------");
    for (int j = 0; j < num_sucursales; j++) {
        printf("-------");
    }
    printf("-------\n");
    
    // Totales por sucursal
    printf("%-20s", "TOTAL SUCURSAL:");
    int gran_total = 0;
    
    for (int j = 0; j < num_sucursales; j++) {
        int total_sucursal = 0;
        for (int i = 0; i < num_productos; i++) {
            total_sucursal += inventario[i][j];
        }
        printf("%-7d", total_sucursal);
        gran_total += total_sucursal;
    }
    printf("%-7d\n", gran_total);
    printf("=========================================================\n");
}

// Función para buscar un producto específico
int buscar_producto_por_nombre(int inventario[][MAX_SUCURSALES], 
                              Producto productos[], int num_productos, 
                              int num_sucursales) {
    char buscar[MAX_NOMBRE];
    char nombre_temp[MAX_NOMBRE];
    
    printf("\nIngrese nombre del producto a buscar: ");
    fgets(buscar, sizeof(buscar), stdin);
    
    // Eliminar salto de línea si existe
    if (buscar[strlen(buscar) - 1] == '\n') {
        buscar[strlen(buscar) - 1] = '\0';
    }
    
    a_minusculas(buscar);
    
    for (int i = 0; i < num_productos; i++) {
        strcpy(nombre_temp, productos[i].nombre);
        a_minusculas(nombre_temp);
        
        if (strstr(nombre_temp, buscar) != NULL) {
            printf("\n--- Producto encontrado ---\n");
            printf("Nombre: %s\n", productos[i].nombre);
            printf("Código: %d\n", productos[i].codigo);
            printf("\nStock por sucursal:\n");
            
            int total_producto = 0;
            for (int j = 0; j < num_sucursales; j++) {
                printf("  Sucursal %d: %d unidades\n", j + 1, inventario[i][j]);
                total_producto += inventario[i][j];
            }
            printf("  Total: %d unidades\n", total_producto);
            return i; // Retorna el índice del producto encontrado
        }
    }
    
    printf("❌ Producto no encontrado.\n");
    return -1;
}

// Función para mostrar lista de productos disponibles
void mostrar_productos(Producto productos[], int num_productos) {
    printf("\n--- Productos disponibles ---\n");
    for (int i = 0; i < num_productos; i++) {
        printf("%d. %s (Código: %d)\n", i, productos[i].nombre, productos[i].codigo);
    }
}

// Función para validar entrada numérica
int obtener_numero(const char* mensaje, int min, int max) {
    int numero;
    char input[100];
    
    while (1) {
        printf("%s", mensaje);
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, "%d", &numero) == 1) {
                if (numero >= min && numero <= max) {
                    return numero;
                } else {
                    printf("❌ Error: El número debe estar entre %d y %d.\n", min, max);
                }
            } else {
                printf("❌ Error: Por favor ingrese un número válido.\n");
            }
        }
    }
}

// Función para transferir stock entre sucursales
void transferir_stock(int inventario[][MAX_SUCURSALES], Producto productos[], 
                     int num_productos, int num_sucursales) {
    printf("\n========== TRANSFERIR STOCK ==========\n");
    
    mostrar_productos(productos, num_productos);
    
    int producto = obtener_numero("Seleccione producto (número): ", 0, num_productos - 1);
    
    printf("\nProducto seleccionado: %s\n", productos[producto].nombre);
    printf("Stock actual por sucursal:\n");
    for (int j = 0; j < num_sucursales; j++) {
        printf("  Sucursal %d: %d unidades\n", j + 1, inventario[producto][j]);
    }
    
    int origen = obtener_numero("Sucursal origen (1-5): ", 1, num_sucursales) - 1;
    
    if (inventario[producto][origen] == 0) {
        printf("❌ Error: La sucursal origen no tiene stock de este producto.\n");
        return;
    }
    
    int destino = obtener_numero("Sucursal destino (1-5): ", 1, num_sucursales) - 1;
    
    if (origen == destino) {
        printf("❌ Error: Las sucursales origen y destino deben ser diferentes.\n");
        return;
    }
    
    printf("Stock disponible en sucursal %d: %d unidades\n", 
           origen + 1, inventario[producto][origen]);
    
    int cantidad = obtener_numero("Cantidad a transferir: ", 1, inventario[producto][origen]);
    
    // Realizar la transferencia
    inventario[producto][origen] -= cantidad;
    inventario[producto][destino] += cantidad;
    
    printf("\n✅ Transferencia realizada exitosamente!\n");
    printf("📦 %d unidades de '%s' transferidas de Sucursal %d a Sucursal %d\n",
           cantidad, productos[producto].nombre, origen + 1, destino + 1);
    
    printf("\nStock actualizado:\n");
    printf("  Sucursal %d: %d unidades\n", origen + 1, inventario[producto][origen]);
    printf("  Sucursal %d: %d unidades\n", destino + 1, inventario[producto][destino]);
}

// Función para mostrar estadísticas del inventario
void mostrar_estadisticas(int inventario[][MAX_SUCURSALES], Producto productos[], 
                         int num_productos, int num_sucursales) {
    printf("\n=============== ESTADÍSTICAS ===============\n");
    
    // Producto con mayor stock
    int max_stock = 0, producto_max = 0;
    int min_stock = __INT_MAX__, producto_min = 0;
    
    for (int i = 0; i < num_productos; i++) {
        int total = 0;
        for (int j = 0; j < num_sucursales; j++) {
            total += inventario[i][j];
        }
        
        if (total > max_stock) {
            max_stock = total;
            producto_max = i;
        }
        
        if (total < min_stock) {
            min_stock = total;
            producto_min = i;
        }
    }
    
    printf("📈 Producto con mayor stock: %s (%d unidades)\n", 
           productos[producto_max].nombre, max_stock);
    printf("📉 Producto con menor stock: %s (%d unidades)\n", 
           productos[producto_min].nombre, min_stock);
    
    // Sucursal con mayor stock
    int max_sucursal_stock = 0, sucursal_max = 0;
    int min_sucursal_stock = __INT_MAX__, sucursal_min = 0;
    
    for (int j = 0; j < num_sucursales; j++) {
        int total = 0;
        for (int i = 0; i < num_productos; i++) {
            total += inventario[i][j];
        }
        
        if (total > max_sucursal_stock) {
            max_sucursal_stock = total;
            sucursal_max = j;
        }
        
        if (total < min_sucursal_stock) {
            min_sucursal_stock = total;
            sucursal_min = j;
        }
    }
    
    printf("🏢 Sucursal con mayor stock: Sucursal %d (%d unidades)\n", 
           sucursal_max + 1, max_sucursal_stock);
    printf("🏪 Sucursal con menor stock: Sucursal %d (%d unidades)\n", 
           sucursal_min + 1, min_sucursal_stock);
    
    // Total general
    int total_general = 0;
    for (int i = 0; i < num_productos; i++) {
        for (int j = 0; j < num_sucursales; j++) {
            total_general += inventario[i][j];
        }
    }
    
    printf("📊 Total general del inventario: %d unidades\n", total_general);
    printf("============================================\n");
}

int main() {
    // Datos iniciales del inventario
    int inventario[MAX_PRODUCTOS][MAX_SUCURSALES] = {
        {100, 150, 200, 80, 120},   // Laptop
        {50, 75, 100, 25, 60},      // Mouse
        {200, 180, 220, 160, 190},  // Teclado
        {30, 45, 60, 15, 35},       // Monitor
        {80, 95, 110, 70, 85}       // Impresora
    };
    
    Producto productos[MAX_PRODUCTOS] = {
        {"Laptop", 1001},
        {"Mouse", 1002},
        {"Teclado", 1003},
        {"Monitor", 1004},
        {"Impresora", 1005}
    };
    
    int num_productos = 5;
    int num_sucursales = 5;
    int opcion;
    
    printf("🏪 Bienvenido al Sistema de Inventario\n");
    printf("=====================================\n");
    
    do {
        printf("\n========= MENÚ PRINCIPAL =========\n");
        printf("1. 📋 Mostrar inventario completo\n");
        printf("2. 🔍 Buscar producto\n");
        printf("3. 🔄 Transferir stock entre sucursales\n");
        printf("4. 📊 Mostrar estadísticas\n");
        printf("5. 🚪 Salir\n");
        printf("=================================\n");
        
        opcion = obtener_numero("Seleccione una opción (1-5): ", 1, 5);
        
        switch (opcion) {
            case 1:
                mostrar_inventario(inventario, productos, num_productos, num_sucursales);
                break;
            case 2:
                buscar_producto_por_nombre(inventario, productos, num_productos, num_sucursales);
                break;
            case 3:
                transferir_stock(inventario, productos, num_productos, num_sucursales);
                break;
            case 4:
                mostrar_estadisticas(inventario, productos, num_productos, num_sucursales);
                break;
            case 5:
                printf("\n👋 ¡Gracias por usar el Sistema de Inventario!\n");
                printf("¡Hasta luego!\n");
                break;
        }
        
        if (opcion != 5) {
            printf("\nPresione Enter para continuar...");
            getchar();
        }
        
    } while (opcion != 5);
    
    return 0;
}