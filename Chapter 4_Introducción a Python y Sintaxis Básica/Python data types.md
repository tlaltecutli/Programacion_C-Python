# Guía Completa de Tipos de Datos en Python

## Introducción

Python es un lenguaje de tipado dinámico, lo que significa que no necesitas declarar explícitamente el tipo de una variable. Python infiere automáticamente el tipo basándose en el valor asignado. Esta guía cubre todos los tipos de datos fundamentales en Python.

---

## 1. Tipos Numéricos

### 1.1 Enteros (int)

Los enteros son números sin parte decimal. En Python 3, no hay límite en el tamaño de los enteros (excepto la memoria disponible).

**Características:**
- Sin punto decimal
- Pueden ser positivos, negativos o cero
- Soportan notación decimal, binaria, octal y hexadecimal

**Ejemplos:**

```python
# Enteros básicos
edad = 25
temperatura = -10
cero = 0

# Números grandes
poblacion_mundial = 7800000000
numero_enorme = 999999999999999999999999999999

# Diferentes bases numéricas
binario = 0b1010        # 10 en decimal
octal = 0o12            # 10 en decimal
hexadecimal = 0xA       # 10 en decimal

# Operaciones
suma = 10 + 5           # 15
resta = 10 - 5          # 5
multiplicacion = 10 * 5 # 50
division_entera = 10 // 3  # 3
modulo = 10 % 3         # 1
potencia = 2 ** 3       # 8

print(type(edad))       # <class 'int'>
```

### 1.2 Flotantes (float)

Los números de punto flotante representan números reales con parte decimal.

**Características:**
- Usan punto decimal o notación científica
- Precisión limitada (aproximadamente 15-17 dígitos decimales)
- Pueden producir errores de redondeo

**Ejemplos:**

```python
# Flotantes básicos
altura = 1.75
temperatura = -273.15
pi = 3.14159265359

# Notación científica
velocidad_luz = 3e8      # 300000000.0
muy_pequeño = 1.5e-10    # 0.00000000015

# Operaciones
suma = 10.5 + 3.2        # 13.7
division = 10 / 3        # 3.3333333333333335

# Conversiones
de_int = float(10)       # 10.0
de_string = float("3.14") # 3.14

# Valores especiales
infinito = float('inf')
menos_infinito = float('-inf')
no_numero = float('nan')

print(type(altura))      # <class 'float'>
```

### 1.3 Números Complejos (complex)

Representan números complejos con parte real e imaginaria.

**Características:**
- Formato: `a + bj` donde `a` es la parte real y `b` la imaginaria
- `j` representa la unidad imaginaria (√-1)

**Ejemplos:**

```python
# Números complejos
z1 = 3 + 4j
z2 = complex(2, 5)       # 2 + 5j
z3 = 1j                  # 0 + 1j

# Acceder a partes
print(z1.real)           # 3.0
print(z1.imag)           # 4.0

# Operaciones
suma = z1 + z2           # (5+9j)
multiplicacion = z1 * z2 # (-14+23j)
conjugado = z1.conjugate() # (3-4j)

# Módulo (valor absoluto)
modulo = abs(z1)         # 5.0

print(type(z1))          # <class 'complex'>
```

---

## 2. Tipos de Secuencia

### 2.1 Cadenas de Texto (str)

Las cadenas son secuencias inmutables de caracteres Unicode.

**Características:**
- Inmutables (no se pueden modificar después de crear)
- Pueden usar comillas simples, dobles o triples
- Soportan indexación y slicing

**Ejemplos:**

```python
# Diferentes formas de crear strings
nombre = 'María'
apellido = "González"
parrafo = """Este es un
texto de múltiples
líneas"""

# Strings con caracteres especiales
con_comillas = "Ella dijo: 'Hola'"
con_escape = 'Línea 1\nLínea 2\tTabulado'
ruta_raw = r'C:\nueva\carpeta'  # raw string

# Concatenación
nombre_completo = nombre + " " + apellido
repeticion = "Hola " * 3        # "Hola Hola Hola "

# Indexación y slicing
mensaje = "Python"
print(mensaje[0])                # 'P'
print(mensaje[-1])               # 'n'
print(mensaje[0:3])              # 'Pyt'
print(mensaje[::2])              # 'Pto'
print(mensaje[::-1])             # 'nohtyP' (reversa)

# Métodos comunes
texto = "  Hola Mundo  "
print(texto.upper())             # "  HOLA MUNDO  "
print(texto.lower())             # "  hola mundo  "
print(texto.strip())             # "Hola Mundo"
print(texto.replace("Mundo", "Python"))  # "  Hola Python  "
print(texto.split())             # ['Hola', 'Mundo']

# Verificaciones
print("Hola".startswith("H"))    # True
print("Hola".endswith("a"))      # True
print("123".isdigit())           # True
print("abc".isalpha())           # True

# Formateo
edad = 30
# f-strings (Python 3.6+)
mensaje = f"Tengo {edad} años"
# format()
mensaje = "Tengo {} años".format(edad)
# % (antiguo)
mensaje = "Tengo %d años" % edad

print(type(nombre))              # <class 'str'>
```

