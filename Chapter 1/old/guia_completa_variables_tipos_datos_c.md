# Variables y Tipos de Datos en C

## Índice
1. [Introducción a Variables](#1-introducción-a-variables)
2. [Tipos de Datos Básicos](#2-tipos-de-datos-básicos)
3. [Declaración y Definición](#3-declaración-y-definición)
4. [Modificadores de Tipo](#4-modificadores-de-tipo)
5. [Constantes](#5-constantes)
6. [Ámbito y Duración](#6-ámbito-y-duración)
7. [Conversión de Tipos](#7-conversión-de-tipos)
8. [Tipos Derivados](#8-tipos-derivados)
9. [Buenas Prácticas](#9-buenas-prácticas)
10. [Ejercicios Prácticos](#10-ejercicios-prácticos)
11. [Conceptos Avanzados](#11-conceptos-avanzados)
12. [Debugging y Herramientas](#12-debugging-y-herramientas)
13. [Resumen y Mejores Prácticas](#13-resumen-y-mejores-prácticas)

---

## 1. Introducción a Variables

### 1.1 ¿Qué es una Variable?

Una **variable** es un espacio reservado en la memoria del computador que tiene:
- Un **nombre** (identificador)
- Un **tipo** de dato
- Un **valor** almacenado
- Una **dirección** de memoria

### 1.2 Analogía Conceptual

Piensa en una variable como una **caja etiquetada**:
- La etiqueta es el **nombre** de la variable
- El **tamaño** de la caja determina qué tipo de dato puede almacenar
- El **contenido** es el valor actual
- La **ubicación** de la caja es su dirección en memoria

### 1.3 Características de las Variables en C

```c
#include <stdio.h>

int main() {
    // Declaración: Se reserva espacio en memoria
    int edad;
    
    // Definición/Inicialización: Se asigna un valor
    edad = 25;
    
    // Uso: Se accede al valor
    printf("La edad es: %d años\n", edad);
    
    return 0;
}
```

### 1.4 Reglas para Nombres de Variables

#### Reglas Obligatorias:
1. **Primer carácter**: Debe ser letra (a-z, A-Z) o guión bajo (_)
2. **Caracteres posteriores**: Letras, dígitos (0-9) o guión bajo
3. **Case-sensitive**: `edad` y `Edad` son variables diferentes
4. **No palabras reservadas**: No usar `int`, `if`, `while`, etc.

#### Ejemplos Válidos:
```c
int edad;           // ✅ Correcto
int _contador;      // ✅ Correcto
int numero1;        // ✅ Correcto
int miVariable;     // ✅ Correcto (camelCase)
int mi_variable;    // ✅ Correcto (snake_case)
```

#### Ejemplos Inválidos:
```c
int 2numero;        // ❌ No puede empezar con dígito
int numero-edad;    // ❌ No puede contener guión
int int;           // ❌ Palabra reservada
int mi variable;   // ❌ No puede contener espacios
```

---

## 2. Tipos de Datos Básicos

### 2.1 Tipos Fundamentales

C proporciona varios tipos de datos básicos:

| Tipo | Descripción | Tamaño (típico) | Rango (típico) |
|------|-------------|-----------------|----------------|
| `char` | Carácter | 1 byte | -128 a 127 |
| `int` | Entero | 4 bytes | -2,147,483,648 a 2,147,483,647 |
| `float` | Punto flotante | 4 bytes | ±3.4E-38 a ±3.4E+38 |
| `double` | Doble precisión | 8 bytes | ±1.7E-308 a ±1.7E+308 |
| `void` | Vacío | - | Sin valor |

### 2.2 Tipo char (Carácter)

```c
#include <stdio.h>

int main() {
    // Declaración e inicialización
    char letra = 'A';
    char digito = '7';
    char simbolo = '$';
    
    // También se puede usar valor ASCII
    char caracter_ascii = 65;  // Equivale a 'A'
    
    printf("Letra: %c\n", letra);
    printf("Dígito: %c\n", digito);
    printf("Símbolo: %c\n", simbolo);
    printf("ASCII 65: %c\n", caracter_ascii);
    
    // Mostrar valores ASCII
    printf("ASCII de 'A': %d\n", letra);
    printf("ASCII de '7': %d\n", digito);
    
    return 0;
}
```

#### Caracteres Especiales:
```c
#include <stdio.h>

int main() {
    char nueva_linea = '\n';    // Nueva línea
    char tabulacion = '\t';     // Tabulación
    char retroceso = '\b';      // Backspace
    char comilla = '\'';        // Comilla simple
    char barra_invertida = '\\'; // Barra invertida
    
    printf("Hola%cMundo\n", nueva_linea);     // Hola\nMundo
    printf("Columna1%cColumna2\n", tabulacion); // Columna1\tColumna2
    
    return 0;
}
```

### 2.3 Tipo int (Entero)

```c
#include <stdio.h>

int main() {
    // Diferentes formas de inicializar
    int numero1 = 42;           // Decimal
    int numero2 = 052;          // Octal (empieza con 0)
    int numero3 = 0x2A;         // Hexadecimal (empieza con 0x)
    
    int positivo = 100;
    int negativo = -50;
    int cero = 0;
    
    printf("Decimal: %d\n", numero1);
    printf("Octal: %d (valor decimal)\n", numero2);
    printf("Hexadecimal: %d (valor decimal)\n", numero3);
    
    // Operaciones básicas
    int suma = positivo + negativo;
    int producto = positivo * 2;
    int division = positivo / 3;  // División entera
    int resto = positivo % 7;     // Módulo
    
    printf("Suma: %d + %d = %d\n", positivo, negativo, suma);
    printf("Producto: %d * 2 = %d\n", positivo, producto);
    printf("División: %d / 3 = %d\n", positivo, division);
    printf("Resto: %d %% 7 = %d\n", positivo, resto);
    
    return 0;
}
```

### 2.4 Tipo float (Punto Flotante)

```c
#include <stdio.h>

int main() {
    // Declaración con diferentes precisiones
    float pi = 3.14159f;        // Sufijo 'f' para float
    float cientifico = 1.23e-4f; // Notación científica
    float negativo = -2.718f;
    
    // Operaciones
    float radio = 5.0f;
    float area = pi * radio * radio;
    float circunferencia = 2.0f * pi * radio;
    
    printf("Pi: %.5f\n", pi);
    printf("Científico: %.2e\n", cientifico);
    printf("Radio: %.1f\n", radio);
    printf("Área: %.2f\n", area);
    printf("Circunferencia: %.2f\n", circunferencia);
    
    // Precisión limitada de float
    float precision = 1.0f / 3.0f;
    printf("1/3 como float: %.10f\n", precision);
    
    return 0;
}
```

### 2.5 Tipo double (Doble Precisión)

```c
#include <stdio.h>

int main() {
    // Mayor precisión que float
    double pi_preciso = 3.141592653589793;
    double euler = 2.718281828459045;
    double muy_grande = 1.23e100;
    double muy_pequeño = 1.23e-100;
    
    printf("Pi (double): %.15f\n", pi_preciso);
    printf("Euler: %.15f\n", euler);
    printf("Muy grande: %.2e\n", muy_grande);
    printf("Muy pequeño: %.2e\n", muy_pequeño);
    
    // Comparación de precisión
    float pi_float = 3.141592653589793f;
    double pi_double = 3.141592653589793;
    
    printf("Pi como float:  %.15f\n", pi_float);
    printf("Pi como double: %.15f\n", pi_double);
    
    // Cálculos que requieren precisión
    double resultado = 1.0 / 3.0;
    printf("1/3 como double: %.15f\n", resultado);
    
    return 0;
}
```

### 2.6 Verificación de Tamaños

```c
#include <stdio.h>

int main() {
    printf("=== TAMAÑOS DE TIPOS DE DATOS ===\n");
    printf("char:    %zu bytes\n", sizeof(char));
    printf("int:     %zu bytes\n", sizeof(int));
    printf("float:   %zu bytes\n", sizeof(float));
    printf("double:  %zu bytes\n", sizeof(double));
    printf("void*:   %zu bytes\n", sizeof(void*));
    
    // Rangos aproximados
    printf("\n=== RANGOS APROXIMADOS ===\n");
    printf("char:   %d a %d\n", -128, 127);
    printf("int:    %d a %d\n", -2147483648, 2147483647);
    printf("float:  ±%.1e a ±%.1e\n", 3.4e-38, 3.4e+38);
    printf("double: ±%.1e a ±%.1e\n", 1.7e-308, 1.7e+308);
    
    return 0;
}
```

---

## 3. Declaración y Definición

### 3.1 Diferencias Conceptuales

- **Declaración**: Informa al compilador sobre la existencia de una variable
- **Definición**: Reserva memoria para la variable
- **Inicialización**: Asigna un valor inicial

### 3.2 Sintaxis Básica

```c
#include <stdio.h>

int main() {
    // Declaración simple
    int edad;
    
    // Declaración con inicialización
    int año = 2024;
    
    // Múltiples declaraciones del mismo tipo
    int x, y, z;
    
    // Múltiples declaraciones con inicialización
    int a = 1, b = 2, c = 3;
    
    // Diferentes tipos
    char inicial = 'J';
    float altura = 1.75f;
    double peso = 70.5;
    
    // Asignación posterior a la declaración
    edad = 25;
    x = 10;
    y = 20;
    z = x + y;
    
    printf("Edad: %d, Año: %d\n", edad, año);
    printf("Variables: a=%d, b=%d, c=%d\n", a, b, c);
    printf("Suma: %d + %d = %d\n", x, y, z);
    printf("Datos personales: %c, %.2fm, %.1fkg\n", inicial, altura, peso);
    
    return 0;
}
```

### 3.3 Inicialización vs Asignación

```c
#include <stdio.h>

int main() {
    // ✅ Inicialización (recomendado)
    int numero_inicializado = 42;
    
    // ⚠️ Declaración sin inicialización
    int numero_no_inicializado;
    
    // ✅ Asignación posterior
    numero_no_inicializado = 10;
    
    printf("Inicializado: %d\n", numero_inicializado);
    printf("Asignado después: %d\n", numero_no_inicializado);
    
    // ❌ Peligro: usar variable no inicializada
    int peligroso;
    // printf("%d\n", peligroso);  // Valor impredecible!
    
    return 0;
}
```

### 3.4 Declaraciones Especiales

#### Variables Automáticas:
```c
#include <stdio.h>

void funcion() {
    auto int variable_auto = 10;  // 'auto' es redundante
    int variable_normal = 20;     // Equivalente a la anterior
    
    printf("Auto: %d, Normal: %d\n", variable_auto, variable_normal);
} // Las variables se destruyen aquí
```

#### Variables Estáticas:
```c
#include <stdio.h>

void contador() {
    static int count = 0;  // Se inicializa solo una vez
    count++;
    printf("Llamada número: %d\n", count);
} // 'count' mantiene su valor entre llamadas

int main() {
    contador();  // Imprime: 1
    contador();  // Imprime: 2
    contador();  // Imprime: 3
    return 0;
}
```

---

## 4. Modificadores de Tipo

### 4.1 Modificadores de Tamaño

#### short y long
```c
#include <stdio.h>

int main() {
    // Modificadores de tamaño
    short int numero_corto = 32767;      // o simplemente: short
    int numero_normal = 2147483647;
    long int numero_largo = 2147483647L;  // o simplemente: long
    long long int numero_muy_largo = 9223372036854775807LL;
    
    printf("short:     %hd (tamaño: %zu bytes)\n", numero_corto, sizeof(short));
    printf("int:       %d (tamaño: %zu bytes)\n", numero_normal, sizeof(int));
    printf("long:      %ld (tamaño: %zu bytes)\n", numero_largo, sizeof(long));
    printf("long long: %lld (tamaño: %zu bytes)\n", numero_muy_largo, sizeof(long long));
    
    return 0;
}
```

### 4.2 Modificadores de Signo

#### signed y unsigned
```c
#include <stdio.h>

int main() {
    // Con signo (por defecto)
    signed char char_con_signo = -128;        // -128 a 127
    signed int int_con_signo = -21474