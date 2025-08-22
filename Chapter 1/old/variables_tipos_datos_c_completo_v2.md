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
    signed int int_con_signo = -2147483648;
    
    // Sin signo
    unsigned char char_sin_signo = 255;       // 0 a 255
    unsigned int int_sin_signo = 4294967295U; // 0 a 4,294,967,295
    
    printf("char con signo: %d\n", char_con_signo);
    printf("char sin signo: %u\n", char_sin_signo);
    printf("int con signo: %d\n", int_con_signo);
    printf("int sin signo: %u\n", int_sin_signo);
    
    // Demostración de desbordamiento
    unsigned char pequeño = 255;
    pequeño = pequeño + 1;  // Desbordamiento: vuelve a 0
    printf("255 + 1 en unsigned char: %u\n", pequeño);
    
    return 0;
}
```

### 4.3 Tabla Completa de Tipos Modificados

```c
#include <stdio.h>

int main() {
    printf("=== TIPOS ENTEROS MODIFICADOS ===\n");
    printf("Tipo                    Tamaño    Rango aproximado\n");
    printf("----------------------------------------------------\n");
    printf("char                    %zu bytes  -128 a 127\n", sizeof(char));
    printf("unsigned char           %zu bytes  0 a 255\n", sizeof(unsigned char));
    printf("short                   %zu bytes  -32,768 a 32,767\n", sizeof(short));
    printf("unsigned short          %zu bytes  0 a 65,535\n", sizeof(unsigned short));
    printf("int                     %zu bytes  ±2.1 billones\n", sizeof(int));
    printf("unsigned int            %zu bytes  0 a 4.3 billones\n", sizeof(unsigned int));
    printf("long                    %zu bytes  ±2.1 billones o más\n", sizeof(long));
    printf("unsigned long           %zu bytes  0 a 4.3 billones o más\n", sizeof(unsigned long));
    printf("long long               %zu bytes  ±9.2 trillones\n", sizeof(long long));
    printf("unsigned long long      %zu bytes  0 a 18.4 trillones\n", sizeof(unsigned long long));
    
    printf("\n=== TIPOS DE PUNTO FLOTANTE ===\n");
    printf("float                   %zu bytes  ±3.4E±38 (7 dígitos)\n", sizeof(float));
    printf("double                  %zu bytes  ±1.7E±308 (15 dígitos)\n", sizeof(double));
    printf("long double             %zu bytes  Precisión extendida\n", sizeof(long double));
    
    return 0;
}
```

---

## 5. Constantes

### 5.1 ¿Qué son las Constantes?

Las **constantes** son valores que no pueden modificarse durante la ejecución del programa.

### 5.2 Constantes Literales

#### Constantes Enteras:
```c
#include <stdio.h>

int main() {
    // Diferentes bases numéricas
    int decimal = 42;          // Base 10
    int octal = 052;           // Base 8 (empieza con 0)
    int hexadecimal = 0x2A;    // Base 16 (empieza con 0x)
    int binario = 0b101010;    // Base 2 (C23/GCC extension)
    
    printf("Decimal: %d\n", decimal);
    printf("Octal: %d\n", octal);
    printf("Hexadecimal: %d\n", hexadecimal);
    
    // Sufijos para especificar tipo
    long numero_largo = 123456789L;
    unsigned int sin_signo = 123456U;
    unsigned long largo_sin_signo = 123456789UL;
    long long muy_largo = 123456789123456789LL;
    
    printf("Long: %ld\n", numero_largo);
    printf("Unsigned: %u\n", sin_signo);
    printf("Long long: %lld\n", muy_largo);
    
    return 0;
}
```

#### Constantes de Punto Flotante:
```c
#include <stdio.h>

int main() {
    // Notación decimal
    float pi_float = 3.14159f;        // Sufijo 'f' para float
    double pi_double = 3.14159;       // double por defecto
    long double pi_long = 3.14159L;   // Sufijo 'L' para long double
    
    // Notación científica
    double avogadro = 6.022e23;       // 6.022 × 10^23
    float planck = 6.626e-34f;        // 6.626 × 10^-34
    
    printf("Pi float: %.5f\n", pi_float);
    printf("Pi double: %.5f\n", pi_double);
    printf("Pi long double: %.5Lf\n", pi_long);
    printf("Avogadro: %.3e\n", avogadro);
    printf("Planck: %.3e\n", planck);
    
    return 0;
}
```

#### Constantes de Carácter:
```c
#include <stdio.h>

int main() {
    // Caracteres normales
    char letra = 'A';
    char digito = '5';
    char espacio = ' ';
    
    // Secuencias de escape
    char nueva_linea = '\n';
    char tabulacion = '\t';
    char comilla_simple = '\'';
    char comilla_doble = '\"';
    char barra_invertida = '\\';
    
    // Códigos ASCII
    char a_mayuscula = 65;     // Equivale a 'A'
    char a_minuscula = 97;     // Equivale a 'a'
    
    printf("Letra: %c\n", letra);
    printf("ASCII 65: %c\n", a_mayuscula);
    printf("ASCII 97: %c\n", a_minuscula);
    printf("Escape: %c%c%c\n", comilla_simple, comilla_doble, barra_invertida);
    
    return 0;
}
```

### 5.3 Constantes Definidas con #define

```c
#include <stdio.h>

// Constantes definidas con #define (macro)
#define PI 3.14159265359
#define MAX_ESTUDIANTES 100
#define NOMBRE_PROGRAMA "Mi Programa"
#define VERDADERO 1
#define FALSO 0

int main() {
    float radio = 5.0;
    float area = PI * radio * radio;
    
    printf("Programa: %s\n", NOMBRE_PROGRAMA);
    printf("Radio: %.1f\n", radio);
    printf("Área: %.2f\n", area);
    printf("Máximo estudiantes: %d\n", MAX_ESTUDIANTES);
    
    int activo = VERDADERO;
    if (activo == VERDADERO) {
        printf("El programa está activo\n");
    }
    
    return 0;
}
```

### 5.4 Variables Constantes con const

```c
#include <stdio.h>

int main() {
    // Variables constantes (no pueden modificarse después)
    const int DIAS_SEMANA = 7;
    const float GRAVEDAD = 9.81f;
    const char INICIAL = 'J';
    
    printf("Días de la semana: %d\n", DIAS_SEMANA);
    printf("Gravedad: %.2f m/s²\n", GRAVEDAD);
    printf("Inicial: %c\n", INICIAL);
    
    // ❌ Error: no se puede modificar
    // DIAS_SEMANA = 8;  // Error de compilación
    
    // ✅ Se puede usar en cálculos
    const float PESO = 70.0f;
    const float FUERZA = PESO * GRAVEDAD;
    
    printf("Peso: %.1f kg\n", PESO);
    printf("Fuerza: %.2f N\n", FUERZA);
    
    return 0;
}
```

### 5.5 Diferencias entre #define y const

```c
#include <stdio.h>

#define DEFINE_PI 3.14159  // Macro del preprocesador
const float CONST_PI = 3.14159f;  // Variable constante

int main() {
    printf("=== COMPARACIÓN #define vs const ===\n");
    
    // Ambas se pueden usar en cálculos
    float radio = 2.5f;
    float area1 = DEFINE_PI * radio * radio;
    float area2 = CONST_PI * radio * radio;
    
    printf("Área con #define: %.2f\n", area1);
    printf("Área con const: %.2f\n", area2);
    
    // Diferencias:
    printf("Tamaño de CONST_PI: %zu bytes\n", sizeof(CONST_PI));
    // printf("Tamaño de DEFINE_PI: %zu bytes\n", sizeof(DEFINE_PI)); // Error
    
    printf("Dirección de CONST_PI: %p\n", (void*)&CONST_PI);
    // printf("Dirección de DEFINE_PI: %p\n", (void*)&DEFINE_PI); // Error
    
    return 0;
}
```

---

## 6. Ámbito y Duración

### 6.1 Conceptos Básicos

- **Ámbito (Scope)**: Donde la variable es visible y accesible
- **Duración (Lifetime)**: Cuánto tiempo existe la variable en memoria

### 6.2 Variables Locales

```c
#include <stdio.h>

void funcion_ejemplo() {
    int variable_local = 20;  // Solo existe dentro de esta función
    printf("Variable local en función: %d\n", variable_local);
} // variable_local se destruye aquí

int main() {
    int variable_local = 10;  // Diferente a la de la función
    
    printf("Variable local en main: %d\n", variable_local);
    funcion_ejemplo();
    
    // printf("%d\n", variable_local);  // Sigue siendo 10, no 20
    
    // Ámbito de bloque
    {
        int variable_bloque = 30;
        printf("Variable en bloque: %d\n", variable_bloque);
    } // variable_bloque se destruye aquí
    
    // printf("%d\n", variable_bloque);  // ❌ Error: fuera de ámbito
    
    return 0;
}
```

### 6.3 Variables Globales

```c
#include <stdio.h>

// Variables globales (declaradas fuera de cualquier función)
int contador_global = 0;
float pi_global = 3.14159f;

void incrementar_contador() {
    contador_global++;  // Acceso a variable global
    printf("Contador global: %d\n", contador_global);
}

void mostrar_pi() {
    printf("Pi global: %.5f\n", pi_global);
}

