# Enunciado: Calcular el salario neto después de deducciones.

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