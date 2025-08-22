# Operaciones Básicas en Programación C

## Introducción

Las operaciones básicas en C son los elementos fundamentales que permiten manipular datos y realizar cálculos. Estas operaciones incluyen operadores aritméticos, de comparación, lógicos y de asignación, así como el manejo básico de entrada y salida de datos.

## 1. Operadores Aritméticos

Los operadores aritméticos permiten realizar cálculos matemáticos básicos:

### Operadores Principales

| Operador | Descripción | Ejemplo | Resultado |
|----------|-------------|---------|-----------|
| `+` | Suma | `5 + 3` | `8` |
| `-` | Resta | `10 - 4` | `6` |
| `*` | Multiplicación | `7 * 2` | `14` |
| `/` | División | `15 / 3` | `5` |
| `%` | Módulo (resto) | `17 % 5` | `2` |

### Ejemplos Prácticos

```c
#include <stdio.h>

int main() {
    int a = 10, b = 3;
    
    printf("Suma: %d + %d = %d\n", a, b, a + b);
    printf("Resta: %d - %d = %d\n", a, b, a - b);
    printf("Multiplicación: %d * %d = %d\n", a, b, a * b);
    printf("División: %d / %d = %d\n", a, b, a / b);
    printf("Módulo: %d %% %d = %d\n", a, b, a % b);
    
    return 0;
}
```

**Nota Importante:** La división entre enteros en C produce un resultado entero (se trunca la parte decimal).

## 2. Operadores de Asignación

### Asignación Simple
- `=` : Asigna un valor a una variable

```c
int x = 5;  // Asigna el valor 5 a x
```

### Operadores de Asignación Compuesta

| Operador | Equivalente | Descripción |
|----------|-------------|-------------|
| `+=` | `x = x + y` | Suma y asigna |
| `-=` | `x = x - y` | Resta y asigna |
| `*=` | `x = x * y` | Multiplica y asigna |
| `/=` | `x = x / y` | Divide y asigna |
| `%=` | `x = x % y` | Módulo y asigna |

```c
int num = 10;
num += 5;  // num ahora vale 15
num -= 3;  // num ahora vale 12
num *= 2;  // num ahora vale 24
```

## 3. Operadores de Incremento y Decremento

### Pre-incremento y Post-incremento
- `++variable` : Pre-incremento (incrementa primero, luego usa el valor)
- `variable++` : Post-incremento (usa el valor, luego incrementa)
- `--variable` : Pre-decremento
- `variable--` : Post-decremento

```c
int a = 5, b = 5;

printf("Pre-incremento: %d\n", ++a);  // Imprime 6
printf("Post-incremento: %d\n", b++); // Imprime 5
printf("Valor de b después: %d\n", b); // Imprime 6
```

## 4. Operadores de Comparación

Estos operadores devuelven 1 (verdadero) o 0 (falso):

| Operador | Descripción | Ejemplo |
|----------|-------------|---------|
| `==` | Igual a | `a == b` |
| `!=` | Diferente de | `a != b` |
| `<` | Menor que | `a < b` |
| `<=` | Menor o igual que | `a <= b` |
| `>` | Mayor que | `a > b` |
| `>=` | Mayor o igual que | `a >= b` |

```c
int x = 5, y = 10;

if (x < y) {
    printf("x es menor que y\n");
}

if (x != y) {
    printf("x es diferente de y\n");
}
```

## 5. Operadores Lógicos

| Operador | Descripción | Ejemplo |
|----------|-------------|---------|
| `&&` | AND lógico | `(a > 0) && (b > 0)` |
| `\|\|` | OR lógico | `(a == 0) \|\| (b == 0)` |
| `!` | NOT lógico | `!(a > b)` |

```c
int edad = 20;
int licencia = 1; // 1 = tiene licencia, 0 = no tiene

if (edad >= 18 && licencia) {
    printf("Puede conducir\n");
}

if (edad < 18 || !licencia) {
    printf("No puede conducir\n");
}
```

## 6. Precedencia de Operadores

La precedencia determina el orden de evaluación:

