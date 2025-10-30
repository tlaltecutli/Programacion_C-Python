"""
SISTEMA DE REGISTRO DE ESTUDIANTES
Proyecto integrador - Semana 6
"""

import datetime

# Constantes del sistema
NOMBRE_ESCUELA = "Instituto Tecnológico Superior"
ANIO_ACTUAL = datetime.datetime.now().year

# Banner de bienvenida
print("=" * 60)
print(f"{'SISTEMA DE REGISTRO DE ESTUDIANTES':^60}")
print(f"{NOMBRE_ESCUELA:^60}")
print("=" * 60)
print()

# Recopilación de datos personales
print("--- DATOS PERSONALES ---")
nombre_completo = input("Nombre completo: ")
edad = int(input("Edad: "))
genero = input("Género (M/F/Otro): ")
fecha_nacimiento = input("Fecha de nacimiento (dd/mm/aaaa): ")

print("\n--- DATOS DE CONTACTO ---")
email = input("Correo electrónico: ")
telefono = input("Teléfono: ")
direccion = input("Dirección: ")
ciudad = input("Ciudad: ")

print("\n--- INFORMACIÓN ACADÉMICA ---")
carrera = input("Carrera: ")
semestre = int(input("Semestre: "))
promedio = float(input("Promedio actual: "))

print("\n--- DATOS ADICIONALES ---")
tiene_beca = input("¿Tiene beca? (si/no): ").lower() == "si"
practica_deporte = input("¿Practica algún deporte? (si/no): ").lower() == "si"

if practica_deporte:
    deporte = input("¿Cuál deporte? ")
else:
    deporte = "Ninguno"

# Cálculos
anio_nacimiento = ANIO_ACTUAL - edad
creditos_aprox = semestre * 6  # Aproximado: 6 materias por semestre
es_buen_promedio = promedio >= 8.0

# Generar número de matrícula
# Formato: AÑO + PRIMERA LETRA NOMBRE + EDAD + SEMESTRE
inicial = nombre_completo[0].upper()
matricula = f"{ANIO_ACTUAL}{inicial}{edad}{semestre}"

# Categoría según promedio
if promedio >= 9.0:
    categoria_academica = "Excelencia"
elif promedio >= 8.0:
    categoria_academica = "Bueno"
elif promedio >= 7.0:
    categoria_academica = "Regular"
else:
    categoria_academica = "Bajo"

# Mostrar ficha completa
print("\n\n")
print("=" * 60)
print(f"{'FICHA DE REGISTRO - ESTUDIANTE':^60}")
print("=" * 60)

print("\n📋 INFORMACIÓN PERSONAL")
print("-" * 60)
print(f"Nombre:              {nombre_completo}")
print(f"Matrícula:           {matricula}")
print(f"Edad:                {edad} años (Nacimiento: {anio_nacimiento})")
print(f"Género:              {genero}")
print(f"Fecha de Nacimiento: {fecha_nacimiento}")

print("\n📞 CONTACTO")
print("-" * 60)
print(f"Email:               {email}")
print(f"Teléfono:            {telefono}")
print(f"Dirección:           {direccion}")
print(f"Ciudad:              {ciudad}")

print("\n🎓 INFORMACIÓN ACADÉMICA")
print("-" * 60)
print(f"Carrera:             {carrera}")
print(f"Semestre:            {semestre}°")
print(f"Promedio:            {promedio:.2f}")
print(f"Categoría:           {categoria_academica}")
print(f"Créditos (aprox):    {creditos_aprox}")
print(f"Beca:                {'Sí' if tiene_beca else 'No'}")
print(f"Deporte:             {deporte}")

print("\n📊 ESTADÍSTICAS")
print("-" * 60)
creditos_restantes = 48 - creditos_aprox  # Suponiendo 48 créditos totales
porcentaje_avance = (creditos_aprox / 48) * 100

print(f"Avance de carrera:   {porcentaje_avance:.1f}%")
print(f"Créditos restantes:  {creditos_restantes}")
print(f"Estado académico:    {'APROBADO' if es_buen_promedio else 'EN OBSERVACIÓN'}")

if tiene_beca:
    monto_beca = promedio * 500  # $500 por punto de promedio
    print(f"Monto de beca:       ${monto_beca:,.2f} MXN")

print("\n" + "=" * 60)
print(f"{'Registro completado exitosamente':^60}")
print(f"{'Fecha: ' + str(datetime.datetime.now().strftime('%d/%m/%Y %H:%M')):^60}")
print("=" * 60)

# Mensaje personalizado
print("\n💬 MENSAJE:")
if promedio >= 9.0:
    print(f"¡Felicidades {nombre_completo.split()[0]}! Tu desempeño es excelente.")
elif promedio >= 8.0:
    print(f"Muy bien {nombre_completo.split()[0]}, sigue esforzándote.")
else:
    print(f"{nombre_completo.split()[0]}, recuerda que puedes mejorar tu promedio.")

print("\n¡Bienvenido al ciclo escolar!")