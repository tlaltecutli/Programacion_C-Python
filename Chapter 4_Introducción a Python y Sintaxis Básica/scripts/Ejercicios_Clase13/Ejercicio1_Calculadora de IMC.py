# Solicitar datos
peso = float(input("Ingresa tu peso en kg: "))
altura = float(input("Ingresa tu altura en metros: "))

# Calcular IMC
imc = peso / (altura ** 2)

# Clasificación
print(f"\nTu IMC es: {imc:.2f}")

if imc < 18.5:
    print("Clasificación: Bajo peso")
elif imc >= 18.5 and imc < 25:
    print("Clasificación: Peso normal")
elif imc >= 25 and imc < 30:
    print("Clasificación: Sobrepeso")
else:
    print("Clasificación: Obesidad")