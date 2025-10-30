# Guía Completa de Tipos de Datos en Python

## 1. Introducción

Python es un lenguaje de **tipado dinámico**, lo que significa que no necesitas declarar explícitamente el tipo de una variable. El intérprete deduce automáticamente el tipo a partir del valor asignado, lo que ofrece gran flexibilidad. Esta guía abarca los tipos de datos fundamentales y avanzados de la biblioteca estándar de Python.

---

## 2. Tipos Numéricos

Los tipos numéricos se utilizan para representar valores matemáticos.

### 2.1 Enteros (`int`)

Representan números sin parte decimal. En Python 3, los enteros no tienen un límite de tamaño, solo están restringidos por la memoria disponible del sistema.

* **Características:** No tienen punto decimal, pueden ser positivos, negativos o cero, y soportan notación decimal, binaria, octal y hexadecimal.
* **Ejemplos:**
    ```python
    edad = 25
    poblacion_mundial = 7800000000  # Soporte para números grandes
    binario = 0b1010                # 10 en decimal
    hexadecimal = 0xA               # 10 en decimal
    
    # Operaciones comunes
    division_entera = 10 // 3       # 3
    potencia = 2 ** 3               # 8
    ```

### 2.2 Flotantes (`float`)

Representan números reales con parte decimal. Su precisión es limitada a aproximadamente 15-17 dígitos decimales, lo que puede causar errores de redondeo en cálculos complejos.

* **Características:** Usan punto decimal o notación científica.
* **Ejemplos:**
    ```python
    pi = 3.14159
    velocidad_luz = 3e8              # Notación científica: 300000000.0
    
    # Valores especiales
    infinito = float('inf')
    no_numero = float('nan')
    
    # Conversión
    de_int = float(10)               # 10.0
    ```

### 2.3 Números Complejos (`complex`)

Representan números con una parte real y una parte imaginaria, utilizando la notación `a + bj`.

* **Características:** El sufijo `j` representa la unidad imaginaria ($$\sqrt{-1}$$).
* **Ejemplos:**
    ```python
    z1 = 3 + 4j
    z2 = complex(2, 5)             # Equivalente a 2 + 5j
    
    print(z1.real)                 # 3.0
    print(z1.imag)                 # 4.0
    print(abs(z1))                 # Módulo (valor absoluto): 5.0
    ```

---

## 3. Tipos de Secuencia

Las secuencias son colecciones ordenadas de elementos.

### 3.1 Cadenas de Texto (`str`)

Secuencias **inmutables** de caracteres Unicode.

* **Características:** Inmutables (no se pueden modificar una vez creadas), permiten indexación y slicing.
* **Ejemplos:**
    ```python
    nombre = "María"
    mensaje = f"Hola, {nombre}"      # f-string (Python 3.6+)
    
    # Slicing
    print(mensaje[0:4])              # 'Hola'
    print(mensaje[::-1])             # Inversión de cadena: 'aíraM ,aloH'
    
    # Métodos comunes
    texto = "  Hola Mundo  "
    print(texto.strip())             # "Hola Mundo"
    print(texto.upper())             # "  HOLA MUNDO  "
    ```

### 3.2 Listas (`list`)

Secuencias **mutables** y ordenadas, lo que permite modificar su contenido. Son muy flexibles y pueden contener elementos de diferentes tipos.

* **Características:** Mutables, mantienen el orden de inserción y permiten duplicados.
* **Ejemplos:**
    ```python
    numeros = [1, 2, 3, "cuatro"]
    
    # Modificación
    numeros.append(5)                # Añade un elemento al final
    numeros[3] = 4                   # Modifica un elemento
    
    # Comprensión de listas
    cuadrados = [x**2 for x in range(5)] # [0, 1, 4, 9, 16]
    ```

### 3.3 Tuplas (`tuple`)

Secuencias **inmutables** y ordenadas. Son más eficientes en memoria y velocidad que las listas.

* **Características:** Inmutables (no se pueden modificar), más rápidas que las listas y se usan para datos que no deben cambiar.
* **Ejemplos:**
    ```python
    coordenadas = (10, 20)
    
    # Desempaquetado
    x, y = coordenadas
    
    # Se usan sin paréntesis para asignar múltiples valores (packing)
    punto = 1, 2, 3
    ```

