# Guía Completa: Punteros y Manejo de Memoria en C

---

## Índice

- [Guía Completa: Punteros y Manejo de Memoria en C](#guía-completa-punteros-y-manejo-de-memoria-en-c)
  - [Índice](#índice)
  - [Introducción](#introducción)
  - [1. Conceptos Básicos de Punteros](#1-conceptos-básicos-de-punteros)
    - [¿Qué es un puntero?](#qué-es-un-puntero)
    - [¿Por qué usar punteros?](#por-qué-usar-punteros)
    - [Conceptos clave](#conceptos-clave)
  - [2. Declaración e Inicialización de Punteros](#2-declaración-e-inicialización-de-punteros)
  - [3. Operadores de Dirección y de Referencia](#3-operadores-de-dirección-y-de-referencia)
  - [4. Punteros y Arreglos](#4-punteros-y-arreglos)
  - [5. Memoria Dinámica](#5-memoria-dinámica)
    - [Ejemplo completo: Arreglo dinámico de cadenas](#ejemplo-completo-arreglo-dinámico-de-cadenas)
  - [6. Punteros Void](#6-punteros-void)
    - [Características de void\*](#características-de-void)
    - [Ejemplo básico](#ejemplo-básico)
  - [7. Punteros a Funciones](#7-punteros-a-funciones)
  - [8. Punteros a Punteros](#8-punteros-a-punteros)
  - [9. Punteros Constantes y Constantes a Punteros](#9-punteros-constantes-y-constantes-a-punteros)
  - [10. Estructuras y Punteros](#10-estructuras-y-punteros)
  - [11. Errores Comunes y Depuración](#11-errores-comunes-y-depuración)
  - [12. Mejores Prácticas](#12-mejores-prácticas)
  - [13. Ejercicios Propuestos](#13-ejercicios-propuestos)
  - [14. Diagramas Visuales](#14-diagramas-visuales)
  - [15. Casos de Uso Avanzados](#15-casos-de-uso-avanzados)

---

## Introducción

Los punteros son una de las características más poderosas del lenguaje C. Esta guía completa te llevará desde los conceptos básicos hasta el uso avanzado de punteros, con ejemplos prácticos, diagramas visuales y ejercicios.

**¿Para quién es esta guía?**

- Estudiantes de programación
- Programadores que necesitan refrescar conceptos
- Desarrolladores interesados en programación de sistemas
- Cualquier persona interesada en programación de sistemas

**¿Qué aprenderás?**

- Fundamentos de punteros y direcciones de memoria
- Gestión de memoria dinámica (malloc, calloc, realloc, free)
- Estructuras de datos con punteros (listas, árboles)
- Depuración de errores comunes con punteros
- Mejores prácticas y patrones de código seguro

---

## 1. Conceptos Básicos de Punteros

### ¿Qué es un puntero?

Un **puntero** es una variable que almacena la dirección de memoria de otra variable. En lugar de contener un valor directo (como `5` o `'A'`), contiene la ubicación en memoria donde se encuentra ese valor.

**Analogía**: Piensa en la memoria de la computadora como un edificio de apartamentos. Cada apartamento tiene una dirección única. Un puntero es como una nota que contiene la dirección de un apartamento específico, en lugar de ser el apartamento mismo.

**Tamaño de los punteros:**

- 4 bytes en sistemas de **32 bits**
- 8 bytes en sistemas de **64 bits**

```c
#include <stdio.h>

int main() {
    printf("Tamaño de puntero: %zu bytes\n", sizeof(void*));
    // En sistema de 64 bits: 8 bytes
    // En sistema de 32 bits: 4 bytes
    return 0;
}
```

### ¿Por qué usar punteros?

1. **Eficiencia**: Permiten pasar grandes estructuras de datos a funciones sin copiarlas
2. **Flexibilidad**: Habilitan la creación de estructuras de datos dinámicas (listas enlazadas, árboles, grafos)
3. **Manipulación directa**: Dan acceso directo a la memoria del sistema
4. **Retorno múltiple**: Permiten que una función modifique múltiples variables
5. **Interfaz con hardware**: Útiles en programación embebida para acceder a registros de memoria
6. **Gestión de memoria**: Control preciso sobre cuándo y cómo se asigna y libera memoria
7. **Implementación de callbacks**: Permiten pasar funciones como argumentos

### Conceptos clave

- **Dirección de memoria**: Ubicación única en la memoria RAM donde se almacena un dato (representada en hexadecimal, e.g., `0x7fff5fbff8a4`)
- de Referenciación: Acceder al valor almacenado en la dirección que apunta un puntero usando el operador `*`
- Puntero nulo (NULL): Puntero que no apunta a ninguna dirección válida (valor `0`).  Usarlo evita accesos a memoria inválida
- Puntero salvaje (wild pointer): Puntero no inicializado que apunta a una dirección aleatoria, causando comportamientos indefinidos
- Puntero colgante (dangling pointer): Puntero que apunta a memoria que ha sido liberada o ya no es válida
- Fuga de memoria (memory leak): Memoria asignada dinámicamente que nunca se libera

**Representación visual de memoria**

Memoria RAM:
┌─────────────┬──────────┐
│  Dirección  │  Valor   │
├─────────────┼──────────┤
│  0x1000     │    42    │ ← Variable entera
│  0x1004     │  0x1000  │ ← Puntero (apunta a 0x1000)
│  0x1008     │    'A'   │ ← Variable char
│  0x100C     │   NULL   │ ← Puntero nulo
└─────────────┴──────────┘

---

## 2. Declaración e Inicialización de Punteros

Sintaxis de declaración

```c
tipo *nombre_puntero;
```

El asterisco `*` indica que es un puntero. El tipo especifica el tipo de dato al que apunta.

Ejemplos de declaración

```c
int *ptr_entero;        // Puntero a entero
char *ptr_caracter;     // Puntero a caracter
float *ptr_flotante;    // Puntero a flotante
double *ptr_doble;      // Puntero a double
void *ptr_generico;     // Puntero genérico

// Múltiples declaraciones (¡cuidado con la sintaxis!)
int *p1, *p2;           // Correcto: ambos son punteros
int* p3, p4;            // ¡Cuidado! p3 es puntero, p4 es int normal

// Para evitar confusión, declara en líneas separadas:
int *p5;
int *p6;
```

> **Nota importante**: La posición del asterisco es cuestión de estilo. `int *ptr`, `int* ptr` y `int * ptr` son equivalentes, pero `int *p1, *p2;` es diferente de `int* p1, p2;`

Inicialización de punteros

1. Inicialización a NULL (recomendado para evitar punteros salvajes):

```c
int *ptr = NULL;  // Forma estándar
int *ptr = 0;     // También válido
int *ptr = (void*)0;  // Definición común de NULL
```

2. Inicialización con dirección de variable:

```c
int numero = 42;
int *ptr = &numero;
```

3. Inicialización con memoria dinámica:

```c
int *ptr = (int *)malloc(sizeof(int));
if (ptr != NULL) {
    *ptr = 100;  // Asignar valor
}
```

> ⚠️ Advertencia crítica: No inicializar un puntero puede llevar a errores graves y comportamientos impredecibles. Siempre inicialízalos a NULL o a una dirección válida.

Ejemplo completo de uso básico

```c
#include <stdio.h>

int main() {
    int valor = 100;
    int *ptr = &valor;  // ptr apunta a valor
    
    printf("=== Información sobre la variable ===\n");
    printf("Valor de 'valor': %d\n", valor);
    printf("Dirección de 'valor': %p\n", (void*)&valor);
    
    printf("\n=== Información sobre el puntero ===\n");
    printf("Contenido de 'ptr' (dirección): %p\n", (void*)ptr);
    printf("Valor apuntado por ptr: %d\n", *ptr);
    printf("Dirección de 'ptr' mismo: %p\n", (void*)&ptr);
    
    printf("\n=== Modificación a través del puntero ===\n");
    *ptr = 200;  // Modifica valor a través del puntero
    printf("Nuevo valor de 'valor': %d\n", valor);
    printf("Nuevo valor apuntado por ptr: %d\n", *ptr);
    
    return 0;
}
```

Salida ejemplo:

=== Información sobre la variable ===
Valor de 'valor': 100
Dirección de 'valor': 0x7ffd5c8e4a3c

=== Información sobre el puntero ===
Contenido de 'ptr' (dirección): 0x7ffd5c8e4a3c
Valor apuntado por ptr: 100
Dirección de 'ptr' mismo: 0x7ffd5c8e4a40

=== Modificación a través del puntero ===
Nuevo valor de 'valor': 200
Nuevo valor apuntado por ptr: 200

Buenas prácticas de inicialización

```c
// ✅ CORRECTO: Inicializar a NULL
int *ptr = NULL;

// ✅ CORRECTO: Inicializar con dirección válida
int x = 10;
int *ptr = &x;

// ❌ INCORRECTO: Puntero no inicializado (puntero salvaje)
int *ptr;  // Apunta a dirección aleatoria
*ptr = 10; // ¡PELIGRO! Comportamiento indefinido

// ✅ CORRECTO: Verificar antes de usar
if (ptr != NULL) {
    *ptr = 20;
}
```

---

## 3. Operadores de Dirección y de Referencia

Operador `&` (dirección de)
Devuelve la dirección de memoria de una variable.

```c
int numero = 10;
int *ptr = &numero;  // ptr ahora contiene la dirección de numero

printf("Valor de numero: %d\n", numero);          // 10
printf("Dirección de numero: %p\n", (void*)&numero);  // 0x...
printf("Contenido de ptr: %p\n", (void*)ptr);     // 0x... (misma dirección)
```

Visualización:

numero: [10] ← dirección: 0x1000
           ↑
           |
ptr: [0x1000] ← &numero da esta dirección

Operador `*` (de referencia)
El operador `*` accede al valor almacenado en la dirección que apunta el puntero.

```c
int numero = 10;
int *ptr = &numero;

int valor = *ptr;  // valor = 10 (lee el valor apuntado)
*ptr = 20;         // Cambia numero a 20 (escribe en la dirección apuntada)

printf("numero ahora es: %d\n", numero);  // 20
```

> Nota crítica: La `de referencia` de un puntero inválido (NULL o dangling) causa un segmentation fault y termina el programa abruptamente.

Operador * en contextos diferentes

```c
int x = 10;

// Contexto 1: Declaración (indica que es un puntero)
int *ptr;

// Contexto 2: Inicialización
ptr = &x;

// Contexto 3: Dereferencia (acceso al valor)
int y = *ptr;  // Lee el valor
*ptr = 20;     // Escribe el valor
```

Ejemplo práctico: Intercambio de valores
Este ejemplo demuestra el paso por referencia para modificar variables.

```c
#include <stdio.h>

void intercambiar(int *a, int *b) {
    int temp = *a;  // Guarda el valor apuntado por a
    *a = *b;        // Copia el valor de b a la posición de a
    *b = temp;      // Copia el valor guardado a la posición de b
}

int main() {
    int x = 5, y = 10;
    
    printf("Antes del intercambio:\n");
    printf("x = %d, y = %d\n", x, y);
    
    // Pasamos las DIRECCIONES de x e y
    intercambiar(&x, &y);
    
    printf("\nDespués del intercambio:\n");
    printf("x = %d, y = %d\n", x, y);  // x = 10, y = 5
    
    return 0;
}
```

Visualización del proceso:
Antes:
x: [5]  y: [10]
    ↑       ↑
    a       b (punteros en la función)

Durante (temp = *a):
temp: [5]

Durante (*a = *b):
x: [10]  y: [10]

Durante (*b = temp):
x: [10]  y: [5]


Ejemplo adicional: Modificar múltiples valores

```c
#include <stdio.h>
#include <math.h>

void calcular_circulo(double radio, double *area, double *perimetro) {
    const double PI = 3.14159265359;
    *area = PI * radio * radio;
    *perimetro = 2 * PI * radio;
}

int main() {
    double r = 5.0;
    double a, p;  // No necesitan inicialización previa
    
    calcular_circulo(r, &a, &p);
    
    printf("Radio: %.2f\n", r);
    printf("Área: %.2f\n", a);
    printf("Perímetro: %.2f\n", p);
    
    return 0;
}
```

Salida:
Radio: 5.00
Área: 78.54
Perímetro: 31.42

Diferencia entre paso por valor y paso por referencia

```c
#include <stdio.h>

// Paso por VALOR: no modifica la variable original
void incrementar_valor(int x) {
    x = x + 1;  // Solo modifica la copia local
}

// Paso por REFERENCIA: modifica la variable original
void incrementar_referencia(int *x) {
    *x = *x + 1;  // Modifica el valor en la dirección apuntada
}

int main() {
    int numero = 10;
    
    printf("Valor inicial: %d\n", numero);  // 10
    
    incrementar_valor(numero);
    printf("Después de paso por valor: %d\n", numero);  // 10 (sin cambios)
    
    incrementar_referencia(&numero);
    printf("Después de paso por referencia: %d\n", numero);  // 11 (modificado)
    
    return 0;
}
```

---

## 4. Punteros y Arreglos

En C, el nombre de un arreglo es un puntero constante al primer elemento. Los arreglos y punteros son intercambiables en muchos contextos.

Relación entre arreglos y punteros

```c
int arr[5] = {10, 20, 30, 40, 50};
int *ptr = arr;  // Equivalente a: int *ptr = &arr[0];

printf("arr: %p\n", (void*)arr);
printf("&arr[0]: %p\n", (void*)&arr[0]);
printf("ptr: %p\n", (void*)ptr);
// Todas imprimen la misma dirección
```

**Aritmética de punteros**
La aritmética avanza en múltiplos del tamaño del tipo. Si tienes un `int*` y haces `ptr + 1`, avanza `sizeof(int)` bytes (generalmente 4 bytes).

```c
int arr[5] = {10, 20, 30, 40, 50};
int *ptr = arr;

printf("%d\n", *ptr);       // 10 (arr[0])
printf("%d\n", *(ptr + 1)); // 20 (arr[1])
printf("%d\n", *(ptr + 2)); // 30 (arr[2])

ptr++;  // Avanza al siguiente elemento
printf("%d\n", *ptr);       // 20 (ahora apunta a arr[1])

ptr += 2;  // Avanza dos elementos más
printf("%d\n", *ptr);       // 40 (ahora apunta a arr[3])
```

Visualización:
arr:  [10] [20] [30] [40] [50]
       ↑    ↑    ↑    ↑    ↑
     ptr  ptr+1 ptr+2 ptr+3 ptr+4

Cada +1 avanza sizeof(int) bytes en memoria

**Equivalencias importantes**
Estas notaciones son equivalentes en C:

```c
int arr[5] = {10, 20, 30, 40, 50};
int *ptr = arr;
int i = 2;

// Todas estas expresiones son equivalentes:
arr[i]     // 30
*(arr + i) // 30
*(ptr + i) // 30
ptr[i]     // 30 (¡sí, puedes usar [] con punteros!)

// Para obtener direcciones:
&arr[i]    // Dirección de arr[2]
(arr + i)  // Dirección de arr[2]
(ptr + i)  // Dirección de arr[2]
```

Ejemplo: Recorrer un arreglo con punteros

```c
#include <stdio.h>

int main() {
    int numeros[5] = {10, 20, 30, 40, 50};
    int *ptr = numeros;

    printf("Método 1: Usando aritmética de punteros\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    printf("Método 2: Incrementando el puntero\n");
    ptr = numeros;  // Resetear puntero al inicio
    for (int i = 0; i < 5; i++) {
        printf("%d ", *ptr);
        ptr++;  // Avanza al siguiente elemento
    }
    printf("\n");

    printf("Método 3: Usando notación de arreglo con puntero\n");
    ptr = numeros;  // Resetear de nuevo
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);  // Funciona igual que arr[i]
    }
    printf("\n");

    return 0;
}
```

Diferencia crucial entre arreglo y puntero
Aunque son similares, hay diferencias importantes:

```c
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr;

// arr es un PUNTERO CONSTANTE (no puede reasignarse)
// arr++; // ❌ ERROR DE COMPILACIÓN: no se puede modificar

// ptr es un PUNTERO VARIABLE (puede reasignarse)
ptr++;  // ✅ OK: ahora apunta a arr[1]
ptr = arr;  // ✅ OK: vuelve a apuntar al inicio
```

Tamaño de arreglos vs punteros

```c
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    printf("sizeof(arr): %zu bytes\n", sizeof(arr));  // 20 bytes (5 * 4)
    printf("sizeof(ptr): %zu bytes\n", sizeof(ptr));  // 8 bytes (en 64 bits)
    
    // Número de elementos en el arreglo
    int num_elementos = sizeof(arr) / sizeof(arr[0]);
    printf("Número de elementos: %d\n", num_elementos);  // 5
    
    return 0;
}
```

> **Importante**:`sizeof(arr)` da el tamaño total del arreglo, pero cuando se pasa a una función, decae a un puntero y `sizeof` devuelve el tamaño del puntero.

Arreglos multidimensionales y punteros

```c
int matriz[3][4] = {
    {1,  2,  3,  4},
    {5,  6,  7,  8},
    {9, 10, 11, 12}
};

// matriz[i][j] es equivalente a *(*(matriz + i) + j)
printf("%d\n", matriz[1][2]);          // 7
printf("%d\n", *(*(matriz + 1) + 2));  // 7 (equivalente)

// matriz es un puntero a arreglo de 4 enteros
int (*ptr)[4] = matriz;
printf("%d\n", ptr[1][2]);  // 7
```

---

## 5. Memoria Dinámica

La memoria dinámica permite reservar espacio en tiempo de ejecución, útil cuando no conoces el tamaño de los datos de antemano. Se utilizan funciones de la biblioteca `<stdlib.h>`.

Funciones principales

|Función                    |Descripción                |Inicializa         |Uso tipico                 |
|---------------------------|---------------------------|-------------------|---------------------------|
|`malloc(size)`             |Reserva `size` bytes       |No                 |Asignación rápida          |
|`calloc(n, size)`          |Reserva `n * size` bytes   |Sí (a 0)           |Necesitas inicialización   |
|`realloc(ptr, new_size)`   |Redimensiona bloque        |No (nuevos bytes)  |Cambiar tamaño             |
|`free(ptr)`                |Libera memoria             |N/A                |Siempre al terminar        |

> ⚠️ Regla de oro: Por cada malloc/calloc/realloc, debe haber un free. No liberar memoria causa fugas de memoria (memory leaks).

malloc - Asignación de memoria

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    
    // Asignar memoria para n enteros
    int *arr = (int *)malloc(n * sizeof(int));
    
    // SIEMPRE verificar si malloc tuvo éxito
    if (arr == NULL) {
        fprintf(stderr, "Error: no se pudo asignar memoria\n");
        return 1;
    }

    // Inicializar y usar el arreglo
    for (int i = 0; i < n; i++) {
        arr[i] = i * 10;
        printf("%d ", arr[i]);
    }
    printf("\n");  // Salida: 0 10 20 30 40

    // SIEMPRE libera la memoria cuando termines
    free(arr);
    arr = NULL;  // Buena práctica: evita dangling pointer
    
    return 0;
}
```

Desglose de `malloc(n * sizeof(int))`:

- `sizeof(int)`: Tamaño de un entero (generalmente 4 bytes)
- `n * sizeof(int)`: Tamaño total necesario
- `(int *)`: Cast del puntero void* retornado por malloc

calloc - Asignación con inicialización

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    
    // calloc inicializa todos los bytes a 0
    int *arr = (int *)calloc(n, sizeof(int));
    
    if (arr == NULL) {
        fprintf(stderr, "Error de memoria\n");
        return 1;
    }
    
    // Todos los elementos están inicializados a 0
    printf("Elementos inicializados: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);  // 0 0 0 0 0
    }
    printf("\n");
    
    free(arr);
    return 0;
}
```

realloc - Redimensionar memoria

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Asignar memoria inicial para 5 enteros
    int *arr = (int *)malloc(5 * sizeof(int));
    if (arr == NULL) return 1;
    
    // Inicializar los primeros 5 elementos
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }
    
    // Necesitamos más espacio: redimensionar a 10 elementos
    int *temp = (int *)realloc(arr, 10 * sizeof(int));
    
    // Verificar si realloc tuvo éxito
    if (temp == NULL) {
        fprintf(stderr, "Error al redimensionar memoria\n");
        free(arr);  // Liberar memoria original
        return 1;
    }
    
    // realloc tuvo éxito, actualizar puntero
    arr = temp;
    
    // Inicializar los nuevos elementos (realloc no los inicializa)
    for (int i = 5; i < 10; i++) {
        arr[i] = i;
    }
    
    // Imprimir todos los elementos
    printf("Arreglo redimensionado: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    return 0;
}
```

> **Importante sobre realloc**:
>
> - Puede mover el bloque de memoria a una nueva ubicación
> - Por eso usamos un puntero temporal (temp) para no perder la referencia original si falla
> - Los primeros bytes conservan su valor, los nuevos están sin inicializar

Diferencias entre malloc y calloc

```c
// malloc: más rápido, no inicializa
int *arr1 = (int *)malloc(5 * sizeof(int));
// arr1[0], arr1[1], etc. contienen basura (valores indefinidos)

// calloc: más lento, inicializa a 0
int *arr2 = (int *)calloc(5, sizeof(int));
// arr2[0] = 0, arr2[1] = 0, ..., arr2[4] = 0

// Equivalente a calloc usando malloc + memset:
int *arr3 = (int *)malloc(5 * sizeof(int));
memset(arr3, 0, 5 * sizeof(int));
```

¿Cuál usar?

- Usa malloc cuando vas a inicializar todos los valores inmediatamente
- Usa calloc cuando necesitas que los valores empiecen en cero

### Ejemplo completo: Arreglo dinámico de cadenas

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num_nombres = 3;
    
    // Asignar arreglo de punteros a char
    char **nombres = (char **)malloc(num_nombres * sizeof(char *));
    if (nombres == NULL) {
        fprintf(stderr, "Error de memoria\n");
        return 1;
    }
    
    // Asignar memoria para cada cadena
    for (int i = 0; i < num_nombres; i++) {
        nombres[i] = (char *)malloc(50 * sizeof(char));
        if (nombres[i] == NULL) {
            // Liberar memoria ya asignada antes de salir
            for (int j = 0; j < i; j++) {
                free(nombres[j]);
            }
            free(nombres);
            fprintf(stderr, "Error de memoria\n");
            return 1;
        }
    }
    
    // Usar las cadenas
    strcpy(nombres[0], "Alice");
    strcpy(nombres[1], "Bob");
    strcpy(nombres[2], "Charlie");
    
    // Imprimir
    printf("Nombres:\n");
    for (int i = 0; i < num_nombres; i++) {
        printf("  %d. %s\n", i + 1, nombres[i]);
    }
    
    // Liberar toda la memoria (orden inverso de asignación)
    for (int i = 0; i < num_nombres; i++) {
        free(nombres[i]);
    }
    free(nombres);
    
    return 0;
}
```

**Zonas de memoria: Stack vs Heap**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    // STACK: memoria automática, rápida, limitada
    int x = 10;              // En el stack
    int arr[100];            // En el stack
    
    // HEAP: memoria dinámica, más lenta, flexible
    int *ptr = (int *)malloc(sizeof(int));  // En el heap
    int *big_arr = (int *)malloc(1000000 * sizeof(int));  // En el heap
    
    // El stack se libera automáticamente al salir del scope
    // El heap debe liberarse manualmente
    free(ptr);
    free(big_arr);
    
    return 0;
}  // x y arr se destruyen automáticamente aquí
```

**Comparación:**

|Aspecto        |Stack              |Heap                           |
|Velocidad      |Muy rápida         |Más lenta                      |
|Tamaño         |Limitado (~1-8 MB) |Grande (hasta RAM disponible)  |
|Gestión        |Automática         |Manual (malloc/free)           |
|Fragmentación  |No                 |Puede ocurrir                  |
|Scope          |Local a función    |Puede trascender funciones     |

---

## 6. Punteros Void

Un `void*` es un puntero genérico que puede apuntar a cualquier tipo de dato. Es el tipo más flexible de puntero en C.

### Características de void*

- Puede almacenar la dirección de **cualquier tipo** de dato
- **No puede ser dereferenciado** directamente (necesita cast)
- **No se puede usar aritmética** de punteros directamente
- Útil para **funciones genéricas** y APIs
- `malloc`, `calloc` y `realloc` retornan `void*`

### Ejemplo básico

```c
#include <stdio.h>

int main() {
    int x = 42;
    float y = 3.14;
    char z = 'A';
    void *ptr;  // Puntero genérico
    
    // Puede apuntar a un int
    ptr = &x;
    printf("Valor de x: %d\n", *(int *)ptr);  // Cast necesario
    
    // Puede apuntar a un float
    ptr = &y;
    printf("Valor de y: %.2f\n", *(float *)ptr);
    
    // Puede apuntar a un char
    ptr = &z;
    printf("Valor de z: %c\n", *(char *)ptr);
    
    return 0;
}
```

**Uso común: malloc devuelve void**

```c
// malloc retorna void*, el cast es opcional en C (obligatorio en C++)
int *arr = (int *)malloc(10 * sizeof(int));  // Con cast (más claro)
int *arr = malloc(10 * sizeof(int));          // Sin cast (válido en C)

// Pero el cast ayuda a:
// 1. Detectar errores si olvidaste #include <stdlib.h>
// 2. Hacer el código compatible con C++
// 3. Dejar clara la intención
```

**Función genérica de impresión**

```c
#include <stdio.h>

void imprimir_dato(void *dato, char tipo) {
    switch(tipo) {
        case 'i':  // int
            printf("Entero: %d\n", *(int *)dato);
            break;
        case 'f':  // float
            printf("Float: %.2f\n", *(float *)dato);
            break;
        case 'd':  // double
            printf("Double: %.4f\n", *(double *)dato);
            break;
        case 'c':  // char
            printf("Char: %c\n", *(char *)dato);
            break;
        case 's':  // string
            printf("String: %s\n", (char *)dato);
            break;
        default:
            printf("Tipo no soportado\n");
    }
}

int main() {
    int a = 10;
    float b = 3.14;
    double c = 2.71828;
    char d = 'X';
    char *e = "Hola Mundo";
    
    imprimir_dato(&a, 'i');
    imprimir_dato(&b, 'f');
    imprimir_dato(&c, 'd');
    imprimir_dato(&d, 'c');
    imprimir_dato(e, 's');
    
    return 0;
}
```

**Limitaciones de `void*`**

```c
void *ptr = malloc(100);

// ❌ ERROR: No se puede dereferenciar directamente
// *ptr = 10;

// ❌ ERROR: No se puede hacer aritmética directamente
// ptr++;

// ✅ CORRECTO: Convertir primero
char *cptr = (char *)ptr;
cptr++;  // Ahora sí funciona
*cptr = 'A';

free(ptr);
```

**Caso de uso: memcpy**

```c
#include <string.h>

// Prototipo de memcpy (simplificado)
void *memcpy(void *dest, const void *src, size_t n);

// Usa void* para copiar CUALQUIER tipo de dato
int arr1[5] = {1, 2, 3, 4, 5};
int arr2[5];
memcpy(arr2, arr1, sizeof(arr1));  // Copia bytes, sin importar el tipo
```

---

## 7. Punteros a Funciones

Los punteros también pueden apuntar a funciones, permitiendo callbacks, tablas de despacho y programación funcional en C.

**Sintaxis**

```c
tipo_retorno (*nombre_puntero)(lista_parametros);
```

**Ejemplo de lectura**:

- `int (*func)(int, int)` → "func es un puntero a función que toma dos ints y retorna int"

**Ejemplo básico**

```c
#include <stdio.h>

void saludar() { 
    printf("¡Hola!\n"); 
}

void despedir() { 
    printf("¡Adiós!\n"); 
}

int main() {
    void (*accion)();  // Puntero a función sin parámetros que retorna void
    
    accion = saludar;  // Asignar dirección de saludar
    accion();          // Llamar a través del puntero: ¡Hola!
    
    accion = despedir; // Cambiar a otra función
    accion();          // ¡Adiós!
    
    // También puedes llamar así (más explícito pero menos común):
    (*accion)();
    
    return 0;
}
```

**Ejemplo: Callback para operaciones matemáticas**

```c
#include <stdio.h>

// Definir las funciones de operaciones
int suma(int a, int b) { return a + b; }
int resta(int a, int b) { return a - b; }
int multiplicacion(int a, int b) { return a * b; }
int division(int a, int b) { 
    return (b != 0) ? a / b : 0; 
}

// Función que ejecuta una operación genérica
void ejecutar_operacion(int x, int y, int (*operacion)(int, int)) {
    int resultado = operacion(x, y);
    printf("Resultado: %d\n", resultado);
}

int main() {
    int a = 10, b = 5;
    
    printf("=== Calculadora con punteros a funciones ===\n");
    printf("Operando 1: %d, Operando 2: %d\n\n", a, b);
    
    printf("Suma: ");
    ejecutar_operacion(a, b, suma);           // 15
    
    printf("Resta: ");
    ejecutar_operacion(a, b, resta);          // 5
    
    printf("Multiplicación: ");
    ejecutar_operacion(a, b, multiplicacion); // 50
    
    printf("División: ");
    ejecutar_operacion(a, b, division);       // 2
    
    return 0;
}
```

**Ejemplo: Tabla de funciones (menú interactivo)**

```c
#include <stdio.h>

void opcion1() { printf("→ Ejecutando: Abrir archivo\n"); }
void opcion2() { printf("→ Ejecutando: Guardar archivo\n"); }
void opcion3() { printf("→ Ejecutando: Cerrar archivo\n"); }
void opcion4() { printf("→ Ejecutando: Salir\n"); }

int main() {
    // Tabla de punteros a funciones
    void (*menu[4])() = {opcion1, opcion2, opcion3, opcion4};
    int eleccion;
    
    printf("=== MENÚ ===\n");
    printf("1. Abrir archivo\n");
    printf("2. Guardar archivo\n");
    printf("3. Cerrar archivo\n");
    printf("4. Salir\n");
    printf("\nElige una opción (1-4): ");
    scanf("%d", &eleccion);
    
    if (eleccion >= 1 && eleccion <= 4) {
        menu[eleccion - 1]();  // Llamar a la función correspondiente
    } else {
        printf("Opción inválida\n");
    }
    
    return 0;
}
```

**Ejemplo: qsort (ordenamiento genérico)**

```c
#include <stdio.h>
#include <stdlib.h>

// Función de comparación para ordenamiento ascendente
int comparar_ascendente(const void *a, const void *b) {
    int int_a = *(int*)a;
    int int_b = *(int*)b;
    return int_a - int_b;  // Negativo si a < b, 0 si a == b, positivo si a > b
}

// Función de comparación para ordenamiento descendente
int comparar_descendente(const void *a, const void *b) {
    return comparar_ascendente(b, a);  // Invertir el orden
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Arreglo original: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    // Ordenar ascendente
    qsort(arr, n, sizeof(int), comparar_ascendente);
    printf("Orden ascendente: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    // Ordenar descendente
    qsort(arr, n, sizeof(int), comparar_descendente);
    printf("Orden descendente: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}
```

**typedef para simplificar sintaxis**

```c
#include <stdio.h>

// Sin typedef (complejo)
void ejecutar1(int x, int (*func)(int)) {
    printf("Resultado: %d\n", func(x));
}

// Con typedef (más legible)
typedef int (*Operacion)(int);

void ejecutar2(int x, Operacion func) {
    printf("Resultado: %d\n", func(x));
}

int cuadrado(int x) { return x * x; }
int cubo(int x) { return x * x * x; }

int main() {
    ejecutar1(5, cuadrado);  // 25
    ejecutar2(5, cubo);      // 125
    
    return 0;
}
```

---

## 8. Punteros a Punteros

Un puntero a puntero almacena la dirección de otro puntero, creando múltiples niveles de indirección.

**Sintaxis básica**

```c
int valor = 100;
int *ptr1 = &valor;   // ptr1 apunta a valor
int **ptr2 = &ptr1;   // ptr2 apunta a ptr1

printf("Valor: %d\n", valor);      // 100
printf("Valor: %d\n", *ptr1);      // 100
printf("Valor: %d\n", **ptr2);     // 100 (doble dereferencia)
```

**Visualización:**
valor: [100]     ← Dirección: 0x400
         ↑
         |
ptr1: [0x400]    ← Dirección: 0x500
         ↑
         |
ptr2: [0x500]    ← Dirección: 0x600

Accesos:
**ptr2  → 100 (valor final)
*ptr2   → 0x400 (dirección de valor)
ptr2    → 0x500 (dirección de ptr1)

**Niveles de indirección**

```c
int x = 42;
int *p1 = &x;
int **p2 = &p1;
int ***p3 = &p2;

printf("%d\n", x);       // 42
printf("%d\n", *p1);     // 42
printf("%d\n", **p2);    // 42
printf("%d\n", ***p3);   // 42 (triple dereferencia)
```

**Uso 1: Modificar un puntero en una función**

```c
#include <stdio.h>
#include <stdlib.h>

// Para modificar un puntero, necesitamos puntero a puntero
void asignar_memoria(int **ptr, int tamaño) {
    *ptr = (int *)malloc(tamaño * sizeof(int));
    if (*ptr == NULL) {
        fprintf(stderr, "Error al asignar memoria\n");
        exit(1);
    }
    printf("Memoria asignada exitosamente\n");
}

int main() {
    int *arr = NULL;  // Inicialmente NULL
    
    // Pasamos la DIRECCIÓN del puntero
    asignar_memoria(&arr, 5);
    
    // Ahora arr apunta a memoria válida
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    return 0;
}
```

**¿Por qué necesitamos `int**`?**

```c
// ❌ Esto NO funciona:
void asignar_mal(int *ptr, int tamaño) {
    ptr = malloc(tamaño * sizeof(int));  // Solo modifica la COPIA local
}

int main() {
    int *arr = NULL;
    asignar_mal(arr, 5);
    // arr sigue siendo NULL aquí
}

// ✅ Esto SÍ funciona:
void asignar_bien(int **ptr, int tamaño) {
    *ptr = malloc(tamaño * sizeof(int));  // Modifica el puntero original
}
```

**Uso 2: Arreglo de cadenas**

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n = 3;
    
    // Arreglo de punteros a char (char**)
    char **nombres = (char **)malloc(n * sizeof(char *));
    if (nombres == NULL) {
        fprintf(stderr, "Error de memoria\n");
        return 1;
    }
    
    // Asignar memoria para cada cadena
    for (int i = 0; i < n; i++) {
        nombres[i] = (char *)malloc(50 * sizeof(char));
        if (nombres[i] == NULL) {
            // Limpiar memoria ya asignada
            for (int j = 0; j < i; j++) {
                free(nombres[j]);
            }
            free(nombres);
            return 1;
        }
    }
    
    // Usar las cadenas
    strcpy(nombres[0], "Alice");
    strcpy(nombres[1], "Bob");
    strcpy(nombres[2], "Charlie");
    
    // Imprimir
    printf("Lista de nombres:\n");
    for (int i = 0; i < n; i++) {
        printf("  %d. %s\n", i + 1, nombres[i]);
    }
    
    // Liberar TODA la memoria (importante: orden)
    for (int i = 0; i < n; i++) {
        free(nombres[i]);  // Primero liberar cada cadena
    }
    free(nombres);  // Luego liberar el arreglo de punteros
    
    return 0;
}
```

**Visualización de la estructura:**
nombres: [ptr0][ptr1][ptr2]  ← char** (arreglo de punteros)
           ↓     ↓     ↓
         "Alice" "Bob" "Charlie"  ← Cada cadena en memoria separada

**Uso 3: Matriz dinámica 2D**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int filas = 3, columnas = 4;
    
    // Asignar arreglo de punteros (las filas)
    int **matriz = (int **)malloc(filas * sizeof(int *));
    if (matriz == NULL) {
        fprintf(stderr, "Error de memoria\n");
        return 1;
    }
    
    // Asignar cada fila
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int *)malloc(columnas * sizeof(int));
        if (matriz[i] == NULL) {
            // Limpiar filas ya asignadas
            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free(matriz);
            return 1;
        }
    }
    
    // Inicializar matriz
    printf("Matriz %dx%d:\n", filas, columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = i * columnas + j;
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);  // Liberar cada fila
    }
    free(matriz);  // Liberar arreglo de punteros
    
    return 0;
}
```

Salida:
Matriz 3x4:
  0   1   2   3 
  4   5   6   7 
  8   9  10  11

**Uso 4: argv en main**

```c
int main(int argc, char **argv) {
    // argc: número de argumentos
    // argv: arreglo de cadenas (char**)
    
    printf("Número de argumentos: %d\n", argc);
    printf("Argumentos:\n");
    for (int i = 0; i < argc; i++) {
        printf("  argv[%d] = %s\n", i, argv[i]);
    }
    
    return 0;
}
```

```bash
$ ./programa hola mundo 123
Número de argumentos: 4
Argumentos:
  argv[0] = ./programa
  argv[1] = hola
  argv[2] = mundo
  argv[3] = 123
```

---

## 9. Punteros Constantes y Constantes a Punteros

El uso de `const` con punteros mejora la seguridad del código y documenta las intenciones del programador.

**Puntero a constante `(const tipo *ptr)`**

El **valor apuntado** no puede modificarse, pero el puntero sí puede cambiar de dirección.

```c
int x = 10, y = 20;
const int *ptr = &x;

// *ptr = 15;  // ❌ ERROR: no puedes modificar el valor
ptr = &y;      // ✅ OK: puedes cambiar a dónde apunta

printf("%d\n", *ptr);  // 20
```

**Uso común**: Parámetros de funciones que no deben modificar datos.

```c
void imprimir_cadena(const char *str) {
    // str[0] = 'X';  // ❌ ERROR de compilación
    printf("%s\n", str);  // ✅ OK: solo lectura
}

int main() {
    char msg[] = "Hola";
    imprimir_cadena(msg);  // Garantiza que no se modificará
    return 0;
}
```

**Puntero constante `(tipo * const ptr)`**
El **puntero** no puede cambiar de dirección, pero el valor sí puede modificarse.

```c
int x = 10, y = 20;
int * const ptr = &x;  // ptr siempre apuntará a x

*ptr = 15;     // ✅ OK: puedes cambiar el valor de x
// ptr = &y;   // ❌ ERROR: no puedes cambiar la dirección

printf("%d\n", x);  // 15
```

**Uso común**: Punteros que siempre deben apuntar al mismo objeto.

```c
int main() {
    int buffer[100];
    int * const buf_ptr = buffer;  // buf_ptr siempre apunta a buffer
    
    buf_ptr[0] = 42;  // ✅ OK: modificar contenido
    // buf_ptr = NULL;  // ❌ ERROR: no puedes reasignar
    
    return 0;
}
```

**Puntero constante a constante `(const tipo * const ptr)`**

Ni el puntero ni el valor pueden cambiar.

```c
int x = 10;
const int * const ptr = &x;

// *ptr = 15;  // ❌ ERROR: valor es constante
// ptr = &y;   // ❌ ERROR: puntero es constante

printf("%d\n", *ptr);  // ✅ OK: solo lectura
```

**Tabla resumen completa**

|Declaración        |Sintaxis alternativa   |Puntero modificable    |Valor modificable  |Uso típico              |
|`int *ptr`         |-                      |✅                     |✅                |General                 |
|`const int *ptr`   |`int const *ptr`       |✅                     |❌                |Parámetros read-only    |
|`int * const ptr`  |-                      |❌                     |✅                |Referencia fija         |
|`const int *`      |`int const *`          |❌                     |❌                |Constante total         |
|`const ptr`        |`const ptr`            |❌                     |❌                |Constante total         |


**Truco para leer declaraciones**
Lee de derecha a izquierda:

```c
const int *ptr;
// ← "ptr es un puntero a un int constante"

int * const ptr;
// ← "ptr es un puntero constante a un int"

const int * const ptr;
// ← "ptr es un puntero constante a un int constante"
```

**Ejemplo práctico completo**

```c
#include <stdio.h>
#include <string.h>

// Puntero a constante: no modifica el string
size_t longitud(const char *str) {
    // str[0] = 'X';  // ❌ ERROR
    return strlen(str);
}

// Puntero constante: siempre usa el mismo buffer
void copiar_a_buffer(const char *src, char * const dest, size_t max) {
    strncpy(dest, src, max - 1);
    dest[max - 1] = '\0';
    // dest = NULL;  // ❌ ERROR: dest es constante
}

int main() {
    char mensaje[] = "Hola Mundo";
    char buffer[20];
    
    printf("Longitud: %zu\n", longitud(mensaje));
    copiar_a_buffer(mensaje, buffer, sizeof(buffer));
    printf("Copiado: %s\n", buffer);
    
    return 0;
}
```

**Const con estructuras**

```c
#include <stdio.h>

struct Punto {
    int x, y;
};

// No puede modificar la estructura
void imprimir_punto(const struct Punto *p) {
    printf("(%d, %d)\n", p->x, p->y);
    // p->x = 10;  // ❌ ERROR
}

// Puede modificar la estructura
void mover_punto(struct Punto *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}

int main() {
    struct Punto p = {5, 10};
    
    imprimir_punto(&p);  // (5, 10)
    mover_punto(&p, 3, -2);
    imprimir_punto(&p);  // (8, 8)
    
    return 0;
}
```

---

## 10. Estructuras y Punteros

Los punteros son especialmente útiles con estructuras `(struct)` para evitar copias costosas y manejar datos dinámicos.

**Ejemplo básico**

```c
#include <stdio.h>

struct Persona {
    char nombre[50];
    int edad;
    float altura;
};

int main() {
    struct Persona p1 = {"Juan Pérez", 30, 1.75};
    struct Persona *ptr = &p1;
    
    // Dos formas de acceder a miembros:
    
    // Forma 1: Dereferencia y punto
    printf("Nombre: %s\n", (*ptr).nombre);
    printf("Edad: %d\n", (*ptr).edad);
    
    // Forma 2: Operador flecha (más común)
    printf("Nombre: %s\n", ptr->nombre);
    printf("Edad: %d\n", ptr->edad);
    printf("Altura: %.2f m\n", ptr->altura);
    
    // Modificar a través del puntero
    ptr->edad = 31;
    printf("Nueva edad: %d\n", p1.edad);  // 31
    
    return 0;
}
```

**Operador -> (flecha)**

El operador `->` es un atajo para `(*ptr).miembro`:

```c
ptr->edad       ≡  (*ptr).edad
ptr->nombre     ≡  (*ptr).nombre
```

¿Por qué usar `->`?

- Más legible
- Evita paréntesis
- Es el estándar en C

**Estructuras dinámicas**

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Persona {
    char *nombre;  // Puntero a nombre dinámico
    int edad;
    float salario;
};

struct Persona* crear_persona(const char *nombre, int edad, float salario) {
    // Asignar memoria para la estructura
    struct Persona *p = (struct Persona *)malloc(sizeof(struct Persona));
    if (p == NULL) return NULL;
    
    // Asignar memoria para el nombre
    p->nombre = (char *)malloc(strlen(nombre) + 1);
    if (p->nombre == NULL) {
        free(p);
        return NULL;
    }
    
    // Inicializar campos
    strcpy(p->nombre, nombre);
    p->edad = edad;
    p->salario = salario;
    
    return p;
}

void liberar_persona(struct Persona *p) {
    if (p != NULL) {
        free(p->nombre);  // Primero liberar el nombre
        free(p);           // Luego la estructura
    }
}

void imprimir_persona(const struct Persona *p) {
    if (p != NULL) {
        printf("Nombre: %s\n", p->nombre);
        printf("Edad: %d años\n", p->edad);
        printf("Salario: $%.2f\n", p->salario);
    }
}

int main() {
    struct Persona *p = crear_persona("María González", 28, 45000.50);
    
    if (p != NULL) {
        imprimir_persona(p);
        liberar_persona(p);
    }
    
    return 0;
}
```

**Lista enlazada simple**
Una de las estructuras de datos más comunes con punteros.

```c
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;  // Puntero al siguiente nodo
};

// Insertar al inicio de la lista
void insertar_inicio(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        fprintf(stderr, "Error de memoria\n");
        return;
    }
    
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;  // El nuevo apunta al antiguo primero
    *cabeza = nuevo;              // Actualizar la cabeza
}

// Insertar al final de la lista
void insertar_final(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        fprintf(stderr, "Error de memoria\n");
        return;
    }
    
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    
    // Si la lista está vacía
    if (*cabeza == NULL) {
        *cabeza = nuevo;
        return;
    }
    
    // Encontrar el último nodo
    struct Nodo *actual = *cabeza;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    actual->siguiente = nuevo;
}

// Imprimir la lista
void imprimir_lista(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Buscar un valor
struct Nodo* buscar(struct Nodo *cabeza, int valor) {
    struct Nodo *actual = cabeza;
    while (actual != NULL) {
        if (actual->dato == valor) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return NULL;
}

// Eliminar un nodo con valor específico
int eliminar_valor(struct Nodo **cabeza, int valor) {
    if (*cabeza == NULL) return 0;
    
    // Caso especial: eliminar el primer nodo
    if ((*cabeza)->dato == valor) {
        struct Nodo *temp = *cabeza;
        *cabeza = (*cabeza)->siguiente;
        free(temp);
        return 1;
    }
    
    // Buscar el nodo anterior al que queremos eliminar
    struct Nodo *actual = *cabeza;
    while (actual->siguiente != NULL && actual->siguiente->dato != valor) {
        actual = actual->siguiente;
    }
    
    if (actual->siguiente == NULL) return 0;  // No encontrado
    
    // Eliminar el nodo
    struct Nodo *temp = actual->siguiente;
    actual->siguiente = temp->siguiente;
    free(temp);
    return 1;
}

// Liberar toda la lista
void liberar_lista(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    while (actual != NULL) {
        struct Nodo *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
}

// Contar nodos
int contar_nodos(struct Nodo *cabeza) {
    int count = 0;
    struct Nodo *actual = cabeza;
    while (actual != NULL) {
        count++;
        actual = actual->siguiente;
    }
    return count;
}

int main() {
    struct Nodo *lista = NULL;  // Lista vacía
    
    printf("=== Creando lista enlazada ===\n");
    insertar_inicio(&lista, 3);
    insertar_inicio(&lista, 2);
    insertar_inicio(&lista, 1);
    insertar_final(&lista, 4);
    insertar_final(&lista, 5);
    
    printf("Lista: ");
    imprimir_lista(lista);  // 1 -> 2 -> 3 ->
    printf("Número de nodos: %d\n", contar_nodos(lista));  // 5
    
    printf("\n=== Buscando valores ===\n");
    struct Nodo *encontrado = buscar(lista, 3);
    if (encontrado != NULL) {
        printf("Valor 3 encontrado en la lista\n");
    }
    
    printf("\n=== Eliminando el valor 3 ===\n");
    eliminar_valor(&lista, 3);
    printf("Lista después de eliminar: ");
    imprimir_lista(lista);  // 1 -> 2 -> 4 -> 5 -> NULL
    
    printf("\n=== Liberando memoria ===\n");
    liberar_lista(lista);
    printf("Lista liberada\n");
    
    return 0;
}
```

**Árbol binario de búsqueda (BST)**

```c
#include <stdio.h>
#include <stdlib.h>

struct NodoArbol {
    int dato;
    struct NodoArbol *izquierdo;
    struct NodoArbol *derecho;
};

// Crear un nuevo nodo
struct NodoArbol* crear_nodo(int valor) {
    struct NodoArbol *nuevo = (struct NodoArbol *)malloc(sizeof(struct NodoArbol));
    if (nuevo == NULL) return NULL;
    
    nuevo->dato = valor;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    return nuevo;
}

// Insertar en BST
struct NodoArbol* insertar(struct NodoArbol *raiz, int valor) {
    if (raiz == NULL) {
        return crear_nodo(valor);
    }
    
    if (valor < raiz->dato) {
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    } else if (valor > raiz->dato) {
        raiz->derecho = insertar(raiz->derecho, valor);
    }
    // Si valor == raiz->dato, no insertar duplicados
    
    return raiz;
}

// Buscar en BST
struct NodoArbol* buscar(struct NodoArbol *raiz, int valor) {
    if (raiz == NULL || raiz->dato == valor) {
        return raiz;
    }
    
    if (valor < raiz->dato) {
        return buscar(raiz->izquierdo, valor);
    } else {
        return buscar(raiz->derecho, valor);
    }
}

// Recorrido in-order (izquierda, raíz, derecha)
void inorden(struct NodoArbol *raiz) {
    if (raiz != NULL) {
        inorden(raiz->izquierdo);
        printf("%d ", raiz->dato);
        inorden(raiz->derecho);
    }
}

// Recorrido pre-order (raíz, izquierda, derecha)
void preorden(struct NodoArbol *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dato);
        preorden(raiz->izquierdo);
        preorden(raiz->derecho);
    }
}

// Recorrido post-order (izquierda, derecha, raíz)
void postorden(struct NodoArbol *raiz) {
    if (raiz != NULL) {
        postorden(raiz->izquierdo);
        postorden(raiz->derecho);
        printf("%d ", raiz->dato);
    }
}

// Liberar árbol
void liberar_arbol(struct NodoArbol *raiz) {
    if (raiz != NULL) {
        liberar_arbol(raiz->izquierdo);
        liberar_arbol(raiz->derecho);
        free(raiz);
    }
}

// Encontrar el valor mínimo
struct NodoArbol* encontrar_minimo(struct NodoArbol *nodo) {
    while (nodo->izquierdo != NULL) {
        nodo = nodo->izquierdo;
    }
    return nodo;
}

int main() {
    struct NodoArbol *raiz = NULL;
    
    printf("=== Creando árbol BST ===\n");
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(valores) / sizeof(valores[0]);
    
    for (int i = 0; i < n; i++) {
        raiz = insertar(raiz, valores[i]);
    }
    
    printf("Recorrido In-order (ordenado): ");
    inorden(raiz);
    printf("\n");
    
    printf("Recorrido Pre-order: ");
    preorden(raiz);
    printf("\n");
    
    printf("Recorrido Post-order: ");
    postorden(raiz);
    printf("\n");
    
    printf("\n=== Búsquedas ===\n");
    int buscar_valor = 40;
    if (buscar(raiz, buscar_valor) != NULL) {
        printf("Valor %d encontrado en el árbol\n", buscar_valor);
    } else {
        printf("Valor %d NO encontrado\n", buscar_valor);
    }
    
    liberar_arbol(raiz);
    return 0;
}
```

---

## 11. Errores Comunes y Depuración

**Error 1: Puntero dangling (colgante)**
Usar un puntero después de liberar la memoria o cuando la variable sale de ámbito.

```c
// ❌ ERROR 1: Usar después de free
int *ptr = (int *)malloc(sizeof(int));
*ptr = 10;
free(ptr);
*ptr = 20;  // ¡PELIGRO! Memoria ya liberada

// ✅ SOLUCIÓN: Asignar NULL después de free
free(ptr);
ptr = NULL;
if (ptr != NULL) {  // Ahora esto falla de forma segura
    *ptr = 20;
}
```

```c
// ❌ ERROR 2: Retornar puntero a variable local
int* obtener_numero() {
    int x = 42;
    return &x;  // ¡ERROR! x se destruye al salir de la función
}

int main() {
    int *ptr = obtener_numero();
    printf("%d\n", *ptr);  // Comportamiento indefinido
}

// ✅ SOLUCIÓN: Usar memoria dinámica o static
int* obtener_numero() {
    int *x = (int *)malloc(sizeof(int));
    if (x == NULL) return NULL;
    *x = 42;
    return x;  // El llamador debe liberar
}

// O usar static (persiste entre llamadas)
int* obtener_numero_static() {
    static int x = 42;
    return &x;
}
```

**Error 2: Fuga de memoria (memory leak)**
Olvidar liberar memoria dinámicamente asignada.

```c
// ❌ ERROR: Memory leak
void funcion() {
    int *arr = (int *)malloc(100 * sizeof(int));
    // ... usar arr ...
    // ¡Falta free(arr)!
}  // La memoria se pierde

// ✅ SOLUCIÓN: Siempre liberar
void funcion() {
    int *arr = (int *)malloc(100 * sizeof(int));
    if (arr == NULL) return;
    
    // ... usar arr ...
    
    free(arr);  // Liberar antes de salir
}
```

```c
// ❌ ERROR: Reasignar sin liberar
int *ptr = (int *)malloc(sizeof(int));
ptr = (int *)malloc(sizeof(int));  // ¡Perdimos la primera asignación!

// ✅ SOLUCIÓN: Liberar primero
int *ptr = (int *)malloc(sizeof(int));
// ... usar ptr ...
free(ptr);
ptr = (int *)malloc(sizeof(int));  // Ahora es seguro
```

**Error 3: Desbordamiento de buffer**
Acceder más allá del tamaño de un arreglo.

```c
// ❌ ERROR: Buffer overflow
int arr[5];
arr[10] = 42;  // ¡ERROR! Fuera de límites

// ❌ ERROR: Escribir más allá del buffer
char nombre[10];
strcpy(nombre, "Este es un nombre muy largo");  // ¡PELIGRO!

// ✅ SOLUCIÓN: Verificar límites
for (int i = 0; i < 5; i++) {  // Usar el tamaño correcto
    arr[i] = i;
}

// ✅ SOLUCIÓN: Usar funciones seguras
char nombre[10];
strncpy(nombre, "Este es un nombre muy largo", sizeof(nombre) - 1);
nombre[sizeof(nombre) - 1] = '\0';  // Asegurar terminación
```

**Error 4: Dereferencia de NULL**
Intentar acceder al valor de un puntero NULL.

```c
// ❌ ERROR: Segmentation fault
int *ptr = NULL;
*ptr = 10;  // ¡CRASH!

// ❌ ERROR: No verificar malloc
int *arr = (int *)malloc(1000000000000 * sizeof(int));  // Probablemente falla
arr[0] = 10;  // ¡CRASH si malloc retornó NULL!

// ✅ SOLUCIÓN: Verificar antes de usar
int *ptr = NULL;
if (ptr != NULL) {
    *ptr = 10;
} else {
    fprintf(stderr, "Error: puntero NULL\n");
}

// ✅ SOLUCIÓN: Verificar malloc
int *arr = (int *)malloc(tamaño * sizeof(int));
if (arr == NULL) {
    fprintf(stderr, "Error de memoria\n");
    return 1;
}
arr[0] = 10;  // Seguro
```

**Error 5: Double free**
Liberar la misma memoria dos veces.

```c
// ❌ ERROR: Double free
int *ptr = (int *)malloc(sizeof(int));
free(ptr);
free(ptr);  // ¡ERROR! Ya fue liberado

// ✅ SOLUCIÓN: Usar NULL después de free
int *ptr = (int *)malloc(sizeof(int));
free(ptr);
ptr = NULL;
free(ptr);  // Seguro: free(NULL) no hace nada
```

**Error 6: Aritmética incorrecta de punteros**

```c
// ❌ ERROR: Tipo incorrecto
char *ptr = (char *)malloc(10);
int *iptr = (int *)ptr;
iptr++;  // Avanza 4 bytes, no 1

// ✅ SOLUCIÓN: Usar el tipo correcto
char *ptr = (char *)malloc(10);
ptr++;  // Avanza 1 byte

// ❌ ERROR: Aritmética fuera de límites
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr;
ptr += 10;  // ¡Fuera de límites!
printf("%d\n", *ptr);  // Comportamiento indefinido

// ✅ SOLUCIÓN: Verificar límites
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr;
int tamaño = 5;
for (int i = 0; i < tamaño; i++) {
    printf("%d ", *(ptr + i));
}
```

---

## 12. Mejores Prácticas

✅ Reglas de oro

1. Inicializar siempre punteros
2. Verificar asignaciones de memoria
3. Liberar memoria y asignar NULL
4. Usar sizeof para portabilidad
5. Preferir calloc para inicialización a cero
6. Usar const donde sea apropiado
7. Documentar propiedad de memoria
8. Compilar con warnings
9. Un malloc, un free
10. Verificar límites de arreglos

**Patrones de código seguro**
Patrón 1: Wrapper para malloc con manejo de errores
Patrón 2: RAII-style en C
Patrón 3: Manejo de errores con goto
Patrón 4: Asignación segura de arreglos 2D

**Checklist de código con punteros**
Antes de considerar tu código completo, verifica:

 Todos los punteros están inicializados (NULL o dirección válida)
 Cada malloc/calloc/realloc tiene su correspondiente free
 Verificas NULL después de cada asignación dinámica
 Asignas NULL después de free
 No accedes fuera de los límites de arreglos
 No retornas punteros a variables locales
 Usas const para punteros que no deben modificar datos
 Compilas con -Wall -Wextra sin warnings
 Pruebas con valgrind o sanitizers
 Documentas quién es responsable de liberar memoria

---

## 13. Ejercicios Propuestos

**Nivel Básico**
Ejercicio 1: Intercambio con punteros
Ejercicio 2: Búsqueda en arreglo
Ejercicio 3: Contar positivos
Ejercicio 4: Copiar arreglo
Ejercicio 5: Suma de elementos

**Nivel Intermedio**
Ejercicio 6: Invertir arreglo
Ejercicio 7: Encontrar máximo y mínimo
Ejercicio 8: Menú con punteros a funciones
Ejercicio 9: Matriz dinámica
Ejercicio 10: Concatenar cadenas
Ejercicio 11: Filtrar arreglo
Ejercicio 12: Remover duplicados

**Nivel Avanzado**
Ejercicio 13: Lista enlazada completa
Ejercicio 14: Árbol binario de búsqueda
Ejercicio 15: Sistema de gestión de memoria
Ejercicio 16: Ordenamiento genérico
Ejercicio 17: Hash table
Ejercicio 18: Cola circular (Ring Buffer)

**Proyecto Integrador**
Sistema de gestión de estudiantes

---

## 14. Diagramas Visuales

**Variable y Puntero**

int x = 10;
int *ptr = &x;

Memoria:
┌─────────────┐
│   x = 10    │ ← Dirección: 0x1000
├─────────────┤
│  ptr=0x1000 │ ← Dirección: 0x2000
└─────────────┘
     │
     └──────► apunta a x

Operaciones:
- ptr almacena 0x1000
- *ptr lee/escribe el valor 10
- &x retorna 0x1000

**Arreglo y Puntero**

int arr[4] = {10, 20, 30, 40};
int *ptr = arr;

┌────┬────┬────┬────┐
│ 10 │ 20 │ 30 │ 40 │
└────┴────┴────┴────┘
  ↑    ↑    ↑    ↑
0x100 0x104 0x108 0x10C (direcciones ejemplo)

ptr = 0x100 (apunta al primer elemento)

Aritmética:
ptr + 0 → 0x100 → 10
ptr + 1 → 0x104 → 20
ptr + 2 → 0x108 → 30
ptr + 3 → 0x10C → 40

**Puntero a Puntero**

int valor = 42;
int *p1 = &valor;
int **p2 = &p1;

┌──────────┐
│ valor=42 │ ← 0x400
└──────────┘
     ↑
     │
┌──────────┐
│ p1=0x400 │ ← 0x500
└──────────┘
     ↑
     │
┌──────────┐
│ p2=0x500 │ ← 0x600
└──────────┘

Accesos:
**p2 → *p1 → valor → 42
*p2  → p1  → 0x400
p2   → 0x500

**Memoria Dinámica: malloc**

int *arr = malloc(3 * sizeof(int));
arr[0] = 10;
arr[1] = 20;
arr[2] = 30;

STACK:                  HEAP:
┌──────────┐           ┌────┬────┬────┐
│arr=0x700 │─────────→ │ 10 │ 20 │ 30 │
└──────────┘           └────┴────┴────┘
                        ↑ 0x700

Después de free(arr):
STACK:                  HEAP:
┌──────────┐           ┌────┬────┬────┐
│arr=0x700 │─────╳→   │ ?? │ ?? │ ?? │ (liberada)
└──────────┘           └────┴────┴────┘
(dangling pointer - PELIGRO)

Después de arr = NULL:
STACK:
┌──────────┐
│arr=NULL  │ (seguro)
└──────────┘

**Lista Enlazada**

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

cabeza
  ↓
┌──────┬─────┐    ┌──────┬─────┐    ┌──────┬──────┐
│ 10   │  ●──┼───→│ 20   │  ●──┼───→│ 30   │ NULL │
└──────┴─────┘    └──────┴─────┘    └──────┴──────┘
 Nodo 1            Nodo 2             Nodo 3

Recorrido:
struct Nodo *actual = cabeza;
while (actual != NULL) {
    printf("%d ", actual->dato);
    actual = actual->siguiente;
}

**Árbol Binario**

50
       /  \
     30    70
    /  \   /  \
   20  40 60  80

struct NodoArbol {
    int dato;
    struct NodoArbol *izquierdo;
    struct NodoArbol *derecho;
};

Representación en memoria:
┌────────────────┐
│  dato: 50      │ ← raíz
│  izq: 0x200    │───┐
│  der: 0x300    │─┐ │
└────────────────┘ │ │
                   │ │
    ┌──────────────┘ │
    ↓                │
┌────────────────┐   │
│  dato: 30      │   │
│  izq: 0x400    │   │
│  der: 0x500    │   │
└────────────────┘   │
                     │
    ┌────────────────┘
    ↓
┌────────────────┐
│  dato: 70      │
│  izq: 0x600    │
│  der: 0x700    │
└────────────────┘

**Stack vs Heap**

MEMORIA DEL PROGRAMA:

Alta dirección (0xFFFFFFFF)
┌─────────────────────────────┐
│         STACK               │
│  - Crece hacia abajo ↓      │
│  - Variables locales        │
│  - Parámetros funciones     │
│  - Direcciones de retorno   │
│  - Rápido                   │
│  - Tamaño limitado (~8MB)   │
│  - Gestión automática       │
│                             │
│  int x = 10;                │
│  char arr[100];             │
├─────────────────────────────┤
│                             │
│         (espacio libre)     │
│                             │
├─────────────────────────────┤
│         HEAP                │
│  - Crece hacia arriba ↑     │
│  - malloc/calloc            │
│  - Más lento                │
│  - Flexible (hasta RAM)     │
│  - Gestión manual           │
│  - Puede fragmentarse       │
│                             │
│  int *ptr = malloc(...);    │
├─────────────────────────────┤
│     SECCIÓN DE DATOS        │
│  - Variables globales       │
│  - Variables static         │
├─────────────────────────────┤
│     SECCIÓN DE CÓDIGO       │
│  - Instrucciones programa   │
└─────────────────────────────┘
Baja dirección (0x00000000)

**Matriz Dinámica 2D**

int **matriz = malloc(3 * sizeof(int*));
for (int i = 0; i < 3; i++)
    matriz[i] = malloc(4 * sizeof(int));

matriz (puntero a punteros)
  ↓
┌─────┐
│  ●──┼───→ ┌───┬───┬───┬───┐
├─────┤     │ 0 │ 1 │ 2 │ 3 │ Fila 0 (0x400)
│  ●──┼───→ ├───┼───┼───┼───┤
├─────┤     │ 4 │ 5 │ 6 │ 7 │ Fila 1 (0x450)
│  ●──┼───→ ├───┼───┼───┼───┤
└─────┘     │ 8 │ 9 │10 │11 │ Fila 2 (0x500)
(0x300)     └───┴───┴───┴───┘

Acceso: matriz[i][j] → *(*(matriz + i) + j)

**Paso por Valor vs Referencia**

// Paso por VALOR
void func1(int x) { x = 20; }

main: x=10          func1: parámetro x=10
┌────┐              ┌────┐
│ 10 │              │ 10 │ (copia)
└────┘              └────┘
                       ↓
                    ┌────┐
                    │ 20 │ (modificada)
                    └────┘
Resultado: x en main sigue siendo 10

// Paso por REFERENCIA
void func2(int *ptr) { *ptr = 20; }

main: x=10          func2: ptr
┌────┐              ┌────┐
│ 10 │ ←────────────│0x..│ (apunta a x)
└────┘              └────┘
  ↓
┌────┐
│ 20 │ (x modificado)
└────┘
Resultado: x en main ahora es 20

**Const con Punteros**

// const int *ptr
┌──────┐     ┌──────┐
│ ptr  │────→│ 10   │ ✗ no se puede modificar
└──────┘     └──────┘
   ↕ puede cambiar

// int * const ptr
┌──────┐     ┌──────┐
│ ptr  │────→│ 10   │ ✓ se puede modificar
└──────┘     └──────┘
   ✗ no puede cambiar

// const int * const ptr
┌──────┐     ┌──────┐
│ ptr  │────→│ 10   │ ✗ no se puede modificar
└──────┘     └──────┘
   ✗ no puede cambiar

---

## 15. Casos de Uso Avanzados

**Pool de Memoria (Memory Pool)**

Útil para evitar fragmentación y mejorar rendimiento en asignaciones frecuentes.
