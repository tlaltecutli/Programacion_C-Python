# MÓDULO 2: PROGRAMACIÓN EN PYTHON
## Semana 6: Introducción a Python y Sintaxis Básica

---

## CLASE 11: FUNDAMENTOS DE PYTHON Y CONFIGURACIÓN DEL ENTORNO

### 1. Características y Ventajas de Python

#### ¿Qué es Python?
Python es un lenguaje de programación interpretado, de alto nivel y de propósito general, creado por Guido van Rossum en 1991.

#### Características Principales

**Lenguaje Interpretado**
- No requiere compilación previa
- El código se ejecuta línea por línea
- Facilita la depuración y el desarrollo rápido

**Sintaxis Simple y Legible**
- Utiliza indentación en lugar de llaves
- Código similar al lenguaje natural
- Menos líneas de código que otros lenguajes

**Tipado Dinámico**
- No es necesario declarar el tipo de variable
- El tipo se asigna automáticamente
- Mayor flexibilidad en el desarrollo

**Multiplataforma**
- Funciona en Windows, Linux, macOS
- Mismo código en diferentes sistemas operativos

**Amplia Biblioteca Estándar**
- Miles de módulos y paquetes disponibles
- Soluciones para casi cualquier problema
- Comunidad muy activa

#### Ventajas de Python

1. **Fácil de Aprender**: Sintaxis intuitiva, ideal para principiantes
2. **Versátil**: Web, ciencia de datos, IA, automatización, juegos
3. **Gran Demanda Laboral**: Uno de los lenguajes más solicitados
4. **Comunidad Enorme**: Abundante documentación y recursos
5. **Desarrollo Rápido**: Menos código, más productividad

#### Aplicaciones Comunes

- **Desarrollo Web**: Django, Flask
- **Ciencia de Datos**: Pandas, NumPy
- **Machine Learning**: TensorFlow, Scikit-learn
- **Automatización**: Scripts, web scraping
- **Desarrollo de Juegos**: Pygame
- **Desktop Applications**: Tkinter, PyQt

---

### 2. Configuración de Python en VSCode

#### Paso 1: Instalación de Python

**Windows:**
```bash
# Descargar desde python.org
# Versión recomendada: Python 3.11 o superior
# IMPORTANTE: Marcar "Add Python to PATH" durante la instalación
```

**Verificar la instalación:**
```bash
# Abrir terminal o CMD
python --version
# o
python3 --version

# Debe mostrar: Python 3.x.x
```

#### Paso 2: Configurar VSCode

**Abrir Visual Studio Code**

1. Ir a la pestaña de extensiones (Ctrl + Shift + X)
2. Buscar "Python"
3. Instalar la extensión oficial de Microsoft

---

### 3. Instalación de Extensiones y Paquetes

#### Extensiones Recomendadas para VSCode

**1. Python (Microsoft)** - Esencial
- IntelliSense (autocompletado)
- Linting (detección de errores)
- Debugging
- Formateo de código

**2. Pylance** - Rendimiento mejorado
- Análisis de tipos
- Autocompletado avanzado
- Refactorización

**3. Python Indent** - Corrección automática
- Corrige la indentación automáticamente

**4. autoDocstring** - Documentación
- Genera docstrings automáticamente

**5. Python Test Explorer** - Testing
- Interfaz visual para pruebas

#### Instalación de Paquetes con pip

**¿Qué es pip?**
- Gestor de paquetes de Python
- Permite instalar bibliotecas externas

**Comandos básicos:**
```bash
# Verificar pip
pip --version

# Instalar un paquete
pip install nombre_paquete

# Instalar versión específica
pip install nombre_paquete==1.2.3

# Listar paquetes instalados
pip list

# Actualizar un paquete
pip install --upgrade nombre_paquete

# Desinstalar un paquete
pip uninstall nombre_paquete
```

**Ejemplo práctico:**
```bash
# Instalar paquetes útiles para comenzar
pip install pylint  # Análisis de código
pip install black   # Formateo automático
pip install pytest  # Framework de testing
```

---

### 4. Sintaxis Básica e Indentación

#### La Indentación en Python

La indentación (espacios al inicio de línea) es **obligatoria** en Python y define bloques de código.

**Ejemplo:**
```python
# Correcto
if True:
    print("Este código está indentado")
    print("Pertenece al bloque if")

# Incorrecto - Error de indentación
if True:
print("Esto causará un error")
```

**Reglas de Indentación:**
- Usar 4 espacios (estándar PEP 8)
- Ser consistente en todo el código
- VSCode lo maneja automáticamente

#### Comentarios

```python
# Esto es un comentario de una línea

"""
Esto es un comentario
de múltiples líneas
(también llamado docstring)
"""

x = 5  # Comentario al final de una línea
```

#### Convenciones de Nombres (PEP 8)

```python
# Variables y funciones: snake_case
mi_variable = 10
nombre_completo = "Juan"

def calcular_promedio():
    pass

# Constantes: MAYÚSCULAS
PI = 3.14159
MAX_INTENTOS = 3

# Clases: PascalCase
class MiClase:
    pass
```

---

### 5. Primer Programa en Python

#### Ejemplo 1: Hola Mundo

```python
# hola_mundo.py
print("¡Hola, Mundo!")
print("Bienvenido a Python")
```

**Ejecutar:**
- Clic derecho → "Run Python File"
- O presionar F5
- O en terminal: `python hola_mundo.py`

#### Ejemplo 2: Programa con Variables

```python
# saludo_personalizado.py

# Definir variables
nombre = "María"
edad = 25
ciudad = "México"

# Mostrar información
print("=== INFORMACIÓN PERSONAL ===")
print("Nombre:", nombre)
print("Edad:", edad)
print("Ciudad:", ciudad)
```

**Salida:**
```
=== INFORMACIÓN PERSONAL ===
Nombre: María
Edad: 25
Ciudad: México
```

#### Ejemplo 3: Calculadora Simple

