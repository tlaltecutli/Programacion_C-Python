# Operaciones Básicas y Tipos de Datos en C

## Introducción

El lenguaje C es un lenguaje de programación de nivel medio que requiere una declaración explícita de tipos de datos. Comprender los tipos de datos y las operaciones básicas es fundamental para escribir programas eficientes y correctos en C.

## Tipos de Datos Básicos

### 1. Tipos Enteros

#### char
- **Tamaño**: 1 byte (8 bits)
- **Rango**: -128 a 127 (signed) o 0 a 255 (unsigned)
- **Uso**: Almacenar caracteres o números pequeños

```c
char letra = 'A';
char numero = 65;  // Equivale a 'A' en ASCII
```

#### int
- **Tamaño**: Típicamente 4 bytes (32 bits)
- **Rango**: -2,147,483,648 a 2,147,483,647
- **Uso**: Números enteros de propósito general

```c
int edad = 25;
int temperatura = -10;
```

#### short
- **Tamaño**: 2 bytes (16 bits)
- **Rango**: -32,768 a 32,767
- **Uso**: Enteros pequeños para ahorrar memoria

```c
short año = 2024;
```

#### long
- **Tamaño**: Al menos 4 bytes (puede ser 8 bytes)
- **Rango**: Depende del sistema
- **Uso**: Números enteros grandes

```c
long poblacion = 1000000000L;
```

#### long long
- **Tamaño**: 8 bytes (64 bits)
- **Rango**: -9,223,372,036,854,775,808 a 9,223,372,036,854,775,807
- **Uso**: Números enteros muy grandes

```c
long long distancia_estrella = 9460730472580800LL;
```

### 2. Tipos de Punto Flotante

#### float
- **Tamaño**: 4 bytes
- **Precisión**: ~6-7 dígitos decimales
- **Rango**: ±3.4E±38

```c
float precio = 19.99f;
float pi = 3.14159f;
```

#### double
- **Tamaño**: 8 bytes
- **Precisión**: ~15-16 dígitos decimales
- **Rango**: ±1.7E±308

```c
double precision_alta = 3.141592653589793;
double resultado = 123.456789012345;
```

#### long double
- **Tamaño**: Típicamente 10, 12 o 16 bytes
- **Precisión**: Mayor que double
- **Uso**: Cálculos que requieren máxima precisión

```c
long double pi_extendido = 3.141592653589793238L;
```

### 3. Modificadores de Tipo

#### signed y unsigned
```c
unsigned int positivo = 4294967295U;  // Solo valores positivos
signed int con_signo = -2000000000;   // Valores positivos y negativos
```

#### Combinaciones comunes
```c
unsigned char byte = 255;
unsigned short puerto = 8080;
unsigned long id = 123456789UL;
```

## Operadores Básicos

### 1. Operadores Aritméticos

| Operador | Descripción | Ejemplo |
|----------|-------------|---------|
| `+` | Suma | `a + b` |
| `-` | Resta | `a - b` |
| `*` | Multiplicación | `a * b` |
| `/` | División | `a / b` |
| `%` | Módulo (resto) | `a % b` |

```c
int a = 10, b = 3;
int suma = a + b;        // 13
int resta = a - b;       // 7
int multiplicacion = a * b; // 30
int division = a / b;    // 3 (división entera)
int modulo = a % b;      // 1
```

### 2. Operadores de Asignación

| Operador | Descripción | Equivalente |
|----------|-------------|-------------|
| `=` | Asignación simple | `a = b` |
| `+=` | Suma y asigna | `a = a + b` |
| `-=` | Resta y asigna | `a = a - b` |
| `*=` | Multiplica y asigna | `a = a * b` |
| `/=` | Divide y asigna | `a = a / b` |
| `%=` | Módulo y asigna | `a = a % b` |

```c
int x = 10;
x += 5;  // x = 15
x -= 3;  // x = 12
x *= 2;  // x = 24
x /= 4;  // x = 6
x %= 4;  // x = 2
```

### 3. Operadores de Incremento y Decremento

```c
int i = 5;
int pre_incremento = ++i;   // i = 6, pre_incremento = 6
int post_incremento = i++;  // i = 7, post_incremento = 6

int j = 8;
int pre_decremento = --j;   // j = 7, pre_decremento = 7
int post_decremento = j--;  // j = 6, post_decremento = 7
```

### 4. Operadores Relacionales

| Operador | Descripción | Ejemplo |
|----------|-------------|---------|
| `==` | Igual a | `a == b` |
| `!=` | Diferente de | `a != b` |
| `<` | Menor que | `a < b` |
| `>` | Mayor que | `a > b` |
| `<=` | Menor o igual | `a <= b` |
| `>=` | Mayor o igual | `a >= b` |