int main() {
    printf("=== VARIABLES GLOBALES ===\n");
    
    // Acceso directo desde main
    printf("Contador inicial: %d\n", contador_global);
    
    // Modificación desde funciones
    incrementar_contador();
    incrementar_contador();
    incrementar_contador();
    
    mostrar_pi();
    
    // Modificación directa
    contador_global = 100;
    printf("Contador modificado: %d\n", contador_global);
    
    return 0;
}
```

### 6.4 Variables Estáticas

```c
#include <stdio.h>

// Variable estática global (solo visible en este archivo)
static int variable_estatica_global = 0;

void funcion_con_estatica() {
    static int contador_local = 0;  // Se inicializa solo una vez
    int variable_normal = 0;
    
    contador_local++;
    variable_normal++;
    
    printf("Estática: %d, Normal: %d\n", contador_local, variable_normal);
}

int main() {
    printf("=== VARIABLES ESTÁTICAS ===\n");
    
    printf("Llamada 1: ");
    funcion_con_estatica();  // Estática: 1, Normal: 1
    
    printf("Llamada 2: ");
    funcion_con_estatica();  // Estática: 2, Normal: 1
    
    printf("Llamada 3: ");
    funcion_con_estatica();  // Estática: 3, Normal: 1
    
    variable_estatica_global = 42;
    printf("Variable estática global: %d\n", variable_estatica_global);
    
    return 0;
}
```

### 6.5 Clases de Almacenamiento

```c
#include <stdio.h>

// Ejemplo completo de clases de almacenamiento
int global = 10;                    // Duración: todo el programa
static int estatica_global = 20;    // Duración: todo el programa, ámbito: este archivo

void demostrar_almacenamiento() {
    auto int automatica = 30;       // Local, se destruye al salir
    static int estatica_local = 40;  // Persistente entre llamadas
    register int registro = 50;      // Sugerencia al compilador (opcional)
    
    printf("Automática: %d\n", automatica);
    printf("Estática local: %d\n", estatica_local);
    printf("Registro: %d\n", registro);
    
    automatica++;
    estatica_local++;
    registro++;
}

int main() {
    printf("=== CLASES DE ALMACENAMIENTO ===\n");
    
    printf("Global: %d\n", global);
    printf("Estática global: %d\n", estatica_global);
    
    printf("\nPrimera llamada:\n");
    demostrar_almacenamiento();
    
    printf("\nSegunda llamada:\n");
    demostrar_almacenamiento();
    
    return 0;
}
```

---

## 7. Conversión de Tipos

### 7.1 Conversión Implícita (Automática)

```c
#include <stdio.h>

int main() {
    printf("=== CONVERSIÓN IMPLÍCITA ===\n");
    
    // Promoción automática
    char c = 100;
    int i = c;           // char → int
    float f = i;         // int → float
    double d = f;        // float → double
    
    printf("char: %d\n", c);
    printf("int: %d\n", i);
    printf("float: %.2f\n", f);
    printf("double: %.2f\n", d);
    
    // En operaciones aritméticas
    int entero = 10;
    float flotante = 3.5f;
    float resultado = entero + flotante;  // int se convierte a float
    
    printf("\n%d + %.1f = %.1f\n", entero, flotante, resultado);
    
    // Pérdida de precisión
    float pi = 3.14159f;
    int pi_entero = pi;  // Se trunca, no se redondea
    
    printf("Pi original: %.5f\n", pi);
    printf("Pi como entero: %d\n", pi_entero);
    
    return 0;
}
```

### 7.2 Conversión Explícita (Casting)

```c
#include <stdio.h>

int main() {
    printf("=== CONVERSIÓN EXPLÍCITA (CASTING) ===\n");
    
    // Casting básico
    float division_flotante = 10.0f / 3.0f;
    int division_entera = 10 / 3;
    int casting_resultado = (int)(10.0f / 3.0f);
    
    printf("División flotante: %.5f\n", division_flotante);
    printf("División entera: %d\n", division_entera);
    printf("Con casting a int: %d\n", casting_resultado);
    
    // División precisa entre enteros
    int a = 10, b = 3;
    float resultado_preciso = (float)a / b;  // Casting de uno es suficiente
    
    printf("\n%d / %d = %.5f\n", a, b, resultado_preciso);
    
    // Casting de double a int
    double precio = 19.99;
    int precio_entero = (int)precio;
    int precio_redondeado = (int)(precio + 0.5);  // Redondeo manual
    
    printf("\nPrecio: %.2f\n", precio);
    printf("Truncado: %d\n", precio_entero);
    printf("Redondeado: %d\n", precio_redondeado);
    
    // Casting entre tipos de carácter
    char letra = 'A';
    int codigo_ascii = (int)letra;
    char siguiente_letra = (char)(codigo_ascii + 1);
    
    printf("\nLetra: %c\n", letra);
    printf("Código ASCII: %d\n", codigo_ascii);
    printf("Siguiente letra: %c\n", siguiente_letra);
    
    return 0;
}
```

### 7.3 Jerarquía de Conversiones

```c
#include <stdio.h>

int main() {
    printf("=== JERARQUÍA DE CONVERSIONES ===\n");
    printf("char → short → int → long → long long\n");
    printf("float → double → long double\n\n");
    
    // Ejemplo de promociones en operaciones
    char c1 = 10, c2 = 20;
    short s1 = 100, s2 = 200;
    int resultado_char = c1 + c2;    // char → int
    int resultado_short = s1 + s2;   // short → int
    
    printf("char + char: %d + %d = %d (tipo resultado: int)\n", c1, c2, resultado_char);
    printf("short + short: %d + %d = %d (tipo resultado: int)\n", s1, s2, resultado_short);
    
    // Operaciones mixtas
    int i = 10;
    float f = 3.5f;
    double d = 2.7;
    
    float resultado_if = i + f;     // int → float
    double resultado_id = i + d;    // int → double
    double resultado_fd = f + d;    // float → double
    
    printf("\nOperaciones mixtas:\n");
    printf("int + float: %d + %.1f = %.1f\n", i, f, resultado_if);
    printf("int + double: %d + %.1f = %.1f\n", i, d, resultado_id);
    printf("float + double: %.1f + %.1f = %.1f\n", f, d, resultado_fd);
    
    return 0;
}
```

### 7.4 Peligros de la Conversión

```c
#include <stdio.h>
#include <limits.h>

int main() {
    printf("=== PELIGROS DE LA CONVERSIÓN ===\n");
    
    // Overflow en conversión
    long numero_grande = 2147483648L;  // Mayor que INT_MAX
    int numero_pequeño = (int)numero_grande;
    
    printf("Número grande (long): %ld\n", numero_grande);
    printf("Convertido a int: %d\n", numero_pequeño);  // Valor impredecible
    
    // Pérdida de precisión
    double preciso = 123456789.123456789;
    float menos_preciso = (float)preciso;
    
    printf("\nPrecisión original: %.9f\n", preciso);
    printf("Después de casting: %.9f\n", menos_preciso);
    
    // Conversión de negativos a unsigned
    int negativo = -10;
    unsigned int positivo = (unsigned int)negativo;
    
    printf("\nNegativo: %d\n", negativo);
    printf("Como unsigned: %u\n", positivo);  // Valor muy grande
    
    // Truncación de decimales
    double con_decimales = 9.99;
    int sin_decimales = (int)con_decimales;
    
    printf("\nCon decimales: %.2f\n", con_decimales);
    printf("Truncado: %d\n", sin_decimales);  // 9, no 10
    
    return 0;
}
```

---

## 8. Tipos Derivados

### 8.1 Arrays (Arreglos)

```c
#include <stdio.h>

