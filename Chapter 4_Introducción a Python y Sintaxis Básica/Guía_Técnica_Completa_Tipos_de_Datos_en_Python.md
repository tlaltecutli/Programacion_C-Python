# Guía Técnica Completa de Tipos de Datos en Python

## 🧭 Resumen Ejecutivo

Esta guía presenta una referencia técnica completa sobre los **tipos de datos en Python**, abordando su estructura interna, comportamiento, mutabilidad y uso práctico. Está dirigida a desarrolladores, investigadores y profesionales que requieren un entendimiento sólido de la biblioteca estándar. Se incluyen ejemplos, buenas prácticas, recomendaciones de eficiencia y referencias oficiales (PEP y documentación de Python).

---

## 📑 Tabla de Contenido

1. [Introducción](#1-introducción)
2. [Tipos Numéricos](#2-tipos-numéricos)
3. [Tipos de Secuencia](#3-tipos-de-secuencia)
4. [Tipos de Mapeo](#4-tipos-de-mapeo)
5. [Tipos de Conjunto](#5-tipos-de-conjunto)
6. [Tipos Booleanos](#6-tipos-booleanos)
7. [Tipo NoneType](#7-tipo-nonetype)
8. [Tipos Binarios](#8-tipos-binarios)
9. [Verificación y Conversión de Tipos](#9-verificación-y-conversión-de-tipos)
10. [Tipos Especiales](#10-tipos-especiales)
11. [Colecciones Avanzadas (`collections`)](#11-colecciones-avanzadas-collections)
12. [Anotaciones de Tipo (`typing`)](#12-anotaciones-de-tipo-typing)
13. [Iteradores y Generadores](#13-iteradores-y-generadores)
14. [Clases y Objetos](#14-clases-y-objetos)
15. [Funciones](#15-funciones)
16. [Módulos](#16-módulos)
17. [Buenas Prácticas](#17-buenas-prácticas)
18. [Eficiencia y Uso de Memoria](#18-eficiencia-y-uso-de-memoria)
19. [Tabla Comparativa de Tipos de Datos](#19-tabla-comparativa-de-tipos-de-datos)
20. [Referencias](#20-referencias)

---

## 1. Introducción

Python es un lenguaje de **tipado dinámico y fuerte**, lo que significa que no requiere declarar tipos explícitamente, pero impone reglas estrictas de compatibilidad entre ellos. El intérprete asigna automáticamente el tipo de una variable con base en el valor. Comprender estos tipos permite escribir código más eficiente, seguro y mantenible.

---

## 2. Tipos Numéricos

Python soporta tres tipos numéricos principales: `int`, `float` y `complex`.

### 🔹 Enteros (`int`)

Representan números sin parte decimal. En Python 3, los enteros son ilimitados (salvo por la memoria).

```python
# Ejemplo
edad = 25
poblacion = 8_000_000_000
binario = 0b1010      # 10 en decimal
hexadecimal = 0xA      # 10 en decimal

# Operaciones
potencia = 2 ** 8      # 256
division_entera = 10 // 3  # 3
```

### 🔹 Flotantes (`float`)

Representan números reales con parte decimal. Su precisión es de ~15-17 dígitos.

```python
pi = 3.1415926535
velocidad_luz = 3e8
division = 10 / 3
```

### 🔹 Complejos (`complex`)

Representan números con parte real e imaginaria.

```python
z = 3 + 4j
print(z.real, z.imag)  # 3.0 4.0
```

---

## 3. Tipos de Secuencia

Incluyen `str`, `list`, `tuple` y `range`.

### 🔹 Cadenas (`str`)

```python
nombre = "Python"
print(nombre[::-1])  # 'nohtyP'
print(nombre.upper())  # 'PYTHON'
```

### 🔹 Listas (`list`)

```python
datos = [1, 2, 3]
datos.append(4)
cuadrados = [x**2 for x in datos]
```

### 🔹 Tuplas (`tuple`)

```python
coordenadas = (10, 20)
x, y = coordenadas
```

### 🔹 Rangos (`range`)

```python
for i in range(0, 10, 2):
    print(i)
```

---

## 4. Tipos de Mapeo

### 🔹 Diccionarios (`dict`)

Colecciones mutables de pares clave-valor.

```python
persona = {"nombre": "Ana", "edad": 28}
persona["ciudad"] = "Madrid"
for k, v in persona.items():
    print(k, v)
```

---

## 5. Tipos de Conjunto

```python
a = {1, 2, 3}
b = {3, 4, 5}
print(a | b)  # Unión
print(a & b)  # Intersección
```

---

## 6. Tipos Booleanos

```python
activo = True
if activo and not False:
    print("Activo")
```

---

## 7. Tipo NoneType

Representa la ausencia de valor.

```python
resultado = None
if resultado is None:
    print("Sin valor")
```

---

## 8. Tipos Binarios

### 🔹 `bytes` (inmutable) y `bytearray` (mutable)

```python
b = b'Hola'
ba = bytearray(b)
ba[0] = 104  # Cambia 'H' → 'h'
```

### 🔹 `memoryview`

```python
mv = memoryview(bytearray(b'Python'))
print(mv[0:3].tobytes())
```

---

## 9. Verificación y Conversión de Tipos

```python
isinstance(5, int)  # True
float("3.14")
list("abc")
```

---

## 10. Tipos Especiales

### 🔹 Funciones (`function`)

```python
def saludar(nombre):
    return f"Hola, {nombre}"
```

### 🔹 Clases y Objetos (`class`, `object`)

```python
class Persona:
    def __init__(self, nombre):
        self.nombre = nombre
```

### 🔹 Módulos (`module`)

```python
import math
print(math.pi)
```

---

## 11. Colecciones Avanzadas (`collections`)

Incluye `namedtuple`, `deque`, `Counter`, `defaultdict`, `OrderedDict`, `ChainMap`.

```python
from collections import Counter
c = Counter("mississippi")
print(c.most_common(2))
```

---

## 12. Anotaciones de Tipo (`typing`)

```python
from typing import List, Dict, Union

def procesar(valores: List[int]) -> Dict[str, Union[int, float]]:
    return {"suma": sum(valores), "media": sum(valores)/len(valores)}
```

---

## 13. Iteradores y Generadores

```python
def fibonacci(n):
    a, b = 0, 1
    for _ in range(n):
        yield a
        a, b = b, a + b
```

---

## 14. Clases y Objetos

(Ver sección 10)

---

## 15. Funciones

Incluyen funciones normales, lambda, closures y decoradores.

```python
cuadrado = lambda x: x**2
```

---

## 16. Módulos

Estructura de archivos reutilizables. Ejemplo con `import`, `from` y alias.

---

## 17. Buenas Prácticas

- Usa `isinstance()` para verificar tipos.  
- Usa `is` para comparar con `None`.  
- Prefiere comprensiones (`[x for x in ...]`).  
- Evita concatenar strings en bucles. Usa `" ".join(lista)`.

---

## 18. Eficiencia y Uso de Memoria

- Prefiere **tuplas** sobre **listas** para datos inmutables.  
- Usa **generadores** para colecciones grandes.  
- Los **sets** ofrecen búsqueda O(1).  
- Evita copiar estructuras grandes innecesariamente.

---

## 19. Tabla Comparativa de Tipos de Datos

| Categoría | Tipo | Mutable | Ordenado | Ejemplo |
|-----------|------|----------|-----------|----------|
| Numérico | int | No | N/A | `42` |
|  | float | No | N/A | `3.14` |
|  | complex | No | N/A | `3+4j` |
| Texto | str | No | Sí | `"Hola"` |
| Secuencia | list | Sí | Sí | `[1,2,3]` |
|  | tuple | No | Sí | `(1,2,3)` |
|  | range | No | Sí | `range(5)` |
| Mapeo | dict | Sí | Sí | `{"a":1}` |
| Conjunto | set | Sí | No | `{1,2,3}` |
|  | frozenset | No | No | `frozenset([1,2])` |
| Booleano | bool | No | N/A | `True` |
| Binario | bytes | No | Sí | `b"ABC"` |
|  | bytearray | Sí | Sí | `bytearray(b"ABC")` |
|  | memoryview | N/A | Sí | `memoryview(b"ABC")` |
| Especial | NoneType | N/A | N/A | `None` |

---

## 20. Referencias

- Python Software Foundation. *The Python Standard Library*. Disponible en: https://docs.python.org/3/library/stdtypes.html  
- PEP 484: *Type Hints*  
- PEP 8: *Style Guide for Python Code*  
- PEP 20: *The Zen of Python*  
- Beazley, D. (2020). *Python Cookbook, 3rd Edition*. O’Reilly Media.  
- Van Rossum, G. et al. (2023). *The Python Language Reference Manual*.
