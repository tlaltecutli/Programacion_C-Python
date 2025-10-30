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