int main() {
    printf("=== ARRAYS ===\n");
    
    // Declaración e inicialización
    int numeros[5] = {1, 2, 3, 4, 5};
    float temperaturas[] = {20.5, 21.3, 19.8, 22.1};  // Tamaño automático
    char vocales[5] = {'a', 'e', 'i', 'o', 'u'};
    
    // Mostrar elementos
    printf("Números: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    
    printf("Temperaturas: ");
    int tam_temp = sizeof(temperaturas) / sizeof(temperaturas[0]);
    for (int i = 0; i < tam_temp; i++) {
        printf("%.1f ", temperaturas[i]);
    }
    printf("\n");
    
    printf("Vocales: ");
    for (int i = 0; i < 5; i++) {
        printf("%c ", vocales[i]);
    }
    printf("\n");
    
    return 0;
}
```

### 8.2 Punteros

```c
#include <stdio.h>

int main() {
    printf("=== PUNTEROS ===\n");
    
    // Declaración de variables y punteros
    int numero = 42;
    int *puntero_numero = &numero;  // Puntero a entero
    
    float pi = 3.14159f;
    float *puntero_pi = &pi;        // Puntero a float
    
    // Mostrar valores y direcciones
    printf("Variable numero: %d\n", numero);
    printf("Dirección de numero: %p\n", (void*)&numero);
    printf("Valor del puntero: %p\n", (void*)puntero_numero);
    printf("Valor apuntado: %d\n", *puntero_numero);
    
    printf("\nVariable pi: %.5f\n", pi);
    printf("Dirección de pi: %p\n", (void*)&pi);
    printf("Valor del puntero: %p\n", (void*)puntero_pi);
    printf("Valor apuntado: %.5f\n", *puntero_pi);
    
    // Modificación a través del puntero
    *puntero_numero = 100;
    printf("\nDespués de modificar con puntero:\n");
    printf("numero = %d\n", numero);
    printf("*puntero_numero = %d\n", *puntero_numero);
    
    return 0;
}
```

### 8.3 Estructuras (Introducción)

```c
#include <stdio.h>
#include <string.h>

// Definición de estructura
struct Persona {
    char nombre[50];
    int edad;
    float altura;
};

int main() {
    printf("=== ESTRUCTURAS ===\n");
    
    // Declaración e inicialización
    struct Persona persona1 = {"Juan Pérez", 25, 1.75f};
    struct Persona persona2;
    
    // Asignación individual
    strcpy(persona2.nombre, "María García");
    persona2.edad = 30;
    persona2.altura = 1.65f;
    
    // Mostrar información
    printf("Persona 1:\n");
    printf("  Nombre: %s\n", persona1.nombre);
    printf("  Edad: %d años\n", persona1.edad);
    printf("  Altura: %.2f m\n", persona1.altura);
    
    printf("\nPersona 2:\n");
    printf("  Nombre: %s\n", persona2.nombre);
    printf("  Edad: %d años\n", persona2.edad);
    printf("  Altura: %.2f m\n", persona2.altura);
    
    return 0;
}
```

---

## 9. Buenas Prácticas

### 9.1 Nomenclatura de Variables

```c
#include <stdio.h>

// ✅ Buenos ejemplos de nombres
int edad_usuario;          // snake_case - descriptivo
int contadorElementos;     // camelCase - descriptivo
const float PI = 3.14159f; // MAYÚSCULAS para constantes
int i, j, k;              // OK para índices de bucles

// ❌ Malos ejemplos
// int a, b, c;            // No descriptivos
// int edadDelUsuarioEnAños; // Demasiado largo
// int 2numero;            // Inválido
// int número;             // Evitar acentos

int main() {
    // ✅ Convenciones recomendadas
    
    // Variables locales: snake_case o camelCase
    int numero_estudiantes = 30;
    float promedio_clase = 8.5f;
    
    // Constantes: MAYÚSCULAS con guiones bajos
    const int MAX_INTENTOS = 3;
    const char LETRA_INICIAL = 'A';
    
    // Booleanos: prefijos is_, has_, can_, should_
    int es_valido = 1;        // o bool es_valido = true;
    int tiene_permiso = 0;
    int puede_continuar = 1;
    
    printf("Estudiantes: %d\n", numero_estudiantes);
    printf("Promedio: %.1f\n", promedio_clase);
    printf("Máximo intentos: %d\n", MAX_INTENTOS);
    
    return 0;
}
```

### 9.2 Inicialización de Variables

```c
#include <stdio.h>

int main() {
    printf("=== INICIALIZACIÓN DE VARIABLES ===\n");
    
    // ✅ Siempre inicializar variables
    int contador = 0;
    float precio = 0.0f;
    char inicial = '\0';
    
    // ✅ Inicialización en el punto de declaración
    int suma = 0;
    for (int i = 1; i <= 10; i++) {  // i se inicializa aquí
        suma += i;
    }
    
    // ✅ Inicialización de arrays
    int numeros[5] = {0};  // Todos los elementos en 0
    char cadena[100] = ""; // String vacío
    
    // ✅ Constantes bien definidas
    const int DIAS_SEMANA = 7;
    const float GRAVEDAD_TIERRA = 9.81f;
    
    printf("Suma 1-10: %d\n", suma);
    printf("Primer número: %d\n", numeros[0]);
    printf("Días semana: %d\n", DIAS_SEMANA);
    
    return 0;
}
```

### 9.3 Uso Apropiado de Tipos

```c
#include <stdio.h>
#include <stdbool.h>  // Para bool, true, false (C99)

int main() {
    printf("=== USO APROPIADO DE TIPOS ===\n");
    
    // ✅ Elegir el tipo correcto según el rango de datos
    
    // Para edades (0-150)
    unsigned char edad = 25;  // 1 byte es suficiente
    
    // Para contadores pequeños
    short contador_paginas = 1;
    
    // Para cálculos financieros, evitar float
    int precio_centavos = 1999;  // $19.99 como 1999 centavos
    printf("Precio: $%.2f\n", precio_centavos / 100.0);
    
    // Para valores booleanos
    bool esta_activo = true;
    bool es_valido = false;
    
    // Para caracteres individuales
    char grado = 'A';
    char digito = '5';
    
    // Para números muy grandes
    long long poblacion_mundial = 8000000000LL;
    
    // ✅ Usar unsigned cuando no se necesiten negativos
    unsigned int indice = 0;
    unsigned short puerto = 8080;
    
    printf("Edad: %u años\n", edad);
    printf("Activo: %s\n", esta_activo ? "Sí" : "No");
    printf("Grado: %c\n", grado);
    printf("Población: %lld\n", poblacion_mundial);
    
    return 0;
}
```

### 9.4 Manejo de Constantes

```c
#include <stdio.h>

// ✅ Constantes globales con #define
#define PI 3.141592653589793
#define MAX_BUFFER 1024
#define PROGRAMA_VERSION "1.0.0"
#define VERDADERO 1
#define FALSO 0

int main() {
    printf("=== MANEJO DE CONSTANTES ===\n");
    
    // ✅ Constantes locales con const
    const int max_estudiantes = 30;
    const float tasa_iva = 0.16f;
    const char separador = '-';
    
    // ✅ Uso en cálculos
    float radio = 2.5f;
    float area = PI * radio * radio;
    float circunferencia = 2 * PI * radio;
    
    // ✅ Validación con constantes
    int num_estudiantes = 25;
    if (num_estudiantes <= max_estudiantes) {
        printf("Grupo válido: %d/%d estudiantes\n", 
               num_estudiantes, max_estudiantes);
    }
    
    // ✅ Cálculos con IVA
    float precio_base = 100.0f;
    float precio_con_iva = precio_base * (1.0f + tasa_iva);
    
    printf("Versión: %s\n", PROGRAMA_VERSION);
    printf("Área círculo: %.2f\n", area);
    printf("Precio con IVA: $%.2f\n", precio_con_iva);
    
    return 0;
}
```

---

## 10. Ejercicios Prácticos

### 10.1 Ejercicios Básicos

#### Ejercicio 1: Información Personal
```c
/*
Crear un programa que:
1. Declare variables para almacenar información personal:
   - Nombre (char array)
   - Edad (int)
   - Altura (float)
   - Peso (float)
   - Es estudiante (int como booleano)
2. Inicialice las variables con sus datos
3. Calcule e imprima el IMC (peso/altura²)
4. Muestre toda la información formateada
*/

#include <stdio.h>
#include <string.h>

int main() {
    // Solución propuesta
    char nombre[50] = "Ana González";
    int edad = 22;
    float altura = 1.68f;  // metros
    float peso = 58.5f;    // kg
    int es_estudiante = 1; // 1 = true, 0 = false
    
    // Cálculo del IMC
    float imc = peso / (altura * altura);
    
    // Mostrar información
    printf("=== INFORMACIÓN PERSONAL ===\n");
    printf("Nombre: %s\n", nombre);
    printf("Edad: %d años\n", edad);
    printf("Altura: %.2f m\n", altura);
    printf("Peso: %.1f kg\n", peso);
    printf("Es estudiante: %s\n", es_estudiante ? "Sí" : "No");
    printf("IMC: %.2f\n", imc);
    
    // Interpretación del IMC
    if (imc < 18.5) {
        printf("Clasificación: Bajo peso\n");
    } else if (imc < 25.0) {
        printf("Clasificación: Peso normal\n");
    } else if (imc < 30.0) {
        printf("Clasificación: Sobrepeso\n");
    } else {
        printf("Clasificación: Obesidad\n");
    }
    
    return 0;
}
```

#### Ejercicio 2: Conversiones de Temperatura
```c
/*
Desarrollar un programa que:
1. Declare una temperatura en Celsius (float)
2. Calcule y muestre las conversiones a:
   - Fahrenheit: (C × 9/5) + 32
   - Kelvin: C + 273.15
3. Use constantes apropiadas para los factores de conversión
4. Muestre los resultados con precisión apropiada
*/

#include <stdio.h>

// Constantes para conversión
#define FACTOR_CELSIUS_FAHRENHEIT 9.0f/5.0f
#define OFFSET_FAHRENHEIT 32.0f
#define OFFSET_KELVIN 273.15f

int main() {
    // Temperatura inicial en Celsius
    float celsius = 25.0f;
    
    // Conversiones
    float fahrenheit = (celsius * FACTOR_CELSIUS_FAHRENHEIT) + OFFSET_FAHRENHEIT;
    float kelvin = celsius + OFFSET_KELVIN;
    
    // Mostrar resultados
    printf("=== CONVERSIONES DE TEMPERATURA ===\n");
    printf("Temperatura original: %.1f°C\n", celsius);
    printf("Fahrenheit: %.1f°F\n", fahrenheit);
    printf("Kelvin: %.2f K\n", kelvin);
    
    // Tabla de conversiones
    printf("\n=== TABLA DE CONVERSIONES ===\n");
    printf("Celsius\tFahrenheit\tKelvin\n");
    printf("-------\t----------\t------\n");
    
    for (int i = 0; i <= 100; i += 20) {
        float c = (float)i;
        float f = (c * FACTOR_CELSIUS_FAHRENHEIT) + OFFSET_FAHRENHEIT;
        float k = c + OFFSET_KELVIN;
        printf("%.0f\t%.1f\t\t%.2f\n", c, f, k);
    }
    
    return 0;
}
```

#### Ejercicio 3: Operaciones con Diferentes Tipos
```c
/*
Crear un programa que demuestre:
1. Declaración de variables de todos los tipos básicos
2. Operaciones entre tipos diferentes
3. Conversiones explícitas e implícitas
4. Mostrar tamaños de memoria de cada tipo
5. Mostrar rangos aproximados de cada tipo
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("=== OPERACIONES CON DIFERENTES TIPOS ===\n\n");
    
    // 1. Declaración de todos los tipos básicos
    char caracter = 'A';
    short entero_corto = 1000;
    int entero_normal = 50000;
    long entero_largo = 1000000L;
    long long entero_muy_largo = 1000000000000LL;
    
    unsigned char caracter_sin_signo = 200;
    unsigned short corto_sin_signo = 60000;
    unsigned int normal_sin_signo = 3000000000U;
    unsigned long largo_sin_signo = 4000000000UL;
    unsigned long long muy_largo_sin_signo = 10000000000000000ULL;
    
    float flotante = 3.14159f;
    double doble_precision = 2.718281828459045;
    long double precision_extendida = 1.41421356237309504880L;
    
    // 2. Mostrar tamaños
    printf("=== TAMAÑOS DE MEMORIA ===\n");
    printf("char: %zu bytes\n", sizeof(char));
    printf("short: %zu bytes\n", sizeof(short));
    printf("int: %zu bytes\n", sizeof(int));
    printf("long: %zu bytes\n", sizeof(long));
    printf("long long: %zu bytes\n", sizeof(long long));
    printf("float: %zu bytes\n", sizeof(float));
    printf("double: %zu bytes\n", sizeof(double));
    printf("long double: %zu bytes\n", sizeof(long double));
    
    // 3. Mostrar rangos
    printf("\n=== RANGOS DE VALORES ===\n");
    printf("char: %d a %d\n", CHAR_MIN, CHAR_MAX);
    printf("short: %d a %d\n", SHRT_MIN, SHRT_MAX);
    printf("int: %d a %d\n", INT_MIN, INT_MAX);
    printf("long: %ld a %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned char: 0 a %u\n", UCHAR_MAX);
    printf("unsigned short: 0 a %u\n", USHRT_MAX);
    printf("unsigned int: 0 a %u\n", UINT_MAX);
    printf("float: %.2e a %.2e\n", FLT_MIN, FLT_MAX);
    printf("double: %.2e a %.2e\n", DBL_MIN, DBL_MAX);
    
    // 4. Operaciones entre tipos diferentes
    printf("\n=== OPERACIONES MIXTAS ===\n");
    
    // Conversión implícita
    float resultado1 = entero_normal + flotante;
    printf("int + float: %d + %.5f = %.5f\n", entero_normal, flotante, resultado1);
    
    // Conversión explícita (casting)
    int entero_desde_float = (int)flotante;
    printf("float a int: %.5f → %d (truncado)\n", flotante, entero_desde_float);
    
    // Operación con redondeo
    int redondeado = (int)(flotante + 0.5f);
    printf("float redondeado: %.5f → %d\n", flotante, redondeado);
    
    // División precisa
    int a = 10, b = 3;
    float division_precisa = (float)a / b;
    int division_entera = a / b;
    printf("División: %d/%d = %.5f (precisa), %d (entera)\n", 
           a, b, division_precisa, division_entera);
    
    // 5. Demostrar promoción automática
    printf("\n=== PROMOCIÓN AUTOMÁTICA ===\n");
    char c1 = 100, c2 = 50;
    int suma_chars = c1 + c2;  // char se promueve a int
    printf("char + char: %d + %d = %d (resultado tipo int)\n", c1, c2, suma_chars);
    
    return 0;
}
```

### 10.2 Ejercicios Intermedios

#### Ejercicio 4: Calculadora de Área de Figuras
```c
/*
Implementar una calculadora que:
1. Use constantes para π y otros valores matemáticos
2. Calcule áreas de diferentes figuras:
   - Círculo: π × r²
   - Rectángulo: base × altura
   - Triángulo: (base × altura) / 2
3. Use tipos de datos apropiados para cada medida
4. Maneje conversiones de tipos correctamente
5. Muestre resultados con formato apropiado
*/

#include <stdio.h>
#include <math.h>

// Constantes matemáticas
#define PI 3.141592653589793
#define E 2.718281828459045

int main() {
    printf("=== CALCULADORA DE ÁREAS ===\n\n");
    
    // Variables para dimensiones
    float radio_circulo = 5.5f;
    float base_rectangulo = 8.0f;
    float altura_rectangulo = 6.0f;
    float base_triangulo = 12.0f;
    float altura_triangulo = 8.0f;
    
    // Cálculos de áreas
    double area_circulo = PI * radio_circulo * radio_circulo;
    double area_rectangulo = base_rectangulo * altura_rectangulo;
    double area_triangulo = (base_triangulo * altura_triangulo) / 2.0;
    
    // Mostrar resultados
    printf("1. CÍRCULO\n");
    printf("   Radio: %.2f unidades\n", radio_circulo);
    printf("   Área: %.4f unidades²\n", area_circulo);
    printf("   Perímetro: %.4f unidades\n", 2 * PI * radio_circulo);
    
    printf("\n2. RECTÁNGULO\n");
    printf("   Base: %.2f, Altura: %.2f unidades\n", base_rectangulo, altura_rectangulo);
    printf("   Área: %.2f unidades²\n", area_rectangulo);
    printf("   Perímetro: %.2f unidades\n", 2 * (base_rectangulo + altura_rectangulo));
    
    printf("\n3. TRIÁNGULO\n");
    printf("   Base: %.2f, Altura: %.2f unidades\n", base_triangulo, altura_triangulo);
    printf("   Área: %.2f unidades²\n", area_triangulo);
    
    // Comparación de áreas
    printf("\n=== COMPARACIÓN DE ÁREAS ===\n");
    printf("Círculo:    %.2f unidades²\n", area_circulo);
    printf("Rectángulo: %.2f unidades²\n", area_rectangulo);
    printf("Triángulo:  %.2f unidades²\n", area_triangulo);
    
    // Encontrar la figura con mayor área
    const char* figura_mayor;
    double area_mayor = area_circulo;
    figura_mayor = "Círculo";
    
    if (area_rectangulo > area_mayor) {
        area_mayor = area_rectangulo;
        figura_mayor = "Rectángulo";
    }
    if (area_triangulo > area_mayor) {
        area_mayor = area_triangulo;
        figura_mayor = "Triángulo";
    }
    
    printf("\nLa figura con mayor área es: %s (%.2f unidades²)\n", 
           figura_mayor, area_mayor);
    
    // Cálculos adicionales con conversiones
    printf("\n=== CONVERSIONES Y VALIDACIONES ===\n");
    
    // Convertir áreas a diferentes unidades
    double area_circulo_cm2 = area_circulo * 10000;  // m² a cm²
    int area_circulo_entero = (int)(area_circulo + 0.5);  // Redondeo
    
    printf("Área círculo: %.4f m² = %.0f cm² ≈ %d m² (redondeado)\n",
           area_circulo, area_circulo_cm2, area_circulo_entero);
    
    return 0;
}
```

#### Ejercicio 5: Sistema de Calificaciones
```c
/*
Desarrollar un sistema que:
1. Declare variables para múltiples calificaciones
2. Use constantes para valores de referencia (nota mínima, máxima)
3. Calcule promedio, máximo y mínimo
4. Determine aprobado/reprobado usando variables booleanas
5. Use casting apropiado para mostrar resultados
*/

#include <stdio.h>
#include <stdbool.h>

// Constantes del sistema de calificaciones
#define NOTA_MINIMA 0.0f
#define NOTA_MAXIMA 10.0f
#define NOTA_APROBATORIA 6.0f
#define NUM_MATERIAS 5

int main() {
    printf("=== SISTEMA DE CALIFICACIONES ===\n\n");
    
    // Nombres de materias
    const char* materias[NUM_MATERIAS] = {
        "Matemáticas",
        "Física",
        "Química",
        "Historia",
        "Literatura"
    };
    
    // Calificaciones del estudiante
    float calificaciones[NUM_MATERIAS] = {8.5f, 7.2f, 9.0f, 5.8f, 8.1f};
    
    // Variables para cálculos
    float suma = 0.0f;
    float promedio;
    float nota_maxima = NOTA_MINIMA;
    float nota_minima = NOTA_MAXIMA;
    int materias_aprobadas = 0;
    int materias_reprobadas = 0;
    
    printf("=== CALIFICACIONES POR MATERIA ===\n");
    
    // Procesar cada calificación
    for (int i = 0; i < NUM_MATERIAS; i++) {
        float nota = calificaciones[i];
        bool aprobado = (nota >= NOTA_APROBATORIA);
        
        // Actualizar estadísticas
        suma += nota;
        if (nota > nota_maxima) nota_maxima = nota;
        if (nota < nota_minima) nota_minima = nota;
        
        if (aprobado) {
            materias_aprobadas++;
        } else {
            materias_reprobadas++;
        }
        
        // Mostrar información de la materia
        printf("%-12s: %.1f %s\n", materias[i], nota, 
               aprobado ? "(✓ Aprobado)" : "(✗ Reprobado)");
    }
    
    // Calcular promedio
    promedio = suma / NUM_MATERIAS;
    bool promedio_aprobatorio = (promedio >= NOTA_APROBATORIA);
    
    // Mostrar estadísticas generales
    printf("\n=== ESTADÍSTICAS GENERALES ===\n");
    printf("Promedio general: %.2f %s\n", promedio,
           promedio_aprobatorio ? "(✓ Aprobado)" : "(✗ Reprobado)");
    printf("Nota máxima: %.1f\n", nota_maxima);
    printf("Nota mínima: %.1f\n", nota_minima);
    printf("Materias aprobadas: %d/%d\n", materias_aprobadas, NUM_MATERIAS);
    printf("Materias reprobadas: %d/%d\n", materias_reprobadas, NUM_MATERIAS);
    
    // Clasificación del estudiante
    printf("\n=== CLASIFICACIÓN FINAL ===\n");
    if (promedio >= 9.0f) {
        printf("Clasificación: Excelente\n");
    } else if (promedio >= 8.0f) {
        printf("Clasificación: Muy Bueno\n");
    } else if (promedio >= 7.0f) {
        printf("Clasificación: Bueno\n");
    } else if (promedio >= 6.0f) {
        printf("Clasificación: Suficiente\n");
    } else {
        printf("Clasificación: Insuficiente\n");
    }
    
    // Conversiones y formatos adicionales
    printf("\n=== INFORMACIÓN ADICIONAL ===\n");
    int promedio_entero = (int)promedio;
    int promedio_redondeado = (int)(promedio + 0.5f);
    float porcentaje_aprobacion = ((float)materias_aprobadas / NUM_MATERIAS) * 100.0f;
    
    printf("Promedio truncado: %d\n", promedio_entero);
    printf("Promedio redondeado: %d\n", promedio_redondeado);
    printf("Porcentaje de aprobación: %.1f%%\n", porcentaje_aprobacion);
    
    return 0;
}
```

### 10.3 Ejercicios Avanzados

#### Ejercicio 6: Análisis de Datos de Sensores
```c
/*
Crear un programa que simule la lectura de sensores:
1. Declare arrays para diferentes tipos de sensores
2. Use diferentes tipos de datos según la precisión requerida
3. Calcule estadísticas (promedio, máximo, mínimo)
4. Identifique valores fuera de rango
5. Genere un reporte completo
*/

#include <stdio.h>
#include <stdbool.h>
#include <float.h>

#define NUM_LECTURAS 10
#define TEMP_MIN -10.0f
#define TEMP_MAX 50.0f
#define PRESION_MIN 900.0f
#define PRESION_MAX 1100.0f
#define HUMEDAD_MIN 0.0f
#define HUMEDAD_MAX 100.0f

int main() {
    printf("=== ANÁLISIS DE DATOS DE SENSORES ===\n\n");
    
    // Datos de sensores (simulados)
    float temperaturas[NUM_LECTURAS] = {
        23.5f, 24.2f, 22.8f, 25.1f, 23.9f,
        24.7f, 23.2f, 24.5f, 23.8f, 24.3f
    };
    
    double presiones[NUM_LECTURAS] = {
        1013.25, 1012.80, 1013.45, 1012.95, 1013.10,
        1012.75, 1013.30, 1012.85, 1013.05, 1013.15
    };
    
    unsigned char humedades[NUM_LECTURAS] = {
        65, 67, 63, 68, 66, 64, 69, 65, 67, 66
    };
    
    // Variables para estadísticas
    float temp_suma = 0.0f, temp_max = -FLT_MAX, temp_min = FLT_MAX;
    double pres_suma = 0.0, pres_max = -DBL_MAX, pres_min = DBL_MAX;
    unsigned int hum_suma = 0;
    unsigned char hum_max = 0, hum_min = 255;
    
    int temp_fuera_rango = 0;
    int pres_fuera_rango = 0;
    int hum_fuera_rango = 0;
    
    printf("=== LECTURAS DE SENSORES ===\n");
    printf("Lectura  Temp(°C)  Presión(hPa)  Humedad(%%)  Estado\n");
    printf("-------  --------  ------------  -----------  ------\n");
    
    // Procesar cada lectura
    for (int i = 0; i < NUM_LECTURAS; i++) {
        // Procesar temperatura
        float temp = temperaturas[i];
        temp_suma += temp;
        if (temp > temp_max) temp_max = temp;
        if (temp < temp_min) temp_min = temp;
        bool temp_ok = (temp >= TEMP_MIN && temp <= TEMP_MAX);
        if (!temp_ok) temp_fuera_rango++;
        
        // Procesar presión
        double pres = presiones[i];
        pres_suma += pres;
        if (pres > pres_max) pres_max = pres;
        if (pres < pres_min) pres_min = pres;
        bool pres_ok = (pres >= PRESION_MIN && pres <= PRESION_MAX);
        if (!pres_ok) pres_fuera_rango++;
        
        // Procesar humedad
        unsigned char hum = humedades[i];
        hum_suma += hum;
        if (hum > hum_max) hum_max = hum;
        if (hum < hum_min) hum_min = hum;
        bool hum_ok = (hum >= HUMEDAD_MIN && hum <= HUMEDAD_MAX);
        if (!hum_ok) hum_fuera_rango++;
        
        // Mostrar lectura
        char estado = (temp_ok && pres_ok && hum_ok) ? '✓' : '✗';
        printf("%7d  %8.1f  %12.2f  %11u  %6c\n", 
               i+1, temp, pres, hum, estado);
    }
    
    // Calcular promedios
    float temp_promedio = temp_suma / NUM_LECTURAS;
    double pres_promedio = pres_suma / NUM_LECTURAS;
    float hum_promedio = (float)hum_suma / NUM_LECTURAS;
    
    // Mostrar estadísticas
    printf("\n=== ESTADÍSTICAS ===\n");
    printf("TEMPERATURA:\n");
    printf("  Promedio: %.2f°C\n", temp_promedio);
    printf("  Máxima:   %.2f°C\n", temp_max);
    printf("  Mínima:   %.2f°C\n", temp_min);
    printf("  Rango:    %.2f°C - %.2f°C\n", TEMP_MIN, TEMP_MAX);
    printf("  Fuera de rango: %d/%d\n", temp_fuera_rango, NUM_LECTURAS);
    
    printf("\nPRESIÓN:\n");
    printf("  Promedio: %.2f hPa\n", pres_promedio);
    printf("  Máxima:   %.2f hPa\n", pres_max);
    printf("  Mínima:   %.2f hPa\n", pres_min);
    printf("  Rango:    %.1f - %.1f hPa\n", PRESION_MIN, PRESION_MAX);
    printf("  Fuera de rango: %d/%d\n", pres_fuera_rango, NUM_LECTURAS);
    
    printf("\nHUMEDAD:\n");
    printf("  Promedio: %.1f%%\n", hum_promedio);
    printf("  Máxima:   %u%%\n", hum_max);
    printf("  Mínima:   %u%%\n", hum_min);
    printf("  Rango:    %.0f%% - %.0f%%\n", HUMEDAD_MIN, HUMEDAD_MAX);
    printf("  Fuera de rango: %d/%d\n", hum_fuera_rango, NUM_LECTURAS);
    
    // Evaluación general
    int total_fuera_rango = temp_fuera_rango + pres_fuera_rango + hum_fuera_rango;
    float calidad_datos = (1.0f - (float)total_fuera_rango / (NUM_LECTURAS * 3)) * 100.0f;
    
    printf("\n=== EVALUACIÓN GENERAL ===\n");
    printf("Total de lecturas: %d\n", NUM_LECTURAS * 3);
    printf("Lecturas válidas: %d\n", (NUM_LECTURAS * 3) - total_fuera_rango);
    printf("Calidad de datos: %.1f%%\n", calidad_datos);
    
    if (calidad_datos >= 95.0f) {
        printf("Estado: Excelente\n");
    } else if (calidad_datos >= 90.0f) {
        printf("Estado: Bueno\n");
    } else if (calidad_datos >= 80.0f) {
        printf("Estado: Aceptable\n");
    } else {
        printf("Estado: Requiere atención\n");
    }
    
    return 0;
}
```

---

## 11. Conceptos Avanzados

### 11.1 Representación en Memoria

```c
#include <stdio.h>

int main() {
    printf("=== REPRESENTACIÓN EN MEMORIA ===\n");
    
    // Variables de diferentes tipos
    char c = 'A';
    short s = 1000;
    int i = 100000;
    float f = 3.14159f;
    double d = 2.718281828;
    
    // Mostrar direcciones y tamaños
    printf("Variable  Valor      Dirección    Tamaño\n");
    printf("--------  ---------  -----------  ------\n");
    printf("char      %c (%d)     %p       %zu bytes\n", c, c, (void*)&c, sizeof(c));
    printf("short     %-9d  %p       %zu bytes\n", s, (void*)&s, sizeof(s));
    printf("int       %-9d  %p       %zu bytes\n", i, (void*)&i, sizeof(i));
    printf("float     %-9.5f  %p       %zu bytes\n", f, (void*)&f, sizeof(f));
    printf("double    %-9.9f  %p       %zu bytes\n", d, (void*)&d, sizeof(d));
    
    // Análisis de alineación
    struct EjemploAlineacion {
        char c1;
        int i1;
        char c2;
        double d1;
    } ejemplo;
    
    printf("\n=== ALINEACIÓN DE ESTRUCTURAS ===\n");
    printf("Tamaño de la estructura: %zu bytes\n", sizeof(ejemplo));
    printf("Dirección base: %p\n", (void*)&ejemplo);
    printf("c1: %p (offset: %zu)\n", (void*)&ejemplo.c1, 
           (char*)&ejemplo.c1 - (char*)&ejemplo);
    printf("i1: %p (offset: %zu)\n", (void*)&ejemplo.i1, 
           (char*)&ejemplo.i1 - (char*)&ejemplo);
    printf("c2: %p (offset: %zu)\n", (void*)&ejemplo.c2, 
           (char*)&ejemplo.c2 - (char*)&ejemplo);
    printf("d1: %p (offset: %zu)\n", (void*)&ejemplo.d1, 
           (char*)&ejemplo.d1 - (char*)&ejemplo);
    
    return 0;
}
```

### 11.2 Operaciones a Nivel de Bits

```c
#include <stdio.h>

void mostrar_bits(unsigned int numero) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (numero >> i) & 1);
        if (i % 4 == 0 && i > 0) printf(" ");
    }
    printf("\n");
}

