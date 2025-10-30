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