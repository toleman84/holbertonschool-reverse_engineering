# Valores predefinidos de local_108[] en la función check_flag
local_108 = [
    0x80, 0xe4, 8, 0x18, 0x4a, 0x58, 0xb8, 0xe4, 0xac, 0x34,
    0x58, 0xe4, 0x7e, 0xbc, 0x9e, 0x8c, 0x7e, 0xd0, 0xc0, 0x7c,
    0xac, 0xf4, 0x7e, 0x28, 0x9e, 4, 0x7e, 0xbc, 0x9e, 0x8c,
    0x7e, 0x5c, 0x14, 0x4c, 0x7e, 0x5c, 0x7e, 0x6c, 2, 0x14,
    0xb8, 0x4c, 0x14, 0xa4, 0x9e, 8, 0x7e, 0xe4, 0xf4, 8,
    0x6a, 0x14, 0xa6, 0x5c, 0xb8, 0x7c, 0x9e, 0x28, 0x3e, 0xac
]

# Reverse function to find the original input
# Reverse function to find the original input
def reverse_check_flag(local_108):
    flag = []
    
    # Iterating through each index of local_108[]
    for i in range(len(local_108)):
        # Calculate iVar2 and uVar3 based on whether i is even or odd
        if i % 2 == 0:  # even index
            iVar2 = -0x2e
            uVar3 = 0xfffffe90
        else:  # odd index
            iVar2 = 0x13c
            uVar3 = 0x9e0
        
        # Reverse the operation: (byte * iVar2) ^ uVar3 = local_108[i]
        # We need to solve for byte, so:
        # byte = ((local_108[i] ^ uVar3) // iVar2) (note the inverse order)
        # Ensure to handle signed and unsigned values properly
        try:
            byte = (local_108[i] ^ uVar3) // iVar2
        except ZeroDivisionError:
            print(f"Warning: Division by zero error at index {i}")
            byte = 0  # Default to 0 or handle differently
        
        # Ensure byte is in the valid ASCII range (0-255)
        if byte < 0 or byte > 255:
            print(f"Warning: Invalid byte value {byte} at index {i}")
            byte = 0  # Default to 0 or some valid fallback
        
        # Append the calculated byte to the flag
        flag.append(chr(byte))  # Convert byte to character
    
    # Join the list of characters to form the flag string
    return ''.join(flag)

# Find the flag by reversing the check_flag logic
flag = reverse_check_flag(local_108)
print("The flag is:", flag)