int main() {
    printf("=== OPERACIONES A NIVEL DE BITS ===\n");
    
    unsigned int a = 60;    // 0011 1100 en binario
    unsigned int b = 13;    // 0000 1101 en binario
    
    printf("a = %u = ", a);
    mostrar_bits(a);
    printf("b = %u = ", b);
    mostrar_bits(b);
    
    printf("\nOperaciones:\n");
    printf("a & b  = %u = ", a & b);
    mostrar_bits(a & b);
    
    printf("a | b  = %u = ", a | b);
    mostrar_bits(a | b);
    
    printf("a ^ b  = %u = ", a ^ b);
    mostrar_bits(a ^ b);
    
    printf("~a     = %u = ", ~a);
    mostrar_bits(~a);
    
    printf("a << 2 = %u = ", a << 2);
    mostrar_bits(a << 2);
    
    printf("a >> 2 = %u = ", a >> 2);
    mostrar_bits(a >> 2);
    
    // Aplicaciones prácticas
    printf("\n=== APLICACIONES PRÁCTICAS ===\n");
    
    // Verificar si un número es par
    int numero = 42;
    printf("¿%d es par? %s\n", numero, (numero & 1) == 0 ? "Sí" : "No");
    
    // Intercambiar valores sin variable temporal
    int x = 10, y = 20;
    printf("Antes: x=%d, y=%d\n", x, y);
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    printf("Después: x=%d, y=%d\n", x, y);
    
    // Establecer, limpiar y verificar bits
    unsigned char flags = 0;
    printf("\nManejo de flags:\n");
    printf("Inicial: ");
    for (int i = 7; i >= 0; i--) printf("%d", (flags >> i) & 1);
    printf("\n");
    
    flags |= (1 << 3);  // Establecer bit 3
    printf("Set bit 3: ");
    for (int i = 7; i >= 0; i--) printf("%d", (flags >> i) & 1);
    printf("\n");
    
    flags &= ~(1 << 1);  // Limpiar bit 1
    printf("Clear bit 1: ");
    for (int i = 7; i >= 0; i--) printf("%d", (flags >> i) & 1);
    printf("\n");
    
    printf("Bit 3 está %s\n", (flags & (1 << 3)) ? "activado" : "desactivado");
    
    return 0;
}
```

### 11.3 Uniones (Unions)

```c
#include <stdio.h>

