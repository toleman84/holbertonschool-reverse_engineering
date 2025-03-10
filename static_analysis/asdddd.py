def transform(local_108):
    # La diferencia entre 0x80 y 0x48
    diff = 0x80 - 0x48
    
    # La lista transformada
    transformed = []
    
    # Recorremos cada valor de la lista
    for value in local_108:
        # Restamos la diferencia al valor actual
        new_value = value - diff
        
        # Nos aseguramos de que el valor esté en el rango de caracteres imprimibles (0x20 a 0x7e)
        if 0x20 <= new_value <= 0x7e:
            transformed.append(new_value)
        else:
            # Si el valor no está dentro del rango imprimible, mantenemos el valor original
            transformed.append(value)
    
    return transformed

# Lista original
local_108 = [
    0x80, 0xe4, 0x08, 0x18, 0x4a, 0x58, 0xb8, 0xe4, 0xac, 0x34,
    0x58, 0xe4, 0x7e, 0xbc, 0x9e, 0x8c, 0x7e, 0xd0, 0xc0, 0x7c,
    0xac, 0xf4, 0x7e, 0x28, 0x9e, 0x04, 0x7e, 0xbc, 0x9e, 0x8c,
    0x7e, 0x5c, 0x14, 0x4c, 0x7e, 0x5c, 0x7e, 0x6c, 0x02, 0x14,
    0xb8, 0x4c, 0x14, 0xa4, 0x9e, 0x08, 0x7e, 0xe4, 0xf4, 0x08,
    0x6a, 0x14, 0xa6, 0x5c, 0xb8, 0x7c, 0x9e, 0x28, 0x3e, 0xac
]

# Llamamos a la función para transformar la lista
transformed = transform(local_108)

# Generamos la flag asegurándonos de que los caracteres sean imprimibles
flag = []
for i in range(len(transformed)):
    if i % 2 == 0:
        iVar2 = -0x2e  # -46 en decimal
        uVar3 = 0xfffffe90  # -368 en decimal
    else:
        iVar2 = 0x13c  # 316 en decimal
        uVar3 = 0x9e0  # 2528 en decimal
    
    # Calcular el inverso multiplicativo de iVar2 módulo 256
    if iVar2 == -0x2e:
        inv_iVar2 = 0x4f  # Inverso de 0xd2 (0xd2 * 0x4f = 1 mod 256)
    else:
        inv_iVar2 = 0xab  # Inverso de 0x3c (0x3c * 0xab = 1 mod 256)
    
    # Calcular el carácter de la flag
    flag_char = ((transformed[i] ^ uVar3) * inv_iVar2) & 0xff
    
    # Asegurarnos de que el carácter sea imprimible (dentro del rango 0x20 - 0x7e)
    if 0x20 <= flag_char <= 0x7e:
        flag.append(chr(flag_char))
    else:
        # Si el carácter no es imprimible, lo descartamos (o lo reemplazamos con un espacio)
        flag.append(' ')

# Mostrar la flag asegurándonos de que solo haya caracteres imprimibles
print("Flag:", ''.join(flag))