### 2.2 Listas (list)

Las listas son secuencias mutables y ordenadas que pueden contener elementos de cualquier tipo.

**Características:**
- Mutables (se pueden modificar)
- Ordenadas (mantienen el orden de inserción)
- Permiten duplicados
- Pueden contener elementos de diferentes tipos

**Ejemplos:**

```python
# Crear listas
vacia = []
numeros = [1, 2, 3, 4, 5]
mixta = [1, "dos", 3.0, True, None]
anidada = [[1, 2], [3, 4], [5, 6]]

# Indexación y slicing
frutas = ["manzana", "banana", "cereza", "durazno"]
print(frutas[0])                 # "manzana"
print(frutas[-1])                # "durazno"
print(frutas[1:3])               # ["banana", "cereza"]

# Modificación
frutas[0] = "naranja"
frutas[1:3] = ["kiwi", "mango"]

# Métodos de adición
frutas.append("uva")             # Añade al final
frutas.insert(1, "pera")         # Inserta en posición
frutas.extend(["sandía", "melón"])  # Añade múltiples

# Métodos de eliminación
frutas.remove("kiwi")            # Elimina primera ocurrencia
elemento = frutas.pop()          # Elimina y retorna el último
elemento = frutas.pop(0)         # Elimina y retorna en índice
frutas.clear()                   # Elimina todos

# Operaciones
lista1 = [1, 2, 3]
lista2 = [4, 5, 6]
concatenada = lista1 + lista2    # [1, 2, 3, 4, 5, 6]
repetida = lista1 * 2            # [1, 2, 3, 1, 2, 3]

# Métodos útiles
numeros = [3, 1, 4, 1, 5, 9, 2]
numeros.sort()                   # Ordena in-place
numeros.reverse()                # Invierte in-place
print(numeros.count(1))          # Cuenta ocurrencias
print(numeros.index(4))          # Índice de primera ocurrencia

# Comprensión de listas
cuadrados = [x**2 for x in range(10)]
pares = [x for x in range(20) if x % 2 == 0]

# Funciones útiles
print(len(numeros))              # Longitud
print(max(numeros))              # Máximo
print(min(numeros))              # Mínimo
print(sum(numeros))              # Suma

print(type(numeros))             # <class 'list'>
```

### 2.3 Tuplas (tuple)

Las tuplas son secuencias inmutables y ordenadas.

**Características:**
- Inmutables (no se pueden modificar después de crear)
- Más rápidas que las listas
- Pueden usarse como claves de diccionarios
- Útiles para datos que no deben cambiar

**Ejemplos:**

```python
# Crear tuplas
vacia = ()
un_elemento = (1,)               # Nota la coma
coordenadas = (10, 20)
mixta = (1, "dos", 3.0, True)
anidada = ((1, 2), (3, 4))

# Sin paréntesis (packing)
punto = 10, 20, 30

# Indexación y slicing (igual que listas)
dias = ("Lun", "Mar", "Mié", "Jue", "Vie")
print(dias[0])                   # "Lun"
print(dias[2:4])                 # ("Mié", "Jue")
print(dias[-1])                  # "Vie"

# Desempaquetado (unpacking)
x, y = coordenadas               # x=10, y=20
primero, *resto = dias           # primero="Lun", resto=["Mar", "Mié", "Jue", "Vie"]

# Métodos limitados (solo 2)
numeros = (1, 2, 3, 2, 4, 2)
print(numeros.count(2))          # 3
print(numeros.index(3))          # 2

# Operaciones
tupla1 = (1, 2, 3)
tupla2 = (4, 5, 6)
concatenada = tupla1 + tupla2    # (1, 2, 3, 4, 5, 6)
repetida = tupla1 * 2            # (1, 2, 3, 1, 2, 3)

# Funciones útiles
print(len(dias))                 # 5
print(max(numeros))              # 4
print(min(numeros))              # 1
print(sum(numeros))              # 14

# Conversión
lista = [1, 2, 3]
tupla = tuple(lista)

print(type(coordenadas))         # <class 'tuple'>
```

### 2.4 Rangos (range)

Representa una secuencia inmutable de números, comúnmente usada en bucles.

**Características:**
- Inmutable
- Genera números bajo demanda (eficiente en memoria)
- Solo puede contener enteros

**Ejemplos:**

```python
# Crear rangos
# range(stop)
r1 = range(5)                    # 0, 1, 2, 3, 4

# range(start, stop)
r2 = range(2, 10)                # 2, 3, 4, 5, 6, 7, 8, 9

# range(start, stop, step)
r3 = range(0, 20, 3)             # 0, 3, 6, 9, 12, 15, 18
r4 = range(10, 0, -2)            # 10, 8, 6, 4, 2

# Uso en bucles
for i in range(5):
    print(i)

# Conversión a lista
lista = list(range(5))           # [0, 1, 2, 3, 4]

# Indexación
print(r2[0])                     # 2
print(r2[-1])                    # 9

# Verificación de membresía
print(5 in r2)                   # True
print(10 in r2)                  # False

# Propiedades
print(r2.start)                  # 2
print(r2.stop)                   # 10
print(r2.step)                   # 1

print(type(r1))                  # <class 'range'>
```