```python
# calculadora_basica.py

# Definir números
numero1 = 10
numero2 = 3

# Realizar operaciones
suma = numero1 + numero2
resta = numero1 - numero2
multiplicacion = numero1 * numero2
division = numero1 / numero2

# Mostrar resultados
print("Calculadora Simple")
print("-" * 30)
print(f"{numero1} + {numero2} = {suma}")
print(f"{numero1} - {numero2} = {resta}")
print(f"{numero1} * {numero2} = {multiplicacion}")
print(f"{numero1} / {numero2} = {division}")
```

**Salida:**
```
Calculadora Simple
------------------------------
10 + 3 = 13
10 - 3 = 7
10 * 3 = 30
10 / 3 = 3.3333333333333335
```

#### Ejemplo 4: Programa con Estructura

```python
# programa_completo.py

# 1. Importar módulos (veremos más adelante)
import datetime

# 2. Definir constantes
EMPRESA = "TechCorp"

# 3. Variables
empleado = "Carlos Ruiz"
salario = 45000.50

# 4. Calcular información
anio_actual = datetime.datetime.now().year
salario_mensual = salario / 12

# 5. Mostrar reporte
print("=" * 40)
print(f"REPORTE DE EMPLEADO - {EMPRESA}")
print("=" * 40)
print(f"Nombre: {empleado}")
print(f"Salario Anual: ${salario:,.2f}")
print(f"Salario Mensual: ${salario_mensual:,.2f}")
print(f"Año: {anio_actual}")
print("=" * 40)
```

---

## CLASE 12: TIPOS DE DATOS Y OPERADORES

### 1. Tipos de Datos en Python

Python tiene varios tipos de datos incorporados. Los fundamentales son:

#### int (Enteros)

```python
# Números enteros positivos y negativos
edad = 25
temperatura = -5
poblacion = 1000000

# Python maneja enteros de tamaño arbitrario
numero_grande = 999999999999999999999999999999

print(type(edad))  # <class 'int'>
```

**Operaciones con int:**
```python
a = 10
b = 3

print(a + b)   # 13 - Suma
print(a - b)   # 7 - Resta
print(a * b)   # 30 - Multiplicación
print(a / b)   # 3.333... - División (retorna float)
print(a // b)  # 3 - División entera
print(a % b)   # 1 - Módulo (resto)
print(a ** b)  # 1000 - Potencia
```

#### float (Números de Punto Flotante)

```python
# Números con decimales
precio = 19.99
pi = 3.14159
temperatura = -10.5
cientifico = 1.5e-4  # Notación científica: 0.00015

print(type(precio))  # <class 'float'>
```

**Operaciones con float:**
```python
x = 10.5
y = 2.5

print(x + y)      # 13.0
print(x * y)      # 26.25
print(round(x))   # 11 - Redondeo
print(round(pi, 2))  # 3.14 - Redondeo a 2 decimales
```

**Conversión entre int y float:**
```python
entero = 10
decimal = 3.14

# int a float
flotante = float(entero)  # 10.0

# float a int (trunca decimales)
numero_entero = int(decimal)  # 3

print(f"{entero} → {flotante}")
print(f"{decimal} → {numero_entero}")
```

#### str (Cadenas de Texto)

```python
# Diferentes formas de definir strings
nombre = "Juan"
apellido = 'Pérez'
mensaje = """Este es un texto
de múltiples líneas"""

print(type(nombre))  # <class 'str'>
```

**Operaciones con strings:**
```python
nombre = "Python"
version = "3.11"

# Concatenación
lenguaje = nombre + " " + version  # "Python 3.11"

# Repetición
linea = "-" * 20  # "--------------------"

# Indexación (empieza en 0)
primera_letra = nombre[0]    # "P"
ultima_letra = nombre[-1]    # "n"

# Slicing (rebanado)
primeras_tres = nombre[0:3]  # "Pyt"
desde_segunda = nombre[1:]   # "ython"
hasta_cuarta = nombre[:4]    # "Pyth"

print(f"Primera letra: {primera_letra}")
print(f"Primeras tres: {primeras_tres}")
```

**Métodos útiles de strings:**
```python
texto = "  Hola Mundo  "

print(texto.upper())        # "  HOLA MUNDO  "
print(texto.lower())        # "  hola mundo  "
print(texto.strip())        # "Hola Mundo" (quita espacios)
print(texto.replace("Mundo", "Python"))  # "  Hola Python  "
print(len(texto))           # 14 (longitud)
print("Hola" in texto)      # True
print(texto.startswith(" ")) # True
print(texto.split())        # ['Hola', 'Mundo']
```

**f-strings (formateo moderno):**
```python
nombre = "Ana"
edad = 28
altura = 1.65

# f-string (Python 3.6+)
mensaje = f"Me llamo {nombre}, tengo {edad} años y mido {altura}m"
print(mensaje)

# Expresiones dentro de f-strings
print(f"El próximo año tendré {edad + 1} años")

# Formateo de números
precio = 1234.5678
print(f"Precio: ${precio:.2f}")  # "Precio: $1234.57"
```

#### bool (Booleanos)

```python
# Solo dos valores: True o False
es_mayor = True
tiene_descuento = False

print(type(es_mayor))  # <class 'bool'>
```

**Operaciones booleanas:**
```python
a = True
b = False

print(a and b)   # False - AND lógico
print(a or b)    # True - OR lógico
print(not a)     # False - NOT lógico

# Comparaciones retornan booleanos
print(5 > 3)     # True
print(10 == 10)  # True
print(7 != 7)    # False
```

---

### 2. Variables y Asignación Dinámica

#### Declaración de Variables

En Python, **no se declara el tipo** de variable explícitamente.

```python
# Python determina el tipo automáticamente
x = 5           # int
y = 3.14        # float
nombre = "Ana"  # str
activo = True   # bool

# Verificar tipo
print(type(x))      # <class 'int'>
print(type(nombre)) # <class 'str'>
```

#### Asignación Múltiple

```python
# Asignar mismo valor a múltiples variables
a = b = c = 0

# Asignar diferentes valores
x, y, z = 1, 2, 3
nombre, edad = "Luis", 30

print(f"{nombre} tiene {edad} años")
```

#### Reasignación Dinámica

```python
# Una variable puede cambiar de tipo
dato = 100          # int
print(type(dato))   # <class 'int'>

dato = "Hola"       # ahora es str
print(type(dato))   # <class 'str'>

dato = True         # ahora es bool
print(type(dato))   # <class 'bool'>
```

