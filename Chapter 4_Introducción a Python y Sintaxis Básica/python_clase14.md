# Clase 14: Bucles e Iteración en Python
**Curso de Programación en Python - Semana 7**  
**Duración: 2 horas**

---

## Objetivos de Aprendizaje

Al finalizar esta clase, serás capaz de:
- Implementar bucles `for` y `while` en Python
- Utilizar la función `range()` de manera efectiva
- Crear list comprehensions para código más eficiente
- Iterar sobre diferentes tipos de datos (listas, tuplas, diccionarios, strings)
- Aplicar técnicas de iteración en problemas reales

---

## 1. Bucle While en Python

### 1.1 Sintaxis Básica

El bucle `while` ejecuta un bloque de código mientras una condición sea verdadera.

```python
# Sintaxis básica
while condicion:
    # código a ejecutar
    # importante: modificar la condición eventualmente
```

### 1.2 Ejemplos Básicos

```python
# Ejemplo 1: Contador simple
contador = 0
while contador < 5:
    print(f"Contador: {contador}")
    contador += 1

# Salida:
# Contador: 0
# Contador: 1
# Contador: 2
# Contador: 3
# Contador: 4
```

```python
# Ejemplo 2: Suma acumulativa
suma = 0
numero = 1
while numero <= 10:
    suma += numero
    numero += 1
print(f"La suma de 1 a 10 es: {suma}")  # 55
```

```python
# Ejemplo 3: Validación de entrada
password = ""
while password != "python123":
    password = input("Ingresa la contraseña: ")
    if password != "python123":
        print("Contraseña incorrecta. Intenta de nuevo.")
print("¡Acceso concedido!")
```

### 1.3 Control de Bucles: break y continue

```python
# break: Sale del bucle inmediatamente
contador = 0
while True:  # Bucle infinito intencional
    print(contador)
    contador += 1
    if contador >= 5:
        break  # Sale del bucle

# continue: Salta a la siguiente iteración
numero = 0
while numero < 10:
    numero += 1
    if numero % 2 == 0:
        continue  # Salta los números pares
    print(numero)  # Solo imprime impares
```

### 1.4 Bucles While con else

```python
# El bloque else se ejecuta si el bucle termina normalmente
# (no por un break)
intentos = 0
max_intentos = 3

while intentos < max_intentos:
    respuesta = input("¿Cuál es la capital de Francia? ")
    if respuesta.lower() == "paris" or respuesta.lower() == "parís":
        print("¡Correcto!")
        break
    intentos += 1
    print(f"Incorrecto. Te quedan {max_intentos - intentos} intentos.")
else:
    print("Se acabaron los intentos. La respuesta era París.")
```

---

## 2. Bucle For en Python

### 2.1 Sintaxis y Conceptos

El bucle `for` en Python es más poderoso que en C. Itera sobre cualquier secuencia (lista, tupla, string, etc.).

```python
# Sintaxis básica
for variable in secuencia:
    # código a ejecutar
```

### 2.2 Ejemplos con Diferentes Tipos de Datos

```python
# Ejemplo 1: Iterar sobre una lista
frutas = ["manzana", "banana", "naranja", "uva"]
for fruta in frutas:
    print(f"Me gusta la {fruta}")

# Ejemplo 2: Iterar sobre un string
palabra = "Python"
for letra in palabra:
    print(letra)

# Ejemplo 3: Iterar sobre una tupla
coordenadas = (10, 20, 30)
for valor in coordenadas:
    print(f"Coordenada: {valor}")
```

### 2.3 Iterar con Índices: enumerate()

```python
# enumerate() proporciona índice y valor
lenguajes = ["Python", "Java", "C++", "JavaScript"]

for indice, lenguaje in enumerate(lenguajes):
    print(f"{indice + 1}. {lenguaje}")

# Con índice inicial personalizado
for indice, lenguaje in enumerate(lenguajes, start=1):
    print(f"{indice}. {lenguaje}")
```

### 2.4 Iterar sobre Múltiples Secuencias: zip()

```python
# zip() combina múltiples secuencias
nombres = ["Ana", "Luis", "María"]
edades = [25, 30, 28]
ciudades = ["Madrid", "Barcelona", "Valencia"]

for nombre, edad, ciudad in zip(nombres, edades, ciudades):
    print(f"{nombre} tiene {edad} años y vive en {ciudad}")
```

