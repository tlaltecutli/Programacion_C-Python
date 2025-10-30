# Guía Completa de Recursividad en C

## Índice
1. [¿Qué es la Recursividad?](#qué-es-la-recursividad)
2. [Conceptos Fundamentales](#conceptos-fundamentales)
3. [Anatomía de una Función Recursiva](#anatomía-de-una-función-recursiva)
4. [Ejemplos Básicos](#ejemplos-básicos)
5. [Recursividad vs Iteración](#recursividad-vs-iteración)
6. [Tipos de Recursividad](#tipos-de-recursividad)
7. [Ejemplos Avanzados](#ejemplos-avanzados)
8. [Stack Overflow y Optimización](#stack-overflow-y-optimización)
9. [Ejercicios Prácticos](#ejercicios-prácticos)
10. [Consejos y Buenas Prácticas](#consejos-y-buenas-prácticas)

---

## ¿Qué es la Recursividad?

La **recursividad** es una técnica de programación donde una función se llama a sí misma para resolver un problema. Es especialmente útil para problemas que pueden dividirse en subproblemas más pequeños del mismo tipo.

### Analogía del Mundo Real
Imagina que estás buscando un libro en una biblioteca con muchos pisos:
- Si no lo encuentras en el piso actual, buscas en el siguiente piso
- Repites este proceso hasta encontrar el libro (caso base) o hasta que no haya más pisos

---

## Conceptos Fundamentales

### 1. Caso Base
El **caso base** es la condición que termina la recursión. Sin él, la función se ejecutaría infinitamente.

### 2. Caso Recursivo
El **caso recursivo** es donde la función se llama a sí misma con parámetros modificados, acercándose al caso base.

### 3. Stack de Llamadas
Cada llamada recursiva se almacena en la pila (stack) del sistema, consumiendo memoria.

---

## Anatomía de una Función Recursiva

```c
tipo_retorno funcion_recursiva(parametros) {
    // Caso base - condición de parada
    if (condicion_de_parada) {
        return valor_base;
    }
    
    // Caso recursivo - llamada a sí misma
    return operacion(funcion_recursiva(parametros_modificados));
}
```

---

## Ejemplos Básicos

### 1. Factorial
El factorial de n (n!) es el producto de todos los números enteros positivos menores o iguales a n.

```c
#include <stdio.h>

long long factorial(int n) {
    // Caso base
    if (n <= 1) {
        return 1;
    }
    
    // Caso recursivo
    return n * factorial(n - 1);
}

int main() {
    int numero = 5;
    printf("Factorial de %d = %lld\n", numero, factorial(numero));
    return 0;
}
```

**Traza de ejecución para factorial(5):**
```
factorial(5) = 5 * factorial(4)
factorial(4) = 4 * factorial(3)
factorial(3) = 3 * factorial(2)
factorial(2) = 2 * factorial(1)
factorial(1) = 1 (caso base)

Resultado: 5 * 4 * 3 * 2 * 1 = 120
```

### 2. Secuencia de Fibonacci
Cada número es la suma de los dos anteriores: 0, 1, 1, 2, 3, 5, 8, 13...

```c
#include <stdio.h>

int fibonacci(int n) {
    // Casos base
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    
    // Caso recursivo
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 10;
    printf("Los primeros %d números de Fibonacci:\n", n);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    
    return 0;
}
```

### 3. Suma de Dígitos
Suma todos los dígitos de un número entero.

```c
#include <stdio.h>

int suma_digitos(int n) {
    // Caso base
    if (n < 10) {
        return n;
    }
    
    // Caso recursivo
    return (n % 10) + suma_digitos(n / 10);
}

int main() {
    int numero = 1234;
    printf("Suma de dígitos de %d = %d\n", numero, suma_digitos(numero));
    return 0;
}
```

---

## Recursividad vs Iteración

### Comparación Factorial

**Versión Recursiva:**
```c
long long factorial_recursivo(int n) {
    if (n <= 1) return 1;
    return n * factorial_recursivo(n - 1);
}
```

**Versión Iterativa:**
```c
long long factorial_iterativo(int n) {
    long long resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}
```

### Ventajas y Desventajas

| Aspecto | Recursividad | Iteración |
|---------|-------------|-----------|
| **Legibilidad** | ✅ Más clara para problemas naturalmente recursivos | ❌ Puede ser más compleja |
| **Memoria** | ❌ Usa más memoria (stack) | ✅ Usa menos memoria |
| **Velocidad** | ❌ Generalmente más lenta | ✅ Más rápida |
| **Complejidad** | ✅ Menos líneas de código | ❌ Más líneas de código |

---

## Tipos de Recursividad

### 1. Recursividad Simple (Linear)
La función se llama a sí misma una sola vez.

```c
int potencia(int base, int exponente) {
    if (exponente == 0) {
        return 1;
    }
    return base * potencia(base, exponente - 1);
}
```

### 2. Recursividad Múltiple
La función se llama a sí misma más de una vez.

```c
// Fibonacci es un ejemplo de recursividad múltiple
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);  // Dos llamadas recursivas
}
```

### 3. Recursividad Mutua (Indirecta)
Dos o más funciones se llaman entre sí.

```c
int es_par(int n);
int es_impar(int n);

int es_par(int n) {
    if (n == 0) return 1;
    return es_impar(n - 1);
}

int es_impar(int n) {
    if (n == 0) return 0;
    return es_par(n - 1);
}
```

### 4. Recursividad de Cola (Tail Recursion)
La llamada recursiva es la última operación de la función.

```c
int factorial_cola(int n, int acumulador) {
    if (n <= 1) {
        return acumulador;
    }
    return factorial_cola(n - 1, n * acumulador);
}

// Función wrapper
int factorial_optimizado(int n) {
    return factorial_cola(n, 1);
}
```

---

## Ejemplos Avanzados

### 1. Torre de Hanoi
Problema clásico de recursividad: mover n discos de una torre a otra usando una torre auxiliar.

```c
#include <stdio.h>

void hanoi(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mover disco 1 de %c a %c\n", origen, destino);
        return;
    }
    
    // Mover n-1 discos de origen a auxiliar
    hanoi(n-1, origen, auxiliar, destino);
    
    // Mover el disco más grande de origen a destino
    printf("Mover disco %d de %c a %c\n", n, origen, destino);
    
    // Mover n-1 discos de auxiliar a destino
    hanoi(n-1, auxiliar, destino, origen);
}

int main() {
    int discos = 3;
    printf("Solución Torre de Hanoi para %d discos:\n", discos);
    hanoi(discos, 'A', 'C', 'B');
    return 0;
}
```

### 2. Búsqueda Binaria Recursiva
Busca un elemento en un arreglo ordenado dividiéndolo por la mitad.

```c
#include <stdio.h>

int busqueda_binaria(int arr[], int inicio, int fin, int objetivo) {
    // Caso base: elemento no encontrado
    if (inicio > fin) {
        return -1;
    }
    
    int medio = inicio + (fin - inicio) / 2;
    
    // Caso base: elemento encontrado
    if (arr[medio] == objetivo) {
        return medio;
    }
    
    // Buscar en la mitad izquierda
    if (objetivo < arr[medio]) {
        return busqueda_binaria(arr, inicio, medio - 1, objetivo);
    }
    
    // Buscar en la mitad derecha
    return busqueda_binaria(arr, medio + 1, fin, objetivo);
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int n = sizeof(arr) / sizeof(arr[0]);
    int objetivo = 23;
    
    int resultado = busqueda_binaria(arr, 0, n-1, objetivo);
    
    if (resultado != -1) {
        printf("Elemento %d encontrado en la posición %d\n", objetivo, resultado);
    } else {
        printf("Elemento %d no encontrado\n", objetivo);
    }
    
    return 0;
}
```

### 3. Quicksort Recursivo
Algoritmo de ordenamiento que usa el paradigma "divide y vencerás".

```c
#include <stdio.h>

void intercambiar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int arr[], int bajo, int alto) {
    int pivote = arr[alto];
    int i = (bajo - 1);
    
    for (int j = bajo; j <= alto - 1; j++) {
        if (arr[j] < pivote) {
            i++;
            intercambiar(&arr[i], &arr[j]);
        }
    }
    intercambiar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quicksort(int arr[], int bajo, int alto) {
    if (bajo < alto) {
        int pi = particionar(arr, bajo, alto);
        
        // Ordenar elementos antes y después de la partición
        quicksort(arr, bajo, pi - 1);
        quicksort(arr, pi + 1, alto);
    }
}

void imprimir_arreglo(int arr[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Arreglo original: ");
    imprimir_arreglo(arr, n);
    
    quicksort(arr, 0, n-1);
    
    printf("Arreglo ordenado: ");
    imprimir_arreglo(arr, n);
    
    return 0;
}
```

---

## Stack Overflow y Optimización

### Problema de Stack Overflow
Cuando hay demasiadas llamadas recursivas, se puede agotar el stack:

```c
// PELIGRO: Puede causar stack overflow para n grandes
int fibonacci_ineficiente(int n) {
    if (n <= 1) return n;
    return fibonacci_ineficiente(n-1) + fibonacci_ineficiente(n-2);
}
```

### Fibonacci Optimizado con Memoización
```c
#include <stdio.h>
#include <string.h>

#define MAX_N 1000

int memo[MAX_N];
int inicializado = 0;

void inicializar_memo() {
    if (!inicializado) {
        memset(memo, -1, sizeof(memo));
        inicializado = 1;
    }
}

int fibonacci_memo(int n) {
    inicializar_memo();
    
    if (n <= 1) {
        return n;
    }
    
    if (memo[n] != -1) {
        return memo[n];
    }
    
    memo[n] = fibonacci_memo(n-1) + fibonacci_memo(n-2);
    return memo[n];
}

int main() {
    int n = 40;
    printf("Fibonacci(%d) = %d\n", n, fibonacci_memo(n));
    return 0;
}
```

---

## Ejercicios Prácticos

### Ejercicio 1: Inversión de un Número
```c
#include <stdio.h>

int invertir_numero(int n) {
    // Caso base
    if (n < 10) {
        return n;
    }
    
    // Calcular la potencia de 10 necesaria
    int temp = n;
    int digitos = 0;
    while (temp > 0) {
        digitos++;
        temp /= 10;
    }
    
    // Caso recursivo
    int ultimo_digito = n % 10;
    int potencia = 1;
    for (int i = 1; i < digitos; i++) {
        potencia *= 10;
    }
    
    return ultimo_digito * potencia + invertir_numero(n / 10);
}

int main() {
    int numero = 12345;
    printf("Número original: %d\n", numero);
    printf("Número invertido: %d\n", invertir_numero(numero));
    return 0;
}
```

### Ejercicio 2: Máximo Común Divisor (Algoritmo de Euclides)
```c
#include <stdio.h>

int mcd(int a, int b) {
    // Caso base
    if (b == 0) {
        return a;
    }
    
    // Caso recursivo
    return mcd(b, a % b);
}

int main() {
    int a = 48, b = 18;
    printf("MCD(%d, %d) = %d\n", a, b, mcd(a, b));
    return 0;
}
```

### Ejercicio 3: Verificar si una Cadena es Palíndromo
```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int es_palindromo(char str[], int inicio, int fin) {
    // Caso base: se han comparado todos los caracteres
    if (inicio >= fin) {
        return 1;
    }
    
    // Ignorar espacios y convertir a minúsculas
    if (!isalnum(str[inicio])) {
        return es_palindromo(str, inicio + 1, fin);
    }
    if (!isalnum(str[fin])) {
        return es_palindromo(str, inicio, fin - 1);
    }
    
    // Comparar caracteres
    if (tolower(str[inicio]) != tolower(str[fin])) {
        return 0;
    }
    
    // Caso recursivo
    return es_palindromo(str, inicio + 1, fin - 1);
}

int main() {
    char str[] = "A man a plan a canal Panama";
    int len = strlen(str);
    
    if (es_palindromo(str, 0, len - 1)) {
        printf("'%s' es un palíndromo\n", str);
    } else {
        printf("'%s' no es un palíndromo\n", str);
    }
    
    return 0;
}
```

---

## Consejos y Buenas Prácticas

### 1. Siempre Define un Caso Base Claro
```c
// ✅ Correcto
int potencia(int base, int exp) {
    if (exp == 0) return 1;  // Caso base claro
    return base * potencia(base, exp - 1);
}

// ❌ Incorrecto - sin caso base
int potencia_mal(int base, int exp) {
    return base * potencia_mal(base, exp - 1);  // Stack overflow
}
```

### 2. Asegúrate de que los Parámetros se Acerquen al Caso Base
```c
// ✅ Correcto - n disminuye hacia el caso base
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// ❌ Incorrecto - n nunca cambia
int factorial_mal(int n) {
    if (n <= 1) return 1;
    return n * factorial_mal(n);  // Recursión infinita
}
```

### 3. Considera la Complejidad
- **Fibonacci recursivo**: O(2^n) - muy ineficiente
- **Fibonacci iterativo**: O(n) - mucho mejor
- **Fibonacci con memoización**: O(n) - eficiente y legible

### 4. Usa Recursividad Cuando Sea Natural
La recursividad es ideal para:
- Estructuras de datos recursivas (árboles, listas enlazadas)
- Algoritmos divide y vencerás (quicksort, mergesort)
- Problemas matemáticos (factorial, fibonacci, combinatoria)
- Backtracking (laberintos, n-reinas)

### 5. Ten Cuidado con el Stack Overflow
```c
// Para entradas grandes, considera límites
int fibonacci_seguro(int n) {
    if (n > 40) {
        printf("Error: n demasiado grande para fibonacci recursivo\n");
        return -1;
    }
    
    if (n <= 1) return n;
    return fibonacci_seguro(n-1) + fibonacci_seguro(n-2);
}
```

---

## Resumen

La recursividad es una herramienta poderosa en C que permite:
- Resolver problemas complejos de manera elegante
- Escribir código más limpio y comprensible
- Implementar algoritmos divide y vencerás eficientemente

**Recuerda:**
1. Siempre define un caso base
2. Asegúrate de que la recursión progrese hacia el caso base
3. Considera el costo en memoria y tiempo
4. Usa recursividad cuando sea la solución más natural al problema

¡Practica con los ejemplos y ejercicios para dominar esta técnica fundamental de programación!

---

## Referencias y Recursos Adicionales

- **Complejidad Algorítmica**: Aprende sobre Big O notation
- **Estructuras de Datos**: Árboles y grafos usan mucha recursividad
- **Algoritmos Avanzados**: Backtracking, programación dinámica
- **Optimización**: Memoización y recursividad de cola