// Unión para interpretar datos de diferentes formas
union Datos {
    int entero;
    float flotante;
    char bytes[4];
};

// Unión para direcciones IP
union DireccionIP {
    unsigned int ip;
    unsigned char octetos[4];
};

int main() {
    printf("=== UNIONES (UNIONS) ===\n");
    
    union Datos dato;
    
    // Almacenar como entero
    dato.entero = 0x41424344;  // ABCD en ASCII
    printf("Como entero: %d (0x%08X)\n", dato.entero, dato.entero);
    printf("Como flotante: %f\n", dato.flotante);
    printf("Como bytes: ");
    for (int i = 0; i < 4; i++) {
        printf("%c", dato.bytes[i]);
    }
    printf("\n");
    printf("Bytes hex: ");
    for (int i = 0; i < 4; i++) {
        printf("%02X ", (unsigned char)dato.bytes[i]);
    }
    printf("\n");
    
    // Cambiar a flotante
    dato.flotante = 3.14159f;
    printf("\nDespués de asignar flotante:\n");
    printf("Como flotante: %f\n", dato.flotante);
    printf("Como entero: %d (0x%08X)\n", dato.entero, dato.entero);
    
    // Ejemplo con dirección IP
    printf("\n=== EJEMPLO: DIRECCIÓN IP ===\n");
    union DireccionIP ip;
    
    // Establecer por octetos
    ip.octetos[0] = 192;
    ip.octetos[1] = 168;
    ip.octetos[2] = 1;
    ip.octetos[3] = 1;
    
    printf("IP como octetos: %u.%u.%u.%u\n", 
           ip.octetos[0], ip.octetos[1], ip.octetos[2], ip.octetos[3]);
    printf("IP como entero: %u (0x%08X)\n", ip.ip, ip.ip);
    
    // Establecer como entero
    ip.ip = 0xC0A80001;  // 192.168.0.1
    printf("Nuevo IP: %u.%u.%u.%u\n", 
           ip.octetos[0], ip.octetos[1], ip.octetos[2], ip.octetos[3]);
    
    printf("\nTamaño de union Datos: %zu bytes\n", sizeof(union Datos));
    printf("Tamaño de union DireccionIP: %zu bytes\n", sizeof(union DireccionIP));
    
    return 0;
}
```

### 11.4 Campos de Bits (Bit Fields)

```c
#include <stdio.h>

