#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>

// Declaración de funciones
void x1(unsigned char *param_1, char *param_2, unsigned int param_3);
void x2(unsigned char *param_1, unsigned int param_2, char *param_3);
void x(void *param_1, int param_2);

void (*encrypted_section1)();  // Puntero a función
size_t encrypted_section1_len = 128;  // Asigna un tamaño arbitrario

void x1(unsigned char *param_1, char *param_2, unsigned int param_3) {
    size_t sVar1 = strlen(param_2);
    for (unsigned int local_14 = 0; local_14 < param_3; local_14++) {
        param_1[local_14] ^= param_2[local_14 % sVar1];
    }
}

void x2(unsigned char *param_1, unsigned int param_2, char *param_3) {
    size_t sVar1 = strlen(param_3);
    for (unsigned int local_14 = 0; local_14 < param_2; local_14++) {
        param_1[local_14] ^= param_3[local_14 % sVar1];
    }
}

void x(void *param_1, int param_2) {
    int page_size = getpagesize();
    void *aligned_addr = (void *)((uintptr_t)param_1 & ~(page_size - 1));

    if (mprotect(aligned_addr, param_2, PROT_READ | PROT_WRITE | PROT_EXEC) != 0) {
        perror("mprotect");
    }
}

int main(void) {
    char local_a4[128];
    
    printf("Enter the flag: ");
    scanf("%127s", local_a4);
    
    size_t sVar1 = strlen(local_a4);
    if (sVar1 < 128) {
        memset(local_a4 + sVar1, 0, 128 - sVar1);
    }

    x1((unsigned char *)local_a4, "kjkjf_ckzj9274jdlfdvn-dpakkk__AhfNNtdsp592", 128);
    x2((unsigned char *)0x14020, encrypted_section1_len, "kjkjf_ckzj9274jdlfdvn-dpakkk__AhfNNtdsp592");
    x((void *)0x14020, encrypted_section1_len);

    if (encrypted_section1) {
        int iVar2 = 1;
        if (iVar2 == 0) {
            puts("Incorrect flag.");
        } else {
            puts("Correct flag!");
        }
    } else {
        puts("Error: encrypted_section1 no está definido.");
    }

    return 0;
}
