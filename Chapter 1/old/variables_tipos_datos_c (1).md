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
```

#### Ejercicio 6: Conversor de Unidades
```c
/*
Crear un conversor completo que:
1. Maneje conversiones de longitud (metros, pies, pulgadas)
2. Maneje conversiones de peso (kg, libras, onzas)
3. Use constantes para factores de conversión
4. Implemente validación de tipos de entrada
5. Muestre tabla de conversiones
*/
```

### 10.3 Ejercicios Avanzados

#### Ejercicio 7: Simulador de Cuenta Bancaria
```c
/*
Implementar un simulador que:
1. Use tipos apropiados para diferentes valores monetarios
2. Maneje intereses con precisión decimal
3. Implemente límites de cuenta usando constantes
4. Use variables estáticas para número de cuenta
5. Demuestre conversiones seguras entre tipos
*/
```

#### Ejercicio 8: Análisis de Datos Científicos
```c
/*
Desarrollar un programa que:
1. Maneje datos de diferentes precisiones (float, double)
2. Implemente constantes físicas (c, h, g, etc.)
3. Realice cálculos científicos complejos
4. Compare precisión entre tipos de punto flotante
5. Muestre resultados en notación científica
*/
```

### 10.4 Proyecto Integrador

#### Proyecto: Sistema de Gestión de Inventario
```c
/*
Crear un sistema completo que:

1. TIPOS DE DATOS:
   - ID producto (int)
   - Nombre producto (char array)
   - Precio (usar enteros para centavos)
   - Cantidad en stock (unsigned int)
   - Es activo (bool)

2. CONSTANTES:
   - Máximo productos
   - IVA
   - Descuentos
   - Límites de stock

3. FUNCIONALIDADES:
   - Calcular valor total del inventario
   - Aplicar descuentos e impuestos
   - Convertir precios a diferentes monedas
   - Generar reportes con formato apropiado
   - Validar rangos de datos

4. DEMOSTRAR:
   - Uso apropiado de cada tipo de dato
   - Conversiones seguras
   - Manejo de constantes
   - Cálculos con precisión apropiada
   - Formateo de salida profesional
*/
```

---

## 11. Conceptos Avanzados

### 11.1 Alineación de Memoria

```c
#include <stdio.h>
#include <stddef.h>  // Para offsetof
#include <stdalign.h> // Para _Alignof (C11)

struct EjemploAlineacion {
    char c;      // 1 byte
    int i;       // 4 bytes
    char c2;     // 1 byte
    double d;    // 8 bytes
};

int main() {
    printf("=== ALINEACIÓN DE MEMORIA ===\n");
    
    printf("Tamaños individuales:\n");
    printf("char: %zu bytes\n", sizeof(char));
    printf("int: %zu bytes\n", sizeof(int));
    printf("double: %zu bytes\n", sizeof(double));
    
    printf("\nTamaño de estructura: %zu bytes\n", 
           sizeof(struct EjemploAlineacion));
    
    printf("\nOffsets en la estructura:\n");
    printf("c: %zu\n", offsetof(struct EjemploAlineacion, c));
    printf("i: %zu\n", offsetof(struct EjemploAlineacion, i));
    printf("c2: %zu\n", offsetof(struct EjemploAlineacion, c2));
    printf("d: %zu\n", offsetof(struct EjemploAlineacion, d));
    
    // Alineación de tipos básicos
    printf("\nAlineación de tipos:\n");
    printf("char: %zu\n", _Alignof(char));
    printf("int: %zu\n", _Alignof(int));
    printf("double: %zu\n", _Alignof(double));
    
    return 0;
}
```

### 11.2 Límites de Tipos

```c
#include <stdio.h>
#include <limits.h>  // Límites de enteros
#include <float.h>   // Límites de punto flotante

int main() {
    printf("=== LÍMITES DE TIPOS ===\n");
    
    printf("Límites de enteros:\n");
    printf("CHAR_MIN: %d, CHAR_MAX: %d\n", CHAR_MIN, CHAR_MAX);
    printf("INT_MIN: %d, INT_MAX: %d\n", INT_MIN, INT_MAX);
    printf("LONG_MIN: %ld, LONG_MAX: %ld\n", LONG_MIN, LONG_MAX);
    printf("UCHAR_MAX: %u\n", UCHAR_MAX);
    printf("UINT_MAX: %u\n", UINT_MAX);
    
    printf("\nLímites de punto flotante:\n");
    printf("FLT_MIN: %e, FLT_MAX: %e\n", FLT_MIN, FLT_MAX);
    printf("DBL_MIN: %e, DBL_MAX: %e\n", DBL_MIN, DBL_MAX);
    printf("FLT_DIG: %d (dígitos significativos)\n", FLT_DIG);
    printf("DBL_DIG: %d (dígitos significativos)\n", DBL_DIG);
    
    // Detección de desbordamiento
    int max_int = INT_MAX;
    printf("\nDetección de desbordamiento:\n");
    printf("INT_MAX: %d\n", max_int);
    printf("INT_MAX + 1: %d (desbordamiento)\n", max_int + 1);
    
    return 0;
}
```

### 11.3 Tipos Especializados (C99/C11)

```c
#include <stdio.h>
#include <stdint.h>   // Tipos de tamaño fijo
#include <stdbool.h>  // Tipo bool
#include <complex.h>  // Números complejos (C99)

