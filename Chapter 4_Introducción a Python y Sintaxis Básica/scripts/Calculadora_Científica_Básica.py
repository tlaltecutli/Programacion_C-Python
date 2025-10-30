# Instrucciones: Crear una calculadora que incluya operaciones avanzadas.

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