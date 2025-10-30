# Enunciado: Convertir segundos a horas, minutos y segundos.
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