#### Convenciones de Nombres

```python
# ✓ Correcto
nombre_usuario = "juan123"
edad_minima = 18
calcular_total = True

# ✗ Incorrecto (pero funcional)
NombreUsuario = "juan"  # Reservado para clases
nombreusuario = "juan"  # Difícil de leer
2nombre = "juan"        # ERROR: no puede empezar con número
nombre-usuario = "juan" # ERROR: guiones no permitidos
```

---

### 3. Operadores en Python

#### Operadores Aritméticos

```python
a = 10
b = 3

print(f"Suma: {a + b}")           # 13
print(f"Resta: {a - b}")          # 7
print(f"Multiplicación: {a * b}") # 30
print(f"División: {a / b}")       # 3.333...
print(f"División entera: {a // b}") # 3
print(f"Módulo: {a % b}")         # 1
print(f"Potencia: {a ** b}")      # 1000
```

**Ejemplo práctico: Conversión de temperatura**
```python
# Celsius a Fahrenheit
celsius = 25
fahrenheit = (celsius * 9/5) + 32
print(f"{celsius}°C = {fahrenheit}°F")  # 25°C = 77.0°F
```

#### Operadores de Comparación

```python
x = 10
y = 5

print(x == y)  # False - Igual a
print(x != y)  # True - Diferente de
print(x > y)   # True - Mayor que
print(x < y)   # False - Menor que
print(x >= y)  # True - Mayor o igual
print(x <= y)  # False - Menor o igual
```

**Ejemplo práctico:**
```python
edad = 18
es_mayor_edad = edad >= 18
print(f"¿Es mayor de edad? {es_mayor_edad}")  # True
```

#### Operadores Lógicos

```python
# AND (y) - Ambas condiciones deben ser True
tiene_licencia = True
tiene_auto = False
puede_conducir = tiene_licencia and tiene_auto
print(f"¿Puede conducir? {puede_conducir}")  # False

# OR (o) - Al menos una condición debe ser True
es_fin_semana = True
es_feriado = False
puede_descansar = es_fin_semana or es_feriado
print(f"¿Puede descansar? {puede_descansar}")  # True

# NOT (no) - Invierte el valor
esta_lloviendo = True
hace_sol = not esta_lloviendo
print(f"¿Hace sol? {hace_sol}")  # False
```

#### Operadores de Asignación

```python
x = 10

x += 5   # x = x + 5  → x = 15
x -= 3   # x = x - 3  → x = 12
x *= 2   # x = x * 2  → x = 24
x /= 4   # x = x / 4  → x = 6.0
x //= 2  # x = x // 2 → x = 3.0
x %= 2   # x = x % 2  → x = 1.0
x **= 3  # x = x ** 3 → x = 1.0

print(f"Resultado final: {x}")
```

---

### 4. Entrada y Salida (input, print)

#### La Función print()

**Sintaxis básica:**
```python
print("Hola, mundo")
```

**Múltiples argumentos:**
```python
nombre = "Carlos"
edad = 30
print("Nombre:", nombre, "Edad:", edad)
# Salida: Nombre: Carlos Edad: 30
```

**Separador personalizado:**
```python
print("Uno", "Dos", "Tres", sep=" - ")
# Salida: Uno - Dos - Tres
```

**Final de línea personalizado:**
```python
print("Cargando", end="...")
print("Completado")
# Salida: Cargando...Completado
```

**Formateo avanzado:**
```python
nombre = "Elena"
edad = 27
salario = 35000.75

# Método 1: f-strings (recomendado)
print(f"Empleado: {nombre}, Edad: {edad}, Salario: ${salario:,.2f}")

# Método 2: format()
print("Empleado: {}, Edad: {}, Salario: ${:,.2f}".format(nombre, edad, salario))

# Método 3: % (antiguo)
print("Empleado: %s, Edad: %d, Salario: $%.2f" % (nombre, edad, salario))
```

#### La Función input()

```python
# Leer entrada del usuario (siempre retorna string)
nombre = input("¿Cuál es tu nombre? ")
print(f"Hola, {nombre}")
```

**Convertir entrada a números:**
```python
# Leer un entero
edad_str = input("¿Cuántos años tienes? ")
edad = int(edad_str)

# O directamente
edad = int(input("¿Cuántos años tienes? "))

# Leer un float
altura = float(input("¿Cuál es tu altura en metros? "))

print(f"Tienes {edad} años y mides {altura}m")
```

**Ejemplo completo: Calculadora interactiva**
```python
print("=== CALCULADORA SIMPLE ===")
print()

# Solicitar números
num1 = float(input("Ingresa el primer número: "))
num2 = float(input("Ingresa el segundo número: "))

# Realizar cálculos
suma = num1 + num2
resta = num1 - num2
multiplicacion = num1 * num2
division = num1 / num2 if num2 != 0 else "No definido"

# Mostrar resultados
print("\n--- RESULTADOS ---")
print(f"{num1} + {num2} = {suma}")
print(f"{num1} - {num2} = {resta}")
print(f"{num1} × {num2} = {multiplicacion}")
print(f"{num1} ÷ {num2} = {division}")
```

**Ejemplo: Sistema de registro**
```python
print("=== REGISTRO DE USUARIO ===\n")

# Recolectar información
nombre = input("Nombre completo: ")
edad = int(input("Edad: "))
email = input("Correo electrónico: ")
ciudad = input("Ciudad: ")

# Confirmar datos
print("\n--- CONFIRMACIÓN DE DATOS ---")
print(f"Nombre: {nombre}")
print(f"Edad: {edad} años")
print(f"Email: {email}")
print(f"Ciudad: {ciudad}")
print("\n¡Registro exitoso!")
```

---

### 5. Diferencias Principales entre C y Python

#### Tabla Comparativa

| Aspecto | C | Python |
|---------|---|--------|
| **Tipo de lenguaje** | Compilado | Interpretado |
| **Declaración de tipos** | Obligatoria | Dinámica |
| **Gestión de memoria** | Manual | Automática |
| **Sintaxis** | Llaves `{}` | Indentación |
| **Punto y coma** | Obligatorio `;` | No requerido |
| **Strings** | Array de caracteres | Tipo nativo |
| **Velocidad** | Muy rápida | Más lenta |
| **Facilidad** | Complejo | Simple |

