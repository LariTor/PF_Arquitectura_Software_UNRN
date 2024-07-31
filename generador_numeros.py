import random

# Número de elementos a generar
num_elements = 1000

# Rango de números
min_value = 0
max_value = 300

# Genera los números aleatorios
numbers = [str(random.randint(min_value, max_value)) for _ in range(num_elements)]

# Guarda los números en un archivo de texto
with open('numbers.txt', 'w') as file:
    file.write('\n'.join(numbers))

print("Archivo 'numbers.txt' generado con éxito.")
