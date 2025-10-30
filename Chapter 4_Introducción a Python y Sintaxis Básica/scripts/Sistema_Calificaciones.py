# Instrucciones: Sistema completo de gestión de calificaciones.

"""
Sistema de Calificaciones
Calcula promedios y determina el estado académico
"""

print("=== SISTEMA DE CALIFICACIONES ===\n")

# Datos del estudiante
nombre = input("Nombre del estudiante: ")
print("\nIngresa las calificaciones (0-10):")

# Solicitar calificaciones
mate = float(input("Matemáticas: "))
fisica = float(input("Física: "))
quimica = float(input("Química: "))
programacion = float(input("Programación: "))
ingles = float(input("Inglés: "))

# Validar que estén en rango
if not (0 <= mate <= 10 and 0 <= fisica <= 10 and 0 <= quimica <= 10 
        and 0 <= programacion <= 10 and 0 <= ingles <= 10):
    print("\n❌ Error: Las calificaciones deben estar entre 0 y 10")
else:
    # Calcular promedios
    promedio = (mate + fisica + quimica + programacion + ingles) / 5
    
    # Encontrar calificación más alta y más baja
    cal_max = max(mate, fisica, quimica, programacion, ingles)
    cal_min = min(mate, fisica, quimica, programacion, ingles)
    
    # Contar materias aprobadas
    aprobadas = 0
    if mate >= 6: aprobadas += 1
    if fisica >= 6: aprobadas += 1
    if quimica >= 6: aprobadas += 1
    if programacion >= 6: aprobadas += 1
    if ingles >= 6: aprobadas += 1
    
    reprobadas = 5 - aprobadas
    
    # Determinar estado
    if promedio >= 9:
        estado = "EXCELENTE"
        emoji = "🏆"
    elif promedio >= 8:
        estado = "MUY BUENO"
        emoji = "⭐"
    elif promedio >= 7:
        estado = "BUENO"
        emoji = "👍"
    elif promedio >= 6:
        estado = "APROBADO"
        emoji = "✅"
    else:
        estado = "REPROBADO"
        emoji = "❌"
    
    # Mostrar boleta
    print("\n" + "=" * 50)
    print(f"BOLETA DE CALIFICACIONES")
    print("=" * 50)
    print(f"Estudiante: {nombre}")
    print("\n" + "-" * 50)
    print(f"{'MATERIA':<20} {'CALIFICACIÓN':>15} {'ESTADO':>12}")
    print("-" * 50)
    print(f"{'Matemáticas':<20} {mate:>15.1f} {'✓' if mate >= 6 else '✗':>12}")
    print(f"{'Física':<20} {fisica:>15.1f} {'✓' if fisica >= 6 else '✗':>12}")
    print(f"{'Química':<20} {quimica:>15.1f} {'✓' if quimica >= 6 else '✗':>12}")
    print(f"{'Programación':<20} {programacion:>15.1f} {'✓' if programacion >= 6 else '✗':>12}")
    print(f"{'Inglés':<20} {ingles:>15.1f} {'✓' if ingles >= 6 else '✗':>12}")
    print("=" * 50)
    print(f"{'PROMEDIO':<20} {promedio:>15.2f}")
    print("=" * 50)
    
    print(f"\n📊 ESTADÍSTICAS")
    print(f"Calificación más alta:  {cal_max}")
    print(f"Calificación más baja:  {cal_min}")
    print(f"Materias aprobadas:     {aprobadas}/5")
    print(f"Materias reprobadas:    {reprobadas}/5")
    print(f"\n{emoji} ESTADO: {estado}")
    
    if reprobadas > 0:
        print(f"\n⚠️  Debes presentar {reprobadas} examen(es) extraordinario(s)")