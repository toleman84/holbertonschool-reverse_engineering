def naive_modular_exponentiation(base, exponent, modulus):
    return pow(base, exponent, modulus)

# Bloques de la flag encriptada (en hexadecimal)
encrypted_flag_hex = (
    "8e82d972b66c836fa896da60a7779a69"
    "bc84db77a0729877a582d1758c778461"
    "a883da69ba70905fa498c14fba6da861"
    "9980c063a763f700")

# Convertir la flag encriptada a bytes
encrypted_flag = bytes.fromhex(encrypted_flag_hex)

# Exponente y módulo para la clave de descifrado
exponent = 0x0000FFFFFFFFFFFF
modulus = 0x0FFFFFFFFFFFFFFB

# Calcular la clave utilizando exponentiación modular
key = naive_modular_exponentiation(2, exponent, modulus)
print(f"Clave generada: {hex(key)}")

# Función para desencriptar la flag
def decrypt_flag(encrypted_flag, decryption_key):
    decrypted_flag = []
    
    # Procesar cada bloque de 8 bytes
    for i in range(0, len(encrypted_flag), 8):
        block = encrypted_flag[i:i+8]
        block_int = int.from_bytes(block, byteorder='little')
        
        decrypted_block = block_int ^ decryption_key
        
        # Convertir el bloque desencriptado a bytes y añadirlo a la lista
        decrypted_flag.append(decrypted_block.to_bytes(8, byteorder='little').decode(errors='ignore'))
    
    return ''.join(decrypted_flag)

# Desencriptar la flag
decrypted_flag = decrypt_flag(encrypted_flag, key)

# Imprimir la flag desencriptada
print(f"Flag descifrada: {decrypted_flag}")