// Estructura con campos de bits
struct Flags {
    unsigned int activo : 1;      // 1 bit
    unsigned int visible : 1;     // 1 bit
    unsigned int prioridad : 3;   // 3 bits (0-7)
    unsigned int reservado : 3;   // 3 bits reservados
    unsigned int id : 8;          // 8 bits (0-255)
};

// Ejemplo de registro de control
struct RegistroControl {
    unsigned char habilitado : 1;
    unsigned char modo : 2;
    unsigned char velocidad : 3;
    unsigned char paridad : 2;
};

int main() {
    printf("=== CAMPOS DE BITS ===\n");
    
    struct Flags flag = {0};
    
    printf("Tamaño de struct Flags: %zu bytes\n", sizeof(flag));
    
    // Asignar valores
    flag.activo = 1;
    flag.visible = 0;
    flag.prioridad = 5;
    flag.id = 123;
    
    printf("Valores:\n");
    printf("  Activo: %u\n", flag.activo);
    printf("  Visible: %u\n", flag.visible);
    printf("  Prioridad: %u\n", flag.prioridad);
    printf("  ID: %u\n", flag.id);
    
    // Mostrar como bits
    printf("\nRepresentación en memoria:\n");
    unsigned char *ptr = (unsigned char*)&flag;
    for (int i = 0; i < sizeof(flag); i++) {
        for (int j = 7; j >= 0; j--) {
            printf("%d", (ptr[i] >> j) & 1);
        }
        printf(" ");
    }
    printf("\n");
    
    // Ejemplo de registro de control
    printf("\n=== REGISTRO DE CONTROL ===\n");
    struct RegistroControl reg = {0};
    
    reg.habilitado = 1;
    reg.modo = 2;        // 0-3
    reg.velocidad = 4;   // 0-7
    reg.paridad = 1;     // 0-3
    
    printf("Configuración:\n");
    printf("  Habilitado: %s\n", reg.habilitado ? "Sí" : "No");
    printf("  Modo: %u\n", reg.modo);
    printf("  Velocidad: %u\n", reg.velocidad);
    printf("  Paridad: %u\n", reg.paridad);
    
    printf("Tamaño del registro: %zu byte(s)\n", sizeof(reg));
    
    // Verificar límites
    printf("\n=== VERIFICACIÓN DE LÍMITES ===\n");
    flag.prioridad = 8;  // Desbordamiento: solo 3 bits
    printf("Prioridad después de overflow: %u\n", flag.prioridad);
    
    return 0;
}
```

---

## 12. Debugging y Herramientas

### 12.1 Técnicas de Debugging

```c
#include <stdio.h>
#include <assert.h>

// Macro para debugging condicional
#define DEBUG 1

