# Programación en C - Arreglos y Cadenas: Guía Completa

## Contenido de la Guía
1. [Introducción a Arreglos](#1-introducción-a-arreglos)
2. [Arreglos Unidimensionales](#2-arreglos-unidimensionales)
3. [Operaciones Avanzadas con Arreglos](#3-operaciones-avanzadas-con-arreglos)
4. [Arreglos Multidimensionales](#4-arreglos-multidimensionales)
5. [Introducción a Cadenas de Caracteres](#5-introducción-a-cadenas-de-caracteres)
6. [Manipulación de Cadenas](#6-manipulación-de-cadenas)
7. [Ejercicios Integrados](#7-ejercicios-integrados)
8. [Debugging y Mejores Prácticas](#8-debugging-y-mejores-prácticas)
9. [Resumen y Conceptos Clave](#9-resumen-y-conceptos-clave)

---

## Objetivos de Aprendizaje

Al finalizar esta guía, serás capaz de:
- Comprender cómo se almacenan los arreglos en memoria
- Implementar algoritmos básicos de búsqueda y ordenamiento
- Trabajar eficientemente con matrices multidimensionales
- Manipular cadenas de caracteres usando funciones estándar
- Aplicar técnicas de debugging para problemas comunes
- Desarrollar programas robustos y seguros en C

---

## 1. Introducción a Arreglos

### Concepto Fundamental
Un **arreglo** es una estructura de datos que permite almacenar múltiples elementos del mismo tipo en una secuencia contigua de memoria. Es como una fila de casilleros numerados: todos tienen el mismo tamaño y tipo de datos, y se accede a ellos por un número llamado **índice**.

### Representación en Memoria
```c
int numeros[5] = {10, 20, 30, 40, 50};
```

```
Memoria:
┌────┬────┬────┬────┬────┐
│ 10 │ 20 │ 30 │ 40 │ 50 │
└────┴────┴────┴────┴────┘
  ↑    ↑    ↑    ↑    ↑
 [0]  [1]  [2]  [3]  [4]
```

### Ventajas y Limitaciones

**Ventajas:**
- Acceso directo O(1) a cualquier elemento
- Uso eficiente de memoria (almacenamiento contiguo)
- Compatibilidad con operaciones aritméticas de punteros

**Limitaciones:**
- Tamaño fijo (determinado en tiempo de compilación)
- No hay verificación automática de límites
- Inserción/eliminación de elementos es costosa

### Características Importantes
- Los índices van de 0 a (tamaño-1)
- El tamaño debe ser una constante conocida en tiempo de compilación
- Todos los elementos son del mismo tipo de dato
- Los elementos se almacenan en posiciones consecutivas de memoria

---

## 2. Arreglos Unidimensionales

### Declaración de Arreglos

La sintaxis básica para declarar un arreglo es:
```c
tipo_dato nombre_arreglo[tamaño];
```

**Ejemplos:**
```c
int numeros[10];        // Arreglo de 10 enteros
float temperaturas[7];  // Arreglo de 7 números flotantes  
char letras[26];        // Arreglo de 26 caracteres
double precios[100];    // Arreglo de 100 números double
```

### Métodos de Inicialización

#### Inicialización Directa
```c
int numeros[5] = {10, 20, 30, 40, 50};
float notas[4] = {8.5, 9.0, 7.2, 6.8};
char vocales[5] = {'a', 'e', 'i', 'o', 'u'};
```

#### Inicialización Parcial
Si proporcionamos menos valores que el tamaño del arreglo, los elementos restantes se inicializan automáticamente a 0:
```c
int datos[10] = {1, 2, 3};  // Solo los primeros 3 elementos tienen valor
// datos = {1, 2, 3, 0, 0, 0, 0, 0, 0, 0}
```

#### Inicialización Automática del Tamaño
El compilador puede determinar automáticamente el tamaño basándose en los valores iniciales:
```c
int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// Automáticamente crea un arreglo de 12 elementos
```

#### Inicialización con Designadores (C99+)
```c
int designado[5] = {[0] = 1, [4] = 5}; // {1, 0, 0, 0, 5}
```

#### Inicialización a Cero
Para inicializar todos los elementos a cero:
```c
int arreglo[100] = {0};  // Todos los elementos serán 0
```

### Acceso a Elementos del Arreglo

Para acceder a un elemento específico, usamos el operador de índice []:

```c
int numeros[5] = {10, 20, 30, 40, 50};

// Lectura
printf("El primer elemento es: %d\n", numeros[0]);  // Imprime 10
printf("El tercer elemento es: %d\n", numeros[2]);  // Imprime 30

// Escritura
numeros[1] = 25;  // Cambia el segundo elemento a 25
numeros[4] = 55;  // Cambia el quinto elemento a 55
```

### Ejemplo Práctico: Sistema de Calificaciones

```c
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
```

### Recorrido de Arreglos con Bucles

#### Usando Bucle for
El bucle `for` es la forma más común y eficiente de recorrer arreglos:

```c
int numeros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int suma = 0;

// Recorrido para calcular la suma
for(int i = 0; i < 10; i++) {
    suma += numeros[i];
}

printf("La suma total es: %d\n", suma);
```

#### Encontrar el Elemento Mayor
```c
int numeros[8] = {23, 67, 12, 89, 34, 56, 78, 45};
int mayor = numeros[0];  // Asumimos que el primero es el mayor

for(int i = 1; i < 8; i++) {
    if(numeros[i] > mayor) {
        mayor = numeros[i];
    }
}

printf("El elemento mayor es: %d\n", mayor);
```

#### Buscar un Elemento
```c
int numeros[6] = {10, 25, 30, 45, 50, 60};
int buscar = 30;
int encontrado = 0;

for(int i = 0; i < 6; i++) {
    if(numeros[i] == buscar) {
        printf("Elemento %d encontrado en la posición %d\n", buscar, i);
        encontrado = 1;
        break;
    }
}

if(!encontrado) {
    printf("Elemento %d no encontrado\n", buscar);
}
```

---

## 3. Operaciones Avanzadas con Arreglos

### Algoritmos de Búsqueda

#### Búsqueda Lineal
```c
int busqueda_lineal(int arreglo[], int tamaño, int elemento) {
    for (int i = 0; i < tamaño; i++) {
        if (arreglo[i] == elemento) {
            return i;  // Retorna el índice donde se encontró
        }
    }
    return -1;  // Elemento no encontrado
}

// Versión que cuenta ocurrencias
int contar_ocurrencias(int arreglo[], int tamaño, int elemento) {
    int contador = 0;
    for (int i = 0; i < tamaño; i++) {
        if (arreglo[i] == elemento) {
            contador++;
        }
    }
    return contador;
}
```

#### Búsqueda Binaria (para arreglos ordenados)
```c
int busqueda_binaria(int arreglo[], int tamaño, int elemento) {
    int izquierda = 0;
    int derecha = tamaño - 1;
    
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        
        if (arreglo[medio] == elemento) {
            return medio;
        }
        
        if (arreglo[medio] < elemento) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }
    
    return -1;  // Elemento no encontrado
}
```

### Algoritmos de Ordenamiento

#### Ordenamiento Burbuja (Bubble Sort)
```c
void ordenamiento_burbuja(int arreglo[], int tamaño) {
    for (int i = 0; i < tamaño - 1; i++) {
        int intercambio = 0;  // Optimización: detectar si ya está ordenado
        
        for (int j = 0; j < tamaño - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                // Intercambiar elementos
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
                intercambio = 1;
            }
        }
        
        if (!intercambio) {
            break;  // Arreglo ya está ordenado
        }
    }
}
```

#### Ordenamiento por Selección
```c
void ordenamiento_seleccion(int arreglo[], int tamaño) {
    for (int i = 0; i < tamaño - 1; i++) {
        int indice_minimo = i;
        
        // Encontrar el elemento mínimo en el resto del arreglo
        for (int j = i + 1; j < tamaño; j++) {
            if (arreglo[j] < arreglo[indice_minimo]) {
                indice_minimo = j;
            }
        }
        
        // Intercambiar si se encontró un elemento menor
        if (indice_minimo != i) {
            int temp = arreglo[i];
            arreglo[i] = arreglo[indice_minimo];
            arreglo[indice_minimo] = temp;
        }
    }
}
```

#### Ordenamiento por Inserción
```c
void ordenamiento_insercion(int arreglo[], int tamaño) {
    for (int i = 1; i < tamaño; i++) {
        int clave = arreglo[i];
        int j = i - 1;
        
        // Mover elementos mayores que la clave una posición adelante
        while (j >= 0 && arreglo[j] > clave) {
            arreglo[j + 1] = arreglo[j];
            j--;
        }
        
        arreglo[j + 1] = clave;
    }
}
```

### Operaciones de Manipulación

#### Insertar Elemento
```c
#include <stdbool.h>

bool insertar_elemento(int arreglo[], int *tamaño, int capacidad, int elemento, int posicion) {
    // Validar parámetros
    if (*tamaño >= capacidad || posicion < 0 || posicion > *tamaño) {
        return false;
    }
    
    // Desplazar elementos hacia la derecha
    for (int i = *tamaño; i > posicion; i--) {
        arreglo[i] = arreglo[i - 1];
    }
    
    // Insertar el nuevo elemento
    arreglo[posicion] = elemento;
    (*tamaño)++;
    
    return true;
}
```

#### Eliminar Elemento
```c
bool eliminar_elemento(int arreglo[], int *tamaño, int posicion) {
    // Validar parámetros
    if (*tamaño <= 0 || posicion < 0 || posicion >= *tamaño) {
        return false;
    }
    
    // Desplazar elementos hacia la izquierda
    for (int i = posicion; i < *tamaño - 1; i++) {
        arreglo[i] = arreglo[i + 1];
    }
    
    (*tamaño)--;
    return true;
}
```

#### Invertir Arreglo
```c
void invertir_arreglo(int arreglo[], int tamaño) {
    int inicio = 0;
    int fin = tamaño - 1;
    
    while (inicio < fin) {
        // Intercambiar elementos
        int temp = arreglo[inicio];
        arreglo[inicio] = arreglo[fin];
        arreglo[fin] = temp;
        
        inicio++;
        fin--;
    }
}
```

---

## 4. Arreglos Multidimensionales

### Conceptos Avanzados de Matrices

Los arreglos multidimensionales son arreglos de arreglos. Los más comunes son los arreglos bidimensionales (matrices), que se pueden visualizar como tablas con filas y columnas.

#### Declaración de Matrices
```c
tipo_dato nombre_matriz[filas][columnas];
```

**Ejemplos:**
```c
int matriz[3][4];        // Matriz de 3 filas y 4 columnas
float tabla[5][5];       // Matriz cuadrada de 5x5
char tablero[8][8];      // Tablero de ajedrez 8x8
```

#### Representación en Memoria
```c
int matriz[3][4];  // 3 filas × 4 columnas

// Representación en memoria:
// [0][0] [0][1] [0][2] [0][3] [1][0] [1][1] [1][2] [1][3] [2][0] [2][1] [2][2] [2][3]
```

### Inicialización de Matrices

#### Inicialización por Filas
```c
int matriz[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
```

#### Inicialización Lineal
```c
int matriz[2][4] = {1, 2, 3, 4, 5, 6, 7, 8};
// Equivale a:
// {{1, 2, 3, 4},
//  {5, 6, 7, 8}}
```

#### Inicialización con Designadores
```c
int matriz_identidad[4][4] = {
    [0] = {1, 0, 0, 0},
    [1] = {0, 1, 0, 0},
    [2] = {0, 0, 1, 0},
    [3] = {0, 0, 0, 1}
};  // Matriz identidad
```

### Acceso a Elementos de Matrices
```c
int matriz[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// Acceso a elementos específicos
printf("Elemento en fila 0, columna 1: %d\n", matriz[0][1]);  // Imprime 2
printf("Elemento en fila 2, columna 2: %d\n", matriz[2][2]);  // Imprime 9

// Modificar elementos
matriz[1][1] = 50;  // Cambia el elemento central a 50
```

### Recorrido de Matrices con Bucles Anidados

#### Recorrido Completo
```c
int matriz[3][4] = {
    {1,  2,  3,  4},
    {5,  6,  7,  8},
    {9, 10, 11, 12}
};

printf("Contenido de la matriz:\n");
for(int i = 0; i < 3; i++) {        // Recorre las filas
    for(int j = 0; j < 4; j++) {    // Recorre las columnas
        printf("%3d ", matriz[i][j]);
    }
    printf("\n");  // Nueva línea al final de cada fila
}
```

### Operaciones con Matrices

#### Suma de Matrices
```c
bool sumar_matrices(int a[][4], int b[][4], int resultado[][4], int filas) {
    if (filas <= 0) return false;
    
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < 4; j++) {
            resultado[i][j] = a[i][j] + b[i][j];
        }
    }
    return true;
}
```

#### Transpuesta de Matriz
```c
void transponer_matriz(int matriz[][4], int transpuesta[][4], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
    }
}
```

#### Multiplicación de Matrices
```c
void multiplicar_matrices(int a[][3], int b[][3], int resultado[][3], int filas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                resultado[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
```

---

## 5. Introducción a Cadenas de Caracteres

### Concepto de String en C
En C, una cadena de caracteres (string) es un arreglo de caracteres que termina con el carácter nulo (`'\0'`). Este carácter especial indica el final de la cadena.

```c
// Declaración e inicialización de strings
char saludo1[] = "Hola Mundo";     // Tamaño automático: 11 caracteres (10 + '\0')
char saludo2[20] = "Hola";         // Reserva 20 espacios, usa 5 (4 + '\0')
char saludo3[] = {'H', 'o', 'l', 'a', '\0'};  // Inicialización carácter por carácter

// Representación en memoria de "Hola":
// [H][o][l][a][\0]
//  0  1  2  3   4
```

### Declaración e Inicialización de Strings

```c
#include <stdio.h>
#include <string.h>

// Diferentes formas de declarar strings
char nombre[50];                    // String vacío de 50 caracteres
char apellido[30] = "";            // String vacío explícito
char ciudad[20] = "Madrid";        // Inicialización directa
char pais[] = "España";            // Tamaño automático
char mensaje[100] = {'H', 'o', 'l', 'a', '\0'};  // Inicialización por caracteres

// String literal (almacenado en memoria de solo lectura)
char *frase = "Esta es una cadena literal";
```

### Lectura y Escritura de Strings

#### Métodos de Entrada
```c
#include <stdio.h>

int main() {
    char nombre[50];
    char apellido[50];
    char linea_completa[100];
    
    // Método 1: scanf() - no lee espacios
    printf("Ingrese su nombre: ");
    scanf("%s", nombre);  // No necesita & para strings
    
    // Método 2: scanf() con especificador de ancho
    printf("Ingrese su apellido (máx 49 chars): ");
    scanf("%49s", apellido);
    
    // Limpiar buffer antes de fgets
    while (getchar() != '\n');
    
    // Método 3: fgets() - lee línea completa incluyendo espacios
    printf("Ingrese una línea completa: ");
    fgets(linea_completa, sizeof(linea_completa), stdin);
    
    printf("\nResultados:\n");
    printf("Nombre: %s\n", nombre);
    printf("Apellido: %s\n", apellido);
    printf("Línea completa: %s", linea_completa);  // fgets incluye \n
    
    return 0;
}
```

#### Función Segura para Leer Strings
```c
#include <stdio.h>
#include <string.h>

void leer_string_seguro(char *cadena, int tamaño_max, const char *mensaje) {
    printf("%s", mensaje);
    fgets(cadena, tamaño_max, stdin);
    
    // Eliminar el salto de línea si existe
    size_t len = strlen(cadena);
    if (len > 0 && cadena[len - 1] == '\n') {
        cadena[len - 1] = '\0';
    }
}

int main() {
    char nombre[50];
    char ciudad[30];
    
    leer_string_seguro(nombre, sizeof(nombre), "Ingrese su nombre: ");
    leer_string_seguro(ciudad, sizeof(ciudad), "Ingrese su ciudad: ");
    
    printf("Hola %s, eres de %s\n", nombre, ciudad);
    
    return 0;
}
```

---

## 6. Manipulación de Cadenas

### Funciones de la Biblioteca <string.h>

#### Funciones Básicas
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Programación";
    char str2[50] = "en C";
    char str3[100];
    char str4[] = "programación";  // Para comparación
    
    // strlen() - longitud de cadena
    printf("Longitud de '%s': %zu\n", str1, strlen(str1));
    
    // strcpy() - copiar cadena
    strcpy(str3, str1);
    printf("Copia: %s\n", str3);
    
    // strcat() - concatenar cadenas
    strcat(str1, " ");  // Agregar espacio
    strcat(str1, str2); // Agregar segunda cadena
    printf("Concatenación: %s\n", str1);
    
    // strcmp() - comparar cadenas (sensible a mayúsculas)
    int resultado = strcmp(str3, str4);
    if (resultado == 0) {
        printf("Las cadenas son iguales\n");
    } else if (resultado > 0) {
        printf("'%s' es mayor que '%s'\n", str3, str4);
    } else {
        printf("'%s' es menor que '%s'\n", str3, str4);
    }
    
    // strchr() - buscar carácter
    char *ptr = strchr(str1, 'C');
    if (ptr != NULL) {
        printf("Carácter 'C' encontrado en posición: %ld\n", ptr - str1);
    }
    
    // strstr() - buscar subcadena
    char *sub = strstr(str1, "en");
    if (sub != NULL) {
        printf("Subcadena 'en' encontrada en posición: %ld\n", sub - str1);
    }
    
    return 0;
}
```

### Funciones de la Biblioteca <string.h> más usadas

| Función | Descripción | Ejemplo |
|---------|-------------|---------|
| `strlen()` | Longitud de cadena | `strlen("Hola")` → 4 |
| `strcpy()` | Copiar cadena | `strcpy(dest, "Hola")` |
| `strncpy()` | Copiar con límite | `strncpy(dest, src, 10)` |
| `strcat()` | Concatenar cadenas | `strcat(str1, str2)` |
| `strncat()` | Concatenar con límite | `strncat(str1, str2, 5)` |
| `strcmp()` | Comparar cadenas | `strcmp("abc", "def")` → -1 |
| `strncmp()` | Comparar con límite | `strncmp(str1, str2, 3)` |
| `strchr()` | Buscar carácter | `strchr("Hola", 'a')` → ptr a 'a' |
| `strstr()` | Buscar subcadena | `strstr("Hola mundo", "mundo")` |
| `strcasecmp()` | Comparar sin distinción de mayúsculas | `strcasecmp("HOLA", "hola")` → 0 |

### Funciones Personalizadas para Strings

#### Longitud de Cadena (implementación propia)
```c
int mi_strlen(const char *str) {
    int longitud = 0;
    while (str[longitud] != '\0') {
        longitud++;
    }
    return longitud;
}
```

#### Copia de Cadena (implementación propia)
```c
void mi_strcpy(char *destino, const char *origen) {
    int i = 0;
    while (origen[i] != '\0') {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0';  // Agregar terminador nulo
}
```

#### Comparación de Cadenas (implementación propia)
```c
int mi_strcmp(const char *str1, const char *str2) {
    int i = 0;
    
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    
    return str1[i] - str2[i];
}
```

### Procesamiento Avanzado de Strings

#### Convertir a Mayúsculas/Minúsculas
```c
#include <ctype.h>

void a_mayusculas(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void a_minusculas(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

// Convertir primera letra de cada palabra a mayúscula
void titulo(char *str) {
    int nueva_palabra = 1;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            if (nueva_palabra) {
                str[i] = toupper(str[i]);
                nueva_palabra = 0;
            } else {
                str[i] = tolower(str[i]);
            }
        } else {
            nueva_palabra = 1;
        }
    }
}
```

#### Contar Palabras
```c
int contar_palabras(const char *str) {
    int contador = 0;
    int en_palabra = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            if (!en_palabra) {
                contador++;
                en_palabra = 1;
            }
        } else {
            en_palabra = 0;
        }
    }
    
    return contador;
}
```

#### Eliminar Espacios en Blanco
```c
// Eliminar espacios al principio y al final
void trim(char *str) {
    int inicio = 0, fin = strlen(str) - 1;
    
    // Encontrar el primer carácter no espacio
    while (str[inicio] != '\0' && isspace(str[inicio])) {
        inicio++;
    }
    
    // Encontrar el último carácter no espacio
    while (fin >= 0 && isspace(str[fin])) {
        fin--;
    }
    
    // Mover la cadena y agregar terminador
    int j = 0;
    for (int i = inicio; i <= fin; i++) {
        str[j++] = str[i];
    }
    str[j] = '\0';
}

// Eliminar espacios duplicados
void eliminar_espacios_duplicados(char *str) {
    int j = 0;
    int espacio_previo = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            str[j++] = str[i];
            espacio_previo = 0;
        } else if (!espacio_previo) {
            str[j++] = ' ';
            espacio_previo = 1;
        }
    }
    str[j] = '\0';
}
```

---

## 7. Ejercicios Integrados

### Ejercicio 1: Analizador de Texto Completo

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXTO 1000

void analizar_texto(const char *texto) {
    int caracteres = strlen(texto);
    int palabras = 0;
    int lineas = 1;  // Al menos una línea
    int vocales = 0, consonantes = 0;
    int digitos = 0, espacios = 0, puntuacion = 0;
    int en_palabra = 0;
    
    printf("\n=== ANÁLISIS DE TEXTO ===\n");
    
    for (int i = 0; texto[i] != '\0'; i++) {
        char c = tolower(texto[i]);
        
        // Contar líneas
        if (texto[i] == '\n') {
            lineas++;
        }
        
        // Contar palabras
        if (!isspace(texto[i])) {
            if (!en_palabra) {
                palabras++;
                en_palabra = 1;
            }
        } else {
            en_palabra = 0;
        }
        
        // Clasificar caracteres
        if (isalpha(c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vocales++;
            } else {
                consonantes++;
            }
        } else if (isdigit(c)) {
            digitos++;
        } else if (isspace(c)) {
            espacios++;
        } else {
            puntuacion++;
        }
    }
    
    // Mostrar resultados
    printf("Total de caracteres: %d\n", caracteres);
    printf("Palabras: %d\n", palabras);
    printf("Líneas: %d\n", lineas);
    printf("Vocales: %d\n", vocales);
    printf("Consonantes: %d\n", consonantes);
    printf("Dígitos: %d\n", digitos);
    printf("Espacios: %d\n", espacios);
    printf("Signos de puntuación: %d\n", puntuacion);
    
    if (palabras > 0) {
        printf("Promedio de caracteres por palabra: %.2f\n", 
               (float)(caracteres - espacios) / palabras);
    }
}

int main() {
    char texto[MAX_TEXTO];
    
    printf("Ingrese un texto (terminar con Enter en línea vacía):\n");
    
    // Leer texto completo
    int pos = 0;
    char linea[200];
    
    while (fgets(linea, sizeof(linea), stdin) && strcmp(linea, "\n") != 0) {
        int len = strlen(linea);
        if (pos + len < MAX_TEXTO - 1) {
            strcpy(texto + pos, linea);
            pos += len;
        } else {
            printf("Texto demasiado largo.\n");
            break;
        }
    }
    texto[pos] = '\0';
    
    if (strlen(texto) > 0) {
        analizar_texto(texto);
    } else {
        printf("No se ingresó texto.\n");
    }
    
    return 0;
}
```

### Ejercicio 2: Sistema de Inventario con Matrices

```c
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 10
#define MAX_SUCURSALES 5
#define MAX_NOMBRE 50

typedef struct {
    char nombre[MAX_NOMBRE];
    int codigo;
} Producto;

void mostrar_inventario(int inventario[][MAX_SUCURSALES], Producto productos[], 
                       int num_productos, int num_sucursales) {
    printf("\n=== INVENTARIO ACTUAL ===\n");
    printf("%-20s", "Producto");
    
    for (int j = 0; j < num_sucursales; j++) {
        printf("Suc%d\t", j + 1);
    }
    printf("Total\n");
    printf("%-20s", "--------");
    
    for (int j = 0; j < num_sucursales; j++) {
        printf("----\t");
    }
    printf("-----\n");
    
    for (int i = 0; i < num_productos; i++) {
        printf("%-20s", productos[i].nombre);
        int total_producto = 0;
        
        for (int j = 0; j < num_sucursales; j++) {
            printf("%d\t", inventario[i][j]);
            total_producto += inventario[i][j];
        }
        printf("%d\n", total_producto);
    }
    
    // Totales por sucursal
    printf("%-20s", "TOTAL:");
    int gran_total = 0;
    
    for (int j = 0; j < num_sucursales; j++) {
        int total_sucursal = 0;
        for (int i = 0; i < num_productos; i++) {
            total_sucursal += inventario[i][j];
        }
        printf("%d\t", total_sucursal);
        gran_total += total_sucursal;
    }
    printf("%d\n", gran_total);
}

void buscar_producto(int inventario[][MAX_SUCURSALES], Producto productos[], 
                    int num_productos, int num_sucursales) {
    char buscar[MAX_NOMBRE];
    printf("\nIngrese nombre del producto a buscar: ");
    scanf("%s", buscar);
    
    for (int i = 0; i < num_productos; i++) {
        if (strcmp(productos[i].nombre, buscar) == 0) {
            printf("\nProducto encontrado: %s (Código: %d)\n", 
                   productos[i].nombre, productos[i].codigo);
            printf("Stock por sucursal:\n");
            
            for (int j = 0; j < num_sucursales; j++) {
                printf("Sucursal %d: %d unidades\n", j + 1, inventario[i][j]);
            }
            return;
        }
    }
    
    printf("Producto no encontrado.\n");
}

void transferir_stock(int inventario[][MAX_SUCURSALES], Producto productos[], 
                     int num_productos, int num_sucursales) {
    int producto, origen, destino, cantidad;
    
    printf("\nSeleccione producto (0-%d): ", num_productos - 1);
    scanf("%d", &producto);
    
    if (producto < 0 || producto >= num_productos) {
        printf("Producto inválido.\n");
        return;
    }
    
    printf("Sucursal origen (1-%d): ", num_sucursales);
    scanf("%d", &origen);
    origen--; // Convertir a índice
    
    printf("Sucursal destino (1-%d): ", num_sucursales);
    scanf("%d", &destino);
    destino--; // Convertir a índice
    
    if (origen < 0 || origen >= num_sucursales || 
        destino < 0 || destino >= num_sucursales || origen == destino) {
        printf("Sucursales inválidas.\n");
        return;
    }
    
    printf("Cantidad a transferir: ");
    scanf("%d", &cantidad);
    
    if (cantidad <= 0 || cantidad > inventario[producto][origen]) {
        printf("Cantidad inválida o insuficiente stock.\n");
        return;
    }
    
    inventario[producto][origen] -= cantidad;
    inventario[producto][destino] += cantidad;
    
    printf("Transferencia realizada exitosamente.\n");
}

int main() {
    int inventario[MAX_PRODUCTOS][MAX_SUCURSALES] = {
        {100, 150, 200, 80, 120},   // Producto 0
        {50, 75, 100, 25, 60},      // Producto 1
        {200, 180, 220, 160, 190},  // Producto 2
        {30, 45, 60, 15, 35},       // Producto 3
        {80, 95, 110, 70, 85}       // Producto 4
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
    
    do {
        printf("\n=== SISTEMA DE INVENTARIO ===\n");
        printf("1. Mostrar inventario completo\n");
        printf("2. Buscar producto\n");
        printf("3. Transferir stock entre sucursales\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                mostrar_inventario(inventario, productos, num_productos, num_sucursales);
                break;
            case 2:
                buscar_producto(inventario, productos, num_productos, num_sucursales);
                break;
            case 3:
                transferir_stock(inventario, productos, num_productos, num_sucursales);
                break;
            case 4:
                printf("¡Hasta luego!\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 4);
    
    return 0;
}
```

### Ejercicio 3: Procesador de Nombres

```c
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
```

---

## 8. Debugging y Mejores Prácticas

### Errores Comunes con Arreglos

#### 1. Acceso Fuera de Límites
```c
// ERROR: Acceder a índice inválido
int numeros[5] = {1, 2, 3, 4, 5};
printf("%d", numeros[5]);  // ¡ERROR! Índice válido: 0-4

// CORRECTO: Validar índices
int indice = 5;
if (indice >= 0 && indice < 5) {
    printf("%d", numeros[indice]);
} else {
    printf("Índice fuera de rango\n");
}
```

#### 2. No Inicializar Arreglos
```c
// PROBLEMÁTICO: Valores basura
int arreglo[10];
for (int i = 0; i < 10; i++) {
    printf("%d ", arreglo[i]);  // Valores impredecibles
}

// CORRECTO: Inicializar
int arreglo[10] = {0};  // Todos los elementos en 0
```

#### 3. Confundir Tamaño con Último Índice
```c
// ERROR COMÚN
int arreglo[10];
for (int i = 0; i <= 10; i++) {  // ¡ERROR! Debería ser i < 10
    arreglo[i] = i;
}

// CORRECTO
for (int i = 0; i < 10; i++) {
    arreglo[i] = i;
}
```

### Errores Comunes con Strings

#### 1. Olvidar el Carácter Nulo
```c
// ERROR: No terminar correctamente la cadena
char nombre[10];
nombre[0] = 'J';
nombre[1] = 'u';
nombre[2] = 'a';
nombre[3] = 'n';
// ¡Falta el '\0'!

// CORRECTO
char nombre[10] = "Juan";  // Automáticamente agrega '\0'
// O manualmente:
nombre[4] = '\0';
```

#### 2. Buffer Overflow
```c
// PELIGROSO: Sin validar tamaño
char destino[10];
strcpy(destino, "Esta cadena es demasiado larga");  // ¡Desbordamiento!

// SEGURO: Usar funciones con límite
char destino[10];
strncpy(destino, "Cadena larga", sizeof(destino) - 1);
destino[sizeof(destino) - 1] = '\0';  // Asegurar terminación
```

#### 3. Modificar String Literals
```c
// ERROR: Intentar modificar literal
char *str = "Hola";
str[0] = 'h';  // ¡Comportamiento indefinido!

// CORRECTO: Usar arreglo
char str[] = "Hola";
str[0] = 'h';  // Ahora es seguro
```

### Técnicas de Debugging

#### 1. Imprimir Valores de Debug
```c
void debug_arreglo(int arr[], int tamaño, const char *mensaje) {
    printf("[DEBUG] %s: ", mensaje);
    for (int i = 0; i < tamaño; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Uso
int numeros[] = {3, 1, 4, 1, 5};
debug_arreglo(numeros, 5, "Antes de ordenar");
ordenar_burbuja(numeros, 5);
debug_arreglo(numeros, 5, "Después de ordenar");
```

#### 2. Validación de Parámetros
```c
int buscar_elemento_seguro(int arreglo[], int tamaño, int elemento) {
    // Validar parámetros
    if (arreglo == NULL || tamaño <= 0) {
        fprintf(stderr, "Error: Parámetros inválidos\n");
        return -2;  // Código de error diferente a "no encontrado"
    }
    
    for (int i = 0; i < tamaño; i++) {
        if (arreglo[i] == elemento) {
            return i;
        }
    }
    return -1;  // No encontrado
}
```

#### 3. Uso de Asserts para Depuración
```c
#include <assert.h>

void procesar_matriz(int matriz[][3], int filas) {
    assert(matriz != NULL);          // Verificar puntero válido
    assert(filas > 0 && filas <= 10); // Verificar rango válido
    
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < 3; j++) {
            assert(matriz[i][j] >= 0);  // Verificar valores válidos
            // Procesar elemento...
        }
    }
}
```

### Mejores Prácticas

#### 1. Uso de Constantes
```c
#define MAX_ESTUDIANTES 50
#define MIN_NOTA 0
#define MAX_NOTA 100

int calificaciones[MAX_ESTUDIANTES];

// Mejor que números mágicos
for (int i = 0; i < MAX_ESTUDIANTES; i++) {
    if (calificaciones[i] >= 60) {  // Mejor usar constante
        // ...
    }
}
```

#### 2. Funciones para Operaciones Comunes
```c
// Función genérica para mostrar arreglos
void mostrar_arreglo(int arr[], int tamaño, const char *nombre) {
    printf("%s: [", nombre);
    for (int i = 0; i < tamaño; i++) {
        printf("%d", arr[i]);
        if (i < tamaño - 1) printf(", ");
    }
    printf("]\n");
}

// Función para validar entrada
int leer_entero_en_rango(int min, int max, const char *mensaje) {
    int valor;
    do {
        printf("%s (%d-%d): ", mensaje, min, max);
        scanf("%d", &valor);
        if (valor < min || valor > max) {
            printf("Valor fuera de rango. Intente nuevamente.\n");
        }
    } while (valor < min || valor > max);
    return valor;
}
```

#### 3. Manejo de Memoria y Límites
```c
// Siempre verificar límites
bool agregar_elemento_seguro(int arreglo[], int *tamaño, int capacidad, int elemento) {
    if (*tamaño >= capacidad) {
        printf("Error: Arreglo lleno\n");
        return false;
    }
    
    arreglo[(*tamaño)++] = elemento;
    return true;
}

// Para strings, siempre reservar espacio para '\0'
char buffer[100];  // Para 99 caracteres + '\0'
fgets(buffer, sizeof(buffer), stdin);
```

---

## 9. Resumen y Conceptos Clave

### Conceptos Fundamentales de Arreglos

**Definición**: Los arreglos son estructuras de datos que almacenan elementos del mismo tipo en posiciones consecutivas de memoria.

**Características clave**:
- Acceso directo O(1) por índice
- Tamaño fijo determinado en compilación
- Índices van de 0 a n-1
- No hay verificación automática de límites

**Operaciones básicas**:
- Acceso: `arreglo[indice]`
- Recorrido: bucles `for`
- Búsqueda: lineal y binaria
- Ordenamiento: burbuja, selección, inserción

### Conceptos Fundamentales de Strings

**Definición**: Las cadenas en C son arreglos de caracteres terminados en '\0'.

**Características clave**:
- Terminación obligatoria con carácter nulo
- Funciones especializadas en `<string.h>`
- Vulnerables a buffer overflow
- Inmutabilidad de literales de cadena

**Operaciones básicas**:
- Longitud: `strlen()`
- Copia: `strcpy()`, `strncpy()`
- Concatenación: `strcat()`, `strncat()`
- Comparación: `strcmp()`, `strncmp()`

### Matrices (Arreglos Multidimensionales)

**Definición**: Arreglos de arreglos que forman estructuras rectangulares.

**Características clave**:
- Almacenamiento por filas en memoria
- Acceso con múltiples índices: `matriz[fila][columna]`
- Útiles para representar datos tabulares
- Recorrido con bucles anidados

### Algoritmos Importantes

#### Búsqueda
- **Lineal**: O(n) - para arreglos no ordenados
- **Binaria**: O(log n) - para arreglos ordenados

#### Ordenamiento
- **Burbuja**: O(n²) - simple, ineficiente para grandes datos
- **Selección**: O(n²) - menos intercambios que burbuja
- **Inserción**: O(n²) - eficiente para datos casi ordenados

### Buenas Prácticas Esenciales

1. **Validación de límites**: Siempre verificar índices válidos
2. **Inicialización**: Nunca usar arreglos sin inicializar
3. **Constantes**: Usar `#define` para tamaños y límites
4. **Funciones seguras**: Preferir versiones con límite (`strncpy`, `strncat`)
5. **Manejo de errores**: Validar parámetros y condiciones

### Errores Críticos a Evitar

1. **Buffer overflow**: Escribir fuera de los límites del arreglo
2. **Acceso fuera de límites**: Usar índices inválidos
3. **Strings no terminados**: Olvidar el carácter '\0'
4. **Modificar literales**: Intentar cambiar string constants
5. **Comparación incorrecta**: Usar `==` en lugar de `strcmp()` para strings

### Herramientas de Debugging

1. **Prints de depuración**: Mostrar valores en puntos críticos
2. **Asserts**: Verificar precondiciones y postcondiciones
3. **Validación de parámetros**: Comprobar entrada de funciones
4. **Herramientas externas**: Valgrind, gdb para análisis profundo

### Aplicaciones Prácticas

- **Sistemas de inventario**: Matrices para stock por ubicación
- **Análisis de texto**: Conteo de caracteres, palabras, estadísticas
- **Procesamiento de datos**: Ordenamiento, búsqueda, filtrado
- **Juegos**: Tableros, coordenadas, estados de juego
- **Bases de datos simples**: Almacenamiento estructurado de información

### Próximos Pasos

Una vez dominados estos conceptos, considera estudiar:
- Punteros y arreglos dinámicos
- Estructuras de datos más complejas (listas, árboles)
- Algoritmos de ordenamiento avanzados (quicksort, mergesort)
- Manejo de archivos con arreglos
- Programación con múltiples dimensiones

---

## Conclusión

Los arreglos y cadenas son fundamentos esenciales en C que proporcionan la base para estructuras de datos más complejas. Su dominio es crucial para desarrollar programas eficientes y seguros. La práctica constante con estos conceptos, junto con la aplicación de buenas prácticas de programación, te permitirá crear aplicaciones robustas y mantenibles.

Recuerda que la seguridad en el manejo de memoria y la validación de límites son aspectos críticos que distinguen al programador experimentado del principiante. ¡Sigue practicando y experimentando con estos conceptos!