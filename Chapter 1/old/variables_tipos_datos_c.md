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
    // Declaración y inicialización
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
#include