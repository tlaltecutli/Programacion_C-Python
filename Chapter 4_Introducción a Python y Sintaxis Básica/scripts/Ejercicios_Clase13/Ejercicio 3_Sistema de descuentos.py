total_compra = float(input("Ingresa el total de la compra: $"))
es_miembro = input("¿Eres miembro? (si/no): ").lower() == "si"

descuento = 0

# Descuento por monto
if total_compra >= 1000:
    descuento = 0.15  # 15%
elif total_compra >= 500:
    descuento = 0.10  # 10%
elif total_compra >= 200:
    descuento = 0.05  # 5%

# Descuento adicional para miembros
if es_miembro:
    descuento += 0.05  # 5% adicional

# Cálculo final
monto_descuento = total_compra * descuento
total_final = total_compra - monto_descuento

print(f"\nResumen de compra:")
print(f"Subtotal: ${total_compra:.2f}")
print(f"Descuento ({descuento*100:.0f}%): ${monto_descuento:.2f}")
print(f"Total a pagar: ${total_final:.2f}")