#### Ejemplo Comparativo: Hola Mundo

**C:**
```c
#include <stdio.h>

int main() {
    printf("Hola, Mundo\n");
    return 0;
}
```

**Python:**
```python
print("Hola, Mundo")
```

#### Ejemplo Comparativo: Variables

**C:**
```c
#include <stdio.h>

int main() {
    int edad = 25;
    float altura = 1.75;
    char nombre[] = "Juan";
    
    printf("Nombre: %s\n", nombre);
    printf("Edad: %d\n", edad);
    printf("Altura: %.2f\n", altura);
    
    return 0;
}
```

**Python:**
```python
edad = 25
altura = 1.75
nombre = "Juan"

print(f"Nombre: {nombre}")
print(f"Edad: {edad}")
print(f"Altura: {altura:.2f}")
```

#### Ejemplo Comparativo: Entrada de Usuario

**C:**
```c
#include <stdio.h>

int main() {
    int edad;
    printf("¿Cuántos años tienes? ");
    scanf("%d", &edad);
    printf("Tienes %d años\n", edad);
    return 0;
}
```

**Python:**
```python
edad = int(input("¿Cuántos años tienes? "))
print(f"Tienes {edad} años")
```

#### Ventajas de Python sobre C

1. **Código más corto**: Menos líneas para la misma funcionalidad
2. **Sin gestión de memoria**: No hay malloc/free
3. **Tipos dinámicos**: No declarar tipos explícitamente
4. **Strings nativos**: Fácil manipulación de texto
5. **Desarrollo rápido**: Menos tiempo de programación
6. **Legibilidad**: Código más claro y entendible

#### Cuándo usar C vs Python

**Usar C cuando:**
- Se necesita máximo rendimiento
- Programación de sistemas (drivers, OS)
- Aplicaciones embebidas
- Control preciso de hardware

**Usar Python cuando:**
- Desarrollo rápido es prioridad
- Ciencia de datos y análisis
- Automatización y scripting
- Prototipado rápido
- Aplicaciones web

---

## EJERCICIOS PRÁCTICOS

### Ejercicio 1: Calculadora de IMC
```python
"""
Crear un programa que calcule el Índice de Masa Corporal (IMC)
Fórmula: IMC = peso / (altura ** 2)
"""

print("=== CALCULADORA DE IMC ===\n")

# Solicitar datos
nombre = input("Nombre: ")
peso = float(input("Peso en kg: "))
altura = float(input("Altura en metros: "))

# Calcular IMC
imc = peso / (altura ** 2)

# Mostrar resultado
print(f"\n--- RESULTADO ---")
print(f"Paciente: {nombre}")
print(f"IMC: {imc:.2f}")

# Interpretación
if imc < 18.5:
    categoria = "Bajo peso"
elif imc < 25:
    categoria = "Peso normal"
elif imc < 30:
    categoria = "Sobrepeso"
else:
    categoria = "Obesidad"

print(f"Categoría: {categoria}")
```

### Ejercicio 2: Conversor de Unidades
```python
"""
Programa que convierte entre diferentes unidades
"""

print("=== CONVERSOR DE UNIDADES ===\n")
print("1. Kilómetros a Millas")
print("2. Celsius a Fahrenheit")
print("3. Kilogramos a Libras")

opcion = int(input("\nElige una opción (1-3): "))

if opcion == 1:
    km = float(input("Kilómetros: "))
    millas = km * 0.621371
    print(f"{km} km = {millas:.2f} millas")
    
elif opcion == 2:
    celsius = float(input("Grados Celsius: "))
    fahrenheit = (celsius * 9/5) + 32
    print(f"{celsius}°C = {fahrenheit:.2f}°F")
    
elif opcion == 3:
    kg = float(input("Kilogramos: "))
    libras = kg * 2.20462
    print(f"{kg} kg = {libras:.2f} libras")
    
else:
    print("Opción inválida")
```

### Ejercicio 3: Calculadora de Propina
```python
"""
Programa que calcula la propina y el total a pagar
"""

print("=== CALCULADORA DE PROPINA ===\n")

# Datos
cuenta = float(input("Total de la cuenta: $"))
porcentaje_propina = float(input("Porcentaje de propina (ej: 15): "))
personas = int(input("Número de personas: "))

# Cálculos
propina = cuenta * (porcentaje_propina / 100)
total = cuenta + propina
por_persona = total / personas

# Resultados
print(f"\n--- DESGLOSE ---")
print(f"Cuenta: ${cuenta:.2f}")
print(f"Propina ({porcentaje_propina}%): ${propina:.2f}")
print(f"Total: ${total:.2f}")
print(f"Por persona: ${por_persona:.2f}")
```

### Ejercicio 4: Información Personal
```python
"""
Programa que recopila y muestra información personal
"""

print("=== FORMULARIO DE REGISTRO ===\n")

# Recopilar datos
nombre = input("Nombre completo: ")
edad = int(input("Edad: "))
altura = float(input("Altura (m): "))
peso = float(input("Peso (kg): "))
ciudad = input("Ciudad: ")
profesion = input("Profesión: ")
pasatiempo = input("Pasatiempo favorito: ")

# Calcular año de nacimiento
anio_actual = 2025
anio_nacimiento = anio_actual - edad

# Calcular IMC
imc = peso / (altura ** 2)

# Mostrar ficha
print("\n" + "=" * 50)
print("FICHA PERSONAL")
print("=" * 50)
print(f"Nombre: {nombre}")
print(f"Edad: {edad} años (nacido en {anio_nacimiento})")
print(f"Estatura: {altura}m | Peso: {peso}kg | IMC: {imc:.1f}")
print(f"Ubicación: {ciudad}")
print(f"Profesión: {profesion}")
print(f"Pasatiempo: {pasatiempo}")
print("=" * 50)
```

---

## RECURSOS ADICIONALES

