import random

# Generar número secreto
numero_secreto = random.randint(1, 100)
intentos = 0
max_intentos = 7

print("¡Juego de adivinanza!")
print(f"Adivina el número entre 1 y 100. Tienes {max_intentos} intentos.")

while intentos < max_intentos:
    intento = int(input(f"\nIntento {intentos + 1}/{max_intentos}: "))
    intentos += 1
    
    if intento == numero_secreto:
        print(f"¡Felicidades! Adivinaste en {intentos} intentos.")
        break
    elif intento < numero_secreto:
        print("El número es mayor")
        if numero_secreto - intento > 20:
            print("Estás muy lejos")
    else:
        print("El número es menor")
        if intento - numero_secreto > 20:
            print("Estás muy lejos")
    
    if intentos == max_intentos:
        print(f"\nGame Over. El número era {numero_secreto}")