---

## 3. Función range()

### 3.1 Formas de Usar range()

```python
# range(stop) - del 0 hasta stop-1
for i in range(5):
    print(i)  # 0, 1, 2, 3, 4

# range(start, stop) - de start hasta stop-1
for i in range(2, 8):
    print(i)  # 2, 3, 4, 5, 6, 7

# range(start, stop, step) - con incremento personalizado
for i in range(0, 10, 2):
    print(i)  # 0, 2, 4, 6, 8

# Rangos decrecientes
for i in range(10, 0, -1):
    print(i)  # 10, 9, 8, ..., 1
```

### 3.2 Ejemplos Prácticos

```python
# Ejemplo 1: Tabla de multiplicar
numero = 7
print(f"Tabla del {numero}:")
for i in range(1, 11):
    print(f"{numero} × {i} = {numero * i}")

# Ejemplo 2: Suma de números en un rango
suma = 0
for i in range(1, 101):
    suma += i
print(f"Suma de 1 a 100: {suma}")

# Ejemplo 3: Crear una lista con range
cuadrados = []
for i in range(1, 11):
    cuadrados.append(i ** 2)
print(cuadrados)  # [1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
```

### 3.3 Convertir range a Lista

```python
# range() es un objeto iterable, no una lista
numeros = range(5)
print(type(numeros))  # <class 'range'>

# Convertir a lista
lista_numeros = list(range(5))
print(lista_numeros)  # [0, 1, 2, 3, 4]
```

---

## 4. List Comprehensions

### 4.1 Sintaxis Básica

Las list comprehensions proporcionan una forma concisa de crear listas.

```python
# Forma tradicional
cuadrados = []
for i in range(10):
    cuadrados.append(i ** 2)

# List comprehension (más elegante)
cuadrados = [i ** 2 for i in range(10)]
print(cuadrados)  # [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
```

### 4.2 List Comprehensions con Condiciones

```python
# Solo números pares
pares = [x for x in range(20) if x % 2 == 0]
print(pares)  # [0, 2, 4, 6, 8, 10, 12, 14, 16, 18]

# Cuadrados de números impares
cuadrados_impares = [x ** 2 for x in range(10) if x % 2 != 0]
print(cuadrados_impares)  # [1, 9, 25, 49, 81]

# Filtrar palabras por longitud
palabras = ["sol", "computadora", "día", "programación", "luz"]
palabras_largas = [p for p in palabras if len(p) > 4]
print(palabras_largas)  # ['computadora', 'programación']
```

### 4.3 List Comprehensions con Transformaciones

```python
# Convertir a mayúsculas
nombres = ["ana", "luis", "maría"]
nombres_mayus = [n.upper() for n in nombres]
print(nombres_mayus)  # ['ANA', 'LUIS', 'MARÍA']

# Operaciones matemáticas
temperaturas_c = [0, 10, 20, 30, 40]
temperaturas_f = [(t * 9/5) + 32 for t in temperaturas_c]
print(temperaturas_f)  # [32.0, 50.0, 68.0, 86.0, 104.0]

# Extraer información
estudiantes = ["Ana:20", "Luis:22", "María:19"]
nombres_edad = [e.split(":")[0] for e in estudiantes]
print(nombres_edad)  # ['Ana', 'Luis', 'María']
```

### 4.4 List Comprehensions Anidadas

```python
# Crear una matriz
matriz = [[i + j for j in range(3)] for i in range(3)]
print(matriz)  # [[0, 1, 2], [1, 2, 3], [2, 3, 4]]

# Aplanar una lista anidada
lista_anidada = [[1, 2, 3], [4, 5], [6, 7, 8]]
aplanada = [num for sublista in lista_anidada for num in sublista]
print(aplanada)  # [1, 2, 3, 4, 5, 6, 7, 8]
```

---

## 5. Iteración sobre Diferentes Tipos de Datos

### 5.1 Iteración sobre Diccionarios

