# Tablas de Operadores en Python

## 📊 Referencia Rápida de Operadores

---

## 1. Operadores Aritméticos

| Operación | Resultado | Notas | Documentación completa |
|-----------|-----------|-------|------------------------|
| `x + y` | suma de *x* e *y* | | |
| `x - y` | resta de *x* e *y* | | |
| `x * y` | multiplicación de *x* por *y* | | |
| `x / y` | división de *x* entre *y* | (1) | |
| `x // y` | división entera a la baja de *x* entre *y* | (1)(2) | |
| `x % y` | resto o residuo de *x* / *y* | (2) | |
| `-x` | valor de *x*, negado | | |
| `+x` | valor de *x*, sin cambiar | | |
| `abs(x)` | valor absoluto de la magnitud de *x* | | [abs()](https://docs.python.org/es/3/library/functions.html#abs) |
| `int(x)` | valor de *x* convertido a entero | (3)(6) | [int()](https://docs.python.org/es/3/library/functions.html#int) |
| `float(x)` | valor de *x* convertido a número de coma flotante | (4)(6) | [float()](https://docs.python.org/es/3/library/functions.html#float) |
| `complex(re, im)` | un número complejo, con parte real *re* y parte imaginaria *im*. El valor de *im* por defecto vale cero. | (6) | [complex()](https://docs.python.org/es/3/library/functions.html#complex) |
| `c.conjugate()` | conjugado del número complejo *c* | | |
| `divmod(x, y)` | el par de valores `(x // y, x % y)` | (2) | [divmod()](https://docs.python.org/es/3/library/functions.html#divmod) |
| `pow(x, y)` | *x* elevado a *y* | (5) | [pow()](https://docs.python.org/es/3/library/functions.html#pow) |
| `x ** y` | *x* elevado a *y* | (5) | |

### Notas sobre Operadores Aritméticos:

1. También conocido como división de enteros. El valor resultante es un número entero completo, aunque el tipo del resultado no sea necesariamente int. El resultado es siempre redondeado hacia menos infinito: `1//2` es `0`, `(-1)//2` es `-1`, `1//(-2)` es `-1` y `(-1)//(-2)` es `0`.

2. No para números complejos. En su lugar, utilice `abs()` para convertir a números de coma flotante.

3. La conversión de coma flotante a entero puede redondear o truncar como en C.

4. float también acepta las cadenas "nan" e "inf" con un prefijo opcional "+" o "-" para Not a Number (NaN) e infinito positivo o negativo.

5. Python define `pow(0, 0)` y `0 ** 0` como `1`, como es común en los lenguajes de programación.

6. Los literales numéricos aceptados incluyen los dígitos del `0` al `9` o cualquier equivalente Unicode (puntos de código con la propiedad `Nd`).

---

## 2. Operadores de Comparación

| Operador | Significado | Ejemplo | Resultado | Notas |
|----------|-------------|---------|-----------|-------|
| `<` | menor que | `5 < 10` | `True` | |
| `<=` | menor o igual que | `5 <= 5` | `True` | |
| `>` | mayor que | `10 > 5` | `True` | |
| `>=` | mayor o igual que | `10 >= 10` | `True` | |
| `==` | igual a | `5 == 5` | `True` | (1) |
| `!=` | diferente de | `5 != 3` | `True` | |
| `is` | identidad de objeto | `x is None` | `True/False` | (2) |
| `is not` | identidad de objeto negada | `x is not None` | `True/False` | (2) |

### Notas sobre Operadores de Comparación:

1. El operador `==` compara **valores**, no identidad de objetos. Para comparar identidad use `is`.

2. Los operadores `is` e `is not` verifican la identidad del objeto: `x is y` es verdadero si y solo si *x* e *y* son el mismo objeto. Se recomienda usar `is` y `is not` solo para comparar con `None`.

### Ejemplos de Comparación:

```python
# Comparación de números
print(5 < 10)      # True
print(5 <= 5)      # True
print(10 > 5)      # True
print(10 >= 10)    # True
print(5 == 5)      # True
print(5 != 3)      # True

# Comparación de cadenas (orden lexicográfico)
print("a" < "b")   # True
print("abc" < "abd")  # True
print("Python" == "Python")  # True

# Comparación encadenada
x = 5
print(1 < x < 10)  # True (equivale a: 1 < x and x < 10)
print(1 < x <= 5)  # True
```

---

## 3. Operadores Lógicos

| Operador | Descripción | Ejemplo | Resultado | Tabla de Verdad |
|----------|-------------|---------|-----------|-----------------|
| `and` | Devuelve `True` si ambas condiciones son verdaderas | `True and False` | `False` | Ver tabla (1) |
| `or` | Devuelve `True` si al menos una condición es verdadera | `True or False` | `True` | Ver tabla (2) |
| `not` | Invierte el valor booleano | `not True` | `False` | Ver tabla (3) |

### Tablas de Verdad:

#### (1) Operador AND
| A | B | A and B |
|---|---|---------|
| `True` | `True` | `True` |
| `True` | `False` | `False` |
| `False` | `True` | `False` |
| `False` | `False` | `False` |

#### (2) Operador OR
| A | B | A or B |
|---|---|--------|
| `True` | `True` | `True` |
| `True` | `False` | `True` |
| `False` | `True` | `True` |
| `False` | `False` | `False` |

#### (3) Operador NOT
| A | not A |
|---|-------|
| `True` | `False` |
| `False` | `True` |

### Evaluación de Cortocircuito:

Los operadores `and` y `or` utilizan evaluación de cortocircuito:

```python
# AND: Si el primer operando es False, no evalúa el segundo
False and funcion_costosa()  # No ejecuta funcion_costosa()

# OR: Si el primer operando es True, no evalúa el segundo
True or funcion_costosa()    # No ejecuta funcion_costosa()
```

### Ejemplos de Operadores Lógicos:

```python
# Operador AND
edad = 25
tiene_licencia = True
if edad >= 18 and tiene_licencia:
    print("Puede conducir")

# Operador OR
dia = "Sábado"
if dia == "Sábado" or dia == "Domingo":
    print("Es fin de semana")

# Operador NOT
es_mayor = edad >= 18
if not es_mayor:
    print("Es menor de edad")

# Combinación de operadores
if (edad >= 18 and tiene_licencia) or edad >= 21:
    print("Cumple los requisitos")
```

---

## 4. Operadores de Asignación

| Operador | Ejemplo | Equivalente a | Descripción |
|----------|---------|---------------|-------------|
| `=` | `x = 5` | — | Asignación simple |
| `+=` | `x += 3` | `x = x + 3` | Suma y asigna |
| `-=` | `x -= 3` | `x = x - 3` | Resta y asigna |
| `*=` | `x *= 3` | `x = x * 3` | Multiplica y asigna |
| `/=` | `x /= 3` | `x = x / 3` | Divide y asigna |
| `//=` | `x //= 3` | `x = x // 3` | División entera y asigna |
| `%=` | `x %= 3` | `x = x % 3` | Módulo y asigna |
| `**=` | `x **= 3` | `x = x ** 3` | Potencia y asigna |
| `&=` | `x &= 3` | `x = x & 3` | AND bit a bit y asigna |
| `|=` | `x |= 3` | `x = x | 3` | OR bit a bit y asigna |
| `^=` | `x ^= 3` | `x = x ^ 3` | XOR bit a bit y asigna |
| `>>=` | `x >>= 3` | `x = x >> 3` | Desplazamiento a derecha y asigna |
| `<<=` | `x <<= 3` | `x = x << 3` | Desplazamiento a izquierda y asigna |

### Ejemplos de Operadores de Asignación:

```python
# Asignación simple
x = 10

# Operadores de asignación compuesta
x += 5    # x = 15
x -= 3    # x = 12
x *= 2    # x = 24
x /= 4    # x = 6.0
x //= 2   # x = 3.0
x %= 2    # x = 1.0
x **= 3   # x = 1.0

# Asignación múltiple
a, b, c = 1, 2, 3
print(a, b, c)  # 1 2 3

# Intercambio de valores
a, b = b, a
print(a, b)  # 2 1

# Asignación encadenada
x = y = z = 0
print(x, y, z)  # 0 0 0

# Desempaquetado
lista = [1, 2, 3, 4, 5]
primero, *resto, ultimo = lista
print(primero)  # 1
print(resto)    # [2, 3, 4]
print(ultimo)   # 5
```

---

## 5. Operadores de Pertenencia

| Operador | Descripción | Ejemplo | Resultado | Uso común |
|----------|-------------|---------|-----------|-----------|
| `in` | Devuelve `True` si el valor está presente en la secuencia | `"a" in "hola"` | `True` | Listas, tuplas, cadenas, conjuntos, diccionarios |
| `not in` | Devuelve `True` si el valor NO está presente en la secuencia | `"x" not in "hola"` | `True` | Listas, tuplas, cadenas, conjuntos, diccionarios |

### Ejemplos de Operadores de Pertenencia:

```python
# Con cadenas
texto = "Python"
print("P" in texto)        # True
print("y" in texto)        # True
print("x" not in texto)    # True

# Con listas
frutas = ["manzana", "pera", "uva"]
print("manzana" in frutas)    # True
print("sandía" not in frutas) # True

# Con tuplas
numeros = (1, 2, 3, 4, 5)
print(3 in numeros)        # True
print(10 not in numeros)   # True

# Con conjuntos (set)
vocales = {"a", "e", "i", "o", "u"}
print("a" in vocales)      # True
print("b" not in vocales)  # True

# Con diccionarios (verifica las claves)
persona = {"nombre": "Ana", "edad": 25}
print("nombre" in persona)    # True
print("direccion" not in persona)  # True

# Verificar valores en diccionario
print("Ana" in persona.values())  # True

# Subcadenas
frase = "Aprender Python es divertido"
print("Python" in frase)     # True
print("Java" not in frase)   # True

# Caso práctico: validación
usuarios_permitidos = ["admin", "user1", "user2"]
usuario = "user1"

if usuario in usuarios_permitidos:
    print("Acceso permitido")
else:
    print("Acceso denegado")
```

---

## 6. Operadores de Identidad

| Operador | Descripción | Ejemplo | Resultado | Notas |
|----------|-------------|---------|-----------|-------|
| `is` | Devuelve `True` si ambas variables son el mismo objeto | `x is y` | `True/False` | (1) |
| `is not` | Devuelve `True` si ambas variables NO son el mismo objeto | `x is not y` | `True/False` | (1) |

### Notas sobre Operadores de Identidad:

1. Los operadores `is` e `is not` comprueban la **identidad del objeto**, no la igualdad de valores. Dos variables con el mismo valor pueden no ser el mismo objeto en memoria.

### Diferencia entre `==` e `is`:

```python
# == compara valores
# is compara identidad (mismo objeto en memoria)

a = [1, 2, 3]
b = [1, 2, 3]
c = a

print(a == b)    # True (mismo valor)
print(a is b)    # False (objetos diferentes en memoria)
print(a is c)    # True (mismo objeto)
print(id(a))     # ID único del objeto a
print(id(b))     # ID diferente
print(id(c))     # Mismo ID que a
```

### Ejemplos de Operadores de Identidad:

```python
# Comparación con None (uso recomendado de is)
valor = None
if valor is None:
    print("El valor es None")

# No recomendado con None
if valor == None:  # Funciona, pero no es la forma idiomática
    print("El valor es None")

# Con números pequeños (internado de Python)
x = 5
y = 5
print(x is y)    # True (números pequeños se reutilizan)

# Con números grandes
x = 1000
y = 1000
print(x is y)    # False (objetos diferentes)
print(x == y)    # True (mismo valor)

# Con cadenas (internado de strings)
s1 = "hola"
s2 = "hola"
print(s1 is s2)  # True (strings pequeños se internan)

# Con listas
lista1 = [1, 2, 3]
lista2 = [1, 2, 3]
lista3 = lista1

print(lista1 == lista2)    # True (mismo contenido)
print(lista1 is lista2)    # False (diferentes objetos)
print(lista1 is lista3)    # True (mismo objeto)

# Verificar tipo de objeto
x = 5
print(type(x) is int)      # True

# Uso en funciones
def procesar(dato=None):
    if dato is None:
        print("No se proporcionó dato")
    else:
        print(f"Procesando: {dato}")

procesar()        # No se proporcionó dato
procesar(10)      # Procesando: 10
```

### Casos de uso recomendados para `is`:

```python
# ✓ Comparar con None
if variable is None:
    pass

# ✓ Comparar con True/False (aunque == también funciona)
if bandera is True:
    pass

# ✓ Verificar si dos variables referencian el mismo objeto
if lista1 is lista2:
    print("Son el mismo objeto")

# ✗ NO usar is para comparar valores
if numero is 5:  # Evitar esto
    pass

# ✓ Usar == para comparar valores
if numero == 5:  # Correcto
    pass
```

---

## 📊 Tabla de Precedencia de Operadores

De mayor a menor precedencia:

| Operador | Descripción |
|----------|-------------|
| `()` | Paréntesis (agrupación) |
| `**` | Exponenciación |
| `+x`, `-x`, `~x` | Positivo, negativo, NOT bit a bit unario |
| `*`, `/`, `//`, `%` | Multiplicación, división, división entera, módulo |
| `+`, `-` | Suma, resta |
| `<<`, `>>` | Desplazamientos bit a bit |
| `&` | AND bit a bit |
| `^` | XOR bit a bit |
| `|` | OR bit a bit |
| `==`, `!=`, `<`, `<=`, `>`, `>=`, `is`, `is not`, `in`, `not in` | Comparaciones, identidad, pertenencia |
| `not` | NOT lógico |
| `and` | AND lógico |
| `or` | OR lógico |

### Ejemplo de precedencia:

```python
resultado = 2 + 3 * 4        # 14 (no 20)
resultado = (2 + 3) * 4      # 20
resultado = 2 ** 3 ** 2      # 512 (no 64) - la exponenciación es asociativa a la derecha
resultado = (2 ** 3) ** 2    # 64

# Con operadores lógicos
resultado = True or False and False  # True (and tiene mayor precedencia)
resultado = (True or False) and False  # False
```

---

## 🎯 Resumen Rápido

### Tipos de Operadores en Python:

1. **Aritméticos**: `+`, `-`, `*`, `/`, `//`, `%`, `**`
2. **Comparación**: `==`, `!=`, `<`, `>`, `<=`, `>=`
3. **Lógicos**: `and`, `or`, `not`
4. **Asignación**: `=`, `+=`, `-=`, `*=`, `/=`, etc.
5. **Pertenencia**: `in`, `not in`
6. **Identidad**: `is`, `is not`

### Mejores Prácticas:

- Usa `==` para comparar valores
- Usa `is` solo para comparar con `None`, `True`, o `False`
- Usa `in` para verificar pertenencia en secuencias
- Aprovecha los operadores de asignación compuesta (`+=`, `-=`, etc.) para código más limpio
- Ten en cuenta la precedencia de operadores o usa paréntesis para mayor claridad

---

## 📚 Referencias

- [Documentación oficial de Python - Operadores](https://docs.python.org/es/3/library/operator.html)
- [PEP 8 - Guía de estilo para Python](https://pep8.org/)
- [Python Tutorial - Expresiones](https://docs.python.org/es/3/tutorial/introduction.html)