### 3.4 Rangos (`range`)

Secuencias inmutables de enteros que generan números bajo demanda, siendo muy eficientes en memoria.

* **Características:** Inmutables y usadas comúnmente en bucles.
* **Ejemplos:**
    ```python
    # range(stop)
    r1 = range(5)                    # Genera 0, 1, 2, 3, 4
    
    # range(start, stop, step)
    r2 = range(0, 10, 2)             # Genera 0, 2, 4, 6, 8
    
    # Conversión a lista
    lista = list(range(5))           # [0, 1, 2, 3, 4]
    ```

---

## 4. Tipos de Mapeo

### 4.1 Diccionarios (`dict`)

Colecciones **mutables** de pares clave-valor.

* **Características:** Las claves deben ser únicas e inmutables. Son ordenados a partir de Python 3.7+ y muy eficientes para búsquedas de elementos.
* **Ejemplos:**
    ```python
    persona = {"nombre": "Ana", "edad": 28}
    
    # Acceso y modificación
    print(persona["nombre"])         # "Ana"
    persona["ciudad"] = "Madrid"     # Añadir un nuevo par
    
    # Iteración
    for clave, valor in persona.items():
        print(f"{clave}: {valor}")
    ```

---

## 5. Tipos de Conjunto

Los conjuntos son colecciones de elementos únicos, sin un orden definido.

### 5.1 Conjuntos (`set`)

Colecciones **mutables** de elementos únicos. Son ideales para eliminar duplicados o realizar operaciones de teoría de conjuntos.

* **Características:** Sin orden definido y no permiten duplicados. Los elementos deben ser inmutables.
* **Ejemplos:**
    ```python
    numeros = {1, 2, 2, 3, 4}        # {1, 2, 3, 4}
    
    # Operaciones de conjuntos
    a = {1, 2, 3}
    b = {3, 4, 5}
    print(a | b)                     # Unión: {1, 2, 3, 4, 5}
    print(a & b)                     # Intersección: {3}
    ```

### 5.2 Conjuntos Inmutables (`frozenset`)

Versión **inmutable** del tipo `set`.

* **Características:** Pueden usarse como claves de un diccionario, a diferencia de los conjuntos mutables.
* **Ejemplos:**
    ```python
    fs = frozenset([1, 2, 3])
    
    # Uso como clave de diccionario
    diccionario = {fs: "mi_conjunto"}
    ```

---

## 6. Tipos Booleanos (`bool`)

Representan valores de verdad: `True` o `False`.

* **Características:** Son una subclase del tipo `int`, donde `True` equivale a `1` y `False` a `0`.
* **Ejemplos:**
    ```python
    verdadero = True
    falso = False
    
    print(5 > 3)                     # True
    print(True + True)               # 2
    
    # Valores 'falsy' (se evalúan como False en un contexto booleano)
    print(bool(0))                   # False
    print(bool(""))                  # False
    print(bool([]))                  # False
    ```

---

## 7. Tipo `NoneType` (`None`)

Representa la ausencia de valor. Solo existe un objeto `None` en Python (es un singleton).

* **Características:** Es un valor de marcador de posición para variables no inicializadas o retornos de funciones que no devuelven nada explícitamente.
* **Ejemplos:**
    ```python
    valor = None
    
    def funcion_sin_retorno():
        pass
    
    resultado = funcion_sin_retorno()
    print(resultado is None)         # True (usar 'is' para verificar None)
    ```

---

## 8. Tipos Binarios

Se utilizan para manejar datos a nivel de bytes.

### 8.1 Bytes (`bytes`) y Arreglo de Bytes (`bytearray`)

* `bytes`: Secuencia **inmutable** de bytes (enteros de 0 a 255).
* `bytearray`: Versión **mutable** de `bytes`, que permite la modificación de sus elementos.
* **Ejemplos:**
    ```python
    datos_inmutables = b'Hola'
    datos_mutables = bytearray(datos_inmutables)
    
    # Modificación de bytearray
    datos_mutables[0] = 104          # Cambia 'H' por 'h'
    print(datos_mutables)            # bytearray(b'hola')
    ```