```python
# Diccionario de ejemplo
estudiante = {
    "nombre": "Ana García",
    "edad": 20,
    "carrera": "Ingeniería",
    "promedio": 9.2
}

# Iterar sobre las claves
print("Claves:")
for clave in estudiante:
    print(clave)

# Iterar sobre los valores
print("\nValores:")
for valor in estudiante.values():
    print(valor)

# Iterar sobre pares clave-valor
print("\nPares clave-valor:")
for clave, valor in estudiante.items():
    print(f"{clave}: {valor}")
```

### 5.2 Iteración sobre Sets

```python
# Los sets no tienen orden garantizado
colores = {"rojo", "azul", "verde", "amarillo"}

for color in colores:
    print(color)

# List comprehension con sets
colores_mayus = {c.upper() for c in colores}
print(colores_mayus)  # Set comprehension
```

### 5.3 Iteración sobre Strings

```python
# Contar vocales
texto = "Python es un lenguaje poderoso"
vocales = "aeiouAEIOU"
contador = 0

for letra in texto:
    if letra in vocales:
        contador += 1
print(f"Número de vocales: {contador}")

# Crear lista de caracteres
caracteres = [c for c in texto if c.isalpha()]
print(caracteres)
```

### 5.4 Iteración sobre Archivos

```python
# Iterar sobre líneas de un archivo (ejemplo conceptual)
# with open("datos.txt", "r") as archivo:
#     for linea in archivo:
#         print(linea.strip())

# Simulación con lista de líneas
lineas = ["Primera línea", "Segunda línea", "Tercera línea"]
for numero, linea in enumerate(lineas, start=1):
    print(f"Línea {numero}: {linea}")
```

---

## 6. Patrones Comunes de Iteración

### 6.1 Acumuladores

```python
# Suma acumulativa
numeros = [10, 20, 30, 40, 50]
total = 0
for num in numeros:
    total += num
print(f"Total: {total}")

# Producto acumulativo
producto = 1
for num in range(1, 6):
    producto *= num
print(f"Factorial de 5: {producto}")
```

### 6.2 Contadores

```python
# Contar elementos que cumplen una condición
edades = [17, 22, 15, 30, 18, 25, 16, 40]
mayores_edad = 0

for edad in edades:
    if edad >= 18:
        mayores_edad += 1
print(f"Personas mayores de edad: {mayores_edad}")
```

### 6.3 Búsqueda en Secuencias

```python
# Buscar elemento
nombres = ["Ana", "Luis", "María", "Carlos", "Elena"]
buscar = "María"
encontrado = False

for nombre in nombres:
    if nombre == buscar:
        encontrado = True
        break

if encontrado:
    print(f"{buscar} está en la lista")
else:
    print(f"{buscar} no está en la lista")

# Forma pythonica (más simple)
if buscar in nombres:
    print(f"{buscar} está en la lista")
```

### 6.4 Encontrar Máximo y Mínimo

```python
# Sin usar funciones built-in
numeros = [45, 23, 67, 12, 89, 34, 56]

maximo = numeros[0]
minimo = numeros[0]

for num in numeros:
    if num > maximo:
        maximo = num
    if num < minimo:
        minimo = num

print(f"Máximo: {maximo}, Mínimo: {minimo}")
```

---

## 7. Comparación Python vs C

### 7.1 Bucle For

**En C:**
```c
// C: Bucle for tradicional
for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
}
```

**En Python:**
```python
# Python: Más simple y legible
for i in range(10):
    print(i)
```

### 7.2 Bucle While

**En C:**
```c
// C: While loop
int i = 0;
while (i < 10) {
    printf("%d\n", i);
    i++;
}
```

**En Python:**
```python
# Python: Similar sintaxis
i = 0
while i < 10:
    print(i)
    i += 1
```

### 7.3 Iteración sobre Arrays

**En C:**
```c
// C: Iteración sobre array
int arr[] = {1, 2, 3, 4, 5};
int size = sizeof(arr) / sizeof(arr[0]);

for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
}
```

**En Python:**
```python
# Python: Mucho más simple
arr = [1, 2, 3, 4, 5]
for elemento in arr:
    print(elemento)
```

---

## 8. Ejercicios en Clase