---

## 3. Tipos de Mapeo

### 3.1 Diccionarios (dict)

Los diccionarios son colecciones mutables de pares clave-valor no ordenadas (ordenadas desde Python 3.7+).

**Características:**
- Pares clave-valor
- Las claves deben ser inmutables y únicas
- Mutables
- Muy eficientes para búsquedas

**Ejemplos:**

```python
# Crear diccionarios
vacio = {}
vacio2 = dict()

persona = {
    "nombre": "Ana",
    "edad": 28,
    "ciudad": "Madrid"
}

# Con dict()
persona2 = dict(nombre="Luis", edad=35, ciudad="Barcelona")

# Con lista de tuplas
persona3 = dict([("nombre", "Carlos"), ("edad", 40)])

# Acceso a valores
print(persona["nombre"])         # "Ana"
print(persona.get("edad"))       # 28
print(persona.get("telefono", "No disponible"))  # "No disponible"

# Modificación
persona["edad"] = 29             # Modifica valor
persona["email"] = "ana@email.com"  # Añade nuevo par

# Métodos de eliminación
del persona["email"]
edad = persona.pop("edad")       # Elimina y retorna
persona.popitem()                # Elimina y retorna último par (3.7+)

# Métodos de consulta
print(persona.keys())            # dict_keys(['nombre', 'ciudad'])
print(persona.values())          # dict_values(['Ana', 'Madrid'])
print(persona.items())           # dict_items([('nombre', 'Ana'), ...])

# Verificación
print("nombre" in persona)       # True
print("edad" in persona)         # False

# Iteración
for clave in persona:
    print(clave, persona[clave])

for clave, valor in persona.items():
    print(f"{clave}: {valor}")

# Métodos útiles
persona2 = {"nombre": "Ana", "edad": 28}
persona2.update({"ciudad": "Madrid", "edad": 29})  # Actualiza múltiples
copia = persona2.copy()          # Copia superficial
persona2.clear()                 # Elimina todo

# Valores por defecto
from collections import defaultdict
contador = defaultdict(int)
contador["a"] += 1               # No da error, inicia en 0

# Diccionarios anidados
estudiantes = {
    "est1": {"nombre": "Ana", "edad": 20},
    "est2": {"nombre": "Luis", "edad": 22}
}

# Comprensión de diccionarios
cuadrados = {x: x**2 for x in range(5)}
# {0: 0, 1: 1, 2: 4, 3: 9, 4: 16}

print(type(persona))             # <class 'dict'>
```

---

## 4. Tipos de Conjunto

### 4.1 Conjuntos (set)

Los conjuntos son colecciones mutables no ordenadas de elementos únicos.

**Características:**
- Sin orden definido
- Sin elementos duplicados
- Elementos deben ser inmutables
- Operaciones de teoría de conjuntos

**Ejemplos:**

```python
# Crear conjuntos
vacio = set()                    # No usar {}, eso es dict
numeros = {1, 2, 3, 4, 5}
mixto = {1, "dos", 3.0, True}    # True y 1 son equivalentes

# Desde listas (elimina duplicados)
lista = [1, 2, 2, 3, 3, 3, 4]
conjunto = set(lista)            # {1, 2, 3, 4}

# Añadir elementos
numeros.add(6)
numeros.update([7, 8, 9])        # Añade múltiples

# Eliminar elementos
numeros.remove(6)                # Error si no existe
numeros.discard(10)              # No da error si no existe
elemento = numeros.pop()         # Elimina y retorna uno aleatorio
numeros.clear()                  # Elimina todos

# Operaciones de conjuntos
a = {1, 2, 3, 4}
b = {3, 4, 5, 6}

union = a | b                    # {1, 2, 3, 4, 5, 6}
union = a.union(b)

interseccion = a & b             # {3, 4}
interseccion = a.intersection(b)

diferencia = a - b               # {1, 2}
diferencia = a.difference(b)

dif_simetrica = a ^ b            # {1, 2, 5, 6}
dif_simetrica = a.symmetric_difference(b)

# Verificaciones
print(3 in a)                    # True
print(a.issubset(b))             # False
print(a.issuperset({1, 2}))      # True
print(a.isdisjoint({7, 8}))      # True

# Comprensión de conjuntos
pares = {x for x in range(10) if x % 2 == 0}
# {0, 2, 4, 6, 8}

print(type(numeros))             # <class 'set'>
```

### 4.2 Conjuntos Inmutables (frozenset)

Versión inmutable de los conjuntos.

**Características:**
- Inmutable
- Puede usarse como clave de diccionario
- Puede ser elemento de otro conjunto

**Ejemplos:**

