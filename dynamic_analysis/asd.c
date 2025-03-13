#include <stdio.h>
#include <string.h>

// Definición de tipos de datos que faltan
typedef unsigned long long undefined8;
typedef unsigned int uint;
typedef unsigned short undefined2;
typedef unsigned char undefined1;
typedef unsigned int undefined4;  // Definición de undefined4
typedef unsigned char byte;       // Definición de byte

int prng(uint *param_1) {
    *param_1 = *param_1 * 0x41c64e6d + 0x3039 & 0x7fffffff;
    return (int)*param_1 >> 0x10;
}

// Función para revertir el cifrado
void custom_decrypt(long param_1, int param_2, uint param_3) {
    int iVar1;
    uint local_28;
    int local_24;
    long local_20;
    byte local_d;
    int local_c;

    local_28 = param_3;
    local_24 = param_2;
    local_20 = param_1;
    for (local_c = 0; local_c < local_24; local_c = local_c + 1) {
        iVar1 = prng(&local_28);
        local_d = (byte)iVar1;
        *(char *)(local_20 + local_c) = *(char *)(local_20 + local_c) + 0x5b;
        *(byte *)(local_20 + local_c) =
            *(byte *)(local_20 + local_c) >> 3 | *(byte *)(local_20 + local_c) << 5;
        *(byte *)(local_20 + local_c) = *(byte *)(local_20 + local_c) ^ local_d;
    }
}

int main(void) {
    // Valores cifrados esperados
    unsigned char encrypted_flag[] = {
        0x49, 0x00, 0xed, 0xeb, 0x78, 0xa3, 0xf0, 0x4e,  // local_a8
        0x4a, 0x99, 0x13, 0x50, 0xf8, 0x56, 0x96, 0x45,  // local_a0
        0x85, 0x15, 0xe9, 0x60, 0xaa, 0x8a, 0xbf, 0xda,  // local_98
        0x68, 0x28, 0xd3, 0x73, 0x68, 0x30, 0x48, 0xce,  // local_90
        0x6d, 0x8d, 0xd0, 0x29, 0x7a, 0xa5, 0x23, 0x73,  // local_88
        0xd8, 0x56, 0xea, 0xe1,  // local_80
        0x5f, 0x60,  // local_7c
        0x5a  // local_7a
    };

    // Aplicar el descifrado
    custom_decrypt((long)encrypted_flag, sizeof(encrypted_flag), 0x3039);

    // Imprimir la flag
    printf("Flag: %s\n", encrypted_flag);

    return 0;
}