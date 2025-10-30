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