### Documentación Oficial
- Python.org: https://www.python.org/
- Python Documentation: https://docs.python.org/3/
- PEP 8 (Guía de Estilo): https://pep8.org/

### Herramientas Online
- Python Tutor (Visualizador): https://pythontutor.com/
- Replit (IDE Online): https://replit.com/
- Google Colab (Notebooks): https://colab.research.google.com/

### Práctica
- HackerRank Python: https://www.hackerrank.com/domains/python
- LeetCode: https://leetcode.com/
- Exercism Python Track: https://exercism.org/tracks/python

---

## RESUMEN DE LA SEMANA 6

### Conceptos Clave Aprendidos

✅ Características y ventajas de Python
✅ Configuración del entorno de desarrollo
✅ Sintaxis básica e indentación
✅ Tipos de datos fundamentales (int, float, str, bool)
✅ Variables y asignación dinámica
✅ Operadores (aritméticos, comparación, lógicos)
✅ Entrada y salida de datos
✅ Diferencias entre C y Python

### Próximos Pasos

En la **Semana 7** continuaremos con:
- Estructuras de control (if, elif, else)
- Bucles (for, while)
- Listas y tuplas
- Funciones básicas

---

## GLOSARIO

**Intérprete**: Programa que ejecuta código Python línea por línea

**Tipado Dinámico**: El tipo de dato se determina automáticamente

**Indentación**: Espacios al inicio de línea que definen bloques de código

**Variable**: Contenedor para almacenar valores en memoria

**Operador**: Símbolo que realiza operaciones sobre valores

**Casting**: Conversión de un tipo de dato a otro

**String**: Cadena de texto (secuencia de caracteres)

**Booleano**: Tipo de dato que solo puede ser True o False

**f-string**: Formato moderno de strings en Python (Python 3.6+)

---

## PROYECTO INTEGRADOR: SISTEMA DE REGISTRO DE ESTUDIANTES

Este proyecto integra todos los conceptos aprendidos en la Semana 6.

```python
"""
SISTEMA DE REGISTRO DE ESTUDIANTES
Proyecto integrador - Semana 6
"""

import datetime

# Constantes del sistema
NOMBRE_ESCUELA = "Instituto Tecnológico Superior"
ANIO_ACTUAL = datetime.datetime.now().year

# Banner de bienvenida
print("=" * 60)
print(f"{'SISTEMA DE REGISTRO DE ESTUDIANTES':^60}")
print(f"{NOMBRE_ESCUELA:^60}")
print("=" * 60)
print()

# Recopilación de datos personales
print("--- DATOS PERSONALES ---")
nombre_completo = input("Nombre completo: ")
edad = int(input("Edad: "))
genero = input("Género (M/F/Otro): ")
fecha_nacimiento = input("Fecha de nacimiento (dd/mm/aaaa): ")

print("\n--- DATOS DE CONTACTO ---")
email = input("Correo electrónico: ")
telefono = input("Teléfono: ")
direccion = input("Dirección: ")
ciudad = input("Ciudad: ")

print("\n--- INFORMACIÓN ACADÉMICA ---")
carrera = input("Carrera: ")
semestre = int(input("Semestre: "))
promedio = float(input("Promedio actual: "))

print("\n--- DATOS ADICIONALES ---")
tiene_beca = input("¿Tiene beca? (si/no): ").lower() == "si"
practica_deporte = input("¿Practica algún deporte? (si/no): ").lower() == "si"

if practica_deporte:
    deporte = input("¿Cuál deporte? ")
else:
    deporte = "Ninguno"

# Cálculos
anio_nacimiento = ANIO_ACTUAL - edad
creditos_aprox = semestre * 6  # Aproximado: 6 materias por semestre
es_buen_promedio = promedio >= 8.0

# Generar número de matrícula
# Formato: AÑO + PRIMERA LETRA NOMBRE + EDAD + SEMESTRE
inicial = nombre_completo[0].upper()
matricula = f"{ANIO_ACTUAL}{inicial}{edad}{semestre}"

# Categoría según promedio
if promedio >= 9.0:
    categoria_academica = "Excelencia"
elif promedio >= 8.0:
    categoria_academica = "Bueno"
elif promedio >= 7.0:
    categoria_academica = "Regular"
else:
    categoria_academica = "Bajo"

# Mostrar ficha completa
print("\n\n")
print("=" * 60)
print(f"{'FICHA DE REGISTRO - ESTUDIANTE':^60}")
print("=" * 60)

print("\n📋 INFORMACIÓN PERSONAL")
print("-" * 60)
print(f"Nombre:              {nombre_completo}")
print(f"Matrícula:           {matricula}")
print(f"Edad:                {edad} años (Nacimiento: {anio_nacimiento})")
print(f"Género:              {genero}")
print(f"Fecha de Nacimiento: {fecha_nacimiento}")

print("\n📞 CONTACTO")
print("-" * 60)
print(f"Email:               {email}")
print(f"Teléfono:            {telefono}")
print(f"Dirección:           {direccion}")
print(f"Ciudad:              {ciudad}")

print("\n🎓 INFORMACIÓN ACADÉMICA")
print("-" * 60)
print(f"Carrera:             {carrera}")
print(f"Semestre:            {semestre}°")
print(f"Promedio:            {promedio:.2f}")
print(f"Categoría:           {categoria_academica}")
print(f"Créditos (aprox):    {creditos_aprox}")
print(f"Beca:                {'Sí' if tiene_beca else 'No'}")
print(f"Deporte:             {deporte}")

print("\n📊 ESTADÍSTICAS")
print("-" * 60)
creditos_restantes = 48 - creditos_aprox  # Suponiendo 48 créditos totales
porcentaje_avance = (creditos_aprox / 48) * 100

print(f"Avance de carrera:   {porcentaje_avance:.1f}%")
print(f"Créditos restantes:  {creditos_restantes}")
print(f"Estado académico:    {'APROBADO' if es_buen_promedio else 'EN OBSERVACIÓN'}")

if tiene_beca:
    monto_beca = promedio * 500  # $500 por punto de promedio
    print(f"Monto de beca:       ${monto_beca:,.2f} MXN")

print("\n" + "=" * 60)
print(f"{'Registro completado exitosamente':^60}")
print(f"{'Fecha: ' + str(datetime.datetime.now().strftime('%d/%m/%Y %H:%M')):^60}")
print("=" * 60)

# Mensaje personalizado
print("\n💬 MENSAJE:")
if promedio >= 9.0:
    print(f"¡Felicidades {nombre_completo.split()[0]}! Tu desempeño es excelente.")
elif promedio >= 8.0:
    print(f"Muy bien {nombre_completo.split()[0]}, sigue esforzándote.")
else:
    print(f"{nombre_completo.split()[0]}, recuerda que puedes mejorar tu promedio.")

print("\n¡Bienvenido al ciclo escolar!")
```

