mes = input("Ingresa el mes (nombre o número): ").lower()

# Convertir número a nombre si es necesario
meses_numero = {
    "1": "enero", "2": "febrero", "3": "marzo", "4": "abril",
    "5": "mayo", "6": "junio", "7": "julio", "8": "agosto",
    "9": "septiembre", "10": "octubre", "11": "noviembre", "12": "diciembre"
}

if mes in meses_numero:
    mes = meses_numero[mes]

# Determinar estación (hemisferio norte)
if mes in ["diciembre", "enero", "febrero"]:
    estacion = "Invierno"
elif mes in ["marzo", "abril", "mayo"]:
    estacion = "Primavera"
elif mes in ["junio", "julio", "agosto"]:
    estacion = "Verano"
elif mes in ["septiembre", "octubre", "noviembre"]:
    estacion = "Otoño"
else:
    estacion = "Mes no válido"

print(f"La estación es: {estacion}")