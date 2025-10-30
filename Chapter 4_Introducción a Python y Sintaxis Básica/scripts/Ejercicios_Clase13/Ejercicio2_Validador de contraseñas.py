password = input("Ingresa una contraseña: ")

# Requisitos
tiene_mayuscula = any(c.isupper() for c in password)
tiene_minuscula = any(c.islower() for c in password)
tiene_numero = any(c.isdigit() for c in password)
longitud_valida = len(password) >= 8

# Validación
if tiene_mayuscula and tiene_minuscula and tiene_numero and longitud_valida:
    print("✓ Contraseña válida y segura")
else:
    print("✗ Contraseña débil. Debe cumplir:")
    if not longitud_valida:
        print("  - Mínimo 8 caracteres")
    if not tiene_mayuscula:
        print("  - Al menos una letra mayúscula")
    if not tiene_minuscula:
        print("  - Al menos una letra minúscula")
    if not tiene_numero:
        print("  - Al menos un número")