```python
# Crear frozensets
numeros = frozenset([1, 2, 3, 4, 5])
letras = frozenset("abcdef")

# Operaciones (igual que set)
a = frozenset([1, 2, 3])
b = frozenset([3, 4, 5])

union = a | b
interseccion = a & b
diferencia = a - b

# Como clave de diccionario
coordenadas = {
    frozenset([1, 2]): "punto1",
    frozenset([3, 4]): "punto2"
}

# Como elemento de set
conjunto_de_conjuntos = {
    frozenset([1, 2]),
    frozenset([3, 4])
}

# No tiene métodos de modificación
# numeros.add(6)  # AttributeError

print(type(numeros))             # <class 'frozenset'>
```

---

## 5. Tipos Booleanos

### 5.1 Booleanos (bool)

Representa valores de verdad: True o False.

**Características:**
- Subclase de int (True=1, False=0)
- Resultado de comparaciones y operaciones lógicas
- Usado en control de flujo

**Ejemplos:**

```python
# Valores booleanos
verdadero = True
falso = False

# En operaciones aritméticas
print(True + True)               # 2
print(True * 5)                  # 5
print(False + 10)                # 10

# Comparaciones
print(5 > 3)                     # True
print(5 == 5)                    # True
print(5 != 3)                    # True
print("a" < "b")                 # True

# Operadores lógicos
print(True and False)            # False
print(True or False)             # True
print(not True)                  # False

# Precedencia
print(True or False and False)   # True (and tiene mayor precedencia)
print((True or False) and False) # False

# Conversión a booleano
print(bool(1))                   # True
print(bool(0))                   # False
print(bool(""))                  # False
print(bool("texto"))             # True
print(bool([]))                  # False
print(bool([1, 2]))              # True

# Valores falsy (se evalúan como False)
falsy = [False, None, 0, 0.0, 0j, "", [], (), {}, set(), frozenset()]

# Valores truthy (se evalúan como True)
truthy = [True, 1, "texto", [1], (1,), {1}, {1: 1}]

# En condiciones
if "texto":
    print("Las cadenas no vacías son truthy")

# Operadores de identidad
a = [1, 2, 3]
b = [1, 2, 3]
c = a

print(a == b)                    # True (mismo valor)
print(a is b)                    # False (diferentes objetos)
print(a is c)                    # True (mismo objeto)

# Operadores de membresía
print(2 in [1, 2, 3])            # True
print("a" not in "hola")         # True

print(type(verdadero))           # <class 'bool'>
```

---

## 6. Tipo None

### 6.1 NoneType (None)

Representa la ausencia de valor.

**Características:**
- Solo existe un objeto None (singleton)
- Usado para valores no inicializados o ausentes
- Retorno por defecto de funciones sin return

**Ejemplos:**

```python
# Asignación
valor = None

# Funciones sin return explícito
def funcion_sin_return():
    x = 5

resultado = funcion_sin_return()
print(resultado)                 # None

# Valores por defecto
def saludar(nombre=None):
    if nombre is None:
        print("Hola, desconocido")
    else:
        print(f"Hola, {nombre}")

# Verificación (usar 'is', no '==')
if valor is None:
    print("valor es None")

if valor is not None:
    print("valor tiene un valor")

# En estructuras de datos
lista = [1, None, 3, None, 5]
diccionario = {"a": 1, "b": None}

# None es falsy
if not None:
    print("None se evalúa como False")

# Diferencia con otros valores "vacíos"
print(None == 0)                 # False
print(None == "")                # False
print(None == False)             # False
print(None is None)              # True

print(type(None))                # <class 'NoneType'>
```

---

## 7. Tipos Binarios

### 7.1 Bytes (bytes)

Secuencia inmutable de bytes (0-255).

**Características:**
- Inmutable
- Cada elemento es un entero 0-255
- Usado para datos binarios

**Ejemplos:**

```python
# Crear bytes
vacio = b''
literal = b'Hola'                # Solo ASCII
desde_lista = bytes([65, 66, 67])  # b'ABC'
desde_int = bytes(5)             # b'\x00\x00\x00\x00\x00'

# Desde string
texto = "Hola"
bytes_utf8 = texto.encode('utf-8')
bytes_ascii = texto.encode('ascii')

# A string
texto_decodificado = bytes_utf8.decode('utf-8')

# Indexación
print(literal[0])                # 72 (código ASCII de 'H')
print(literal[0:2])              # b'Ho'

# Métodos (similares a strings)
print(literal.upper())           # b'HOLA'
print(literal.replace(b'H', b'h'))  # b'hola'

# Inmutable
# literal[0] = 104  # TypeError

# Operaciones
b1 = b'Hello'
b2 = b'World'
concatenado = b1 + b' ' + b2     # b'Hello World'
repetido = b'Hi' * 3             # b'HiHiHi'

# Conversión hexadecimal
print(literal.hex())             # '486f6c61'
desde_hex = bytes.fromhex('486f6c61')  # b'Hola'

print(type(literal))             # <class 'bytes'>
```

### 7.2 Arreglo de Bytes (bytearray)

Versión mutable de bytes.

