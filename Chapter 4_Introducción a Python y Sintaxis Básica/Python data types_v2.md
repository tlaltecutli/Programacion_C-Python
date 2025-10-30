# Guía Técnica Completa de Tipos de Datos en Python

## Introducción

Python es un lenguaje de **tipado dinámico**, lo que significa que no es necesario declarar explícitamente el tipo de una variable. El intérprete deduce automáticamente el tipo a partir del valor asignado.  
Esta guía presenta de forma estructurada y técnica los tipos de datos fundamentales de la biblioteca estándar de Python, con ejemplos claros y buenas prácticas.

---

## 1. Tipos Numéricos

### 1.1 Enteros (`int`)

Representan números sin parte decimal. En Python 3, los enteros no tienen un tamaño máximo predeterminado, salvo por la memoria disponible.

**Características:**
- No poseen punto decimal.  
- Pueden ser positivos, negativos o cero.  
- Soportan notación decimal, binaria, octal y hexadecimal.  

**Ejemplo:**

```python
# Declaración y operaciones con enteros
edad = 25
temperatura = -10
binario = 0b1010      # 10 en decimal
octal = 0o12          # 10 en decimal
hexadecimal = 0xA     # 10 en decimal

suma = 10 + 5           # 15
division_entera = 10 // 3  # 3
modulo = 10 % 3         # 1
potencia = 2 ** 3       # 8
```

---

### 1.2 Flotantes (`float`)

Los números de punto flotante representan valores reales con parte decimal. Tienen precisión limitada (~15-17 dígitos).

**Características:**
- Usan punto decimal o notación científica.  
- Pueden producir errores de redondeo debido a su representación binaria.  

**Ejemplo:**

```python
pi = 3.14159265359
velocidad_luz = 3e8
division = 10 / 3   # 3.3333333333333335
infinito = float('inf')
no_numero = float('nan')
```

---

### 1.3 Números Complejos (`complex`)

Representan números con parte real e imaginaria.

**Características:**
- Formato: `a + bj` donde `a` es la parte real y `b` la imaginaria.  
- `j` representa la unidad imaginaria (√-1).  

**Ejemplo:**

```python
z1 = 3 + 4j
z2 = complex(2, 5)
print(z1.real)  # 3.0
print(z1.imag)  # 4.0
print(abs(z1))  # 5.0
```

---

## 2. Tipos de Secuencia

### 2.1 Cadenas de Texto (`str`)

Secuencias inmutables de caracteres Unicode.

**Características:**
- Inmutables.  
- Soportan indexación, slicing y métodos integrados.  

**Ejemplo:**

```python
nombre = "María"
mensaje = f"Hola, {nombre}"
print(mensaje[::-1])  # Inversión de cadena
```

---

### 2.2 Listas (`list`)

Secuencias mutables y ordenadas.

**Características:**
- Permiten duplicados.  
- Pueden contener elementos de distintos tipos.  

**Ejemplo:**

```python
numeros = [1, 2, 3, 4]
numeros.append(5)
cuadrados = [x**2 for x in numeros]
```

---

### 2.3 Tuplas (`tuple`)

Secuencias inmutables y ordenadas, más eficientes que las listas.

**Ejemplo:**

```python
coordenadas = (10, 20)
x, y = coordenadas
```

---

### 2.4 Rangos (`range`)

Secuencias inmutables de enteros, usadas frecuentemente en bucles.

```python
for i in range(0, 10, 2):
    print(i)
```

---

## 3. Tipos de Mapeo

### 3.1 Diccionarios (`dict`)

Colecciones mutables de pares clave-valor.

**Características:**
- Claves únicas e inmutables.  
- Ordenados desde Python 3.7+.  

**Ejemplo:**

```python
persona = {"nombre": "Ana", "edad": 28}
persona["ciudad"] = "Madrid"
for clave, valor in persona.items():
    print(clave, valor)
```

---

## 4. Tipos de Conjunto

### 4.1 Conjuntos (`set`)

Colecciones mutables, no ordenadas y sin elementos duplicados.

```python
a = {1, 2, 3}
b = {3, 4, 5}
print(a | b)  # Unión
print(a & b)  # Intersección
```

---

### 4.2 Conjuntos Inmutables (`frozenset`)

