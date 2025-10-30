# Estructuras en C - Guía Completa

## Índice
1. [Introducción](#introducción)
2. [Definición de Estructuras](#definición-de-estructuras)
3. [Declaración de Variables de Estructura](#declaración-de-variables-de-estructura)
4. [Inicialización de Estructuras](#inicialización-de-estructuras)
5. [Acceso a Miembros](#acceso-a-miembros)
6. [Estructuras Anidadas](#estructuras-anidadas)
7. [Arrays de Estructuras](#arrays-de-estructuras)
8. [Punteros a Estructuras](#punteros-a-estructuras)
9. [Estructuras y Funciones](#estructuras-y-funciones)
10. [Typedef con Estructuras](#typedef-con-estructuras)
11. [Uniones (Union)](#uniones-union)
12. [Enumeraciones (Enum)](#enumeraciones-enum)
13. [Ejemplos Prácticos](#ejemplos-prácticos)
14. [Mejores Prácticas](#mejores-prácticas)

---

## Introducción

Las **estructuras** en C son tipos de datos definidos por el usuario que permiten agrupar variables de diferentes tipos bajo un mismo nombre. Son fundamentales para organizar datos relacionados y crear tipos de datos más complejos.

### ¿Por qué usar estructuras?
- Agrupan datos relacionados lógicamente
- Mejoran la organización del código
- Facilitan el mantenimiento
- Permiten crear tipos de datos personalizados
- Base para la programación orientada a objetos en otros lenguajes

---

## Definición de Estructuras

### Sintaxis Básica

```c
struct nombre_estructura {
    tipo_dato miembro1;
    tipo_dato miembro2;
    // ... más miembros
};
```

### Ejemplo Básico

```c
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    char carrera[30];
};
```

### Definición con Inicialización Inmediata

```c
struct Punto {
    int x;
    int y;
} punto1, punto2;  // Se declaran variables al mismo tiempo
```

---

## Declaración de Variables de Estructura

### Declaración Después de la Definición

```c
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

// Declaración de variables
struct Estudiante estudiante1;
struct Estudiante estudiante2;
```

### Declaración Durante la Definición

```c
struct Producto {
    char nombre[30];
    float precio;
    int cantidad;
} producto1, producto2, inventario[100];
```

---

## Inicialización de Estructuras

### Inicialización en la Declaración

```c
struct Punto {
    int x;
    int y;
};

// Inicialización ordenada
struct Punto p1 = {10, 20};

// Inicialización con designadores (C99)
struct Punto p2 = {.x = 5, .y = 15};
struct Punto p3 = {.y = 25, .x = 35}; // Orden no importa
```

### Inicialización Parcial

```c
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

// Solo algunos miembros (resto se inicializa a 0)
struct Estudiante est1 = {"Juan", 20}; // promedio = 0.0
struct Estudiante est2 = {.nombre = "Ana"}; // edad = 0, promedio = 0.0
```

### Inicialización Después de la Declaración

```c
struct Estudiante estudiante;

strcpy(estudiante.nombre, "Carlos");
estudiante.edad = 22;
estudiante.promedio = 8.5;
```

---

## Acceso a Miembros

### Operador Punto (.)

```c
struct Estudiante est;

// Asignación
strcpy(est.nombre, "María");
est.edad = 21;
est.promedio = 9.2;

// Lectura
printf("Nombre: %s\n", est.nombre);
printf("Edad: %d\n", est.edad);
printf("Promedio: %.2f\n", est.promedio);
```

### Operador Flecha (->) para Punteros

```c
struct Estudiante *ptr_est;
struct Estudiante est = {"Pedro", 23, 8.8};

ptr_est = &est;

// Acceso a través de puntero
printf("Nombre: %s\n", ptr_est->nombre);
printf("Edad: %d\n", ptr_est->edad);

// Equivalente a:
printf("Nombre: %s\n", (*ptr_est).nombre);
printf("Edad: %d\n", (*ptr_est).edad);
```

---

## Estructuras Anidadas

### Definición de Estructuras Anidadas

```c
struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Persona {
    char nombre[50];
    struct Fecha nacimiento;
    struct Fecha ingreso;
};
```

### Uso de Estructuras Anidadas

```c
struct Persona empleado;

strcpy(empleado.nombre, "Ana García");
empleado.nacimiento.dia = 15;
empleado.nacimiento.mes = 3;
empleado.nacimiento.anio = 1990;

empleado.ingreso.dia = 1;
empleado.ingreso.mes = 9;
empleado.ingreso.anio = 2020;

printf("Empleado: %s\n", empleado.nombre);
printf("Nacimiento: %d/%d/%d\n", 
       empleado.nacimiento.dia,
       empleado.nacimiento.mes,
       empleado.nacimiento.anio);
```

---

## Arrays de Estructuras

### Declaración de Arrays de Estructuras

```c
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

struct Estudiante clase[30];  // Array de 30 estudiantes
```

### Inicialización de Arrays de Estructuras

```c
struct Punto puntos[] = {
    {0, 0},
    {1, 1},
    {2, 4},
    {3, 9}
};

// Con designadores
struct Estudiante grupo[] = {
    {.nombre = "Juan", .edad = 20, .promedio = 8.5},
    {.nombre = "María", .edad = 19, .promedio = 9.0},
    {.nombre = "Pedro", .edad = 21, .promedio = 7.8}
};
```

### Manipulación de Arrays de Estructuras

```c
// Llenar array de estructuras
for (int i = 0; i < 3; i++) {
    printf("Ingrese datos del estudiante %d:\n", i + 1);
    printf("Nombre: ");
    scanf("%s", grupo[i].nombre);
    printf("Edad: ");
    scanf("%d", &grupo[i].edad);
    printf("Promedio: ");
    scanf("%f", &grupo[i].promedio);
}

// Mostrar datos
for (int i = 0; i < 3; i++) {
    printf("Estudiante %d: %s, %d años, promedio: %.2f\n",
           i + 1, grupo[i].nombre, grupo[i].edad, grupo[i].promedio);
}
```

---

## Punteros a Estructuras

### Declaración y Uso Básico

```c
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

struct Estudiante est = {"Carlos", 22, 8.7};
struct Estudiante *ptr = &est;

// Acceso a miembros
printf("Nombre: %s\n", ptr->nombre);
printf("Edad: %d\n", ptr->edad);
printf("Promedio: %.2f\n", ptr->promedio);
```

### Asignación Dinámica de Memoria

```c
#include <stdlib.h>

struct Estudiante *crear_estudiante(char *nombre, int edad, float promedio) {
    struct Estudiante *nuevo = malloc(sizeof(struct Estudiante));
    
    if (nuevo != NULL) {
        strcpy(nuevo->nombre, nombre);
        nuevo->edad = edad;
        nuevo->promedio = promedio;
    }
    
    return nuevo;
}

// Uso
struct Estudiante *est_ptr = crear_estudiante("Ana", 20, 9.1);
if (est_ptr != NULL) {
    printf("Estudiante creado: %s\n", est_ptr->nombre);
    free(est_ptr);  // Liberar memoria
}
```

---

## Estructuras y Funciones

### Pasar Estructuras por Valor

```c
void mostrar_estudiante(struct Estudiante est) {
    printf("Nombre: %s\n", est.nombre);
    printf("Edad: %d\n", est.edad);
    printf("Promedio: %.2f\n", est.promedio);
}

// Uso
struct Estudiante estudiante = {"Luis", 23, 8.9};
mostrar_estudiante(estudiante);  // Se copia toda la estructura
```

### Pasar Estructuras por Referencia

```c
void modificar_promedio(struct Estudiante *est, float nuevo_promedio) {
    est->promedio = nuevo_promedio;
}

void mostrar_estudiante_ref(const struct Estudiante *est) {
    printf("Nombre: %s\n", est->nombre);
    printf("Edad: %d\n", est->edad);
    printf("Promedio: %.2f\n", est->promedio);
}

// Uso
struct Estudiante estudiante = {"Carmen", 21, 7.5};
modificar_promedio(&estudiante, 8.2);
mostrar_estudiante_ref(&estudiante);
```

### Funciones que Retornan Estructuras

```c
struct Punto crear_punto(int x, int y) {
    struct Punto p;
    p.x = x;
    p.y = y;
    return p;
}

struct Punto sumar_puntos(struct Punto p1, struct Punto p2) {
    struct Punto resultado;
    resultado.x = p1.x + p2.x;
    resultado.y = p1.y + p2.y;
    return resultado;
}

// Uso
struct Punto p1 = crear_punto(3, 4);
struct Punto p2 = crear_punto(1, 2);
struct Punto suma = sumar_puntos(p1, p2);
printf("Suma: (%d, %d)\n", suma.x, suma.y);
```

---

## Typedef con Estructuras

### Uso Básico de typedef

```c
typedef struct {
    char nombre[50];
    int edad;
    float promedio;
} Estudiante;

// Ahora se puede usar directamente
Estudiante est1;
Estudiante clase[30];
Estudiante *ptr_est;
```

### typedef con Nombre de Estructura

```c
typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;  // Necesario para estructuras autoreferenciadas
} Nodo;

// Uso
Nodo *cabeza = NULL;
```

### Comparación: Con y Sin typedef

```c
// Sin typedef
struct Estudiante est1;
struct Estudiante *ptr1;

// Con typedef
typedef struct {
    char nombre[50];
    int edad;
} Estudiante;

Estudiante est2;      // Más limpio
Estudiante *ptr2;     // Más legible
```

---

## Uniones (Union)

### Definición y Uso de Uniones

```c
union Valor {
    int entero;
    float flotante;
    char caracter;
};

union Valor v;
v.entero = 42;
printf("Entero: %d\n", v.entero);

v.flotante = 3.14f;
printf("Flotante: %.2f\n", v.flotante);
// Nota: v.entero ya no es válido
```

### Uniones con Estructuras

```c
struct TipoDato {
    enum { ENTERO, FLOTANTE, CADENA } tipo;
    union {
        int i;
        float f;
        char s[50];
    } valor;
};

struct TipoDato dato;
dato.tipo = FLOTANTE;
dato.valor.f = 2.718f;

switch (dato.tipo) {
    case ENTERO:
        printf("Entero: %d\n", dato.valor.i);
        break;
    case FLOTANTE:
        printf("Flotante: %.3f\n", dato.valor.f);
        break;
    case CADENA:
        printf("Cadena: %s\n", dato.valor.s);
        break;
}
```

---

## Enumeraciones (Enum)

### Definición Básica

```c
enum DiaSemana {
    LUNES,      // 0
    MARTES,     // 1
    MIERCOLES,  // 2
    JUEVES,     // 3
    VIERNES,    // 4
    SABADO,     // 5
    DOMINGO     // 6
};

enum DiaSemana hoy = VIERNES;
printf("Hoy es el día %d\n", hoy);  // Imprime: 5
```

### Enumeraciones con Valores Personalizados

```c
enum Estado {
    INACTIVO = 0,
    ACTIVO = 1,
    SUSPENDIDO = 2,
    ERROR = -1
};

enum Prioridad {
    BAJA = 1,
    MEDIA = 5,
    ALTA = 10,
    CRITICA = 20
};
```

### Uso con Estructuras

```c
enum TipoEmpleado {
    TEMPORAL,
    PERMANENTE,
    CONTRATISTA
};

struct Empleado {
    char nombre[50];
    enum TipoEmpleado tipo;
    float salario;
};

struct Empleado emp = {"Juan Pérez", PERMANENTE, 50000.0f};

switch (emp.tipo) {
    case TEMPORAL:
        printf("Empleado temporal\n");
        break;
    case PERMANENTE:
        printf("Empleado permanente\n");
        break;
    case CONTRATISTA:
        printf("Contratista\n");
        break;
}
```

---

## Ejemplos Prácticos

### Sistema de Gestión de Biblioteca

```c
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
```

### Sistema de Coordenadas y Geometría

```c
#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y;
} Punto;

typedef struct {
    Punto centro;
    double radio;
} Circulo;

typedef struct {
    Punto vertices[4];
} Rectangulo;

double distancia_puntos(Punto p1, Punto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double area_circulo(Circulo c) {
    return M_PI * c.radio * c.radio;
}

int punto_en_circulo(Punto p, Circulo c) {
    return distancia_puntos(p, c.centro) <= c.radio;
}

Punto centroide_rectangulo(Rectangulo r) {
    Punto centroide;
    centroide.x = (r.vertices[0].x + r.vertices[2].x) / 2.0;
    centroide.y = (r.vertices[0].y + r.vertices[2].y) / 2.0;
    return centroide;
}
```

### Sistema de Inventario

```c
#include <stdio.h>
#include <string.h>

typedef enum {
    ELECTRONICO,
    ROPA,
    ALIMENTO,
    LIBRO,
    OTRO
} Categoria;

typedef struct {
    char codigo[10];
    char nombre[50];
    Categoria categoria;
    double precio;
    int stock;
    double descuento;  // Porcentaje de descuento
} Producto;

typedef struct {
    Producto productos[500];
    int cantidad;
} Inventario;

double precio_con_descuento(Producto *p) {
    return p->precio * (1.0 - p->descuento / 100.0);
}

void mostrar_producto(Producto *p) {
    char *categorias[] = {"Electrónico", "Ropa", "Alimento", "Libro", "Otro"};
    
    printf("Código: %s\n", p->codigo);
    printf("Nombre: %s\n", p->nombre);
    printf("Categoría: %s\n", categorias[p->categoria]);
    printf("Precio: $%.2f", p->precio);
    if (p->descuento > 0) {
        printf(" (Con descuento: $%.2f)", precio_con_descuento(p));
    }
    printf("\nStock: %d\n", p->stock);
    printf("------------------------\n");
}

void productos_por_categoria(Inventario *inv, Categoria cat) {
    printf("Productos en la categoría:\n");
    for (int i = 0; i < inv->cantidad; i++) {
        if (inv->productos[i].categoria == cat) {
            mostrar_producto(&inv->productos[i]);
        }
    }
}
```

---

## Mejores Prácticas

### Organización y Legibilidad

1. **Use nombres descriptivos**:
```c
// Mal
struct s {
    int x;
    char n[20];
};

// Bien
struct Estudiante {
    int edad;
    char nombre[50];
};
```

2. **Agrupe datos relacionados lógicamente**:
```c
struct Empleado {
    // Información personal
    char nombre[50];
    char apellido[50];
    int edad;
    
    // Información laboral
    char puesto[30];
    double salario;
    int anios_servicio;
    
    // Información de contacto
    char telefono[15];
    char email[50];
};
```

3. **Use typedef para simplificar**:
```c
typedef struct {
    double x, y, z;
} Vector3D;

// En lugar de repetir "struct Vector3D"
Vector3D v1, v2, resultado;
```

### Eficiencia y Rendimiento

1. **Considere el tamaño de las estructuras**:
```c
// Alineación de memoria - orden importa
struct Ineficiente {
    char c1;     // 1 byte + 3 bytes padding
    int i;       // 4 bytes
    char c2;     // 1 byte + 3 bytes padding
};  // Total: 12 bytes

struct Eficiente {
    int i;       // 4 bytes
    char c1;     // 1 byte
    char c2;     // 1 byte + 2 bytes padding
};  // Total: 8 bytes
```

2. **Use const para parámetros de solo lectura**:
```c
void mostrar_punto(const Punto *p) {
    printf("(%f, %f)\n", p->x, p->y);
    // p->x = 10;  // Error de compilación - buena práctica
}
```

3. **Pase estructuras grandes por referencia**:
```c
// Ineficiente para estructuras grandes
void procesar_datos(struct GranEstructura datos) { /* ... */ }

// Eficiente
void procesar_datos(const struct GranEstructura *datos) { /* ... */ }
```

### Manejo de Memoria

1. **Siempre verifique malloc**:
```c
Estudiante *crear_estudiante() {
    Estudiante *est = malloc(sizeof(Estudiante));
    if (est == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria\n");
        return NULL;
    }
    return est;
}
```

2. **Libere la memoria asignada**:
```c
void cleanup_estudiantes(Estudiante **estudiantes, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        free(estudiantes[i]);
    }
    free(estudiantes);
}
```

### Documentación

```c
/**
 * Estructura que representa un punto en el espacio 2D
 * @param x Coordenada horizontal
 * @param y Coordenada vertical
 */
typedef struct {
    double x;  ///< Coordenada X
    double y;  ///< Coordenada Y
} Punto;

/**
 * Calcula la distancia entre dos puntos
 * @param p1 Primer punto
 * @param p2 Segundo punto
 * @return Distancia euclidiana entre los puntos
 */
double distancia(const Punto *p1, const Punto *p2);
```

---

## Conclusión

Las estructuras en C son una herramienta fundamental que permite:

- **Organizar datos relacionados** de manera lógica y eficiente
- **Crear tipos de datos personalizados** adaptados a las necesidades específicas
- **Mejorar la legibilidad y mantenibilidad** del código
- **Facilitar la programación modular** y el desarrollo de sistemas complejos

Al dominar las estructuras, junto con las uniones y enumeraciones, tendrás las bases para crear programas más organizados, eficientes y fáciles de mantener. Las estructuras son el fundamento de muchos conceptos avanzados en programación y son esenciales para el desarrollo de aplicaciones robustas en C.

---

*Este documento proporciona una guía completa sobre el uso de estructuras en C. Para profundizar más, se recomienda practicar con proyectos reales que requieran organización compleja de datos.*