### Ejemplo de Ejecución del Proyecto

```
============================================================
        SISTEMA DE REGISTRO DE ESTUDIANTES
          Instituto Tecnológico Superior
============================================================

--- DATOS PERSONALES ---
Nombre completo: María González López
Edad: 20
Género (M/F/Otro): F
Fecha de nacimiento (dd/mm/aaaa): 15/03/2005

--- DATOS DE CONTACTO ---
Correo electrónico: maria.gonzalez@email.com
Teléfono: 5551234567
Dirección: Av. Universidad 123
Ciudad: Ciudad de México

--- INFORMACIÓN ACADÉMICA ---
Carrera: Ingeniería en Sistemas
Semestre: 4
Promedio actual: 8.7

--- DATOS ADICIONALES ---
¿Tiene beca? (si/no): si
¿Practica algún deporte? (si/no): si
¿Cuál deporte? Voleibol


============================================================
              FICHA DE REGISTRO - ESTUDIANTE
============================================================

📋 INFORMACIÓN PERSONAL
------------------------------------------------------------
Nombre:              María González López
Matrícula:           2025M204
Edad:                20 años (Nacimiento: 2005)
Género:              F
Fecha de Nacimiento: 15/03/2005

📞 CONTACTO
------------------------------------------------------------
Email:               maria.gonzalez@email.com
Teléfono:            5551234567
Dirección:           Av. Universidad 123
Ciudad:              Ciudad de México

🎓 INFORMACIÓN ACADÉMICA
------------------------------------------------------------
Carrera:             Ingeniería en Sistemas
Semestre:            4°
Promedio:            8.70
Categoría:           Bueno
Créditos (aprox):    24
Beca:                Sí
Deporte:             Voleibol

📊 ESTADÍSTICAS
------------------------------------------------------------
Avance de carrera:   50.0%
Créditos restantes:  24
Estado académico:    APROBADO
Monto de beca:       $4,350.00 MXN

============================================================
            Registro completado exitosamente
              Fecha: 14/10/2025 15:30
============================================================

💬 MENSAJE:
Muy bien María, sigue esforzándote.

¡Bienvenido al ciclo escolar!
```

---

## EJERCICIOS ADICIONALES CON SOLUCIONES

### Ejercicio 5: Calculadora de Edad Detallada

**Enunciado:** Crear un programa que calcule la edad en años, meses y días aproximados.

```python
"""
Calculadora de edad detallada
"""

print("=== CALCULADORA DE EDAD ===\n")

# Solicitar fecha de nacimiento
print("Ingresa tu fecha de nacimiento:")
dia_nac = int(input("Día: "))
mes_nac = int(input("Mes: "))
anio_nac = int(input("Año: "))

# Fecha actual (ejemplo)
dia_actual = 14
mes_actual = 10
anio_actual = 2025

# Calcular años
anios = anio_actual - anio_nac

# Calcular meses aproximados
if mes_actual >= mes_nac:
    meses = mes_actual - mes_nac
else:
    meses = 12 - mes_nac + mes_actual
    anios -= 1

# Calcular días aproximados
if dia_actual >= dia_nac:
    dias = dia_actual - dia_nac
else:
    dias = 30 - dia_nac + dia_actual
    meses -= 1

# Calcular totales
total_meses = anios * 12 + meses
total_dias = anios * 365 + meses * 30 + dias
total_horas = total_dias * 24

# Mostrar resultados
print(f"\n--- RESULTADOS ---")
print(f"Tienes {anios} años, {meses} meses y {dias} días")
print(f"\nEn total:")
print(f"• {total_meses} meses")
print(f"• {total_dias} días (aproximado)")
print(f"• {total_horas:,} horas (aproximado)")
```

### Ejercicio 6: Sistema de Descuentos

**Enunciado:** Crear un programa que calcule descuentos según el monto de compra.

```python
"""
Sistema de cálculo de descuentos
Descuentos:
- Menos de $500: 0%
- $500 - $1000: 5%
- $1001 - $2000: 10%
- Más de $2000: 15%
"""

print("=== SISTEMA DE DESCUENTOS ===\n")

# Datos de compra
producto = input("Nombre del producto: ")
precio = float(input("Precio: $"))
cantidad = int(input("Cantidad: "))

# Calcular subtotal
subtotal = precio * cantidad

# Determinar descuento
if subtotal < 500:
    porcentaje_desc = 0
elif subtotal <= 1000:
    porcentaje_desc = 5
elif subtotal <= 2000:
    porcentaje_desc = 10
else:
    porcentaje_desc = 15

# Calcular montos
descuento = subtotal * (porcentaje_desc / 100)
total = subtotal - descuento
iva = total * 0.16  # IVA del 16%
total_final = total + iva

# Mostrar ticket
print("\n" + "=" * 40)
print("TICKET DE COMPRA")
print("=" * 40)
print(f"Producto: {producto}")
print(f"Precio unitario: ${precio:.2f}")
print(f"Cantidad: {cantidad}")
print("-" * 40)
print(f"Subtotal: ${subtotal:.2f}")
print(f"Descuento ({porcentaje_desc}%): -${descuento:.2f}")
print(f"Subtotal con descuento: ${total:.2f}")
print(f"IVA (16%): ${iva:.2f}")
print("=" * 40)
print(f"TOTAL A PAGAR: ${total_final:.2f}")
print("=" * 40)
print("\n¡Gracias por su compra!")
```

### Ejercicio 7: Conversor de Tiempo

**Enunciado:** Convertir segundos a horas, minutos y segundos.