1. `()` - Paréntesis
2. `!`, `++`, `--` - Operadores unarios
3. `*`, `/`, `%` - Multiplicación, división, módulo
4. `+`, `-` - Suma, resta
5. `<`, `<=`, `>`, `>=` - Comparación
6. `==`, `!=` - Igualdad
7. `&&` - AND lógico
8. `||` - OR lógico
9. `=`, `+=`, `-=`, etc. - Asignación

```c
int resultado = 2 + 3 * 4;  // = 14, no 20
int resultado2 = (2 + 3) * 4;  // = 20
```

## 7. Entrada y Salida Básica

### Función printf()
Muestra datos en pantalla con formato:

```c
int edad = 25;
float altura = 1.75;
char inicial = 'J';

printf("Edad: %d años\n", edad);
printf("Altura: %.2f metros\n", altura);
printf("Inicial: %c\n", inicial);
```

### Especificadores de formato comunes:
- `%d` : Enteros
- `%f` : Números flotantes
- `%c` : Caracteres
- `%s` : Cadenas de texto

### Función scanf()
Lee datos del usuario:

```c
int numero;
float decimal;

printf("Ingrese un número entero: ");
scanf("%d", &numero);

printf("Ingrese un número decimal: ");
scanf("%f", &decimal);

printf("Números ingresados: %d y %.2f\n", numero, decimal);
```

## 8. Conversión de Tipos (Casting)

### Conversión Implícita
C convierte automáticamente tipos compatibles:

```c
int entero = 5;
float flotante = entero;  // Conversión implícita de int a float
```

### Conversión Explícita (Cast)
Forzar la conversión de tipos:

```c
float a = 7.8;
int b = (int)a;  // b = 7, se trunca la parte decimal

int x = 7, y = 2;
float resultado = (float)x / y;  // resultado = 3.5
```

## 9. Ejemplo Integrador: Calculadora Básica

```c
#include <stdio.h>

int main() {
    float num1, num2, resultado;
    char operador;
    
    printf("=== CALCULADORA BÁSICA ===\n");
    printf("Ingrese el primer número: ");
    scanf("%f", &num1);
    
    printf("Ingrese el operador (+, -, *, /): ");
    scanf(" %c", &operador);
    
    printf("Ingrese el segundo número: ");
    scanf("%f", &num2);
    
    switch(operador) {
        case '+':
            resultado = num1 + num2;
            printf("%.2f + %.2f = %.2f\n", num1, num2, resultado);
            break;
        case '-':
            resultado = num1 - num2;
            printf("%.2f - %.2f = %.2f\n", num1, num2, resultado);
            break;
        case '*':
            resultado = num1 * num2;
            printf("%.2f * %.2f = %.2f\n", num1, num2, resultado);
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
                printf("%.2f / %.2f = %.2f\n", num1, num2, resultado);
            } else {
                printf("Error: División por cero\n");
            }
            break;
        default:
            printf("Operador no válido\n");
    }
    
    return 0;
}
```

## 10. Ejercicios Prácticos

### Ejercicio 1: Área y Perímetro
Escriba un programa que calcule el área y perímetro de un rectángulo.

### Ejercicio 2: Intercambio de Variables
Intercambie los valores de dos variables sin usar una tercera variable.

### Ejercicio 3: Promedio de Calificaciones
Calcule el promedio de tres calificaciones e indique si el estudiante aprobó (promedio >= 70).

### Ejercicio 4: Conversión de Temperatura
Convierta temperaturas de Celsius a Fahrenheit y viceversa.

## Consejos Importantes

1. **Inicializa siempre tus variables** antes de usarlas
2. **Usa paréntesis** para aclarar precedencia cuando sea necesario
3. **Cuidado con la división entera**: `5/2` en enteros es `2`, no `2.5`
4. **El operador módulo `%`** solo funciona con enteros
5. **Usa nombres descriptivos** para tus variables
6. **Comenta tu código** para explicar operaciones complejas

## Conclusión

Las operaciones básicas son la base de toda programación en C. Dominar estos conceptos es esencial para construir programas más complejos. Practica regularmente con diferentes combinaciones de operadores y tipos de datos para fortalecer tu comprensión.

---

*Documento creado para el curso de Programación en C - Operaciones Básicas*