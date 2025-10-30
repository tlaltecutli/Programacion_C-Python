# Guía Completa de Funciones en C

## Índice
1. [Introducción a las Funciones](#introducción-a-las-funciones)
2. [Sintaxis y Declaración](#sintaxis-y-declaración)
3. [Tipos de Funciones](#tipos-de-funciones)
4. [Parámetros y Argumentos](#parámetros-y-argumentos)
5. [Ámbito de Variables](#ámbito-de-variables)
6. [Recursividad](#recursividad)
7. [Punteros a Funciones](#punteros-a-funciones)
8. [Funciones de la Biblioteca Estándar](#funciones-de-la-biblioteca-estándar)
9. [Buenas Prácticas](#buenas-prácticas)
10. [Ejemplos Avanzados](#ejemplos-avanzados)

---

## 1. Introducción a las Funciones

Las funciones en C son bloques de código que realizan una tarea específica. Son fundamentales para la programación modular, permitiendo reutilizar código, mejorar la legibilidad y facilitar el mantenimiento.

### Ventajas de usar funciones:
- **Modularidad**: Dividir el código en partes manejables
- **Reutilización**: Usar el mismo código múltiples veces
- **Legibilidad**: Código más fácil de entender
- **Mantenimiento**: Cambios en un solo lugar
- **Debugging**: Aislar problemas más fácilmente

---

## 2. Sintaxis y Declaración

### Estructura básica de una función:

```c
tipo_retorno nombre_funcion(lista_parametros) {
    // Cuerpo de la función
    // Declaraciones locales
    // Instrucciones
    return valor; // (opcional)
}
```

### Ejemplo básico:

```c
#include <stdio.h>

// Declaración de función (prototipo)
int sumar(int a, int b);

int main() {
    int resultado = sumar(5, 3);
    printf("La suma es: %d\n", resultado);
    return 0;
}

// Definición de función
int sumar(int a, int b) {
    return a + b;
}
```

### Prototipos de funciones:
Los prototipos permiten declarar funciones antes de definirlas, útil cuando las funciones se definen después de `main()` o en otros archivos.

```c
// Prototipo completo
int multiplicar(int x, int y);

// Prototipo sin nombres de parámetros (válido pero menos claro)
int multiplicar(int, int);
```

---

## 3. Tipos de Funciones

### 3.1 Funciones que retornan valores

```c
// Función que retorna entero
int calcular_cuadrado(int n) {
    return n * n;
}

// Función que retorna float
float calcular_area_circulo(float radio) {
    const float PI = 3.14159;
    return PI * radio * radio;
}

// Función que retorna char
char obtener_calificacion(int puntos) {
    if (puntos >= 90) return 'A';
    else if (puntos >= 80) return 'B';
    else if (puntos >= 70) return 'C';
    else return 'F';
}
```

### 3.2 Funciones void (sin retorno)

```c
// Función que no retorna valor
void imprimir_mensaje(char mensaje[]) {
    printf("Mensaje: %s\n", mensaje);
}

// Función void con múltiples parámetros
void mostrar_datos_persona(char nombre[], int edad, float altura) {
    printf("Nombre: %s\n", nombre);
    printf("Edad: %d años\n", edad);
    printf("Altura: %.2f metros\n", altura);
}
```

### 3.3 Función main()

```c
// Forma estándar de main
int main() {
    // código
    return 0; // indica ejecución exitosa
}

// main con argumentos de línea de comandos
int main(int argc, char *argv[]) {
    printf("Número de argumentos: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("Argumento %d: %s\n", i, argv[i]);
    }
    return 0;
}
```

---

## 4. Parámetros y Argumentos

### 4.1 Paso por valor

En C, los parámetros se pasan por valor por defecto, creando una copia del valor original.

```c
void incrementar_copia(int x) {
    x = x + 1; // Solo modifica la copia local
    printf("Dentro de función: %d\n", x);
}

int main() {
    int numero = 5;
    incrementar_copia(numero);
    printf("Fuera de función: %d\n", numero); // numero sigue siendo 5
    return 0;
}
```

**Parámetros**: Son las variables declaradas en la definición de una función. Actúan como "placeholders" o marcadores de posición que especifican qué tipo de datos espera recibir la función.

**Argumentos**: Son los valores reales que se pasan a la función cuando se llama. Son los datos concretos que se envían para que la función los procese.

```c
// PARÁMETROS: a, b, c (variables en la definición)
int sumar(int a, int b, int c) {
    return a + b + c;
}

int main() {
    int x = 5, y = 10, z = 15;
    
    // ARGUMENTOS: x, y, z (valores reales que se pasan)
    int resultado = sumar(x, y, z);
    
    // También pueden ser valores literales como argumentos
    int resultado2 = sumar(3, 7, 12);  // 3, 7, 12 son argumentos
    
    return 0;
}
```



### 4.2 Paso por referencia (usando punteros)

```c
void incrementar_referencia(int *x) {
    *x = *x + 1; // Modifica el valor original
    printf("Dentro de función: %d\n", *x);
}

int main() {
    int numero = 5;
    incrementar_referencia(&numero);
    printf("Fuera de función: %d\n", numero); // numero ahora es 6
    return 0;
}
```

### 4.3 Arrays como parámetros

```c
// Los arrays siempre se pasan por referencia
void modificar_array(int arr[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        arr[i] = arr[i] * 2;
    }
}

// Sintaxis alternativa
void imprimir_array(int *arr, int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int numeros[] = {1, 2, 3, 4, 5};
    int tamaño = sizeof(numeros) / sizeof(numeros[0]);
    
    printf("Array original: ");
    imprimir_array(numeros, tamaño);
    
    modificar_array(numeros, tamaño);
    printf("Array modificado: ");
    imprimir_array(numeros, tamaño);
    
    return 0;
}
```

### 4.4 Strings como parámetros

```c
#include <string.h>

// String como parámetro (solo lectura)
int contar_caracteres(char str[]) {
    return strlen(str);
}

// Modificar string
void convertir_a_mayusculas(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

int main() {
    char mensaje[] = "hola mundo";
    printf("Caracteres: %d\n", contar_caracteres(mensaje));
    
    convertir_a_mayusculas(mensaje);
    printf("En mayúsculas: %s\n", mensaje);
    
    return 0;
}
```

---

## 5. Ámbito de Variables

### 5.1 Variables locales

```c
void funcion_ejemplo() {
    int local = 10; // Variable local
    printf("Variable local: %d\n", local);
} // 'local' se destruye aquí
```

### 5.2 Variables globales

```c
#include <stdio.h>

int global = 100; // Variable global

void mostrar_global() {
    printf("Variable global: %d\n", global);
}

void modificar_global() {
    global = 200;
}

int main() {
    mostrar_global(); // 100
    modificar_global();
    mostrar_global(); // 200
    return 0;
}
```

### 5.3 Variables estáticas

```c
void contador() {
    static int cuenta = 0; // Se inicializa solo una vez
    cuenta++;
    printf("Llamada número: %d\n", cuenta);
}

int main() {
    contador(); // Llamada número: 1
    contador(); // Llamada número: 2
    contador(); // Llamada número: 3
    return 0;
}
```

---

## 6. Recursividad

### 6.1 Conceptos básicos

La recursividad ocurre cuando una función se llama a sí misma. Toda función recursiva necesita:
- **Caso base**: Condición que detiene la recursión
- **Caso recursivo**: La función se llama a sí misma con parámetros modificados

### 6.2 Ejemplo: Factorial

```c
// Factorial recursivo
int factorial_recursivo(int n) {
    // Caso base
    if (n <= 1) {
        return 1;
    }
    // Caso recursivo
    return n * factorial_recursivo(n - 1);
}

// Factorial iterativo (para comparación)
int factorial_iterativo(int n) {
    int resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}
```

### 6.3 Ejemplo: Secuencia de Fibonacci

```c
// Fibonacci recursivo (ineficiente)
int fibonacci_recursivo(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
}

// Fibonacci iterativo (más eficiente)
int fibonacci_iterativo(int n) {
    if (n <= 1) return n;
    
    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}
```

### 6.4 Ejemplo: Torre de Hanoi

```c
void hanoi(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mover disco 1 de %c a %c\n", origen, destino);
        return;
    }
    
    hanoi(n - 1, origen, auxiliar, destino);
    printf("Mover disco %d de %c a %c\n", n, origen, destino);
    hanoi(n - 1, auxiliar, destino, origen);
}
```

---

## 7. Punteros a Funciones

### 7.1 Declaración y uso básico

```c
#include <stdio.h>

// Funciones de ejemplo
int sumar(int a, int b) { return a + b; }
int restar(int a, int b) { return a - b; }
int multiplicar(int a, int b) { return a * b; }

int main() {
    // Declarar puntero a función
    int (*operacion)(int, int);
    
    // Asignar función al puntero
    operacion = sumar;
    printf("Suma: %d\n", operacion(5, 3));
    
    operacion = restar;
    printf("Resta: %d\n", operacion(5, 3));
    
    operacion = multiplicar;
    printf("Multiplicación: %d\n", operacion(5, 3));
    
    return 0;
}
```

### 7.2 Array de punteros a funciones

```c
#include <stdio.h>

int sumar(int a, int b) { return a + b; }
int restar(int a, int b) { return a - b; }
int multiplicar(int a, int b) { return a * b; }
int dividir(int a, int b) { return b != 0 ? a / b : 0; }

int main() {
    // Array de punteros a funciones
    int (*operaciones[])(int, int) = {sumar, restar, multiplicar, dividir};
    char *nombres[] = {"Suma", "Resta", "Multiplicación", "División"};
    
    int a = 10, b = 5;
    
    for (int i = 0; i < 4; i++) {
        printf("%s de %d y %d: %d\n", nombres[i], a, b, operaciones[i](a, b));
    }
    
    return 0;
}
```

### 7.3 Funciones como parámetros

```c
#include <stdio.h>

// Función que recibe otra función como parámetro
void aplicar_operacion(int arr[], int tamaño, int (*func)(int)) {
    for (int i = 0; i < tamaño; i++) {
        arr[i] = func(arr[i]);
    }
}

// Funciones para aplicar
int cuadrado(int x) { return x * x; }
int cubo(int x) { return x * x * x; }
int doble(int x) { return x * 2; }

void imprimir_array(int arr[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int numeros[] = {1, 2, 3, 4, 5};
    int tamaño = 5;
    
    printf("Array original: ");
    imprimir_array(numeros, tamaño);
    
    aplicar_operacion(numeros, tamaño, cuadrado);
    printf("Después de elevar al cuadrado: ");
    imprimir_array(numeros, tamaño);
    
    return 0;
}
```

---

## 8. Funciones de la Biblioteca Estándar

### 8.1 Funciones de entrada/salida (stdio.h)

```c
#include <stdio.h>

void ejemplos_stdio() {
    // printf - salida formateada
    printf("Entero: %d, Float: %.2f, String: %s\n", 42, 3.14, "Hola");
    
    // scanf - entrada formateada
    int numero;
    printf("Ingresa un número: ");
    scanf("%d", &numero);
    
    // getchar/putchar - caracteres individuales
    printf("Ingresa un carácter: ");
    char c = getchar();
    printf("Ingresaste: ");
    putchar(c);
    
    // fgets - leer línea completa
    char buffer[100];
    printf("\nIngresa una línea: ");
    fgets(buffer, sizeof(buffer), stdin);
    printf("Línea ingresada: %s", buffer);
}
```

### 8.2 Funciones de manejo de strings (string.h)

```c
#include <string.h>

void ejemplos_string() {
    char str1[50] = "Hola";
    char str2[50] = "Mundo";
    char str3[100];
    
    // strlen - longitud de string
    printf("Longitud de '%s': %lu\n", str1, strlen(str1));
    
    // strcpy - copiar string
    strcpy(str3, str1);
    printf("Copia: %s\n", str3);
    
    // strcat - concatenar strings
    strcat(str3, " ");
    strcat(str3, str2);
    printf("Concatenación: %s\n", str3);
    
    // strcmp - comparar strings
    if (strcmp(str1, str2) == 0) {
        printf("Los strings son iguales\n");
    } else {
        printf("Los strings son diferentes\n");
    }
    
    // strchr - buscar carácter
    char *pos = strchr(str3, 'M');
    if (pos != NULL) {
        printf("'M' encontrado en posición: %ld\n", pos - str3);
    }
}
```

### 8.3 Funciones matemáticas (math.h)

```c
#include <math.h>

void ejemplos_math() {
    double x = 16.0, y = 3.0;
    
    printf("sqrt(%.1f) = %.2f\n", x, sqrt(x));
    printf("pow(%.1f, %.1f) = %.2f\n", x, y, pow(x, y));
    printf("sin(%.1f) = %.2f\n", y, sin(y));
    printf("cos(%.1f) = %.2f\n", y, cos(y));
    printf("log(%.1f) = %.2f\n", x, log(x));
    printf("ceil(%.1f) = %.0f\n", y, ceil(y));
    printf("floor(%.1f) = %.0f\n", y, floor(y));
    printf("fabs(-%.1f) = %.1f\n", y, fabs(-y));
}
```

### 8.4 Funciones de utilidad general (stdlib.h)

```c
#include <stdlib.h>
#include <time.h>

void ejemplos_stdlib() {
    // malloc/free - gestión de memoria dinámica
    int *arr = malloc(5 * sizeof(int));
    if (arr != NULL) {
        for (int i = 0; i < 5; i++) {
            arr[i] = i + 1;
        }
        // usar array...
        free(arr);
    }
    
    // rand/srand - números aleatorios
    srand(time(NULL)); // semilla aleatoria
    for (int i = 0; i < 5; i++) {
        printf("Número aleatorio: %d\n", rand() % 100);
    }
    
    // atoi/atof - conversión de strings
    char str_num[] = "123";
    char str_float[] = "45.67";
    printf("String a int: %d\n", atoi(str_num));
    printf("String a float: %.2f\n", atof(str_float));
    
    // abs - valor absoluto
    printf("abs(-42) = %d\n", abs(-42));
}
```

---

## 9. Buenas Prácticas

### 9.1 Nomenclatura

```c
// ✅ Buenos nombres de funciones
int calcular_promedio(int valores[], int cantidad);
bool es_numero_primo(int numero);
void mostrar_menu_principal();

// ❌ Malos nombres
int calc(int v[], int c);
bool check(int n);
void show();
```

### 9.2 Documentación

```c
/**
 * Calcula el factorial de un número
 * @param n: número entero positivo
 * @return: factorial de n, o -1 si n es negativo
 */
int factorial(int n) {
    if (n < 0) {
        return -1; // Error: número negativo
    }
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}
```

### 9.3 Validación de parámetros

```c
#include <stdio.h>

// ✅ Función con validación
int dividir_seguro(int dividendo, int divisor, int *resultado) {
    if (resultado == NULL) {
        return -1; // Error: puntero nulo
    }
    
    if (divisor == 0) {
        return -2; // Error: división por cero
    }
    
    *resultado = dividendo / divisor;
    return 0; // Éxito
}

// Uso de la función
int main() {
    int resultado;
    int estado = dividir_seguro(10, 3, &resultado);
    
    switch (estado) {
        case 0:
            printf("Resultado: %d\n", resultado);
            break;
        case -1:
            printf("Error: puntero nulo\n");
            break;
        case -2:
            printf("Error: división por cero\n");
            break;
    }
    
    return 0;
}
```

### 9.4 Funciones pequeñas y enfocadas

```c
// ✅ Funciones pequeñas y específicas
bool es_par(int numero) {
    return numero % 2 == 0;
}

bool es_positivo(int numero) {
    return numero > 0;
}

void imprimir_numero_con_propiedades(int numero) {
    printf("Número: %d", numero);
    
    if (es_par(numero)) {
        printf(" (par)");
    } else {
        printf(" (impar)");
    }
    
    if (es_positivo(numero)) {
        printf(" (positivo)");
    } else {
        printf(" (no positivo)");
    }
    
    printf("\n");
}
```

### 9.5 Uso de const para parámetros de solo lectura

```c
// Indica que no se modificará el array
void imprimir_array_const(const int arr[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        printf("%d ", arr[i]);
        // arr[i] = 0; // Error de compilación
    }
    printf("\n");
}

// Indica que no se modificará el string
int contar_vocales(const char *str) {
    int contador = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            contador++;
        }
    }
    return contador;
}
```

---

## 10. Ejemplos Avanzados

### 10.1 Sistema de menús con funciones

```c
#include <stdio.h>
#include <stdlib.h>

// Funciones del menú
void opcion_suma() {
    int a, b;
    printf("Ingrese dos números: ");
    scanf("%d %d", &a, &b);
    printf("Resultado: %d + %d = %d\n", a, b, a + b);
}

void opcion_resta() {
    int a, b;
    printf("Ingrese dos números: ");
    scanf("%d %d", &a, &b);
    printf("Resultado: %d - %d = %d\n", a, b, a - b);
}

void opcion_multiplicacion() {
    int a, b;
    printf("Ingrese dos números: ");
    scanf("%d %d", &a, &b);
    printf("Resultado: %d * %d = %d\n", a, b, a * b);
}

void mostrar_menu() {
    printf("\n=== CALCULADORA ===\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicación\n");
    printf("4. Salir\n");
    printf("Seleccione una opción: ");
}

int main() {
    // Array de punteros a funciones del menú
    void (*opciones[])() = {opcion_suma, opcion_resta, opcion_multiplicacion};
    
    int seleccion;
    
    do {
        mostrar_menu();
        scanf("%d", &seleccion);
        
        if (seleccion >= 1 && seleccion <= 3) {
            opciones[seleccion - 1]();
        } else if (seleccion == 4) {
            printf("¡Hasta luego!\n");
        } else {
            printf("Opción inválida. Intente de nuevo.\n");
        }
        
    } while (seleccion != 4);
    
    return 0;
}
```

### 10.2 Sistema de ordenamiento genérico

```c
#include <stdio.h>
#include <string.h>

// Función de intercambio genérica
void intercambiar(void *a, void *b, size_t tamaño) {
    char temp[tamaño];
    memcpy(temp, a, tamaño);
    memcpy(a, b, tamaño);
    memcpy(b, temp, tamaño);
}

// Ordenamiento burbuja genérico
void ordenamiento_burbuja(void *arr, int n, size_t tamaño_elemento, 
                         int (*comparar)(const void *, const void *)) {
    char *array = (char *)arr;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            void *elem1 = array + j * tamaño_elemento;
            void *elem2 = array + (j + 1) * tamaño_elemento;
            
            if (comparar(elem1, elem2) > 0) {
                intercambiar(elem1, elem2, tamaño_elemento);
            }
        }
    }
}

// Funciones de comparación
int comparar_enteros(const void *a, const void *b) {
    int int_a = *(const int *)a;
    int int_b = *(const int *)b;
    return int_a - int_b;
}

int comparar_strings(const void *a, const void *b) {
    const char *str_a = *(const char **)a;
    const char *str_b = *(const char **)b;
    return strcmp(str_a, str_b);
}

// Funciones de impresión
void imprimir_enteros(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void imprimir_strings(char *arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Ejemplo con enteros
    int numeros[] = {64, 34, 25, 12, 22, 11, 90};
    int n_numeros = sizeof(numeros) / sizeof(numeros[0]);
    
    printf("Números originales: ");
    imprimir_enteros(numeros, n_numeros);
    
    ordenamiento_burbuja(numeros, n_numeros, sizeof(int), comparar_enteros);
    
    printf("Números ordenados: ");
    imprimir_enteros(numeros, n_numeros);
    
    // Ejemplo con strings
    char *palabras[] = {"banana", "manzana", "cereza", "durazno", "uva"};
    int n_palabras = sizeof(palabras) / sizeof(palabras[0]);
    
    printf("\nPalabras originales: ");
    imprimir_strings(palabras, n_palabras);
    
    ordenamiento_burbuja(palabras, n_palabras, sizeof(char *), comparar_strings);
    
    printf("Palabras ordenadas: ");
    imprimir_strings(palabras, n_palabras);
    
    return 0;
}
```

### 10.3 Calculadora de expresiones con funciones

```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Estructura para operaciones
typedef struct {
    char simbolo;
    int precedencia;
    int (*funcion)(int, int);
} Operacion;

// Funciones de operaciones
int sumar_op(int a, int b) { return a + b; }
int restar_op(int a, int b) { return a - b; }
int multiplicar_op(int a, int b) { return a * b; }
int dividir_op(int a, int b) { return b != 0 ? a / b : 0; }

// Array de operaciones disponibles
Operacion operaciones[] = {
    {'+', 1, sumar_op},
    {'-', 1, restar_op},
    {'*', 2, multiplicar_op},
    {'/', 2, dividir_op}
};

int num_operaciones = sizeof(operaciones) / sizeof(operaciones[0]);

// Buscar operación por símbolo
Operacion* buscar_operacion(char simbolo) {
    for (int i = 0; i < num_operaciones; i++) {
        if (operaciones[i].simbolo == simbolo) {
            return &operaciones[i];
        }
    }
    return NULL;
}

// Evaluador simple de expresiones (solo para números de un dígito)
int evaluar_expresion(char *expresion) {
    int resultado = expresion[0] - '0'; // Primer número
    
    for (int i = 1; i < strlen(expresion); i += 2) {
        char op_simbolo = expresion[i];
        int siguiente_numero = expresion[i + 1] - '0';
        
        Operacion *op = buscar_operacion(op_simbolo);
        if (op != NULL) {
            resultado = op->funcion(resultado, siguiente_numero);
        }
    }
    
    return resultado;
}

int main() {
    char expresion[100];
    
    printf("Calculadora simple (solo números de un dígito)\n");
    printf("Operaciones disponibles: +, -, *, /\n");
    printf("Ejemplo: 5+3*2-1\n");
    printf("Ingrese una expresión: ");
    
    if (fgets(expresion, sizeof(expresion), stdin)) {
        // Remover salto de línea
        expresion[strcspn(expresion, "\n")] = 0;
        
        int resultado = evaluar_expresion(expresion);
        printf("Resultado de '%s' = %d\n", expresion, resultado);
    }
    
    return 0;
}
```

---

## Conclusión

Las funciones en C son una herramienta fundamental que permite escribir código modular, reutilizable y mantenible. Esta guía ha cubierto desde conceptos básicos hasta técnicas avanzadas como punteros a funciones y programación genérica.

### Puntos clave para recordar:

1. **Siempre declara prototipos** para funciones definidas después de su uso
2. **Usa nombres descriptivos** para funciones y parámetros
3. **Valida parámetros** antes de usarlos en funciones críticas
4. **Mantén funciones pequeñas** y enfocadas en una sola tarea
5. **Usa const** para parámetros que no deben modificarse
6. **Documenta funciones complejas** con comentarios claros
7. **Maneja errores apropiadamente** con códigos de retorno o parámetros de salida
8. **Evita variables globales** cuando sea posible, prefiere parámetros

### Recursos adicionales:

Para profundizar en el tema de funciones en C, se recomienda:
- Practicar con los ejemplos proporcionados
- Experimentar con diferentes tipos de parámetros
- Implementar algoritmos usando recursividad
- Explorar bibliotecas estándar de C
- Estudiar código fuente de proyectos open source

Las funciones son la base de la programación estructurada en C. Dominar su uso te permitirá escribir programas más eficientes, legibles y profesionales.

---

*Documento creado como guía de referencia para el aprendizaje de funciones en C. Los ejemplos están diseñados para ser compilados y ejecutados en cualquier entorno de desarrollo C estándar.*