**Características:**
- Mutable
- Mismas operaciones que bytes
- Puede modificarse in-place

**Ejemplos:**

```python
# Crear bytearrays
vacio = bytearray()
desde_bytes = bytearray(b'Hola')
desde_lista = bytearray([65, 66, 67])
desde_int = bytearray(5)

# Modificación
ba = bytearray(b'Hola')
ba[0] = 104                      # Cambia 'H' por 'h'
print(ba)                        # bytearray(b'hola')

# Métodos de modificación
ba.append(33)                    # Añade '!'
ba.extend(b' Mundo')
ba.insert(0, 72)                 # Inserta 'H' al inicio
ba.remove(33)                    # Elimina '!'
byte = ba.pop()                  # Elimina y retorna último

# Conversión
a_bytes = bytes(ba)
a_string = ba.decode('utf-8')

# Operaciones
ba1 = bytearray(b'Hello')
ba2 = bytearray(b'World')
concatenado = ba1 + ba2
ba1 += b' '                      # Modificación in-place

print(type(ba))                  # <class 'bytearray'>
```

### 7.3 Vista de Memoria (memoryview)

Permite acceso eficiente a datos binarios sin copiarlos.

**Características:**
- Acceso sin copiar datos
- Útil para grandes cantidades de datos
- Soporta slicing sin copias

**Ejemplos:**

```python
# Crear memoryview
datos = bytearray(b'Hola Mundo')
vista = memoryview(datos)

# Acceso
print(vista[0])                  # 72
print(vista[0:4].tobytes())      # b'Hola'

# Modificar a través de la vista
vista[0] = 104                   # Cambia 'H' por 'h'
print(datos)                     # bytearray(b'hola Mundo')

# Información
print(vista.format)              # 'B' (unsigned byte)
print(vista.itemsize)            # 1
print(vista.ndim)                # 1
print(vista.readonly)            # False
print(len(vista))                # 10

# Con arrays numéricos
import array
numeros = array.array('i', [1, 2, 3, 4, 5])
vista_num = memoryview(numeros)
print(vista_num[0])              # 1

# Slicing sin copias (eficiente)
subvista = vista[0:4]
print(subvista.tobytes())        # b'hola'

# Conversión
lista = vista.tolist()
bytes_obj = vista.tobytes()

print(type(vista))               # <class 'memoryview'>
```

---

## 8. Verificación y Conversión de Tipos

### 8.1 Funciones de Verificación

```python
# type() - Retorna el tipo exacto
x = 5
print(type(x))                   # <class 'int'>
print(type(x) == int)            # True

# isinstance() - Verifica si es instancia (considera herencia)
print(isinstance(x, int))        # True
print(isinstance(x, (int, float)))  # True (cualquiera)
print(isinstance(True, int))     # True (bool hereda de int)

# callable() - Verifica si es invocable
def funcion():
    pass

print(callable(funcion))         # True
print(callable(5))               # False
```

### 8.2 Funciones de Conversión

```python
# A entero
print(int(3.14))                 # 3
print(int("42"))                 # 42
print(int("1010", 2))            # 10 (desde binario)
print(int("FF", 16))             # 255 (desde hexadecimal)

# A flotante
print(float(5))                  # 5.0
print(float("3.14"))             # 3.14

# A string
print(str(42))                   # "42"
print(str([1, 2, 3]))            # "[1, 2, 3]"

# A lista
print(list("abc"))               # ['a', 'b', 'c']
print(list((1, 2, 3)))           # [1, 2, 3]
print(list(range(5)))            # [0, 1, 2, 3, 4]

# A tupla
print(tuple([1, 2, 3]))          # (1, 2, 3)
print(tuple("abc"))              # ('a', 'b', 'c')

# A conjunto
print(set([1, 2, 2, 3]))         # {1, 2, 3}
print(set("hello"))              # {'h', 'e', 'l', 'o'}

# A diccionario
print(dict([("a", 1), ("b", 2)]))  # {'a': 1, 'b': 2}

# A booleano
print(bool(0))                   # False
print(bool(1))                   # True
print(bool(""))                  # False
print(bool("texto"))             # True
```

---

## 9. Tipos Especiales

### 9.1 Funciones (function)

Las funciones son objetos de primera clase en Python.

```python
# Definir función
def saludar(nombre):
    return f"Hola, {nombre}"

# Las funciones son objetos
print(type(saludar))             # <class 'function'>

# Asignar a variable
mi_funcion = saludar
print(mi_funcion("Ana"))         # "Hola, Ana"

# Pasar como argumento
def ejecutar(funcion, valor):
    return funcion(valor)

resultado = ejecutar(saludar, "Luis")

# Lambda (funciones anónimas)
cuadrado = lambda x: x ** 2
print(cuadrado(5))               # 25

suma = lambda a, b: a + b
print(suma(3, 4))                # 7

# Funciones anidadas
def exterior():
    def interior():
        return "Desde interior"
    return interior()

# Closures
def multiplicador(n):
    def multiplicar(x):
        return x * n
    return multiplicar

por_dos = multiplicador(2)
print(por_dos(5))                # 10

# Decoradores
def mi_decorador(func):
    def wrapper():
        print("Antes")
        func()
        print("Después")
    return wrapper

@mi_decorador
def funcion_decorada():
    print("Durante")

# Atributos de función
print(saludar.__name__)          # 'saludar'
print(saludar.__doc__)           # Docstring si existe
```

