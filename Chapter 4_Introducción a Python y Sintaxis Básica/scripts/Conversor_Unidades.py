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