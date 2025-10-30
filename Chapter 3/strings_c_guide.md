# Guía Completa de Strings en C

## Índice
1. [Introducción](#introducción)
2. [Conceptos Fundamentales](#conceptos-fundamentales)
3. [Declaración e Inicialización](#declaración-e-inicialización)
4. [Funciones de la Biblioteca string.h](#funciones-de-la-biblioteca-stringh)
5. [Entrada y Salida de Strings](#entrada-y-salida-de-strings)
6. [Manipulación Manual de Strings](#manipulación-manual-de-strings)
7. [Arrays de Strings](#arrays-de-strings)
8. [Gestión de Memoria Dinámica](#gestión-de-memoria-dinámica)
9. [Problemas Comunes y Soluciones](#problemas-comunes-y-soluciones)
10. [Ejemplos Prácticos](#ejemplos-prácticos)
11. [Mejores Prácticas](#mejores-prácticas)

## Introducción

En el lenguaje de programación C, los strings (cadenas de caracteres) no son un tipo de dato primitivo como en otros lenguajes. En su lugar, se representan como arrays de caracteres terminados en el carácter nulo (`\0`). Esta implementación proporciona flexibilidad pero también requiere un manejo cuidadoso de la memoria y una comprensión profunda de cómo funcionan internamente.

## Conceptos Fundamentales

### ¿Qué es un String en C?

Un string en C es una secuencia de caracteres almacenada en posiciones consecutivas de memoria, que termina con el carácter nulo (`\0`). Este carácter especial indica el final de la cadena y es crucial para que las funciones de manipulación de strings funcionen correctamente.

```c
// Representación en memoria de "Hola"
['H']['o']['l']['a']['\0']
```

### Características Principales

- **Terminación nula**: Todo string válido debe terminar con `\0`
- **Inmutabilidad de literales**: Los string literals son inmutables
- **Gestión manual de memoria**: El programador debe gestionar la memoria
- **Sin verificación de límites**: C no verifica automáticamente los límites de los arrays

## Declaración e Inicialización

### Métodos de Declaración

#### 1. Array de Caracteres con Tamaño Específico

```c
char nombre[50];  // Array de 50 caracteres (incluyendo \0)
```

#### 2. Inicialización con String Literal

```c
char saludo[] = "Hola mundo";  // Tamaño determinado automáticamente
char mensaje[20] = "Bienvenido"; // Tamaño específico con inicialización
```

#### 3. Inicialización Carácter por Carácter

```c
char palabra[] = {'H', 'o', 'l', 'a', '\0'};
```

#### 4. Puntero a String Literal

```c
char *texto = "Este es un string literal";
```

### Diferencias Entre Arrays y Punteros

```c
// Array de caracteres - modificable
char arr[] = "Modificable";
arr[0] = 'X';  // Válido

// Puntero a string literal - inmutable
char *ptr = "Inmutable";
// ptr[0] = 'X';  // Error! Comportamiento indefinido
```

## Funciones de la Biblioteca string.h

### Funciones de Longitud

#### strlen() - Calcular Longitud

```c
#include <string.h>

size_t strlen(const char *s);

// Ejemplo
char texto[] = "Hola mundo";
int longitud = strlen(texto);  // Retorna 10
```

### Funciones de Copia

#### strcpy() - Copia Simple

```c
char *strcpy(char *dest, const char *src);

// Ejemplo
char origen[] = "Fuente";
char destino[20];
strcpy(destino, origen);  // destino ahora contiene "Fuente"
```

#### strncpy() - Copia con Límite

```c
char *strncpy(char *dest, const char *src, size_t n);

// Ejemplo
char origen[] = "Texto muy largo";
char destino[10];
strncpy(destino, origen, 9);
destino[9] = '\0';  // Asegurar terminación nula
```

### Funciones de Concatenación

#### strcat() - Concatenación Simple

```c
char *strcat(char *dest, const char *src);

// Ejemplo
char saludo[20] = "Hola ";
char nombre[] = "Juan";
strcat(saludo, nombre);  // saludo ahora es "Hola Juan"
```

#### strncat() - Concatenación con Límite

```c
char *strncat(char *dest, const char *src, size_t n);

// Ejemplo
char buffer[30] = "Inicio: ";
char texto[] = "Final muy largo";
strncat(buffer, texto, 5);  // Agrega solo "Final"
```

### Funciones de Comparación

#### strcmp() - Comparación Completa

```c
int strcmp(const char *s1, const char *s2);

// Retorna: < 0 si s1 < s2, 0 si s1 == s2, > 0 si s1 > s2

// Ejemplo
char str1[] = "abc";
char str2[] = "abd";
int resultado = strcmp(str1, str2);  // Negativo (str1 < str2)
```

#### strncmp() - Comparación con Límite

```c
int strncmp(const char *s1, const char *s2, size_t n);

// Ejemplo
char str1[] = "abcdef";
char str2[] = "abcxyz";
int resultado = strncmp(str1, str2, 3);  // 0 (primeros 3 chars iguales)
```

### Funciones de Búsqueda

#### strchr() - Buscar Carácter

```c
char *strchr(const char *s, int c);

// Ejemplo
char texto[] = "Hola mundo";
char *posicion = strchr(texto, 'o');  // Apunta al primer 'o'
```

#### strstr() - Buscar Substring

```c
char *strstr(const char *haystack, const char *needle);

// Ejemplo
char frase[] = "El gato subió al tejado";
char *encontrado = strstr(frase, "gato");  // Apunta a "gato subió..."
```

#### strrchr() - Buscar Carácter desde el Final

```c
char *strrchr(const char *s, int c);

// Ejemplo
char ruta[] = "/home/usuario/documento.txt";
char *nombre = strrchr(ruta, '/') + 1;  // Apunta a "documento.txt"
```

## Entrada y Salida de Strings

### Funciones de Entrada

#### gets() - NO RECOMENDADA

```c
// ¡PELIGROSA! No verifica límites
char buffer[50];
gets(buffer);  // EVITAR - puede causar buffer overflow
```

#### fgets() - Entrada Segura

```c
char *fgets(char *s, int size, FILE *stream);

// Ejemplo seguro
char buffer[100];
printf("Ingrese texto: ");
fgets(buffer, sizeof(buffer), stdin);

// Remover salto de línea si existe
buffer[strcspn(buffer, "\n")] = '\0';
```

#### scanf() con Limitaciones

```c
char nombre[50];
scanf("%49s", nombre);  // Límite de 49 caracteres + \0
```

### Funciones de Salida

#### printf() y puts()

```c
char mensaje[] = "Hola mundo";

printf("%s\n", mensaje);  // Con formato
puts(mensaje);           // Automáticamente agrega \n
```

## Manipulación Manual de Strings

### Implementación de strlen()

```c
int mi_strlen(const char *str) {
    int longitud = 0;
    while (str[longitud] != '\0') {
        longitud++;
    }
    return longitud;
}
```

### Implementación de strcpy()

```c
char *mi_strcpy(char *dest, const char *src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') {
        i++;
    }
    return dest;
}
```

### Implementación de strcmp()

```c
int mi_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char*)s1 - *(unsigned char*)s2;
}
```

## Arrays de Strings

### Declaración e Inicialización

```c
// Array de punteros a strings
char *dias[] = {
    "Lunes",
    "Martes",
    "Miércoles",
    "Jueves",
    "Viernes",
    "Sábado",
    "Domingo"
};

// Array bidimensional de caracteres
char meses[][20] = {
    "Enero",
    "Febrero",
    "Marzo",
    // ...
};
```

### Recorrido de Arrays de Strings

```c
// Usando array de punteros
for (int i = 0; i < 7; i++) {
    printf("Día %d: %s\n", i + 1, dias[i]);
}

// Usando array bidimensional
int num_meses = sizeof(meses) / sizeof(meses[0]);
for (int i = 0; i < num_meses; i++) {
    printf("Mes %d: %s\n", i + 1, meses[i]);
}
```

## Gestión de Memoria Dinámica

### Asignación Dinámica para Strings

```c
#include <stdlib.h>

// Crear string dinámico
char *crear_string(int tamaño) {
    char *str = malloc(tamaño * sizeof(char));
    if (str == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria\n");
        exit(1);
    }
    return str;
}

// Liberar memoria
void liberar_string(char *str) {
    if (str != NULL) {
        free(str);
    }
}
```

### Redimensionamiento Dinámico

```c
char *redimensionar_string(char *str, int nuevo_tamaño) {
    char *nuevo_str = realloc(str, nuevo_tamaño * sizeof(char));
    if (nuevo_str == NULL) {
        fprintf(stderr, "Error: No se pudo redimensionar\n");
        free(str);  // Liberar memoria original
        exit(1);
    }
    return nuevo_str;
}
```

## Problemas Comunes y Soluciones

### Buffer Overflow

**Problema:**
```c
char buffer[10];
strcpy(buffer, "Este string es demasiado largo");  // PELIGRO!
```

**Solución:**
```c
char buffer[10];
strncpy(buffer, "Este string es demasiado largo", sizeof(buffer) - 1);
buffer[sizeof(buffer) - 1] = '\0';
```

### Memory Leaks

**Problema:**
```c
char *str = malloc(100);
strcpy(str, "Hola");
// Olvido de free(str) - memory leak!
```

**Solución:**
```c
char *str = malloc(100);
if (str != NULL) {
    strcpy(str, "Hola");
    // Usar el string...
    free(str);  // Liberar memoria
    str = NULL; // Evitar dangling pointer
}
```

### String sin Terminación Nula

**Problema:**
```c
char str[5];
strncpy(str, "Hola!", 5);  // No hay espacio para \0
```

**Solución:**
```c
char str[6];  // Espacio para \0
strncpy(str, "Hola!", sizeof(str) - 1);
str[sizeof(str) - 1] = '\0';
```

## Ejemplos Prácticos

### Invertir un String

```c
void invertir_string(char *str) {
    int longitud = strlen(str);
    int inicio = 0;
    int final = longitud - 1;
    
    while (inicio < final) {
        char temp = str[inicio];
        str[inicio] = str[final];
        str[final] = temp;
        inicio++;
        final--;
    }
}
```

### Contar Palabras

```c
int contar_palabras(const char *str) {
    int contador = 0;
    int en_palabra = 0;
    
    while (*str) {
        if (*str != ' ' && *str != '\t' && *str != '\n') {
            if (!en_palabra) {
                contador++;
                en_palabra = 1;
            }
        } else {
            en_palabra = 0;
        }
        str++;
    }
    
    return contador;
}
```

### Convertir a Mayúsculas

```c
#include <ctype.h>

void a_mayusculas(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}
```

### Eliminar Espacios en Blanco

```c
void eliminar_espacios(char *str) {
    char *src = str;
    char *dest = str;
    
    while (*src) {
        if (*src != ' ') {
            *dest = *src;
            dest++;
        }
        src++;
    }
    *dest = '\0';
}
```

## Mejores Prácticas

### 1. Verificación de Punteros Nulos

```c
void procesar_string(const char *str) {
    if (str == NULL) {
        fprintf(stderr, "Error: String nulo\n");
        return;
    }
    // Procesar el string...
}
```

### 2. Uso de const para Parámetros de Solo Lectura

```c
int calcular_longitud(const char *str) {
    // const garantiza que no modificaremos el string
    return strlen(str);
}
```

### 3. Verificación de Límites

```c
void copia_segura(char *dest, const char *src, size_t dest_size) {
    if (dest == NULL || src == NULL || dest_size == 0) {
        return;
    }
    
    strncpy(dest, src, dest_size - 1);
    dest[dest_size - 1] = '\0';
}
```

### 4. Inicialización Adecuada

```c
char buffer[100] = {0};  // Inicializar todo a 0
// o
char buffer[100];
buffer[0] = '\0';        // Marcar como string vacío
```

### 5. Uso de sizeof vs strlen

```c
char arr[] = "Hola";
int tamaño_array = sizeof(arr);    // 5 (incluye \0)
int longitud_string = strlen(arr); // 4 (caracteres visibles)
```

### 6. Validación de Entrada

```c
int leer_string_seguro(char *buffer, int tamaño) {
    if (fgets(buffer, tamaño, stdin) == NULL) {
        return -1;  // Error de lectura
    }
    
    // Remover salto de línea
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n') {
        buffer[len-1] = '\0';
    }
    
    return 0;  // Éxito
}
```

### 7. Manejo Robusto de Memoria

```c
char *duplicar_string(const char *src) {
    if (src == NULL) {
        return NULL;
    }
    
    size_t len = strlen(src) + 1;
    char *copia = malloc(len);
    
    if (copia == NULL) {
        return NULL;  // Error de asignación
    }
    
    memcpy(copia, src, len);
    return copia;
}
```

## Conclusión

El manejo de strings en C requiere una comprensión profunda de la gestión de memoria y las características del lenguaje. Aunque puede parecer complejo comparado con lenguajes de alto nivel, este control manual permite escribir código eficiente y optimizado. Las claves del éxito son:

- Siempre verificar límites de buffer
- Gestionar correctamente la memoria dinámica
- Usar las funciones de la biblioteca estándar apropiadamente
- Validar entradas y manejar casos de error
- Mantener la terminación nula en todos los strings

Con práctica y siguiendo estas mejores prácticas, el manejo de strings en C se vuelve una herramienta poderosa y precisa para el desarrollo de software eficiente.