### 9.2 Clases y Objetos (class/object)

Las clases definen nuevos tipos de objetos.

```python
# Definir clase
class Persona:
    # Variable de clase
    especie = "Humano"
    
    # Constructor
    def __init__(self, nombre, edad):
        # Variables de instancia
        self.nombre = nombre
        self.edad = edad
    
    # Método de instancia
    def saludar(self):
        return f"Hola, soy {self.nombre}"
    
    # Método de clase
    @classmethod
    def desde_año_nacimiento(cls, nombre, año):
        edad = 2025 - año
        return cls(nombre, edad)
    
    # Método estático
    @staticmethod
    def es_mayor_edad(edad):
        return edad >= 18
    
    # Representación
    def __repr__(self):
        return f"Persona('{self.nombre}', {self.edad})"

# Crear instancias
persona1 = Persona("Ana", 28)
persona2 = Persona.desde_año_nacimiento("Luis", 1995)

print(type(persona1))            # <class '__main__.Persona'>
print(isinstance(persona1, Persona))  # True

# Acceder a atributos
print(persona1.nombre)           # "Ana"
print(persona1.especie)          # "Humano"

# Llamar métodos
print(persona1.saludar())        # "Hola, soy Ana"
print(Persona.es_mayor_edad(20)) # True

# Herencia
class Estudiante(Persona):
    def __init__(self, nombre, edad, carrera):
        super().__init__(nombre, edad)
        self.carrera = carrera
    
    def estudiar(self):
        return f"{self.nombre} estudia {self.carrera}"

estudiante = Estudiante("Carlos", 22, "Ingeniería")
print(estudiante.saludar())      # Heredado
print(estudiante.estudiar())     # Propio
```

### 9.3 Módulos (module)

Los módulos son archivos que contienen código Python.

```python
# Importar módulo completo
import math
print(type(math))                # <class 'module'>
print(math.pi)                   # 3.141592653589793

# Importar elementos específicos
from math import sqrt, ceil
print(sqrt(16))                  # 4.0

# Importar con alias
import datetime as dt
hoy = dt.date.today()

# Ver contenido del módulo
print(dir(math))                 # Lista todos los nombres

# Información del módulo
print(math.__name__)             # 'math'
print(math.__file__)             # Ubicación del archivo
```

### 9.4 Iteradores y Generadores

```python
# Iterador
lista = [1, 2, 3]
iterador = iter(lista)
print(type(iterador))            # <class 'list_iterator'>

print(next(iterador))            # 1
print(next(iterador))            # 2
print(next(iterador))            # 3
# next(iterador)                 # StopIteration

# Crear iterador personalizado
class Contador:
    def __init__(self, inicio, fin):
        self.actual = inicio
        self.fin = fin
    
    def __iter__(self):
        return self
    
    def __next__(self):
        if self.actual >= self.fin:
            raise StopIteration
        self.actual += 1
        return self.actual - 1

for num in Contador(1, 5):
    print(num)                   # 1, 2, 3, 4

# Generador (con yield)
def fibonacci(n):
    a, b = 0, 1
    for _ in range(n):
        yield a
        a, b = b, a + b

print(type(fibonacci(10)))       # <class 'generator'>

for num in fibonacci(10):
    print(num, end=' ')          # 0 1 1 2 3 5 8 13 21 34

# Expresión generadora
cuadrados = (x**2 for x in range(10))
print(type(cuadrados))           # <class 'generator'>
print(list(cuadrados))           # [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
```

---

## 10. Colecciones Especiales (collections module)

Python ofrece estructuras de datos adicionales en el módulo `collections`.

### 10.1 namedtuple

Tupla con campos nombrados.

```python
from collections import namedtuple

# Definir namedtuple
Punto = namedtuple('Punto', ['x', 'y'])
Persona = namedtuple('Persona', 'nombre edad ciudad')

# Crear instancias
p = Punto(10, 20)
persona = Persona('Ana', 28, 'Madrid')

# Acceso
print(p.x)                       # 10
print(p[0])                      # 10 (también por índice)
print(persona.nombre)            # 'Ana'

# Desempaquetado
x, y = p

# Inmutable (como tupla)
# p.x = 15  # AttributeError

# Métodos
print(p._asdict())               # {'x': 10, 'y': 20}
p2 = p._replace(x=15)            # Punto(x=15, y=20)
```

### 10.2 deque

Cola de doble extremo, eficiente para agregar/quitar elementos.

