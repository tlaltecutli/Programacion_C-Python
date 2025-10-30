/*
    Sistema de Gestión de Biblioteca
    Autor: Tu Nombre
    Fecha: 2024-06-15
    Descripción: Implementación de estructuras para gestionar una biblioteca.    
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int dia, mes, anio;
} Fecha;

typedef struct {
    char isbn[20];
    char titulo[100];
    char autor[50];
    Fecha fecha_publicacion;
    int disponible;  // 1 = disponible, 0 = prestado
} Libro;

typedef struct {
    Libro libros[1000];
    int cantidad;
} Biblioteca;

void agregar_libro(Biblioteca *bib, char *isbn, char *titulo, char *autor, 
                   int dia, int mes, int anio) {
    if (bib->cantidad < 1000) {
        strcpy(bib->libros[bib->cantidad].isbn, isbn);
        strcpy(bib->libros[bib->cantidad].titulo, titulo);
        strcpy(bib->libros[bib->cantidad].autor, autor);
        bib->libros[bib->cantidad].fecha_publicacion.dia = dia;
        bib->libros[bib->cantidad].fecha_publicacion.mes = mes;
        bib->libros[bib->cantidad].fecha_publicacion.anio = anio;
        bib->libros[bib->cantidad].disponible = 1;
        bib->cantidad++;
    }
}

void buscar_libro(Biblioteca *bib, char *titulo) {
    for (int i = 0; i < bib->cantidad; i++) {
        if (strstr(bib->libros[i].titulo, titulo) != NULL) {
            printf("Encontrado: %s por %s (%s)\n",
                   bib->libros[i].titulo,
                   bib->libros[i].autor,
                   bib->libros[i].disponible ? "Disponible" : "Prestado");
        }
    }
}