int main() {
    printf("=== TIPOS ESPECIALIZADOS ===\n");
    
    // Tipos de tamaño fijo
    int8_t byte_con_signo = -128;
    uint8_t byte_sin_signo = 255;
    int32_t entero_32_bits = 2147483647;
    uint64_t entero_64_bits = 18446744073709551615ULL;
    
    printf("int8_t: %d\n", byte_con_signo);
    printf("uint8_t: %u\n", byte_sin_signo);
    printf("int32_t: %d\n", entero_32_bits);
    printf("uint64_t: %llu\n", entero_64_bits);
    
    // Tipo booleano
    bool es_verdadero = true;
    bool es_falso = false;
    
    printf("\nTipo bool:\n");
    printf("true: %d\n", es_verdadero);
    printf("false: %d\n", es_falso);
    
    // Números complejos (C99)
    double complex z1 = 1.0 + 2.0*I;
    double complex z2 = 3.0 + 4.0*I;
    double complex suma = z1 + z2;
    
    printf("\nNúmeros complejos:\n");
    printf("z1 = %.1f + %.1fi\n", creal(z1), cimag(z1));
    printf("z2 = %.1f + %.1fi\n", creal(z2), cimag(z2));
    printf("z1 + z2 = %.1f + %.1fi\n", creal(suma), cimag(suma));
    
    return 0;
}
```

---

## 12. Debugging y Herramientas

### 12.1 Macros de Debug

```c
#include <stdio.h>

// Macro para debugging
#define DEBUG 1

#if DEBUG
    #define debug_print(fmt, ...) \
        printf("DEBUG %s:%d: " fmt, __FILE__, __LINE__, ##__VA_ARGS__)
#else
    #define debug_print(fmt, ...)  // No hace nada en release
#endif

int main() {
    int x = 10;
    float y = 3.14f;
    char letra = 'A';
    
    debug_print("Valores iniciales: x=%d, y=%.2f, letra=%c\n", x, y, letra);
    
    x *= 2;
    debug_print("Después de multiplicar x por 2: x=%d\n", x);
    
    // Información del compilador y sistema
    printf("Información de compilación:\n");
    printf("Archivo: %s\n", __FILE__);
    printf("Línea: %d\n", __LINE__);
    printf("Fecha compilación: %s\n", __DATE__);
    printf("Hora compilación: %s\n", __TIME__);
    
    return 0;
}
```

### 12.2 Validación de Tipos

```c
#include <stdio.h>
#include <assert.h>

// Función para validar rangos
int validar_rango_entero(int valor, int min, int max) {
    if (valor >= min && valor <= max) {
        return 1;  // Válido
    }
    printf("Error: %d está fuera del rango [%d, %d]\n", valor, min, max);
    return 0;  // Inválido
}

int main() {
    printf("=== VALIDACIÓN DE TIPOS ===\n");
    
    // Validación con assert
    int edad = 25;
    assert(edad >= 0 && edad <= 150);  // El programa termina si falla
    
    // Validación con función personalizada
    int nota = 85;
    if (validar_rango_entero(nota, 0, 100)) {
        printf("Nota válida: %d\n", nota);
    }
    
    // Validación de overflow
    int a = 2000000000;
    int b = 2000000000;
    
    // Verificar antes de la operación
    if (a > INT_MAX - b) {
        printf("Advertencia: la suma %d + %d causará overflow\n", a, b);
    } else {
        int suma = a + b;
        printf("Suma: %d + %d = %d\n", a, b, suma);
    }
    
    return 0;
}
```

---

## 13. Resumen y Mejores Prácticas

### 13.1 Checklist para Variables y Tipos

**Al declarar variables:**
- [ ] ¿El nombre es descriptivo y sigue convenciones?
- [ ] ¿He elegido el tipo más apropiado para el rango de datos?
- [ ] ¿He inicializado la variable?
- [ ] ¿El ámbito de la variable es el correcto?

**Al usar constantes:**
- [ ] ¿He usado `const` o `#define` apropiadamente?
- [ ] ¿Los nombres de constantes están en MAYÚSCULAS?
- [ ] ¿He agrupado constantes relacionadas?

**Al hacer conversiones:**
- [ ] ¿Es necesaria la conversión?
- [ ] ¿He usado casting explícito cuando es necesario?
- [ ] ¿He considerado la pérdida de precisión o desbordamiento?

### 13.2 Tabla de Referencia Rápida

| Uso | Tipo Recomendado | Ejemplo |
|-----|------------------|---------|
| Edad, cantidades pequeñas | `unsigned char` | `unsigned char edad = 25;` |
| Contadores, índices | `int` | `int contador = 0;` |
| Dinero | `int` (centavos) | `int precio = 1999; // $19.99` |
| Cálculos científicos | `double` | `double resultado = 1.0/3.0;` |
| Caracteres individuales | `char` | `char grado = 'A';` |
| Valores verdadero/falso | `bool` | `bool es_valido = true;` |
| IDs, claves | `unsigned long` | `unsigned long id = 123456;` |

### 13.3 Errores Comunes a Evitar

```c
// ❌ No inicializar variables
int x;
printf("%d\n", x);  // Valor impredecible

// ❌ Usar float para dinero
float precio = 19.99f;  // Puede tener errores de precisión

// ❌ No considerar desbordamiento
int grande = INT_MAX;
grande = grande + 1;  // Desbordamiento

// ❌ Conversión sin cuidado
double d = 1234567890.123;
float f = (float