```python
from collections import deque

# Crear deque
d = deque([1, 2, 3])
d2 = deque(maxlen=5)             # Tamaño máximo

# Agregar elementos
d.append(4)                      # Añade a la derecha
d.appendleft(0)                  # Añade a la izquierda
print(d)                         # deque([0, 1, 2, 3, 4])

# Extender
d.extend([5, 6])                 # A la derecha
d.extendleft([-2, -1])           # A la izquierda (invierte)

# Eliminar
ultimo = d.pop()                 # Elimina de la derecha
primero = d.popleft()            # Elimina de la izquierda

# Rotar
d.rotate(2)                      # Rota 2 posiciones a la derecha
d.rotate(-1)                     # Rota 1 posición a la izquierda

# Otras operaciones
d.reverse()                      # Invierte in-place
print(d.count(2))                # Cuenta ocurrencias
```

### 10.3 Counter

Contador de elementos, útil para frecuencias.

```python
from collections import Counter

# Crear Counter
c = Counter([1, 2, 2, 3, 3, 3])
palabras = Counter("mississippi")

print(c)                         # Counter({3: 3, 2: 2, 1: 1})
print(palabras)                  # Counter({'i': 4, 's': 4, 'p': 2, 'm': 1})

# Acceso
print(c[2])                      # 2
print(c[99])                     # 0 (no da error)

# Métodos
print(c.most_common(2))          # [(3, 3), (2, 2)]
print(list(c.elements()))        # [1, 2, 2, 3, 3, 3]

# Operaciones
c1 = Counter(['a', 'b', 'c', 'a'])
c2 = Counter(['a', 'b', 'd'])

print(c1 + c2)                   # Suma
print(c1 - c2)                   # Diferencia
print(c1 & c2)                   # Intersección (mínimo)
print(c1 | c2)                   # Unión (máximo)

# Actualizar
c1.update(['a', 'b'])            # Suma conteos
c1.subtract(['a'])               # Resta conteos
```

### 10.4 defaultdict

Diccionario con valor por defecto.

```python
from collections import defaultdict

# Con int (default: 0)
contador = defaultdict(int)
contador['a'] += 1               # No da error, inicia en 0
print(contador['a'])             # 1

# Con list (default: [])
grupos = defaultdict(list)
grupos['pares'].append(2)
grupos['pares'].append(4)
print(grupos['pares'])           # [2, 4]

# Con set (default: set())
tags = defaultdict(set)
tags['python'].add('programación')
tags['python'].add('lenguaje')

# Con lambda personalizado
dd = defaultdict(lambda: "No encontrado")
print(dd['clave'])               # "No encontrado"

# Ejemplo: agrupar por longitud
palabras = ['hola', 'adiós', 'hi', 'mundo']
por_longitud = defaultdict(list)
for palabra in palabras:
    por_longitud[len(palabra)].append(palabra)

print(dict(por_longitud))        # {4: ['hola'], 5: ['adiós', 'mundo'], 2: ['hi']}
```

### 10.5 OrderedDict

Diccionario que mantiene orden de inserción (menos necesario desde Python 3.7+).

```python
from collections import OrderedDict

# Crear OrderedDict
od = OrderedDict()
od['b'] = 2
od['a'] = 1
od['c'] = 3

print(list(od.keys()))           # ['b', 'a', 'c']

# Mover al final
od.move_to_end('a')
print(list(od.keys()))           # ['b', 'c', 'a']

# Mover al inicio
od.move_to_end('c', last=False)
print(list(od.keys()))           # ['c', 'b', 'a']

# Eliminar último/primero
ultimo = od.popitem()            # ('a', 1)
primero = od.popitem(last=False) # ('c', 3)
```

### 10.6 ChainMap

Combina múltiples diccionarios en una vista unificada.

```python
from collections import ChainMap

# Crear ChainMap
dict1 = {'a': 1, 'b': 2}
dict2 = {'b': 3, 'c': 4}
dict3 = {'c': 5, 'd': 6}

cm = ChainMap(dict1, dict2, dict3)

# Búsqueda (en orden)
print(cm['a'])                   # 1 (de dict1)
print(cm['b'])                   # 2 (de dict1, no dict2)
print(cm['c'])                   # 4 (de dict2, no dict3)

# Ver todos los valores
print(dict(cm))                  # {'d': 6, 'c': 4, 'b': 2, 'a': 1}

# Modificación (afecta al primer dict)
cm['a'] = 10
print(dict1)                     # {'a': 10, 'b': 2}

# Agregar nuevo nivel
cm = cm.new_child({'e': 7})
print(cm['e'])                   # 7

# Acceder a mapas
print(cm.maps)                   # [{'e': 7}, {'a': 10, 'b': 2}, ...]
```

---

## 11. Tipos de Anotaciones (Type Hints)

Python 3.5+ permite anotaciones de tipo para mejor documentación.