```c
int a = 5, b = 10;
int igual = (a == b);      // 0 (falso)
int diferente = (a != b);  // 1 (verdadero)
int menor = (a < b);       // 1 (verdadero)
int mayor = (a > b);       // 0 (falso)
```

### 5. Operadores Lógicos

| Operador | Descripción | Ejemplo |
|----------|-------------|---------|
| `&&` | AND lógico | `a && b` |
| `\|\|` | OR lógico | `a \|\| b` |
| `!` | NOT lógico | `!a` |

```c
int verdadero = 1, falso = 0;
int and_logico = verdadero && falso;  // 0
int or_logico = verdadero || falso;   // 1
int not_logico = !verdadero;          // 0
```

## Conversiones de Tipo

### 1. Conversión Implícita (Automática)

```c
int entero = 10;
float flotante = entero;  // 10.0 (int a float)

char caracter = 'A';
int ascii = caracter;     // 65 (char a int)
```

### 2. Conversión Explícita (Casting)

```c
float pi = 3.14159;
int entero = (int)pi;     // 3 (trunca la parte decimal)

int a = 7, b = 3;
float division = (float)a / b;  // 2.333333 (no 2)
```

## Constantes

### 1. Definición con #define

```c
#define PI 3.14159
#define MAX_ESTUDIANTES 100
#define MENSAJE "Hola Mundo"
```

### 2. Variables const

```c
const int MAX_INTENTOS = 3;
const float GRAVEDAD = 9.81f;
const char NUEVA_LINEA = '\n';
```

## Ejemplos Prácticos

### Programa 1: Calculadora Básica

```c
#include <stdio.h>

int main() {
    float num1, num2;
    char operador;
    float resultado;
    
    printf("Ingrese dos números: ");
    scanf("%f %f", &num1, &num2);
    
    printf("Ingrese operador (+, -, *, /): ");
    scanf(" %c", &operador);
    
    switch(operador) {
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            if(num2 != 0) {
                resultado = num1 / num2;
            } else {
                printf("Error: División por cero\n");
                return 1;
            }
            break;
        default:
            printf("Operador inválido\n");
            return 1;
    }
    
    printf("%.2f %c %.2f = %.2f\n", num1, operador, num2, resultado);
    return 0;
}
```

### Programa 2: Conversión de Tipos

```c
#include <stdio.h>

int main() {
    // Demostración de conversiones
    int entero = 10;
    float flotante = 3.7f;
    char caracter = 'B';
    
    printf("Valores originales:\n");
    printf("Entero: %d\n", entero);
    printf("Flotante: %.2f\n", flotante);
    printf("Caracter: %c (ASCII: %d)\n", caracter, caracter);
    
    printf("\nConversiones:\n");
    printf("Entero a float: %.2f\n", (float)entero);
    printf("Float a int: %d\n", (int)flotante);
    printf("Char a int: %d\n", (int)caracter);
    
    // División entera vs división con decimales
    int a = 7, b = 3;
    printf("\nDivisión:\n");
    printf("División entera: %d / %d = %d\n", a, b, a/b);
    printf("División decimal: %d / %d = %.2f\n", a, b, (float)a/b);
    
    return 0;
}
```

## Buenas Prácticas

1. **Elección del tipo apropiado**: Usa el tipo de dato más pequeño que pueda contener tus valores para optimizar memoria.

2. **Inicialización**: Siempre inicializa las variables antes de usarlas.
   ```c
   int contador = 0;  // Buena práctica
   ```

3. **Constantes**: Usa constantes para valores que no cambiarán.
   ```c
   const float PI = 3.14159f;
   ```

4. **Precisión en flotantes**: Ten cuidado con la comparación de números flotantes.
   ```c
   // Evita esto:
   if(flotante == 3.14) { ... }
   
   // Mejor:
   if(fabs(flotante - 3.14) < 0.001) { ... }
   ```

5. **Overflow**: Ten cuidado con el desbordamiento de enteros.
   ```c
   unsigned char valor = 255;
   valor++;  // Resulta en 0 (overflow)
   ```

## Ejercicios Sugeridos

1. **Básico**: Crear un programa que calcule el área y perímetro de un rectángulo usando variables float.

2. **Intermedio**: Implementar un conversor de unidades (metros a pies, Celsius a Fahrenheit, etc.).

3. **Avanzado**: Crear un programa que determine el rango y precisión de los diferentes tipos de datos en tu sistema.

## Conclusión

Los tipos de datos y operaciones básicas son la base fundamental de la programación en C. Un buen entendimiento de estos conceptos te permitirá escribir código más eficiente y evitar errores comunes. Recuerda siempre considerar el rango y precisión de los tipos de datos que elijas para tus variables.