### Ejercicio 1: Calculadora de Promedio
```python
# Pedir números hasta que el usuario ingrese 'fin'
# Calcular y mostrar el promedio

numeros = []
while True:
    entrada = input("Ingresa un número (o 'fin' para terminar): ")
    if entrada.lower() == 'fin':
        break
    try:
        numero = float(entrada)
        numeros.append(numero)
    except ValueError:
        print("Entrada inválida. Intenta de nuevo.")

if numeros:
    promedio = sum(numeros) / len(numeros)
    print(f"Promedio: {promedio:.2f}")
else:
    print("No se ingresaron números.")
```

### Ejercicio 2: Tabla de Multiplicar Múltiple
```python
# Crear tablas de multiplicar del 1 al 10
for tabla in range(1, 11):
    print(f"\nTabla del {tabla}:")
    for i in range(1, 11):
        print(f"{tabla} × {i} = {tabla * i}")
```

### Ejercicio 3: Filtrado de Lista
```python
# Filtrar números de una lista según condiciones
numeros = [12, 7, 23, 45, 8, 16, 34, 9, 50, 18]

# Números mayores a 15
mayores = [n for n in numeros if n > 15]
print(f"Mayores a 15: {mayores}")

# Múltiplos de 3
multiplos_3 = [n for n in numeros if n % 3 == 0]
print(f"Múltiplos de 3: {multiplos_3}")
```

---

## 9. Ejercicios de Tarea

### Ejercicio 1: Serie de Fibonacci
Escribe un programa que genere los primeros N números de la serie de Fibonacci usando un bucle while.

**Entrada esperada:** N = 10  
**Salida esperada:** [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]

### Ejercicio 2: Contador de Palabras
Crea un programa que cuente cuántas veces aparece cada palabra en una frase usando diccionarios y bucles.

**Entrada:** "python es genial python es poderoso python es fácil"  
**Salida:** {'python': 3, 'es': 3, 'genial': 1, 'poderoso': 1, 'fácil': 1}