```python
"""
Conversor de tiempo
Convierte segundos a formato HH:MM:SS
"""

print("=== CONVERSOR DE TIEMPO ===\n")

# Solicitar segundos totales
segundos_totales = int(input("Ingresa los segundos: "))

# Calcular conversiones
horas = segundos_totales // 3600
minutos = (segundos_totales % 3600) // 60
segundos = segundos_totales % 60

# Mostrar resultado
print(f"\n{segundos_totales} segundos equivalen a:")
print(f"{horas:02d}:{minutos:02d}:{segundos:02d}")
print(f"\n• {horas} horas")
print(f"• {minutos} minutos")
print(f"• {segundos} segundos")

# Conversiones adicionales
dias = horas // 24
semanas = dias // 7

if dias > 0:
    print(f"\nTambién equivalen a:")
    print(f"• {dias} días y {horas % 24} horas")
    if semanas > 0:
        print(f"• {semanas} semanas y {dias % 7} días")
```

### Ejercicio 8: Calculadora de Salario

**Enunciado:** Calcular el salario neto después de deducciones.

```python
"""
Calculadora de salario neto
Calcula el salario después de impuestos y deducciones
"""

print("=== CALCULADORA DE SALARIO ===\n")

# Datos del empleado
nombre = input("Nombre del empleado: ")
salario_bruto = float(input("Salario bruto mensual: $"))
horas_extra = int(input("Horas extra trabajadas: "))
pago_hora_extra = float(input("Pago por hora extra: $"))

# Cálculos de ingresos
ingreso_horas_extra = horas_extra * pago_hora_extra
ingreso_total = salario_bruto + ingreso_horas_extra

# Cálculos de deducciones
# ISR (Impuesto Sobre la Renta) - Simplificado
if ingreso_total <= 7000:
    isr = ingreso_total * 0.02
elif ingreso_total <= 15000:
    isr = ingreso_total * 0.10
else:
    isr = ingreso_total * 0.16

# IMSS (5%)
imss = ingreso_total * 0.05

# Total deducciones
total_deducciones = isr + imss

# Salario neto
salario_neto = ingreso_total - total_deducciones

# Mostrar recibo
print("\n" + "=" * 50)
print(f"RECIBO DE NÓMINA - {nombre.upper()}")
print("=" * 50)

print("\n💰 INGRESOS")
print("-" * 50)
print(f"Salario base:        ${salario_bruto:>12,.2f}")
print(f"Horas extra ({horas_extra}h):    ${ingreso_horas_extra:>12,.2f}")
print("-" * 50)
print(f"TOTAL INGRESOS:      ${ingreso_total:>12,.2f}")

print("\n📉 DEDUCCIONES")
print("-" * 50)
print(f"ISR:                 ${isr:>12,.2f}")
print(f"IMSS:                ${imss:>12,.2f}")
print("-" * 50)
print(f"TOTAL DEDUCCIONES:   ${total_deducciones:>12,.2f}")

print("\n" + "=" * 50)
print(f"💵 SALARIO NETO:     ${salario_neto:>12,.2f}")
print("=" * 50)

# Información adicional
porcentaje_deduccion = (total_deducciones / ingreso_total) * 100
print(f"\n📊 Se dedujo el {porcentaje_deduccion:.2f}% del ingreso total")
```

---

## DESAFÍOS DE PROGRAMACIÓN

### Desafío 1: Calculadora Científica Básica ⭐⭐

Crear una calculadora que incluya operaciones avanzadas.

```python
"""
Calculadora Científica Básica
"""

print("=== CALCULADORA CIENTÍFICA ===\n")

num = float(input("Ingresa un número: "))

# Operaciones básicas
cuadrado = num ** 2
cubo = num ** 3
raiz_cuadrada = num ** 0.5

# Operaciones adicionales
inverso = 1 / num if num != 0 else "Indefinido"
porcentaje = num / 100
doble = num * 2
triple = num * 3

# Mostrar resultados
print(f"\n--- RESULTADOS PARA {num} ---")
print(f"Cuadrado:        {cuadrado}")
print(f"Cubo:            {cubo}")
print(f"Raíz cuadrada:   {raiz_cuadrada:.4f}")
print(f"Inverso (1/x):   {inverso}")
print(f"Porcentaje:      {porcentaje}%")
print(f"Doble:           {doble}")
print(f"Triple:          {triple}")

# Análisis del número
es_positivo = num > 0
es_par = int(num) % 2 == 0 if num == int(num) else False

print(f"\n--- ANÁLISIS ---")
print(f"Es positivo:     {es_positivo}")
print(f"Es negativo:     {not es_positivo and num != 0}")
print(f"Es par:          {es_par}")
```

### Desafío 2: Sistema de Calificaciones ⭐⭐⭐

Sistema completo de gestión de calificaciones.