```python
# Anotaciones básicas
def saludar(nombre: str) -> str:
    return f"Hola, {nombre}"

edad: int = 25
altura: float = 1.75
activo: bool = True

# Colecciones
from typing import List, Dict, Set, Tuple, Optional

numeros: List[int] = [1, 2, 3]
persona: Dict[str, int] = {"edad": 25}
unicos: Set[str] = {"a", "b", "c"}
coordenadas: Tuple[float, float] = (10.5, 20.3)

# Optional (puede ser None)
def buscar(id: int) -> Optional[str]:
    return None if id < 0 else "encontrado"

# Union (múltiples tipos)
from typing import Union

def procesar(valor: Union[int, str]) -> str:
    return str(valor)

# Callable
from typing import Callable

def aplicar(func: Callable[[int], int], x: int) -> int:
    return func(x)

# Any (cualquier tipo)
from typing import Any

def imprimir(valor: Any) -> None:
    print(valor)

# TypeVar (genéricos)
from typing import TypeVar

T = TypeVar('T')

def primero(lista: List[T]) -> T:
    return lista[0]

# Nota: Las anotaciones no se ejecutan en runtime
# Son principalmente para herramientas como mypy
```

---

## 12. Tabla Resumen de Tipos de Datos

| Categoría | Tipo | Mutable | Ordenado | Duplicados | Ejemplo |
|-----------|------|---------|----------|------------|---------|
| **Numéricos** | int | No | N/A | N/A | `42` |
| | float | No | N/A | N/A | `3.14` |
| | complex | No | N/A | N/A | `3+4j` |
| **Texto** | str | No | Sí | Sí | `"Hola"` |
| **Secuencias** | list | Sí | Sí | Sí | `[1, 2, 3]` |
| | tuple | No | Sí | Sí | `(1, 2, 3)` |
| | range | No | Sí | N/A | `range(5)` |
| **Mapeo** | dict | Sí | Sí* | Claves no | `{"a": 1}` |
| **Conjuntos** | set | Sí | No | No | `{1, 2, 3}` |
| | frozenset | No | No | No | `frozenset([1, 2])` |
| **Booleano** | bool | No | N/A | N/A | `True` |
| **Binarios** | bytes | No | Sí | Sí | `b"ABC"` |
| | bytearray | Sí | Sí | Sí | `bytearray(b"ABC")` |
| | memoryview | N/A | Sí | N/A | `memoryview(b"ABC")` |
| **Especial** | NoneType | N/A | N/A | N/A | `None` |

*Ordenado desde Python 3.7+

---

## 13. Buenas Prácticas

### 13.1 Elección del Tipo Correcto

```python
# ✓ Usa tuple para datos inmutables
coordenadas = (10, 20)

# ✓ Usa list para colecciones que cambiarán
tareas = ["tarea1", "tarea2"]
tareas.append("tarea3")

# ✓ Usa set para eliminar duplicados o verificación rápida
unicos = set([1, 2, 2, 3, 3])  # {1, 2, 3}
if elemento in mi_set:  # O(1) vs O(n) en lista
    pass

# ✓ Usa dict para relaciones clave-valor
edades = {"Ana": 25, "Luis": 30}

# ✓ Usa defaultdict cuando necesites valores por defecto
from collections import defaultdict
contador = defaultdict(int)

# ✓ Usa Counter para contar elementos
from collections import Counter
frecuencias = Counter(["a", "b", "a", "c", "b", "a"])
```

### 13.2 Verificación de Tipos

```python
# ✓ Usa isinstance() en lugar de type()
if isinstance(x, (int, float)):
    print("Es número")

# ✗ Evita
if type(x) == int:
    pass

# ✓ Para verificar None usa 'is'
if valor is None:
    pass

# ✗ Evita
if valor == None:
    pass
```

### 13.3 Conversiones Seguras

```python
# ✓ Maneja excepciones en conversiones
try:
    numero = int(entrada_usuario)
except ValueError:
    print("Entrada inválida")

# ✓ Usa get() con diccionarios
valor = diccionario.get('clave', 'default')

# ✗ Evita (puede dar KeyError)
valor = diccionario['clave']
```

### 13.4 Eficiencia

```python
# ✓ Usa comprensiones cuando sea apropiado
cuadrados = [x**2 for x in range(10)]

# ✓ Usa generadores para grandes conjuntos de datos
grandes_datos = (x**2 for x in range(1000000))

# ✓ Usa join() para concatenar strings
palabras = ["Hola", "mundo", "Python"]
frase = " ".join(palabras)

# ✗ Evita concatenación repetida
frase = ""
for palabra in palabras:
    frase += palabra + " "
```

---

## 14. Conclusión

Python ofrece una rica variedad de tipos de datos integrados que cubren la mayoría de las necesidades de programación:

- **Tipos numéricos**: Para cálculos matemáticos
- **Secuencias**: Para colecciones ordenadas de datos
- **Mapeos**: Para relaciones clave-valor
- **Conjuntos**: Para elementos únicos y operaciones de conjuntos
- **Tipos binarios**: Para datos binarios y bajo nivel
- **Tipos especiales**: Para propósitos específicos

Comprender estos tipos y cuándo usar cada uno es fundamental para escribir código Python eficiente y efectivo. La elección del tipo de dato correcto puede impactar significativamente en el rendimiento y la claridad del código.