#if DEBUG
    #define DEBUG_PRINT(fmt, ...) \
        fprintf(stderr, "[DEBUG] %s:%d - " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
    #define DEBUG_PRINT(fmt, ...)
#endif

int dividir(int a, int b) {
    DEBUG_PRINT("Dividiendo %d entre %d", a, b);
    
    // Usar assert para verificar precondiciones
    assert(b != 0 && "División por cero!");
    
    int resultado = a / b;
    DEBUG_PRINT("Resultado: %d", resultado);
    
    return resultado;
}

int main() {
    printf("=== TÉCNICAS DE DEBUGGING ===\n");
    
    // Variables para demonstrar debugging
    int x = 10, y = 3, z = 0;
    
    DEBUG_PRINT("Iniciando programa");
    DEBUG_PRINT("Variables: x=%d, y=%d, z=%d", x, y, z);
    
    // Operación normal
    int resultado1 = dividir(x, y);
    printf("10 / 3 = %d\n", resultado1);
    
    // Imprimir información de variables
    printf("\n=== INFORMACIÓN DE VARIABLES ===\n");
    printf("Variable x:\n");
    printf("  Valor: %d\n", x);
    printf("  Dirección: %p\n", (void*)&x);
    printf("  Tamaño: %zu bytes\n", sizeof(x));
    
    // Hexadecimal dump de una variable
    printf("\nDump hexadecimal de x:\n");
    unsigned char *ptr = (unsigned char*)&x;
    for (int i = 0; i < sizeof(x); i++) {
        printf("Byte %d: 0x%02X (%u)\n", i, ptr[i], ptr[i]);
    }
    
    // Mostrar información del sistema
    printf("\n=== INFORMACIÓN DEL SISTEMA ===\n");
    printf("Archivo: %s\n", __FILE__);
    printf("Línea: %d\n", __LINE__);
    printf("Fecha de compilación: %s\n", __DATE__);
    printf("Hora de compilación: %s\n", __TIME__);
    
    // Intentar división por cero (comentado para evitar crash)
    // int resultado2 = dividir(x, z);  // Esto causaría assert failure
    
    return 0;
}
```

### 12.2 Herramientas de Análisis

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función que demuestra problemas comunes
void demostrar_problemas() {
    printf("=== PROBLEMAS COMUNES Y SU DETECCIÓN ===\n");
    
    // 1. Variable no inicializada
    int no_inicializada;
    printf("Variable no inicializada: %d (valor impredecible)\n", no_inicializada);
    
    // 2. Buffer overflow (cuidado!)
    char buffer[10];
    strcpy(buffer, "Texto demasiado largo para el buffer");
    printf("Buffer después del overflow: %s\n", buffer);
    
    // 3. Memory leak simulation
    int *ptr = malloc(sizeof(int) * 100);
    *ptr = 42;
    printf("Valor en memoria dinámica: %d\n", *ptr);
    // free(ptr); // Comentado para simular memory leak
    
    // 4. Uso después de free
    free(ptr);
    // printf("Valor después de free: %d\n", *ptr); // Peligroso!
    
    // 5. Double free
    // free(ptr); // Esto causaría error
}

// Función para analizar uso de memoria
void analizar_memoria() {
    printf("\n=== ANÁLISIS DE MEMORIA ===\n");
    
    // Variables locales
    int local_int = 100;
    char local_array[1000];
    
    // Variables dinámicas
    int *dynamic_int = malloc(sizeof(int));
    char *dynamic_array = malloc(1000);
    
    if (dynamic_int && dynamic_array) {
        *dynamic_int = 200;
        strcpy(dynamic_array, "Memoria dinámica");
        
        printf("Variables locales:\n");
        printf("  int local: %p (stack)\n", (void*)&local_int);
        printf("  array local: %p (stack)\n", (void*)local_array);
        
        printf("Variables dinámicas:\n");
        printf("  int dinámico: %p (heap)\n", (void*)dynamic_int);
        printf("  array dinámico: %p (heap)\n", (void*)dynamic_array);
        
        // Liberar memoria
        free(dynamic_int);
        free(dynamic_array);
        
        // Buena práctica: poner punteros a NULL
        dynamic_int = NULL;
        dynamic_array = NULL;
    }
}

int main() {
    printf("=== HERRAMIENTAS DE DEBUGGING ===\n");
    printf("Compile con flags de debugging:\n");
    printf("gcc -g -Wall -Wextra -Werror -fsanitize=address archivo.c\n\n");
    
    printf("Herramientas recomendadas:\n");
    printf("- GDB: GNU Debugger\n");
    printf("- Valgrind: Detección de memory leaks\n");
    printf("- AddressSanitizer: Detección de buffer overflows\n");
    printf("- Static analyzers: cppcheck, clang-static-analyzer\n\n");
    
    // Demonstrar problemas (con cuidado)
    // demostrar_problemas(); // Descomentado solo para testing controlado
    
    analizar_memoria();
    
    // Información útil para debugging
    printf("\n=== INFORMACIÓN ÚTIL PARA DEBUGGING ===\n");
    printf("Tamaños de tipos en este sistema:\n");
    printf("  char: %zu bytes\n", sizeof(char));
    printf("  int: %zu bytes\n", sizeof(int));
    printf("  long: %zu bytes\n", sizeof(long));
    printf("  float: %zu bytes\n", sizeof(float));
    printf("  double: %zu bytes\n", sizeof(double));
    printf("  void*: %zu bytes\n", sizeof(void*));
    
    return 0;
}
```

---

## 13. Resumen y Mejores Prácticas

### 13.1 Checklist de Buenas Prácticas

```c
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

/*
=== CHECKLIST DE BUENAS PRÁCTICAS ===

✅ DECLARACIÓN Y NOMBRES:
   - Nombres descriptivos y consistentes
   - Inicializar todas las variables
   - Usar const para valores que no cambian
   - Elegir el tipo apropiado para cada uso

✅ TIPOS DE DATOS:
   - int para contadores y números generales
   - float/double para números decimales
   - unsigned para valores siempre positivos
   - char para caracteres individuales
   - bool para valores verdadero/falso

✅ CONSTANTES:
   - #define para constantes del preprocesador
   - const para constantes con tipo
   - Nombres en MAYÚSCULAS para constantes

✅ CONVERSIONES:
   - Usar casting explícito cuando sea necesario
   - Evitar pérdida de precisión
   - Verificar rangos antes de convertir

✅ MEMORIA Y RENDIMIENTO:
   - Evitar variables globales innecesarias
   - Usar static para funciones auxiliares
   - Considerar alineación en estructuras
*/

// Ejemplo que sigue las mejores prácticas
int main() {
    printf("=== EJEMPLO DE MEJORES PRÁCTICAS ===\n");
    
    // ✅ Constantes bien definidas
    const int MAX_ESTUDIANTES = 50;
    const float NOTA_APROBATORIA = 6.0f;
    const char GRADO_EXCELENTE = 'A';
    
    // ✅ Variables con nombres descriptivos e inicializadas
    int numero_estudiantes = 0;
    float suma_notas = 0.0f;
    float promedio_clase = 0.0f;
    bool clase_aprobada = false;
    
    // ✅ Uso de tipos apropiados
    unsigned char edad_estudiante = 20;  // 0-255 es suficiente
    short año_inscripcion = 2024;        // -32768 a 32767 es suficiente
    
    // ✅ Arrays inicializados correctamente
    float notas_estudiantes[MAX_ESTUDIANTES] = {0.0f};
    char nombres_estudiantes[MAX_ESTUDIANTES][50] = {""};
    
    // ✅ Simulación de datos (normalmente leídos de input)
    numero_estudiantes = 5;
    float notas_ejemplo[] = {8.5f, 7.2f, 9.1f, 6.8f, 7.9f};
    
    // ✅ Procesamiento con validación
    for (int i = 0; i < numero_estudiantes && i < MAX_ESTUDIANTES; i++) {
        float nota = notas_ejemplo[i];
        
        // ✅ Validación de rango
        if (nota >= 0.0f && nota <= 10.0f) {
            notas_estudiantes[i] = nota;
            suma_notas += nota;
        } else {
            printf("⚠️  Nota inválida para estudiante %d: %.1f\n", i+1, nota);
        }
    }
    
    // ✅ Cálculos seguros (evitar división por cero)
    if (numero_estudiantes > 0) {
        promedio_clase = suma_notas / numero_estudiantes;
        clase_aprobada = (promedio_clase >= NOTA_APROBATORIA);
    }
    
    // ✅ Output formateado y claro
    printf("\n=== RESULTADOS ===\n");
    printf("Número de estudiantes: %d\n", numero_estudiantes);
    printf("Promedio de clase: %.2f\n", promedio_clase);
    printf("Estado: %s\n", clase_aprobada ? "✅ Aprobada" : "❌ No aprobada");
    
    // ✅ Información adicional con conversiones apropiadas
    char grado_clase;
    if (promedio_clase >= 9.0f) grado_clase = 'A';
    else if (promedio_clase >= 8.0f) grado_clase = 'B';
    else if (promedio_clase >= 7.0f) grado_clase = 'C';
    else if (promedio_clase >= 6.0f) grado_clase = 'D';
    else grado_clase = 'F';
    
    printf("Grado de la clase: %c\n", grado_clase);
    
    // ✅ Conversiones explícitas cuando sea necesario
    int promedio_redondeado = (int)(promedio_clase + 0.5f);
    printf("Promedio redondeado: %d\n", promedio_redondeado);
    
    return 0;
}
```

### 13.2 Errores Comunes y Cómo Evitarlos

```c
#include <stdio.h>
#include <string.h>

void demostrar_errores_comunes() {
    printf("=== ERRORES COMUNES Y SU PREVENCIÓN ===\n");
    
    // ❌ ERROR 1: Variables no inicializadas
    printf("\n1. VARIABLES NO INICIALIZADAS\n");
    int malo;  // ❌ No inicializada
    int bueno = 0;  // ✅ Inicializada
    
    printf("❌ Variable no inicializada: %d (valor impredecible)\n", malo);
    printf("✅ Variable inicializada: %d\n", bueno);
    
    // ❌ ERROR 2: Confundir = con ==
    printf("\n2. CONFUNDIR ASIGNACIÓN CON COMPARACIÓN\n");
    int x = 5;
    
    // ❌ if (x = 10)  // Asignación, no comparación
    if (x == 10) {  // ✅ Comparación correcta
        printf("x es igual a 10\n");
    } else {
        printf("x no es igual a 10 (x = %d)\n", x);
    }
    
    // ❌ ERROR 3: Desbordamiento de tipos
    printf("\n3. DESBORDAMIENTO DE TIPOS\n");
    char pequeño = 127;  // Máximo para signed char
    printf("Valor inicial: %d\n", pequeño);
    pequeño++;  // ❌ Desbordamiento
    printf("❌ Después del desbordamiento: %d\n", pequeño);
    
    // ✅ Solución: usar tipo apropiado o verificar límites
    int apropiado = 127;
    if (apropiado < 200) {  // Verificación
        apropiado++;
        printf("✅ Valor seguro: %d\n", apropiado);
    }
    
    // ❌ ERROR 4: Pérdida de precisión
    printf("\n4. PÉRDIDA DE PRECISIÓN\n");
    float precision_perdida = 1.0f / 3.0f;
    double precision_mantenida = 1.0 / 3.0;
    
    printf("❌ float (7 dígitos):  %.10f\n", precision_perdida);
    printf("✅ double (15 dígitos): %.10f\n", precision_mantenida);
    
    // ❌ ERROR 5: División entera inesperada
    printf("\n5. DIVISIÓN ENTERA INESPERADA\n");
    int a = 5, b = 2;
    int resultado_malo = a / b;  // ❌ División entera
    float resultado_bueno = (float)a / b;  // ✅ División decimal
    
    printf("❌ División entera: %d / %d = %d\n", a, b, resultado_malo);
    printf("✅ División decimal: %d / %d = %.2f\n", a, b, resultado_bueno);
}

void mejores_practicas_resumen() {
    printf("\n=== RESUMEN DE MEJORES PRÁCTICAS ===\n");
    
    printf("\n✅ DECLARACIÓN DE VARIABLES:\n");
    printf("   • Siempre inicializar\n");
    printf("   • Usar nombres descriptivos\n");
    printf("   • Declarar cerca de su uso\n");
    printf("   • Usar const para valores constantes\n");
    
    printf("\n✅ ELECCIÓN DE TIPOS:\n");
    printf("   • int: para enteros generales\n");
    printf("   • unsigned: para valores no negativos\n");
    printf("   • float/double: para decimales\n");
    printf("   • char: para caracteres\n");
    printf("   • bool: para verdadero/falso\n");
    
    printf("\n✅ CONVERSIONES:\n");
    printf("   • Usar casting explícito\n");
    printf("   • Verificar rangos de destino\n");
    printf("   • Cuidado con pérdida de precisión\n");
    
    printf("\n✅ CONSTANTES:\n");
    printf("   • #define para macros\n");
    printf("   • const para variables constantes\n");
    printf("   • Nombres en MAYÚSCULAS\n");
    
    printf("\n✅ DEBUGGING:\n");
    printf("   • Compilar con -Wall -Wextra\n");
    printf("   • Usar herramientas como Valgrind\n");
    printf("   • Verificar límites de arrays\n");
    printf("   • Inicializar punteros a NULL\n");
}

int main() {
    demostrar_errores_comunes();
    mejores_practicas_resumen();
    return 0;
}
```

### 13.3 Recursos Adicionales y Referencias

```c
#include <stdio.h>

/*
=== RECURSOS ADICIONALES ===

📚 DOCUMENTACIÓN OFICIAL:
   • ISO C Standard (C11/C18)
   • GNU C Library Documentation
   • POSIX.1-2017

📖 LIBROS RECOMENDADOS:
   • "The C Programming Language" - Kernighan & Ritchie
   • "C: A Modern Approach" - K. N. King
   • "Expert C Programming" - Peter van der Linden
   • "C Traps and Pitfalls" - Andrew Koenig

🛠️ HERRAMIENTAS:
   • Compiladores: GCC, Clang, MSVC
   • Debuggers: GDB, LLDB
   • Static Analysis: Cppcheck, PVS-Studio
   • Memory Tools: Valgrind, AddressSanitizer

🌐 RECURSOS ONLINE:
   • cppreference.com
   • stackoverflow.com
   • GitHub repositories con ejemplos
   • Online compilers: ideone.com, onlinegdb.com

⚡ PRÁCTICA:
   • HackerRank, LeetCode para algoritmos
   • Project Euler para matemáticas
   • Contribuir a proyectos open source
   • Implementar estructuras de datos básicas
*/

void mostrar_ejemplo_completo() {
    printf("=== EJEMPLO COMPLETO APLICANDO TODAS LAS PRÁCTICAS ===\n");
    
    // Constantes bien definidas
    const int MAX_PRODUCTOS = 100;
    const float IVA = 0.16f;
    const float DESCUENTO_MAYORISTA = 0.10f;
    
    // Variables con tipos apropiados e inicializadas
    unsigned int num_productos = 0;
    float subtotal = 0.0f;
    float total_con_iva = 0.0f;
    float descuento = 0.0f;
    float total_final = 0.0f;
    bool es_mayorista = false;
    
    // Arrays inicializados
    float precios[MAX_PRODUCTOS] = {0.0f};
    char nombres[MAX_PRODUCTOS][50] = {""};
    
    // Datos de ejemplo
    num_productos = 3;
    float precios_ejemplo[] = {25.50f, 15.75f, 42.00f};
    const char* nombres_ejemplo[] = {"Producto A", "Producto B", "Producto C"};
    
    printf("=== FACTURACIÓN ===\n");
    printf("Producto               Precio\n");
    printf("---------------------- --------\n");
    
    // Procesamiento seguro
    for (unsigned int i = 0; i < num_productos && i < MAX_PRODUCTOS; i++) {
        // Validación de entrada
        if (precios_ejemplo[i] > 0.0f) {
            precios[i] = precios_ejemplo[i];
            strncpy(nombres[i], nombres_ejemplo[i], 49);
            nombres[i][49] = '\0';  // Asegurar terminación
            
            subtotal += precios[i];
            printf("%-22s $%.2f\n", nombres[i], precios[i]);
        }
    }
    
    // Cálculos con validación
    if (subtotal > 0.0f) {
        // Aplicar descuento si es mayorista
        if (subtotal > 100.0f) {  // Criterio para mayorista
            es_mayorista = true;
            descuento = subtotal * DESCUENTO_MAYORISTA;
        }
        
        float subtotal_con_descuento = subtotal - descuento;
        float iva_calculado = subtotal_con_descuento * IVA;
        total_final = subtotal_con_descuento + iva_calculado;
        
        // Mostrar resultados
        printf("\n---------------------- --------\n");
        printf("Subtotal:              $%.2f\n", subtotal);
        
        if (es_mayorista) {
            printf("Descuento (%.0f%%):       -$%.2f\n", 
                   DESCUENTO_MAYORISTA * 100, descuento);
            printf("Subtotal con descuento: $%.2f\n", subtotal_con_descuento);
        }
        
        printf("IVA (%.0f%%):              +$%.2f\n", IVA * 100, iva_calculado);
        printf("TOTAL:                 $%.2f\n", total_final);
        
        // Información adicional
        printf("\nEstado: %s\n", es_mayorista ? "Cliente mayorista" : "Cliente regular");
        printf("Productos: %u\n", num_productos);
        printf("Precio promedio: $%.2f\n", subtotal / num_productos);
    } else {
        printf("❌ Error: No hay productos válidos\n");
    }
}

int main() {
    printf("Variables y Tipos de Datos en C - Guía Completa\n");
    printf("===============================================\n\n");
    
    mostrar_ejemplo_completo();
    
    printf("\n=== FIN DE LA GUÍA ===\n");
    printf("¡Has completado el estudio de variables y tipos de datos en C!\n");
    printf("Continúa practicando y explorando conceptos más avanzados.\n");
    
    return 0;
}
```

---

## Conclusión

Esta guía completa sobre **Variables y Tipos de Datos en C** cubre todos los aspectos fundamentales y avanzados que necesitas conocer:

### Lo que has aprendido:

1. **Fundamentos**: Qué son las variables, sus características y nomenclatura
2. **Tipos básicos**: char, int, float, double y sus variaciones
3. **Modificadores**: signed, unsigned, short, long
4. **Constantes**: Literales, #define y const
5. **Ámbito**: Variables locales, globales y estáticas
6. **Conversiones**: Implícitas, explícitas y sus peligros
7. **Tipos derivados**: Arrays, punteros, estructuras y uniones
8. **Conceptos avanzados**: Representación en memoria, operaciones de bits
9. **Buenas prácticas**: Nomenclatura, inicialización, debugging
10. **Ejemplos prácticos**: Ejercicios completos y casos de uso reales

### Próximos pasos:

- Practica con los ejercicios proporcionados
- Experimenta con diferentes compiladores y flags
- Estudia estructuras de control (if, while, for)
- Aprende sobre funciones y paso de parámetros
- Explora programación con punteros y memoria dinámica
- Contribuye a proyectos open source para ganar experiencia

¡Continúa programando y nunca dejes de aprender! 🚀