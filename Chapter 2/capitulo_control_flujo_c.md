# Capítulo: Control de Flujo en C

## Índice
1. [Introducción al Control de Flujo](#1-introducción-al-control-de-flujo)
2. [Estructuras de Decisión](#2-estructuras-de-decisión)
3. [Estructuras de Repetición](#3-estructuras-de-repetición)
4. [Instrucciones de Control de Flujo](#4-instrucciones-de-control-de-flujo)
5. [Anidamiento y Combinaciones](#5-anidamiento-y-combinaciones)
6. [Buenas Prácticas](#6-buenas-prácticas)
7. [Ejercicios Prácticos](#7-ejercicios-prácticos)

---

## 1. Introducción al Control de Flujo

### 1.1 ¿Qué es el Control de Flujo?

El **control de flujo** se refiere a la capacidad de controlar el orden en que se ejecutan las instrucciones en un programa. Por defecto, las instrucciones se ejecutan secuencialmente (de arriba hacia abajo), pero las estructuras de control permiten:

- **Tomar decisiones** basadas en condiciones
- **Repetir** bloques de código
- **Saltar** a diferentes partes del programa
- **Controlar** la ejecución de manera precisa

### 1.2 Tipos de Control de Flujo

1. **Secuencial**: Ejecución línea por línea (comportamiento por defecto)
2. **Condicional**: Ejecución basada en condiciones (if, if-else, switch)
3. **Iterativo**: Repetición de bloques de código (for, while, do-while)
4. **Incondicional**: Saltos directos (goto, break, continue, return)

### 1.3 Importancia en la Programación

```c
// Ejemplo de flujo secuencial simple
#include <stdio.h>

int main() {
    printf("Línea 1\n");    // Se ejecuta primero
    printf("Línea 2\n");    // Se ejecuta segundo
    printf("Línea 3\n");    // Se ejecuta tercero
    return 0;
}
```

---

## 2. Estructuras de Decisión

### 2.1 Sentencia if

La estructura más básica para tomar decisiones.

#### Sintaxis:
```c
if (condición) {
    // Código a ejecutar si la condición es verdadera
}
```

#### Ejemplo:
```c
#include <stdio.h>

int main() {
    int edad;
    
    printf("Ingrese su edad: ");
    scanf("%d", &edad);
    
    if (edad >= 18) {
        printf("Usted es mayor de edad.\n");
    }
    
    return 0;
}
```

### 2.2 Sentencia if-else

Permite ejecutar código alternativo cuando la condición es falsa.

#### Sintaxis:
```c
if (condición) {
    // Código si la condición es verdadera
} else {
    // Código si la condición es falsa
}
```

#### Ejemplo:
```c
#include <stdio.h>

int main() {
    int numero;
    
    printf("Ingrese un número: ");
    scanf("%d", &numero);
    
    if (numero % 2 == 0) {
        printf("%d es un número par.\n", numero);
    } else {
        printf("%d es un número impar.\n", numero);
    }
    
    return 0;
}
```

### 2.3 Sentencia if-else if-else

Para múltiples condiciones en cascada.

#### Sintaxis:
```c
if (condición1) {
    // Código para condición1
} else if (condición2) {
    // Código para condición2
} else if (condición3) {
    // Código para condición3
} else {
    // Código por defecto
}
```

#### Ejemplo: Sistema de Calificaciones
```c
#include <stdio.h>

int main() {
    float calificacion;
    
    printf("Ingrese su calificación (0-100): ");
    scanf("%f", &calificacion);
    
    if (calificacion >= 90) {
        printf("Excelente (A)\n");
    } else if (calificacion >= 80) {
        printf("Muy Bueno (B)\n");
    } else if (calificacion >= 70) {
        printf("Bueno (C)\n");
    } else if (calificacion >= 60) {
        printf("Suficiente (D)\n");
    } else {
        printf("Insuficiente (F)\n");
    }
    
    return 0;
}
```

### 2.4 Operadores de Comparación y Lógicos

#### Operadores de Comparación:
```c
== // Igual a
!= // Diferente de
<  // Menor que
<= // Menor o igual que
>  // Mayor que
>= // Mayor o igual que
```

#### Operadores Lógicos:
```c
&& // AND lógico (y)
|| // OR lógico (o)
!  // NOT lógico (no)
```

#### Ejemplo con Operadores Lógicos:
```c
#include <stdio.h>

int main() {
    int edad;
    char licencia;
    
    printf("Ingrese su edad: ");
    scanf("%d", &edad);
    printf("¿Tiene licencia de conducir? (s/n): ");
    scanf(" %c", &licencia);
    
    if (edad >= 18 && (licencia == 's' || licencia == 'S')) {
        printf("Puede conducir legalmente.\n");
    } else {
        printf("No puede conducir.\n");
        
        if (edad < 18) {
            printf("Razón: Es menor de edad.\n");
        }
        if (!(licencia == 's' || licencia == 'S')) {
            printf("Razón: No tiene licencia válida.\n");
        }
    }
    
    return 0;
}
```

### 2.5 Sentencia switch

Alternativa elegante para múltiples condiciones con valores específicos.

#### Sintaxis:
```c
switch (expresión) {
    case valor1:
        // Código para valor1
        break;
    case valor2:
        // Código para valor2
        break;
    case valor3:
        // Código para valor3
        break;
    default:
        // Código por defecto
        break;
}
```

#### Ejemplo: Calculadora Básica
```c
#include <stdio.h>

int main() {
    double num1, num2, resultado;
    char operador;
    
    printf("Ingrese primer número: ");
    scanf("%lf", &num1);
    printf("Ingrese operador (+, -, *, /): ");
    scanf(" %c", &operador);
    printf("Ingrese segundo número: ");
    scanf("%lf", &num2);
    
    switch (operador) {
        case '+':
            resultado = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, resultado);
            break;
        case '-':
            resultado = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, resultado);
            break;
        case '*':
            resultado = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, resultado);
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, resultado);
            } else {
                printf("Error: División por cero.\n");
            }
            break;
        default:
            printf("Operador no válido.\n");
            break;
    }
    
    return 0;
}
```

#### Ejemplo: Menú de Opciones
```c
#include <stdio.h>

int main() {
    int opcion;
    
    do {
        printf("\n=== MENÚ PRINCIPAL ===\n");
        printf("1. Opción A\n");
        printf("2. Opción B\n");
        printf("3. Opción C\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                printf("Ha seleccionado la Opción A\n");
                break;
            case 2:
                printf("Ha seleccionado la Opción B\n");
                break;
            case 3:
                printf("Ha seleccionado la Opción C\n");
                break;
            case 4:
                printf("¡Hasta luego!\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
                break;
        }
    } while (opcion != 4);
    
    return 0;
}
```

---

## 3. Estructuras de Repetición

### 3.1 Bucle for

Ideal cuando conocemos exactamente cuántas veces queremos repetir algo.

#### Sintaxis:
```c
for (inicialización; condición; incremento) {
    // Código a repetir
}
```

#### Ejemplo Básico:
```c
#include <stdio.h>

int main() {
    int i;
    
    // Imprimir números del 1 al 10
    for (i = 1; i <= 10; i++) {
        printf("Número: %d\n", i);
    }
    
    return 0;
}
```

#### Ejemplo: Tabla de Multiplicar
```c
#include <stdio.h>

int main() {
    int numero, i;
    
    printf("Ingrese un número para su tabla de multiplicar: ");
    scanf("%d", &numero);
    
    printf("\nTabla de multiplicar del %d:\n", numero);
    for (i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }
    
    return 0;
}
```

#### Ejemplo: Cálculo de Factorial
```c
#include <stdio.h>

int main() {
    int n, i;
    long long factorial = 1;
    
    printf("Ingrese un número positivo: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Error: El factorial no está definido para números negativos.\n");
    } else {
        for (i = 1; i <= n; i++) {
            factorial *= i;
        }
        printf("El factorial de %d es: %lld\n", n, factorial);
    }
    
    return 0;
}
```

### 3.2 Bucle while

Se ejecuta mientras la condición sea verdadera. La condición se evalúa antes de cada iteración.

#### Sintaxis:
```c
while (condición) {
    // Código a repetir
    // Debe incluir algo que modifique la condición
}
```

#### Ejemplo: Suma de Números
```c
#include <stdio.h>

int main() {
    int numero, suma = 0;
    
    printf("Ingrese números enteros (0 para terminar):\n");
    
    scanf("%d", &numero);
    while (numero != 0) {
        suma += numero;
        printf("Suma actual: %d\n", suma);
        printf("Ingrese otro número (0 para terminar): ");
        scanf("%d", &numero);
    }
    
    printf("Suma total: %d\n", suma);
    return 0;
}
```

#### Ejemplo: Validación de Entrada
```c
#include <stdio.h>

int main() {
    int edad;
    
    printf("Ingrese su edad (debe ser entre 0 y 120): ");
    scanf("%d", &edad);
    
    while (edad < 0 || edad > 120) {
        printf("Edad no válida. Ingrese una edad entre 0 y 120: ");
        scanf("%d", &edad);
    }
    
    printf("Su edad es: %d años\n", edad);
    return 0;
}
```

### 3.3 Bucle do-while

Similar a while, pero garantiza al menos una ejecución del bloque de código.

#### Sintaxis:
```c
do {
    // Código a repetir
} while (condición);
```

#### Ejemplo: Menú Interactivo
```c
#include <stdio.h>

int main() {
    int opcion;
    
    do {
        printf("\n=== CALCULADORA ===\n");
        printf("1. Sumar\n");
        printf("2. Restar\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("5. Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                printf("Función suma seleccionada\n");
                break;
            case 2:
                printf("Función resta seleccionada\n");
                break;
            case 3:
                printf("Función multiplicación seleccionada\n");
                break;
            case 4:
                printf("Función división seleccionada\n");
                break;
            case 5:
                printf("¡Gracias por usar la calculadora!\n");
                break;
            default:
                printf("Opción no válida\n");
        }
    } while (opcion != 5);
    
    return 0;
}
```

#### Ejemplo: Juego de Adivinanza
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numero_secreto, intento, intentos = 0;
    char jugar_otra_vez;
    
    srand(time(NULL)); // Inicializar generador de números aleatorios
    
    do {
        numero_secreto = rand() % 100 + 1; // Número entre 1 y 100
        intentos = 0;
        
        printf("\n¡Adivina el número entre 1 y 100!\n");
        
        do {
            printf("Ingresa tu intento: ");
            scanf("%d", &intento);
            intentos++;
            
            if (intento < numero_secreto) {
                printf("Muy bajo. Intenta con un número mayor.\n");
            } else if (intento > numero_secreto) {
                printf("Muy alto. Intenta con un número menor.\n");
            } else {
                printf("¡Felicidades! Adivinaste en %d intentos.\n", intentos);
            }
        } while (intento != numero_secreto);
        
        printf("¿Quieres jugar otra vez? (s/n): ");
        scanf(" %c", &jugar_otra_vez);
        
    } while (jugar_otra_vez == 's' || jugar_otra_vez == 'S');
    
    return 0;
}
```

---

## 4. Instrucciones de Control de Flujo

### 4.1 break

Termina inmediatamente el bucle más interno o la sentencia switch.

#### Ejemplo en bucles:
```c
#include <stdio.h>

int main() {
    int i;
    
    printf("Números del 1 al 10, pero paramos en 5:\n");
    for (i = 1; i <= 10; i++) {
        if (i == 5) {
            printf("¡Encontramos el 5! Saliendo del bucle.\n");
            break;
        }
        printf("%d ", i);
    }
    
    return 0;
}
```

#### Ejemplo: Búsqueda en Array
```c
#include <stdio.h>

int main() {
    int numeros[] = {10, 25, 30, 45, 50, 60, 75};
    int tamaño = sizeof(numeros) / sizeof(numeros[0]);
    int buscar, i, encontrado = 0;
    
    printf("Ingrese el número a buscar: ");
    scanf("%d", &buscar);
    
    for (i = 0; i < tamaño; i++) {
        if (numeros[i] == buscar) {
            printf("Número %d encontrado en la posición %d\n", buscar, i);
            encontrado = 1;
            break; // Salir del bucle una vez encontrado
        }
    }
    
    if (!encontrado) {
        printf("Número %d no encontrado en el array\n", buscar);
    }
    
    return 0;
}
```

### 4.2 continue

Salta a la siguiente iteración del bucle, omitiendo el resto del código en la iteración actual.

#### Ejemplo:
```c
#include <stdio.h>

int main() {
    int i;
    
    printf("Números impares del 1 al 10:\n");
    for (i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue; // Saltar números pares
        }
        printf("%d ", i);
    }
    printf("\n");
    
    return 0;
}
```

#### Ejemplo: Procesamiento de Datos
```c
#include <stdio.h>

int main() {
    int numeros[] = {1, -2, 3, -4, 5, -6, 7, 0, 9, -10};
    int tamaño = sizeof(numeros) / sizeof(numeros[0]);
    int i, suma_positivos = 0, contador_positivos = 0;
    
    printf("Procesando solo números positivos:\n");
    
    for (i = 0; i < tamaño; i++) {
        if (numeros[i] <= 0) {
            continue; // Saltar números negativos y cero
        }
        
        printf("Número positivo: %d\n", numeros[i]);
        suma_positivos += numeros[i];
        contador_positivos++;
    }
    
    if (contador_positivos > 0) {
        printf("Suma de números positivos: %d\n", suma_positivos);
        printf("Promedio: %.2f\n", (float)suma_positivos / contador_positivos);
    }
    
    return 0;
}
```

### 4.3 return

Termina la ejecución de una función y opcionalmente devuelve un valor.

#### Ejemplo en main():
```c
#include <stdio.h>

int main() {
    int edad;
    
    printf("Ingrese su edad: ");
    scanf("%d", &edad);
    
    if (edad < 0) {
        printf("Error: Edad no válida\n");
        return 1; // Terminar programa con código de error
    }
    
    printf("Su edad es: %d años\n", edad);
    return 0; // Terminar programa exitosamente
}
```

### 4.4 goto (No Recomendado)

Salta incondicionalmente a una etiqueta específica. Su uso se desaconseja fuertemente.

#### Ejemplo (Solo para conocimiento):
```c
#include <stdio.h>

int main() {
    int i = 1;
    
    inicio: // Etiqueta
    if (i <= 5) {
        printf("Iteración %d\n", i);
        i++;
        goto inicio; // Saltar a la etiqueta
    }
    
    printf("Fin del programa\n");
    return 0;
}
```

**Nota**: El uso de `goto` hace el código difícil de leer y mantener. Siempre prefiere usar estructuras de control estructuradas.

---

## 5. Anidamiento y Combinaciones

### 5.1 Bucles Anidados

#### Ejemplo: Tabla de Multiplicar Completa
```c
#include <stdio.h>

int main() {
    int i, j;
    
    printf("Tabla de multiplicar del 1 al 10:\n\n");
    
    // Encabezado
    printf("   ");
    for (j = 1; j <= 10; j++) {
        printf("%4d", j);
    }
    printf("\n");
    
    // Línea separadora
    printf("   ");
    for (j = 1; j <= 10; j++) {
        printf("----");
    }
    printf("\n");
    
    // Tabla
    for (i = 1; i <= 10; i++) {
        printf("%2d|", i);
        for (j = 1; j <= 10; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
    
    return 0;
}
```

#### Ejemplo: Patrón de Estrellas
```c
#include <stdio.h>

int main() {
    int filas, i, j;
    
    printf("Ingrese el número de filas para el triángulo: ");
    scanf("%d", &filas);
    
    printf("\nTriángulo creciente:\n");
    for (i = 1; i <= filas; i++) {
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    
    printf("\nTriángulo decreciente:\n");
    for (i = filas; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    
    return 0;
}
```

### 5.2 Condiciones Anidadas

#### Ejemplo: Sistema de Notas Avanzado
```c
#include <stdio.h>

int main() {
    float nota1, nota2, nota3, promedio;
    int faltas;
    
    printf("Ingrese las tres notas del estudiante: ");
    scanf("%f %f %f", &nota1, &nota2, &nota3);
    printf("Ingrese el número de faltas: ");
    scanf("%d", &faltas);
    
    promedio = (nota1 + nota2 + nota3) / 3.0;
    
    printf("Promedio: %.2f\n", promedio);
    
    if (promedio >= 60) {
        if (faltas <= 3) {
            printf("Estado: APROBADO\n");
            if (promedio >= 90) {
                printf("Calificación: Excelente\n");
            } else if (promedio >= 80) {
                printf("Calificación: Muy Bueno\n");
            } else {
                printf("Calificación: Bueno\n");
            }
        } else {
            printf("Estado: REPROBADO POR FALTAS\n");
            printf("Número de faltas excesivo: %d\n", faltas);
        }
    } else {
        printf("Estado: REPROBADO POR NOTAS\n");
        if (promedio >= 50) {
            printf("Puede presentar examen de recuperación\n");
        } else {
            printf("Debe repetir la materia\n");
        }
    }
    
    return 0;
}
```

### 5.3 Combinando Diferentes Estructuras

#### Ejemplo: Sistema de Login con Intentos Limitados
```c
#include <stdio.h>
#include <string.h>

int main() {
    char usuario_correcto[] = "admin";
    char password_correcto[] = "12345";
    char usuario[50], password[50];
    int intentos = 0, max_intentos = 3;
    int login_exitoso = 0;
    
    printf("=== SISTEMA DE LOGIN ===\n");
    
    do {
        printf("\nIntento %d de %d\n", intentos + 1, max_intentos);
        printf("Usuario: ");
        scanf("%s", usuario);
        printf("Contraseña: ");
        scanf("%s", password);
        
        if (strcmp(usuario, usuario_correcto) == 0 && 
            strcmp(password, password_correcto) == 0) {
            printf("¡Login exitoso!\n");
            login_exitoso = 1;
            break;
        } else {
            intentos++;
            if (intentos < max_intentos) {
                printf("Usuario o contraseña incorrectos. Intente nuevamente.\n");
            }
        }
    } while (intentos < max_intentos);
    
    if (!login_exitoso) {
        printf("Demasiados intentos fallidos. Acceso bloqueado.\n");
    } else {
        // Menú principal después del login exitoso
        int opcion;
        
        do {
            printf("\n=== MENÚ PRINCIPAL ===\n");
            printf("1. Ver perfil\n");
            printf("2. Configuración\n");
            printf("3. Ayuda\n");
            printf("4. Cerrar sesión\n");
            printf("Seleccione una opción: ");
            scanf("%d", &opcion);
            
            switch (opcion) {
                case 1:
                    printf("Mostrando perfil de usuario...\n");
                    break;
                case 2:
                    printf("Abriendo configuración...\n");
                    break;
                case 3:
                    printf("Mostrando ayuda...\n");
                    break;
                case 4:
                    printf("Cerrando sesión. ¡Hasta luego!\n");
                    break;
                default:
                    printf("Opción no válida.\n");
            }
        } while (opcion != 4);
    }
    
    return 0;
}
```

---

## 6. Buenas Prácticas

### 6.1 Legibilidad del Código

#### Usar Indentación Consistente:
```c
// ✅ Correcto
if (condicion) {
    if (otra_condicion) {
        printf("Mensaje\n");
    }
}

// ❌ Incorrecto
if (condicion) {
if (otra_condicion) {
printf("Mensaje\n");
}
}
```

#### Usar Llaves Siempre:
```c
// ✅ Recomendado
if (x > 0) {
    printf("Positivo\n");
}

// ❌ Evitar (propenso a errores)
if (x > 0)
    printf("Positivo\n");
```

### 6.2 Optimización y Eficiencia

#### Evitar Condiciones Innecesarias:
```c
// ✅ Mejor
bool es_par = (numero % 2 == 0);

// ❌ Innecesario
bool es_par;
if (numero % 2 == 0) {
    es_par = true;
} else {
    es_par = false;
}
```

#### Ordenar Condiciones por Probabilidad:
```c
// Si sabemos que condicion1 es más probable
if (condicion1) {
    // Código más frecuente
} else if (condicion2) {
    // Código menos frecuente
} else {
    // Caso raro
}
```

### 6.3 Manejo de Errores

#### Validación de Entrada:
```c
#include <stdio.h>

int main() {
    int numero, resultado;
    
    printf("Ingrese un número entero: ");
    resultado = scanf("%d", &numero);
    
    if (resultado != 1) {
        printf("Error: Entrada no válida\n");
        return 1;
    }
    
    // Procesar número válido
    printf("Número ingresado: %d\n", numero);
    return 0;
}
```

### 6.4 Comentarios Útiles

```c
#include <stdio.h>

int main() {
    int edad;
    
    // Solicitar edad al usuario
    printf("Ingrese su edad: ");
    scanf("%d", &edad);
    
    // Validar rango de edad (0-150 años es razonable)
    if (edad < 0 || edad > 150) {
        printf("Edad fuera del rango válido\n");
        return 1;
    }
    
    // Determinar categoría de edad
    if (edad < 13) {
        printf("Categoría: Niño\n");
    } else if (edad < 18) {
        printf("Categoría: Adolescente\n");
    } else if (edad < 60) {
        printf("Categoría: Adulto\n");
    } else {
        printf("Categoría: Adulto Mayor\n");
    }
    
    return 0;
}
```

---

## 7. Ejercicios Prácticos

### 7.1 Ejercicios Básicos

#### Ejercicio 1: Calculadora de IMC
```c
/*
Crear un programa que:
1. Pida peso y altura al usuario
2. Calcule el IMC (peso / altura²)
3. Clasifique el resultado:
   - Bajo peso: IMC < 18.5
   - Normal: 18.5 ≤ IMC < 25
   - Sobrepeso: 25 ≤ IMC < 30
   - Obesidad: IMC ≥ 30
*/
```

#### Ejercicio 2: Números Primos
```c
/*
Escribir un programa que:
1. Pida un número al usuario
2. Determine si es primo
3. Si no es primo, muestre sus divisores
*/
```

### 7.2 Ejercicios Intermedios

#### Ejercicio 3: Juego de Piedra, Papel, Tijeras
```c
/*
Crear un juego que:
1. Permita al usuario jugar contra la computadora
2. Lleve el marcador de victorias
3. Permita jugar múltiples rondas
4. Muestre estadísticas al final
*/
```

#### Ejercicio 4: Sistema de Cajero Automático
```c
/*
Simular un cajero que:
1. Requiera PIN para acceder (3 intentos máximo)
2. Muestre menú con opciones:
   - Consultar saldo
   - Retirar dinero (validar fondos)
   - Depositar dinero
   - Salir
3. Mantenga el saldo actualizado
*/
```

### 7.3 Ejercicios Avanzados

#### Ejercicio 5: Generador de Patrones
```c
/*
Crear un programa que genere diferentes patrones según la elección del usuario:
1. Triángulo de números
2. Pirámide de estrellas
3. Rombo de caracteres
4. Patrón de tablero de ajedrez
Permitir al usuario especificar el tamaño del patrón.
*/
```

#### Ejercicio 6: Sistema de Gestión de Notas
```c
/*
Desarrollar un programa que:
1. Permita ingresar notas de múltiples estudiantes
2. Calcule estadísticas (promedio, nota más alta, más baja)
3. Muestre histograma de calificaciones
4. Determine quién necesita recuperación
5. Genere reporte final
*/
```

#### Ejercicio 7: Conversor de Bases Numéricas
```c
/*
Crear un conversor que:
1. Permita convertir números entre diferentes bases (2, 8, 10, 16)
2. Valide la entrada según la base origen
3. Muestre el proceso de conversión paso a paso
4. Maneje números negativos
*/
```

### 7.4 Proyectos Integradores

#### Proyecto 1: Juego de Adivinanza Avanzado
```c
/*
Características del juego:
1. Diferentes niveles de dificultad
2. Sistema de pistas inteligentes
3. Puntuación basada en intentos
4. Guardado de mejores puntuaciones
5. Estadísticas del jugador
6. Modo multijugador por turnos
*/
```

#### Proyecto 2: Calculadora Científica
```c
/*
Implementar una calculadora con:
1. Operaciones básicas (+, -, *, /, %)
2. Funciones científicas (potencia, raíz, factorial)
3. Historial de operaciones
4. Modo de memoria (M+, M-, MR, MC)
5. Conversión de unidades básicas
6. Interfaz de menú intuitiva
*/
```

---

## 8. Conceptos Avanzados

### 8.1 Cortocircuito en Operadores Lógicos

En C, los operadores `&&` y `||` utilizan evaluación de cortocircuito:

```c
#include <stdio.h>

int funcion_costosa() {
    printf("Ejecutando función costosa...\n");
    return 1;
}

int main() {
    int x = 0;
    
    // Con &&: si x es 0, no se ejecuta funcion_costosa()
    if (x != 0 && funcion_costosa()) {
        printf("Ambas condiciones son verdaderas\n");
    }
    
    // Con ||: si x es 0, SÍ se ejecuta funcion_costosa()
    if (x == 0 || funcion_costosa()) {
        printf("Al menos una condición es verdadera\n");
    }
    
    return 0;
}
```

### 8.2 Operador Ternario

Una forma concisa de escribir if-else simples:

```c
#include <stdio.h>

int main() {
    int a = 10, b = 20;
    
    // Forma tradicional
    int maximo_tradicional;
    if (a > b) {
        maximo_tradicional = a;
    } else {
        maximo_tradicional = b;
    }
    
    // Usando operador ternario
    int maximo_ternario = (a > b) ? a : b;
    
    printf("Máximo tradicional: %d\n", maximo_tradicional);
    printf("Máximo ternario: %d\n", maximo_ternario);
    
    // Ejemplo con strings
    char* resultado = (a > b) ? "a es mayor" : "b es mayor o igual";
    printf("%s\n", resultado);
    
    return 0;
}
```

### 8.3 Switch con Fall-through

Uso intencional de la caída entre casos:

```c
#include <stdio.h>

int main() {
    int mes;
    
    printf("Ingrese el número del mes (1-12): ");
    scanf("%d", &mes);
    
    printf("El mes %d tiene ", mes);
    
    switch (mes) {
        case 1:  // Enero
        case 3:  // Marzo
        case 5:  // Mayo
        case 7:  // Julio
        case 8:  // Agosto
        case 10: // Octubre
        case 12: // Diciembre
            printf("31 días\n");
            break;
        case 4:  // Abril
        case 6:  // Junio
        case 9:  // Septiembre
        case 11: // Noviembre
            printf("30 días\n");
            break;
        case 2:  // Febrero
            printf("28 o 29 días (dependiendo del año)\n");
            break;
        default:
            printf("Error: Mes no válido\n");
            break;
    }
    
    return 0;
}
```

### 8.4 Bucles Infinitos Controlados

Uso apropiado de bucles infinitos:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcion;
    
    // Bucle infinito con break para salir
    while (1) {  // También puede ser: for (;;) {
        printf("\n=== MENÚ PRINCIPAL ===\n");
        printf("1. Opción A\n");
        printf("2. Opción B\n");
        printf("3. Salir\n");
        printf("Seleccione: ");
        
        if (scanf("%d", &opcion) != 1) {
            printf("Entrada no válida. Terminando programa.\n");
            break;
        }
        
        switch (opcion) {
            case 1:
                printf("Ejecutando Opción A...\n");
                break;
            case 2:
                printf("Ejecutando Opción B...\n");
                break;
            case 3:
                printf("¡Hasta luego!\n");
                return 0;  // Salir del programa
            default:
                printf("Opción no válida. Intente nuevamente.\n");
                continue;  // Volver al inicio del bucle
        }
    }
    
    return 1;  // Error exit
}
```

---

## 9. Errores Comunes y Cómo Evitarlos

### 9.1 Asignación vs Comparación

```c
// ❌ Error común
int x = 5;
if (x = 10) {  // Asignación accidental
    printf("Esta condición siempre será verdadera\n");
}

// ✅ Correcto
if (x == 10) {  // Comparación
    printf("x es igual a 10\n");
}

// ✅ Técnica defensiva (compilador detecta error)
if (10 == x) {  // Constante primero
    printf("x es igual a 10\n");
}
```

### 9.2 Bucles Infinitos Accidentales

```c
// ❌ Error: punto y coma extra
for (int i = 0; i < 10; i++); {  // ; termina el bucle
    printf("%d\n", i);  // Solo se ejecuta una vez
}

// ✅ Correcto
for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
}

// ❌ Error: condición que nunca cambia
int i = 0;
while (i < 10) {
    printf("%d\n", i);
    // Falta: i++;  <-- Bucle infinito
}
```

### 9.3 Problemas con Switch

```c
// ❌ Error: falta break
switch (opcion) {
    case 1:
        printf("Opción 1\n");
        // Falta break - continúa al caso 2
    case 2:
        printf("Opción 2\n");
        break;
}

// ✅ Correcto
switch (opcion) {
    case 1:
        printf("Opción 1\n");
        break;
    case 2:
        printf("Opción 2\n");
        break;
    default:
        printf("Opción no válida\n");
        break;
}
```

### 9.4 Validación de Entrada Inadecuada

```c
// ❌ Sin validación
int numero;
scanf("%d", &numero);
// ¿Qué pasa si el usuario ingresa texto?

// ✅ Con validación
int numero, resultado;
printf("Ingrese un número: ");
resultado = scanf("%d", &numero);

if (resultado != 1) {
    printf("Error: Entrada no válida\n");
    // Limpiar buffer de entrada
    while (getchar() != '\n');
    return 1;
}
```

---

## 10. Optimización y Rendimiento

### 10.1 Optimización de Condiciones

```c
// ✅ Ordenar condiciones por probabilidad
if (caso_comun) {
    // Código para caso más frecuente
} else if (caso_menos_comun) {
    // Código para caso menos frecuente
} else {
    // Caso raro
}

// ✅ Usar operadores de cortocircuito eficientemente
if (condicion_rapida && condicion_lenta) {
    // condicion_lenta solo se evalúa si condicion_rapida es verdadera
}
```

### 10.2 Optimización de Bucles

```c
// ❌ Ineficiente: cálculo repetido
int limite = strlen(cadena);
for (int i = 0; i < strlen(cadena); i++) {  // strlen() se llama cada vez
    // procesar cadena[i]
}

// ✅ Eficiente: calcular una vez
int limite = strlen(cadena);
for (int i = 0; i < limite; i++) {
    // procesar cadena[i]
}

// ✅ Aún mejor: bucle descendente (cuando el orden no importa)
for (int i = limite - 1; i >= 0; i--) {
    // procesar cadena[i]
}
```

---

## 11. Herramientas de Debugging

### 11.1 Printf Debugging

```c
#include <stdio.h>

// Macro útil para debugging
#define DEBUG_PRINT(fmt, args...) \
    printf("DEBUG %s:%d: " fmt, __FILE__, __LINE__, ##args)

int main() {
    int x = 5, y = 10;
    
    DEBUG_PRINT("Valores iniciales: x=%d, y=%d\n", x, y);
    
    if (x < y) {
        DEBUG_PRINT("Entrando en rama if\n");
        x += y;
    }
    
    DEBUG_PRINT("Resultado final: x=%d\n", x);
    
    return 0;
}
```

### 11.2 Usar Assertions

```c
#include <stdio.h>
#include <assert.h>

int dividir(int a, int b) {
    assert(b != 0);  // El programa termina si b es 0
    return a / b;
}

int main() {
    int resultado = dividir(10, 2);  // OK
    printf("10/2 = %d\n", resultado);
    
    // resultado = dividir(10, 0);  // Esto terminaría el programa
    
    return 0;
}
```

---

## 12. Resumen y Mejores Prácticas

### 12.1 Checklist para Control de Flujo

**Antes de escribir código:**
- [ ] ¿Es necesaria una decisión? → usar if/switch
- [ ] ¿Necesito repetir código? → usar bucles
- [ ] ¿Conozco exactamente cuántas iteraciones? → usar for
- [ ] ¿La condición puede cambiar durante la ejecución? → usar while
- [ ] ¿Necesito ejecutar al menos una vez? → usar do-while

**Durante la implementación:**
- [ ] ¿Todas las condiciones están entre paréntesis?
- [ ] ¿Todos los bloques tienen llaves?
- [ ] ¿Los bucles tienen condiciones de terminación?
- [ ] ¿He manejado todos los casos edge?
- [ ] ¿La lógica es clara y legible?

**Después de escribir:**
- [ ] ¿El código está bien indentado?
- [ ] ¿Los comentarios explican el "por qué", no el "qué"?
- [ ] ¿He probado con diferentes entradas?
- [ ] ¿Manejo los errores apropiadamente?

### 12.2 Principios Fundamentales

1. **Claridad sobre Brevedad**: Prefiere código claro sobre código corto
2. **Consistencia**: Mantén un estilo consistente en todo el programa
3. **Robustez**: Siempre valida las entradas del usuario
4. **Eficiencia**: Considera el rendimiento, pero no sacrifiques legibilidad
5. **Mantenibilidad**: Escribe código que puedas entender en 6 meses

### 12.3 Patrones de Diseño Comunes

#### Patrón de Validación de Entrada:
```c
int obtener_numero_valido(int min, int max) {
    int numero, resultado;
    
    do {
        printf("Ingrese un número entre %d y %d: ", min, max);
        resultado = scanf("%d", &numero);
        
        if (resultado != 1) {
            printf("Error: Ingrese solo números.\n");
            while (getchar() != '\n');  // Limpiar buffer
            continue;
        }
        
        if (numero < min || numero > max) {
            printf("Número fuera del rango válido.\n");
            continue;
        }
        
        return numero;  // Número válido
        
    } while (1);
}
```

#### Patrón de Menú Robusto:
```c
void mostrar_menu() {
    printf("\n=== MENÚ ===\n");
    printf("1. Opción A\n");
    printf("2. Opción B\n");
    printf("3. Salir\n");
    printf("Seleccione: ");
}

int main() {
    int opcion;
    
    do {
        mostrar_menu();
        opcion = obtener_numero_valido(1, 3);
        
        switch (opcion) {
            case 1:
                printf("Ejecutando Opción A...\n");
                break;
            case 2:
                printf("Ejecutando Opción B...\n");
                break;
            case 3:
                printf("¡Hasta luego!\n");
                break;
        }
        
        if (opcion != 3) {
            printf("Presione Enter para continuar...");
            getchar();  // Esperar enter
        }
        
    } while (opcion != 3);
    
    return 0;
}
```

---

## Conclusión

El control de flujo es fundamental en la programación en C. Dominar estas estructuras te permitirá:

- Crear programas interactivos y dinámicos
- Implementar lógica compleja de manera ordenada
- Optimizar el rendimiento de tus aplicaciones
- Escribir código más legible y mantenible

**Recuerda:**
- Practica regularmente con ejercicios progresivos
- Siempre valida las entradas del usuario
- Escribe código que sea fácil de leer y mantener
- No temas refactorizar cuando sea necesario
- La experiencia se gana resolviendo problemas reales

**Próximos temas sugeridos:**
- Arrays y Strings
- Funciones y Modularización
- Punteros y Gestión de Memoria
- Estructuras de Datos

¡Sigue practicando y experimentando con diferentes combinaciones de estructuras de control!