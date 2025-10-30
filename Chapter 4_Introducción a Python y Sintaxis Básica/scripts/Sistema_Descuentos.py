# Enunciado: Crear un programa que calcule descuentos según el monto de compra.
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