Versiones inmutables de los conjuntos.

```python
fs = frozenset([1, 2, 3])
```

---

## 5. Tipos Booleanos (`bool`)

Subclase de `int`, con valores `True` y `False`.

```python
x = True
y = False
print(x and not y)
```

---

## 6. Tipo `NoneType`

Representa la ausencia de valor.

```python
def funcion():
    pass

resultado = funcion()
print(resultado is None)
```

---

## 7. Tipos Binarios

### 7.1 `bytes` (inmutable) y `bytearray` (mutable)

Usados para manejar datos binarios.

```python
b = b'Hola'
ba = bytearray(b)
ba[0] = 104  # Modifica el primer byte
```

### 7.2 `memoryview`

Proporciona acceso eficiente sin copiar datos.

```python
mv = memoryview(bytearray(b'Python'))
print(mv[0:3].tobytes())
```

---

## 8. Verificación y Conversión de Tipos

```python
# Verificación
isinstance(5, int)  # True

# Conversión
int("42")      # 42
float("3.14")  # 3.14
list("abc")    # ['a', 'b', 'c']
```

---

## 9. Tipos Especiales

### 9.1 Funciones (`function`)

Las funciones son objetos de primera clase.

```python
def saludar(nombre):
    return f"Hola, {nombre}"

mi_funcion = saludar
print(mi_funcion("Ana"))
```

### 9.2 Clases y Objetos (`class` / `object`)

```python
class Persona:
    def __init__(self, nombre):
        self.nombre = nombre

    def saludar(self):
        return f"Hola, soy {self.nombre}"
```

### 9.3 Módulos (`module`)

```python
import math
print(math.pi)
```

### 9.4 Iteradores y Generadores

```python
def fibonacci(n):
    a, b = 0, 1
    for _ in range(n):
        yield a
        a, b = b, a + b
```

---

## 10. Colecciones Especiales (`collections`)

Incluye estructuras optimizadas como `namedtuple`, `deque`, `Counter`, `defaultdict`, `OrderedDict` y `ChainMap`.

**Ejemplo:**

```python
from collections import Counter
c = Counter("mississippi")
print(c.most_common(2))
```

---

## 11. Anotaciones de Tipo (`Type Hints`)

Mejoran la legibilidad y permiten análisis estático.

```python
from typing import List, Dict, Union

def procesar(valores: List[int]) -> Dict[str, Union[int, float]]:
    return {"suma": sum(valores), "media": sum(valores) / len(valores)}
```

---

## 12. Tabla Resumen

| Categoría | Tipo | Mutable | Ordenado | Ejemplo |
|-----------|------|----------|-----------|----------|
| Numérico | int | No | N/A | `42` |
| | float | No | N/A | `3.14` |
| | complex | No | N/A | `3+4j` |
| Texto | str | No | Sí | `"Hola"` |
| Secuencia | list | Sí | Sí | `[1,2,3]` |
| | tuple | No | Sí | `(1,2,3)` |
| | range | No | Sí | `range(5)` |
| Mapeo | dict | Sí | Sí | `{"a":1}` |
| Conjunto | set | Sí | No | `{1,2,3}` |
| | frozenset | No | No | `frozenset([1,2])` |
| Booleano | bool | No | N/A | `True` |
| Binario | bytes | No | Sí | `b"ABC"` |
| | bytearray | Sí | Sí | `bytearray(b"ABC")` |
| Especial | NoneType | N/A | N/A | `None` |

---

## 13. Buenas Prácticas

- Usa `tuple` para datos inmutables.  
- Usa `list` cuando la colección cambie.  
- Usa `set` para eliminar duplicados o verificar pertenencia.  
- Usa `dict` para relaciones clave-valor.  
- Usa `isinstance()` para verificar tipos.  
- Evita `type(x) == int`.  
- Usa `is` y `is not` para comprobar `None`.  

---

## 14. Conclusión

Python ofrece una amplia variedad de tipos de datos integrados que cubren la mayoría de las necesidades de programación.  
Dominar estos tipos y sus propiedades permite escribir código **eficiente, claro y mantenible**. La elección correcta del tipo de dato es clave para optimizar el rendimiento y la legibilidad del programa.