```python
"""
Sistema de Calificaciones
Calcula promedios y determina el estado académico
"""

print("=== SISTEMA DE CALIFICACIONES ===\n")

# Datos del estudiante
nombre = input("Nombre del estudiante: ")
print("\nIngresa las calificaciones (0-10):")

# Solicitar calificaciones
mate = float(input("Matemáticas: "))
fisica = float(input("Física: "))
quimica = float(input("Química: "))
programacion = float(input("Programación: "))
ingles = float(input("Inglés: "))

# Validar que estén en rango
if not (0 <= mate <= 10 and 0 <= fisica <= 10 and 0 <= quimica <= 10 
        and 0 <= programacion <= 10 and 0 <= ingles <= 10):
    print("\n❌ Error: Las calificaciones deben estar entre 0 y 10")
else:
    # Calcular promedios
    promedio = (mate + fisica + quimica + programacion + ingles) / 5
    
    # Encontrar calificación más alta y más baja
    cal_max = max(mate, fisica, quimica, programacion, ingles)
    cal_min = min(mate, fisica, quimica, programacion, ingles)
    
    # Contar materias aprobadas
    aprobadas = 0
    if mate >= 6: aprobadas += 1
    if fisica >= 6: aprobadas += 1
    if quimica >= 6: aprobadas += 1
    if programacion >= 6: aprobadas += 1
    if ingles >= 6: aprobadas += 1
    
    reprobadas = 5 - aprobadas
    
    # Determinar estado
    if promedio >= 9:
        estado = "EXCELENTE"
        emoji = "🏆"
    elif promedio >= 8:
        estado = "MUY BUENO"
        emoji = "⭐"
    elif promedio >= 7:
        estado = "BUENO"
        emoji = "👍"
    elif promedio >= 6:
        estado = "APROBADO"
        emoji = "✅"
    else:
        estado = "REPROBADO"
        emoji = "❌"
    
    # Mostrar boleta
    print("\n" + "=" * 50)
    print(f"BOLETA DE CALIFICACIONES")
    print("=" * 50)
    print(f"Estudiante: {nombre}")
    print("\n" + "-" * 50)
    print(f"{'MATERIA':<20} {'CALIFICACIÓN':>15} {'ESTADO':>12}")
    print("-" * 50)
    print(f"{'Matemáticas':<20} {mate:>15.1f} {'✓' if mate >= 6 else '✗':>12}")
    print(f"{'Física':<20} {fisica:>15.1f} {'✓' if fisica >= 6 else '✗':>12}")
    print(f"{'Química':<20} {quimica:>15.1f} {'✓' if quimica >= 6 else '✗':>12}")
    print(f"{'Programación':<20} {programacion:>15.1f} {'✓' if programacion >= 6 else '✗':>12}")
    print(f"{'Inglés':<20} {ingles:>15.1f} {'✓' if ingles >= 6 else '✗':>12}")
    print("=" * 50)
    print(f"{'PROMEDIO':<20} {promedio:>15.2f}")
    print("=" * 50)
    
    print(f"\n📊 ESTADÍSTICAS")
    print(f"Calificación más alta:  {cal_max}")
    print(f"Calificación más baja:  {cal_min}")
    print(f"Materias aprobadas:     {aprobadas}/5")
    print(f"Materias reprobadas:    {reprobadas}/5")
    print(f"\n{emoji} ESTADO: {estado}")
    
    if reprobadas > 0:
        print(f"\n⚠️  Debes presentar {reprobadas} examen(es) extraordinario(s)")
```

---

## TIPS Y MEJORES PRÁCTICAS

### 1. Nombres Descriptivos

```python
# ❌ Mal
a = 10
b = 20
c = a + b

# ✅ Bien
precio_unitario = 10
cantidad = 20
precio_total = precio_unitario * cantidad
```

### 2. Usar Constantes para Valores Fijos

```python
# ✅ Bien
IVA = 0.16
SALARIO_MINIMO = 7468.00
MAX_INTENTOS = 3

precio = 100
precio_con_iva = precio * (1 + IVA)
```

### 3. Validar Entrada de Datos

```python
# ✅ Bien
edad_str = input("Edad: ")

if edad_str.isdigit():
    edad = int(edad_str)
    if edad > 0 and edad < 150:
        print(f"Edad válida: {edad}")
    else:
        print("Edad fuera de rango")
else:
    print("Debes ingresar un número")
```

### 4. Comentar el Código

```python
# ✅ Bien
# Calcular el descuento según el monto de compra
if monto >= 1000:
    descuento = monto * 0.10  # 10% de descuento
else:
    descuento = 0  # Sin descuento
```

### 5. Formateo Consistente

```python
# ✅ Bien - Usar f-strings para formateo
nombre = "Juan"
edad = 25
print(f"Hola, me llamo {nombre} y tengo {edad} años")

# ✅ Bien - Formatear números
precio = 1234.567
print(f"Precio: ${precio:,.2f}")  # Precio: $1,234.57
```

---

## PREGUNTAS FRECUENTES (FAQ)

**Q: ¿Cuál es la diferencia entre `input()` y `print()`?**
A: `input()` recibe datos del usuario, `print()` muestra datos en pantalla.

**Q: ¿Por qué `input()` siempre retorna un string?**
A: Por seguridad y flexibilidad. Debes convertir explícitamente a int o float.

**Q: ¿Cuándo uso `//` y cuándo `/`?**
A: `/` retorna float (con decimales), `//` retorna int (división entera).

**Q: ¿Puedo cambiar el tipo de una variable?**
A: Sí, Python tiene tipado dinámico. Puedes reasignar cualquier tipo.

**Q: ¿Es obligatoria la indentación?**
A: Sí, es parte de la sintaxis de Python. Usa 4 espacios.

**Q: ¿Cómo comento varias líneas?**
A: Usa `"""comentario"""` o `'''comentario'''` para múltiples líneas.

---

## ERRORES COMUNES Y SOLUCIONES

### Error 1: IndentationError

```python
# ❌ Error
if x > 5:
print("Mayor")  # Falta indentación

# ✅ Solución
if x > 5:
    print("Mayor")
```

### Error 2: ValueError al convertir

```python
# ❌ Error
edad = int(input("Edad: "))  # Usuario ingresa "abc"

# ✅ Solución
edad_str = input("Edad: ")
if edad_str.isdigit():
    edad = int(edad_str)
else:
    print("Debes ingresar un número")
```

### Error 3: División por cero

```python
# ❌ Error
resultado = 10 / 0  # ZeroDivisionError

# ✅ Solución
divisor = 0
if divisor != 0:
    resultado = 10 / divisor
else:
    print("No se puede dividir por cero")
```

### Error 4: Comparación vs Asignación

```python
# ❌ Error
if x = 5:  # SyntaxError

# ✅ Solución
if x == 5:  # Comparación usa ==
    print("x es 5")
```

---

## CONCLUSIÓN DE LA SEMANA 6

Has completado exitosamente la introducción a Python. Ahora puedes:

✅ Configurar un entorno de desarrollo profesional
✅ Escribir programas básicos en Python
✅ Trabajar con diferentes tipos de datos
✅ Realizar operaciones matemáticas y lógicas
✅ Interactuar con el usuario mediante input/output
✅ Comprender las diferencias fundamentales con C

**Próximo paso**: En la Semana 7 aprenderemos sobre estructuras de control (if/elif/else) y bucles (for/while) que te permitirán crear programas más complejos y dinámicos.

¡Sigue practicando! La programación se aprende haciendo. 🚀