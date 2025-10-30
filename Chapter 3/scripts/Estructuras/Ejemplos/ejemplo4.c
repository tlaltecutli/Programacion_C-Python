/*
Ejemplo 4 de uso de estructuras en C con múltiples variables
Autor: Tu Nombre
Fecha: 2024-06-15
Descripción: Este programa define una estructura para representar un producto, permite ingresar y mostrar sus datos utilizando
funciones y declara múltiples variables de la estructura.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Producto {
    char nombre[30];
    float precio;
    int cantidad;
} producto1, producto2, inventario[100];

void ingresarDatos(struct Producto *producto) {
    printf("Ingrese el nombre del producto: ");
    fgets(producto->nombre, sizeof(producto->nombre), stdin);
    producto->nombre[strcspn(producto->nombre, "\n")] = '\0';

    printf("Ingrese el precio del producto: ");
    scanf("%f", &producto->precio);

    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &producto->cantidad);
    getchar(); // Limpiar el buffer de entrada
}
void mostrarDatos(struct Producto producto) {
    printf("\nDatos del Producto:\n");
    printf("Nombre: %s\n", producto.nombre);
    printf("Precio: %.2f\n", producto.precio);
    printf("Cantidad: %d\n", producto.cantidad);
}
int main() {
    ingresarDatos(&producto1);
    mostrarDatos(producto1);

    return 0;
}