### 8.2 Vista de Memoria (`memoryview`)

Permite un acceso eficiente a los datos binarios sin copiarlos.

* **Características:** Útil para procesar grandes cantidades de datos binarios de forma eficiente.
* **Ejemplo:**
    ```python
    datos = bytearray(b'Python')
    vista = memoryview(datos)
    print(vista[0:3].tobytes())      # b'Pyt'
    
    # La modificación a través de la vista afecta al objeto original
    vista[0] = 104                   # Cambia 'P' por 'p'
    print(datos)                     # bytearray(b'python')
    ```

---

## 9. Tipos de Colecciones Especiales

El módulo `collections` ofrece estructuras de datos optimizadas.

### 9.1 `namedtuple`

Una tupla con campos nombrados, lo que mejora la legibilidad del código.

* **Ejemplo:**
    ```python
    from collections import namedtuple
    Punto = namedtuple('Punto', ['x', 'y'])
    p = Punto(10, 20)
    
    print(p.x)                       # Acceso por nombre
    print(p[0])                      # Acceso por índice
    ```

### 9.2 `defaultdict`

Un diccionario que proporciona un valor por defecto para las claves que no existen, evitando errores `KeyError`.

* **Ejemplo:**
    ```python
    from collections import defaultdict
    contador = defaultdict(int)
    contador['a'] += 1               # No da error, inicializa en 0 y luego suma 1
    ```

### 9.3 `Counter`

Una subclase de `dict` que se usa para contar objetos "hashable".

* **Ejemplo:**
    ```python
    from collections import Counter
    palabras = Counter("mississippi")
    print(palabras.most_common(2))   # [('i', 4), ('s', 4)]
    ```

---

## 10. Buenas Prácticas y Consejos

### 10.1 Elección del Tipo Correcto

* Usa **`tuple`** para datos que no deben cambiar, como coordenadas.
* Usa **`list`** cuando la colección necesite ser modificada.
* Usa **`set`** para eliminar duplicados de una colección o para verificar la pertenencia de un elemento de forma eficiente.
* Usa **`dict`** para almacenar relaciones clave-valor.
* Usa **`is`** y **`is not`** para comparar si un objeto es `None`.
    * **Correcto:** `if valor is None:`
    * **Incorrecto:** `if valor == None:`

### 10.2 Verificación de Tipos

* Usa **`isinstance()`** en lugar de `type()` para verificar el tipo de un objeto, ya que considera la herencia.
    * **Correcto:** `isinstance(5, int)`
    * **Incorrecto:** `type(5) == int`

### 10.3 Eficiencia

* Prefiere las **comprensiones de lista** (`[... for ...]`) sobre los bucles `for` para crear nuevas listas.
* Usa **generadores** (`(... for ...)`) para colecciones grandes, ya que generan elementos bajo demanda y son más eficientes en memoria.

---

## 11. Tabla Resumen de Tipos de Datos

| Categoría | Tipo | Mutable | Ordenado | Duplicados | Ejemplo |
|:----------|:---|:---|:---|:---|:---|
| **Numéricos** | `int` | No | N/A | N/A | `42` |
| | `float` | No | N/A | N/A | `3.14` |
| | `complex` | No | N/A | N/A | `3+4j` |
| **Secuencias** | `str` | No | Sí | Sí | `"Hola"` |
| | `list` | Sí | Sí | Sí | `[1, 2, 3]` |
| | `tuple` | No | Sí | Sí | `(1, 2, 3)` |
| | `range` | No | Sí | N/A | `range(5)` |
| **Mapeo** | `dict` | Sí | Sí* | Claves no | `{"a": 1}` |
| **Conjuntos** | `set` | Sí | No | No | `{1, 2, 3}` |
| | `frozenset` | No | No | No | `frozenset([1, 2])`|
| **Booleano** | `bool` | No | N/A | N/A | `True` |
| **Binarios** | `bytes` | No | Sí | Sí | `b"ABC"` |
| | `bytearray`| Sí | Sí | Sí | `bytearray(b"ABC")`|
| **Especial** | `NoneType`| N/A | N/A | N/A | `None` |