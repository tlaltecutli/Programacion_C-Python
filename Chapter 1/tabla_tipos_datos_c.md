# Tipos de Datos en C - Tabla Completa

## Tipos Básicos (Primitivos)

| Tipo | Tamaño (bytes) | Rango de valores | Especificador de formato | Descripción |
|------|----------------|------------------|--------------------------|-------------|
| `char` | 1 | -128 a 127 | `%c` | Carácter individual |
| `unsigned char` | 1 | 0 a 255 | `%c` | Carácter sin signo |
| `signed char` | 1 | -128 a 127 | `%c` | Carácter con signo explícito |

## Tipos Enteros

| Tipo | Tamaño (bytes) | Rango de valores | Especificador de formato | Descripción |
|------|----------------|------------------|--------------------------|-------------|
| `short` o `short int` | 2 | -32,768 a 32,767 | `%hd` | Entero corto |
| `unsigned short` | 2 | 0 a 65,535 | `%hu` | Entero corto sin signo |
| `int` | 4 | -2,147,483,648 a 2,147,483,647 | `%d` o `%i` | Entero estándar |
| `unsigned int` | 4 | 0 a 4,294,967,295 | `%u` | Entero sin signo |
| `long` o `long int` | 4/8* | -2,147,483,648 a 2,147,483,647 (32-bit) | `%ld` | Entero largo |
| `unsigned long` | 4/8* | 0 a 4,294,967,295 (32-bit) | `%lu` | Entero largo sin signo |
| `long long` | 8 | -9,223,372,036,854,775,808 a 9,223,372,036,854,775,807 | `%lld` | Entero muy largo |
| `unsigned long long` | 8 | 0 a 18,446,744,073,709,551,615 | `%llu` | Entero muy largo sin signo |

## Tipos de Punto Flotante

| Tipo | Tamaño (bytes) | Precisión | Rango aproximado | Especificador de formato | Descripción |
|------|----------------|-----------|------------------|--------------------------|-------------|
| `float` | 4 | ~7 dígitos | ±3.4E±38 | `%f`, `%e`, `%g` | Punto flotante simple |
| `double` | 8 | ~15 dígitos | ±1.7E±308 | `%lf`, `%le`, `%lg` | Punto flotante doble |
| `long double` | 8/12/16* | ~19 dígitos | ±1.1E±4932 | `%Lf`, `%Le`, `%Lg` | Punto flotante extendido |

## Tipos Derivados

| Tipo | Sintaxis | Descripción | Ejemplo |
|------|----------|-------------|---------|
| **Array** | `tipo nombre[tamaño]` | Colección de elementos del mismo tipo | `int numeros[10]` |
| **Puntero** | `tipo *nombre` | Variable que almacena dirección de memoria | `int *ptr` |
| **Función** | `tipo_retorno nombre(parámetros)` | Bloque de código reutilizable | `int suma(int a, int b)` |

## Tipos Definidos por el Usuario

| Tipo | Sintaxis | Descripción | Ejemplo |
|------|----------|-------------|---------|
| **Estructura** | `struct nombre { ... }` | Agrupa variables de diferentes tipos | `struct Persona { char nombre[50]; int edad; }` |
| **Unión** | `union nombre { ... }` | Comparte memoria entre diferentes tipos | `union Dato { int entero; float decimal; }` |
| **Enumeración** | `enum nombre { ... }` | Define constantes enteras con nombres | `enum Color { ROJO, VERDE, AZUL }` |
| **Typedef** | `typedef tipo nuevo_nombre` | Crea un alias para un tipo existente | `typedef unsigned int uint` |

## Tipos con Modificadores

| Modificador | Descripción | Aplicable a |
|-------------|-------------|-------------|
| `signed` | Con signo (por defecto para int) | char, int, short, long |
| `unsigned` | Sin signo (solo valores positivos) | char, int, short, long |
| `short` | Versión corta del tipo | int |
| `long` | Versión larga del tipo | int, double |
| `const` | Valor constante (no modificable) | Cualquier tipo |
| `volatile` | Valor puede cambiar inesperadamente | Cualquier tipo |
| `static` | Variable con duración de programa | Cualquier tipo |
| `extern` | Variable definida en otro archivo | Cualquier tipo |
| `register` | Sugerencia para almacenar en registro | Tipos básicos |

## Tipos Especiales

| Tipo | Descripción | Uso |
|------|-------------|-----|
| `void` | Tipo vacío (sin valor) | Funciones que no retornan valor, punteros genéricos |
| `size_t` | Tipo para tamaños (definido en stddef.h) | Resultados de sizeof, índices de arrays |
| `ptrdiff_t` | Diferencia entre punteros | Aritmética de punteros |
| `NULL` | Puntero nulo (definido como 0) | Inicialización de punteros |

## Notas Importantes

- **Tamaños variables (*)**: Los tamaños pueden variar según la arquitectura del sistema (32-bit vs 64-bit)
- **Portabilidad**: Para código portable, usa `stdint.h` con tipos como `int32_t`, `uint64_t`, etc.
- **Inicialización**: Siempre inicializa las variables para evitar valores basura
- **Conversiones**: C realiza conversiones automáticas entre tipos compatibles
- **Límites**: Usa `limits.h` y `float.h` para obtener los valores límite exactos del sistema

## Ejemplo de uso de stdint.h (Recomendado para portabilidad)

```c
#include <stdint.h>

int8_t    byte_con_signo;      // 8 bits con signo
uint8_t   byte_sin_signo;      // 8 bits sin signo  
int16_t   entero_16_bits;      // 16 bits con signo
uint32_t  entero_32_sin_signo; // 32 bits sin signo
int64_t   entero_64_bits;      // 64 bits con signo
```