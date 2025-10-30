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