### Ejercicio 3: Validador de Contraseña
Implementa un validador de contraseña que verifique:
- Longitud mínima de 8 caracteres
- Al menos una letra mayúscula
- Al menos un número
- Al menos un carácter especial (@, #, $, %)

### Ejercicio 4: Números Primos
Escribe un programa que encuentre todos los números primos entre 1 y 100 usando list comprehension y una función auxiliar.

### Ejercicio 5: Procesamiento de Calificaciones
Dada una lista de calificaciones, calcula:
- El promedio general
- Cuántos estudiantes aprobaron (>= 6)
- Cuántos reprobaron (< 6)
- La calificación más alta y más baja

```python
calificaciones = [8.5, 5.2, 9.0, 7.8, 4.5, 10.0, 6.5, 3.8, 8.0, 7.0]
```

### Ejercicio 6: Generador de Patrones
Crea un programa que genere el siguiente patrón usando bucles anidados:
```
*
**
***
****
*****
```

### Ejercicio 7: Conversión de Temperaturas
Crea una tabla de conversión de Celsius a Fahrenheit para temperaturas de -10°C a 40°C con incrementos de 5°C, usando list comprehension.

### Ejercicio 8: Análisis de Texto
Escribe un programa que analice un texto y determine:
- Número total de caracteres (sin espacios)
- Número de palabras
- Número de vocales y consonantes
- Palabra más larga

---

## 10. Proyecto Final: Sistema de Gestión de Estudiantes

### Descripción del Proyecto

Crea un sistema de gestión de estudiantes que permita:
1. Agregar estudiantes con su nombre y calificaciones
2. Mostrar todos los estudiantes
3. Calcular el promedio de cada estudiante
4. Encontrar al estudiante con mejor promedio
5. Filtrar estudiantes por estado (aprobado/reprobado)
6. Buscar estudiante por nombre

### Especificaciones Técnicas

```python
# Estructura de datos sugerida
estudiantes = []

# Cada estudiante es un diccionario:
# {
#     "nombre": "Ana García",
#     "calificaciones": [9.0, 8.5, 9.5, 8.0]
# }

# Funciones requeridas:
def agregar_estudiante(nombre, calificaciones):
    """Agrega un estudiante al sistema"""
    pass

def mostrar_estudiantes():
    """Muestra todos los estudiantes con sus datos"""
    pass

def calcular_promedio(calificaciones):
    """Calcula el promedio de una lista de calificaciones"""
    pass

def mejor_estudiante():
    """Encuentra al estudiante con mejor promedio"""
    pass

def filtrar_por_estado(estado):
    """Filtra estudiantes por 'aprobado' o 'reprobado' (promedio >= 6)"""
    pass

def buscar_estudiante(nombre):
    """Busca un estudiante por nombre"""
    pass
```

### Requisitos del Proyecto

1. **Uso obligatorio de:**
   - Bucles `for` y `while`
   - List comprehensions
   - Diccionarios para almacenar datos
   - Función `range()` donde sea apropiado

2. **Interfaz de usuario:**
   - Menú interactivo con opciones numeradas
   - Validación de entrada del usuario
   - Mensajes claros y descriptivos

3. **Funcionalidades adicionales (opcional):**
   - Eliminar estudiante
   - Modificar calificaciones
   - Exportar datos a formato texto
   - Estadísticas generales del grupo

### Ejemplo de Ejecución

```
=== SISTEMA DE GESTIÓN DE ESTUDIANTES ===
1. Agregar estudiante
2. Mostrar todos los estudiantes
3. Buscar estudiante
4. Mejor estudiante
5. Filtrar por estado
6. Salir

Selecciona una opción: 1
Nombre del estudiante: Ana García
Número de calificaciones: 4
Calificación 1: 9.0
Calificación 2: 8.5
Calificación 3: 9.5
Calificación 4: 8.0
¡Estudiante agregado exitosamente!

Selecciona una opción: 2

=== LISTA DE ESTUDIANTES ===
1. Ana García
   Calificaciones: [9.0, 8.5, 9.5, 8.0]
   Promedio: 8.75
   Estado: APROBADO
```

### Criterios de Evaluación

- **Funcionalidad (40%):** Todas las funciones trabajan correctamente
- **Uso de conceptos (30%):** Implementación adecuada de bucles, list comprehensions y estructuras de datos
- **Código limpio (20%):** Código legible, bien organizado y con buenos nombres de variables
- **Interfaz de usuario (10%):** Menú intuitivo y manejo de errores

---

## 11. Recursos Adicionales

### Documentación Oficial
- [Python For Loops](https://docs.python.org/3/tutorial/controlflow.html#for-statements)
- [Python While Loops](https://docs.python.org/3/reference/compound_stmts.html#while)
- [List Comprehensions](https://docs.python.org/3/tutorial/datastructures.html#list-comprehensions)

### Consejos de Buenas Prácticas

1. **Evita bucles infinitos accidentales:** Asegúrate de que la condición del while eventualmente sea falsa
2. **Usa for cuando sepas cuántas iteraciones necesitas**
3. **Usa while cuando dependas de una condición que cambia dinámicamente**
4. **List comprehensions son más rápidas pero menos legibles en casos complejos**
5. **Siempre valida la entrada del usuario en bucles interactivos**

### Errores Comunes a Evitar

```python
# ❌ Modificar lista mientras iteras sobre ella
numeros = [1, 2, 3, 4, 5]
for num in numeros:
    if num % 2 == 0:
        numeros.remove(num)  # ¡Error!

# ✅ Crea una nueva lista
numeros = [1, 2, 3, 4, 5]
impares = [num for num in numeros if num % 2 != 0]

# ❌ Range equivocado
for i in range(len(lista)):
    print(lista[i])  # Innecesariamente complejo

# ✅ Itera directamente
for elemento in lista:
    print(elemento)
```

---

## 12. Resumen de la Clase

**Conceptos clave aprendidos:**
- Bucles `while` y `for` en Python
- Uso de `break` y `continue` para control de flujo
- Función `range()` con diferentes parámetros
- List comprehensions para código conciso
- Iteración sobre listas, tuplas, diccionarios, sets y strings
- Patrones comunes: acumuladores, contadores, búsquedas
- Diferencias entre Python y C en estructuras de control

**Próxima clase:** Funciones en Python y modularización de código

---

## Preguntas de Reflexión

1. ¿Cuándo es preferible usar `while` sobre `for`?
2. ¿Qué ventajas tienen las list comprehensions sobre bucles tradicionales?
3. ¿Cómo se puede evitar un bucle infinito en `while`?
4. ¿En qué situaciones usarías `enumerate()` o `zip()`?
5. ¿Cuál es la diferencia entre `break` y `continue`?

**¡Mucho éxito con los ejercicios y el proyecto!**