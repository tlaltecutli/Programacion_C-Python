# Clase 13: Condicionales en Python
## Semana 7 - Estructuras de Control en Python

---

## 📋 Contenido de la Clase

1. [Introducción a las Estructuras Condicionales](#1-introducción-a-las-estructuras-condicionales)
2. [Condicionales en Python: if, elif, else](#2-condicionales-en-python-if-elif-else)
3. [Operadores de Comparación](#3-operadores-de-comparación)
4. [Operadores Lógicos](#4-operadores-lógicos)
5. [Expresiones Booleanas Avanzadas](#5-expresiones-booleanas-avanzadas)
6. [Comparación entre C y Python](#6-comparación-entre-c-y-python)
7. [Ejercicios Prácticos](#7-ejercicios-prácticos)

---

## 1. Introducción a las Estructuras Condicionales

Las estructuras condicionales permiten que un programa tome decisiones basadas en condiciones específicas. En Python, estas estructuras son fundamentales para crear programas dinámicos que respondan a diferentes situaciones.

### ¿Por qué son importantes?

- Permiten ejecutar código diferente según las condiciones
- Hacen que los programas sean interactivos y adaptativos
- Son la base de la lógica de programación
- Facilitan la validación de datos y el manejo de casos especiales

---

## 2. Condicionales en Python: if, elif, else

### 2.1 Estructura básica: if

La sentencia `if` evalúa una condición y ejecuta un bloque de código si la condición es verdadera.

**Sintaxis:**
```python
if condicion:
    # Código a ejecutar si la condición es True
    instruccion1
    instruccion2
```

**Ejemplo 1: Verificar mayoría de edad**
```python
edad = 18

if edad >= 18:
    print("Eres mayor de edad")
    print("Puedes votar")
```

**Salida:**
```
Eres mayor de edad
Puedes votar
```

### 2.2 Estructura if-else

La cláusula `else` proporciona una alternativa cuando la condición del `if` es falsa.

**Sintaxis:**
```python
if condicion:
    # Código si la condición es True
    instruccion1
else:
    # Código si la condición es False
    instruccion2
```

**Ejemplo 2: Verificar si un número es par o impar**
```python
numero = 7

if numero % 2 == 0:
    print(f"{numero} es par")
else:
    print(f"{numero} es impar")
```

**Salida:**
```
7 es impar
```

### 2.3 Estructura if-elif-else

`elif` (else if) permite evaluar múltiples condiciones en secuencia.

**Sintaxis:**
```python
if condicion1:
    # Código si condicion1 es True
    instruccion1
elif condicion2:
    # Código si condicion2 es True
    instruccion2
elif condicion3:
    # Código si condicion3 es True
    instruccion3
else:
    # Código si ninguna condición es True
    instruccion4
```

**Ejemplo 3: Sistema de calificaciones**
```python
calificacion = 85

if calificacion >= 90:
    print("Excelente - A")
elif calificacion >= 80:
    print("Muy bien - B")
elif calificacion >= 70:
    print("Bien - C")
elif calificacion >= 60:
    print("Suficiente - D")
else:
    print("Reprobado - F")
```

**Salida:**
```
Muy bien - B
```

### 2.4 Condicionales anidados

Los condicionales pueden contener otros condicionales dentro de ellos.

**Ejemplo 4: Verificar acceso con múltiples condiciones**
```python
tiene_ticket = True
edad = 16

if tiene_ticket:
    if edad >= 18:
        print("Acceso permitido al evento")
    else:
        print("Tienes ticket pero eres menor de edad")
        print("Necesitas un adulto acompañante")
else:
    print("Necesitas un ticket para entrar")
```

**Salida:**
```
Tienes ticket pero eres menor de edad
Necesitas un adulto acompañante
```

---

## 3. Operadores de Comparación

Los operadores de comparación se utilizan para comparar valores y devuelven un valor booleano (`True` o `False`).

### Tabla de Operadores de Comparación

| Operador | Descripción | Ejemplo | Resultado |
|----------|-------------|---------|-----------|
| `==` | Igual a | `5 == 5` | `True` |
| `!=` | Diferente de | `5 != 3` | `True` |
| `>` | Mayor que | `5 > 3` | `True` |
| `<` | Menor que | `3 < 5` | `True` |
| `>=` | Mayor o igual que | `5 >= 5` | `True` |
| `<=` | Menor o igual que | `3 <= 5` | `True` |

**Ejemplo 5: Uso de operadores de comparación**
```python
x = 10
y = 20

print(f"x == y: {x == y}")  # False
print(f"x != y: {x != y}")  # True
print(f"x > y: {x > y}")    # False
print(f"x < y: {x < y}")    # True
print(f"x >= 10: {x >= 10}")  # True
print(f"y <= 20: {y <= 20}")  # True
```

### Comparación de cadenas

En Python, las cadenas se pueden comparar usando los mismos operadores.

**Ejemplo 6: Comparación de strings**
```python
nombre1 = "Ana"
nombre2 = "Carlos"

if nombre1 == nombre2:
    print("Los nombres son iguales")
else:
    print("Los nombres son diferentes")

# Comparación alfabética
if nombre1 < nombre2:
    print(f"{nombre1} viene antes que {nombre2} alfabéticamente")
```

**Salida:**
```
Los nombres son diferentes
Ana viene antes que Carlos alfabéticamente
```

---

## 4. Operadores Lógicos

Los operadores lógicos permiten combinar múltiples condiciones.

### Tipos de Operadores Lógicos

| Operador | Descripción | Ejemplo | Resultado |
|----------|-------------|---------|-----------|
| `and` | Verdadero si ambas condiciones son verdaderas | `True and False` | `False` |
| `or` | Verdadero si al menos una condición es verdadera | `True or False` | `True` |
| `not` | Invierte el valor booleano | `not True` | `False` |

### 4.1 Operador AND

Devuelve `True` solo si todas las condiciones son verdaderas.

**Tabla de verdad AND:**
| A | B | A and B |
|---|---|---------|
| True | True | True |
| True | False | False |
| False | True | False |
| False | False | False |

**Ejemplo 7: Verificar rango de edad**
```python
edad = 25

if edad >= 18 and edad <= 65:
    print("Edad dentro del rango laboral")
else:
    print("Edad fuera del rango laboral")
```

### 4.2 Operador OR

Devuelve `True` si al menos una condición es verdadera.

**Tabla de verdad OR:**
| A | B | A or B |
|---|---|--------|
| True | True | True |
| True | False | True |
| False | True | True |
| False | False | False |

**Ejemplo 8: Día de descanso**
```python
dia = "Sábado"

if dia == "Sábado" or dia == "Domingo":
    print("Es fin de semana - Día de descanso")
else:
    print("Es día laboral")
```

### 4.3 Operador NOT

Invierte el valor booleano de una expresión.

**Ejemplo 9: Verificar si NO es adulto**
```python
edad = 15
es_adulto = edad >= 18

if not es_adulto:
    print("No es adulto, requiere supervisión")
else:
    print("Es adulto")
```

### 4.4 Combinación de operadores lógicos

**Ejemplo 10: Sistema de acceso con múltiples condiciones**
```python
usuario = "admin"
password = "1234"
intentos = 2

if (usuario == "admin" and password == "1234") and intentos < 3:
    print("Acceso concedido")
elif intentos >= 3:
    print("Cuenta bloqueada por múltiples intentos fallidos")
else:
    print("Usuario o contraseña incorrectos")
```

---

## 5. Expresiones Booleanas Avanzadas

### 5.1 Operadores de pertenencia (in, not in)

Verifican si un valor está presente en una secuencia.

**Ejemplo 11: Verificar pertenencia**
```python
frutas = ["manzana", "pera", "uva", "naranja"]
fruta_buscada = "pera"

if fruta_buscada in frutas:
    print(f"{fruta_buscada} está en la lista")
else:
    print(f"{fruta_buscada} no está en la lista")

# Verificar que NO está en la lista
fruta_nueva = "sandía"
if fruta_nueva not in frutas:
    print(f"{fruta_nueva} es una fruta nueva en el inventario")
```

### 5.2 Operadores de identidad (is, is not)

Verifican si dos variables referencian al mismo objeto en memoria.

**Ejemplo 12: Diferencia entre == e is**
```python
lista1 = [1, 2, 3]
lista2 = [1, 2, 3]
lista3 = lista1

# Comparación de valores
print(f"lista1 == lista2: {lista1 == lista2}")  # True (mismo contenido)

# Comparación de identidad
print(f"lista1 is lista2: {lista1 is lista2}")  # False (objetos diferentes)
print(f"lista1 is lista3: {lista1 is lista3}")  # True (mismo objeto)

# Uso común con None
valor = None
if valor is None:
    print("El valor es None")
```

### 5.3 Evaluación de cortocircuito

Python evalúa expresiones lógicas de izquierda a derecha y se detiene cuando el resultado es determinado.

**Ejemplo 13: Cortocircuito en operadores lógicos**
```python
def funcion_costosa():
    print("Esta función se ejecuta")
    return True

# Con AND: si la primera es False, no evalúa la segunda
x = 5
if x > 10 and funcion_costosa():
    print("Ambas condiciones son verdaderas")
else:
    print("Al menos una condición es falsa")
# No se imprime "Esta función se ejecuta" porque x > 10 es False

# Con OR: si la primera es True, no evalúa la segunda
if x < 10 or funcion_costosa():
    print("Al menos una condición es verdadera")
# No se imprime "Esta función se ejecuta" porque x < 10 ya es True
```

### 5.4 Expresiones ternarias (operador condicional)

Python permite escribir condicionales simples en una sola línea.

**Sintaxis:**
```python
valor_si_true if condicion else valor_si_false
```

**Ejemplo 14: Operador ternario**
```python
edad = 20
mensaje = "Mayor de edad" if edad >= 18 else "Menor de edad"
print(mensaje)

# Ejemplo con cálculo
numero = 15
resultado = "Par" if numero % 2 == 0 else "Impar"
print(f"{numero} es {resultado}")

# Equivalente con if-else tradicional
if numero % 2 == 0:
    resultado = "Par"
else:
    resultado = "Impar"
```

### 5.5 Valores "Truthy" y "Falsy"

En Python, algunos valores se evalúan como `False` en un contexto booleano:
- `False`, `None`
- `0`, `0.0`
- Secuencias vacías: `""`, `[]`, `()`, `{}`

**Ejemplo 15: Valores truthy y falsy**
```python
# Lista vacía
lista = []
if lista:
    print("La lista tiene elementos")
else:
    print("La lista está vacía")

# String vacío
nombre = ""
if not nombre:
    print("El nombre está vacío")

# Número cero
contador = 0
if contador:
    print(f"Contador: {contador}")
else:
    print("El contador está en cero")

# Valores truthy
texto = "Hola"
if texto:
    print("El texto tiene contenido")
```

---

## 6. Comparación entre C y Python

### 6.1 Sintaxis de condicionales

**En C:**
```c
int edad = 18;

if (edad >= 18) {
    printf("Mayor de edad\n");
} else {
    printf("Menor de edad\n");
}
```

**En Python:**
```python
edad = 18

if edad >= 18:
    print("Mayor de edad")
else:
    print("Menor de edad")
```

### 6.2 Diferencias principales

| Aspecto | C | Python |
|---------|---|--------|
| Paréntesis | Obligatorios en condiciones | Opcionales |
| Llaves | Obligatorias para bloques | No se usan |
| Indentación | Opcional (se usa para legibilidad) | Obligatoria |
| Operadores lógicos | `&&`, `||`, `!` | `and`, `or`, `not` |
| Switch/Case | Existe (switch-case) | No existe (usar if-elif) |
| Valores booleanos | `0` (false), `1` (true) | `True`, `False` |

### 6.3 Equivalencia de operadores lógicos

**En C:**
```c
int x = 5, y = 10;

// AND
if (x > 0 && y > 0) {
    printf("Ambos son positivos\n");
}

// OR
if (x > 15 || y > 5) {
    printf("Al menos uno cumple\n");
}

// NOT
if (!(x > 10)) {
    printf("x no es mayor que 10\n");
}
```

**En Python:**
```python
x = 5
y = 10

# AND
if x > 0 and y > 0:
    print("Ambos son positivos")

# OR
if x > 15 or y > 5:
    print("Al menos uno cumple")

# NOT
if not (x > 10):
    print("x no es mayor que 10")
```

### 6.4 Switch-case vs if-elif

**En C (Switch-case):**
```c
int opcion = 2;

switch(opcion) {
    case 1:
        printf("Opción 1\n");
        break;
    case 2:
        printf("Opción 2\n");
        break;
    case 3:
        printf("Opción 3\n");
        break;
    default:
        printf("Opción no válida\n");
}
```

**En Python (if-elif):**
```python
opcion = 2

if opcion == 1:
    print("Opción 1")
elif opcion == 2:
    print("Opción 2")
elif opcion == 3:
    print("Opción 3")
else:
    print("Opción no válida")
```

**Python 3.10+ (match-case):**
```python
opcion = 2

match opcion:
    case 1:
        print("Opción 1")
    case 2:
        print("Opción 2")
    case 3:
        print("Opción 3")
    case _:
        print("Opción no válida")
```

---

## 7. Ejercicios Prácticos

### Ejercicio 1: Calculadora de IMC
Crea un programa que calcule el Índice de Masa Corporal y clasifique el resultado.

```python
# Solicitar datos
peso = float(input("Ingresa tu peso en kg: "))
altura = float(input("Ingresa tu altura en metros: "))

# Calcular IMC
imc = peso / (altura ** 2)

# Clasificación
print(f"\nTu IMC es: {imc:.2f}")

if imc < 18.5:
    print("Clasificación: Bajo peso")
elif imc >= 18.5 and imc < 25:
    print("Clasificación: Peso normal")
elif imc >= 25 and imc < 30:
    print("Clasificación: Sobrepeso")
else:
    print("Clasificación: Obesidad")
```

### Ejercicio 2: Validador de contraseñas
Crea un validador que verifique si una contraseña cumple con ciertos requisitos.

```python
password = input("Ingresa una contraseña: ")

# Requisitos
tiene_mayuscula = any(c.isupper() for c in password)
tiene_minuscula = any(c.islower() for c in password)
tiene_numero = any(c.isdigit() for c in password)
longitud_valida = len(password) >= 8

# Validación
if tiene_mayuscula and tiene_minuscula and tiene_numero and longitud_valida:
    print("✓ Contraseña válida y segura")
else:
    print("✗ Contraseña débil. Debe cumplir:")
    if not longitud_valida:
        print("  - Mínimo 8 caracteres")
    if not tiene_mayuscula:
        print("  - Al menos una letra mayúscula")
    if not tiene_minuscula:
        print("  - Al menos una letra minúscula")
    if not tiene_numero:
        print("  - Al menos un número")
```

### Ejercicio 3: Sistema de descuentos
Implementa un sistema que calcule descuentos según el monto de compra y membresía.

```python
total_compra = float(input("Ingresa el total de la compra: $"))
es_miembro = input("¿Eres miembro? (si/no): ").lower() == "si"

descuento = 0

# Descuento por monto
if total_compra >= 1000:
    descuento = 0.15  # 15%
elif total_compra >= 500:
    descuento = 0.10  # 10%
elif total_compra >= 200:
    descuento = 0.05  # 5%

# Descuento adicional para miembros
if es_miembro:
    descuento += 0.05  # 5% adicional

# Cálculo final
monto_descuento = total_compra * descuento
total_final = total_compra - monto_descuento

print(f"\nResumen de compra:")
print(f"Subtotal: ${total_compra:.2f}")
print(f"Descuento ({descuento*100:.0f}%): ${monto_descuento:.2f}")
print(f"Total a pagar: ${total_final:.2f}")
```

### Ejercicio 4: Determinador de estación del año
Determina la estación del año según el mes.

```python
mes = input("Ingresa el mes (nombre o número): ").lower()

# Convertir número a nombre si es necesario
meses_numero = {
    "1": "enero", "2": "febrero", "3": "marzo", "4": "abril",
    "5": "mayo", "6": "junio", "7": "julio", "8": "agosto",
    "9": "septiembre", "10": "octubre", "11": "noviembre", "12": "diciembre"
}

if mes in meses_numero:
    mes = meses_numero[mes]

# Determinar estación (hemisferio norte)
if mes in ["diciembre", "enero", "febrero"]:
    estacion = "Invierno"
elif mes in ["marzo", "abril", "mayo"]:
    estacion = "Primavera"
elif mes in ["junio", "julio", "agosto"]:
    estacion = "Verano"
elif mes in ["septiembre", "octubre", "noviembre"]:
    estacion = "Otoño"
else:
    estacion = "Mes no válido"

print(f"La estación es: {estacion}")
```

### Ejercicio 5: Juego de adivinanza
Crea un juego simple de adivinanza de números.

```python
import random

# Generar número secreto
numero_secreto = random.randint(1, 100)
intentos = 0
max_intentos = 7

print("¡Juego de adivinanza!")
print(f"Adivina el número entre 1 y 100. Tienes {max_intentos} intentos.")

while intentos < max_intentos:
    intento = int(input(f"\nIntento {intentos + 1}/{max_intentos}: "))
    intentos += 1
    
    if intento == numero_secreto:
        print(f"¡Felicidades! Adivinaste en {intentos} intentos.")
        break
    elif intento < numero_secreto:
        print("El número es mayor")
        if numero_secreto - intento > 20:
            print("Estás muy lejos")
    else:
        print("El número es menor")
        if intento - numero_secreto > 20:
            print("Estás muy lejos")
    
    if intentos == max_intentos:
        print(f"\nGame Over. El número era {numero_secreto}")
```

---

## 📝 Resumen de Conceptos Clave

1. **Estructura if-elif-else**: Permite ejecutar diferentes bloques de código según condiciones
2. **Operadores de comparación**: `==`, `!=`, `>`, `<`, `>=`, `<=`
3. **Operadores lógicos**: `and`, `or`, `not`
4. **Operadores de pertenencia**: `in`, `not in`
5. **Operadores de identidad**: `is`, `is not`
6. **Expresión ternaria**: Forma compacta de escribir condicionales simples
7. **Valores truthy/falsy**: Valores que se evalúan como True o False en contextos booleanos

---

## 🎯 Tareas para Practicar

1. **Calculadora básica**: Crea una calculadora que solicite dos números y una operación (+, -, *, /) y muestre el resultado usando condicionales.

2. **Conversor de temperatura**: Programa que convierta entre Celsius, Fahrenheit y Kelvin según la opción del usuario.

3. **Verificador de año bisiesto**: Determina si un año es bisiesto usando las reglas apropiadas.

4. **Sistema de login simple**: Crea un sistema que valide usuario y contraseña con un máximo de 3 intentos.

5. **Clasificador de triángulos**: Dados tres lados, determina si forman un triángulo válido y clasifícalo (equilátero, isósceles, escaleno).

---

## 📚 Recursos Adicionales

- Documentación oficial de Python sobre estructuras de control
- PEP 8: Guía de estilo para código Python
- Python Tutor: Visualizador de ejecución de código paso a paso

---

## Próxima Clase

En la **Clase 14** aprenderemos sobre:
- Bucles `for` y `while` en Python
- Función `range()` y sus aplicaciones
- List comprehensions básicas
- Iteración sobre diferentes tipos de datos

¡Practica los ejercicios y nos vemos en la próxima clase!