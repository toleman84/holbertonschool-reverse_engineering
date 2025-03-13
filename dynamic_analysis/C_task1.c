#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/ptrace.h>

// Definición de tipos de datos que faltan
typedef unsigned long long undefined8;
typedef unsigned int uint;
typedef unsigned short undefined2;
typedef unsigned char undefined1;
typedef unsigned int undefined4;  // Definición de undefined4
typedef unsigned char byte;       // Definición de byte

// Prototipos de funciones
void anti_debug_ptrace(void);
void anti_debug_timing(void);
undefined8 verify_flag(char *param_1);
void custom_encrypt(long param_1, int param_2, uint param_3);
int prng(uint *param_1);

void anti_debug_ptrace(void) {
    long lVar1;

    lVar1 = ptrace(PTRACE_TRACEME, 0, 1, 0);
    if (lVar1 == -1) {
        puts("Debugger detected! Exiting...");
        exit(1);
    }
    return;
}

void anti_debug_timing(void) {
    int iVar1;

    iVar1 = rand();
    usleep((iVar1 % 100) * 1000);
    return;
}

undefined8 verify_flag(char *param_1) {
    int iVar1;
    size_t sVar2;
    undefined8 uVar3;
    long in_FS_OFFSET;
    undefined8 local_a8;
    undefined8 local_a0;
    undefined8 local_98;
    undefined8 local_90;
    undefined8 local_88;
    undefined4 local_80;
    undefined2 local_7c;
    undefined1 local_7a;
    undefined8 local_78;
    undefined8 local_70;
    undefined8 local_68;
    undefined8 local_60;
    undefined8 local_58;
    undefined8 local_50;
    undefined8 local_48;
    undefined8 local_40;
    undefined8 local_38;
    undefined8 local_30;
    undefined8 local_28;
    undefined8 local_20;
    undefined4 local_18;
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    sVar2 = strlen(param_1);
    iVar1 = (int)sVar2;
    local_78 = 0;
    local_70 = 0;
    local_68 = 0;
    local_60 = 0;
    local_58 = 0;
    local_50 = 0;
    local_48 = 0;
    local_40 = 0;
    local_38 = 0;
    local_30 = 0;
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    memcpy(&local_78, param_1, (long)iVar1);
    custom_encrypt((long)&local_78, iVar1, 0x3039);
    local_a8 = 0x4ef0a378ebed0049;
    local_a0 = 0x459656f85013994a;
    local_98 = 0xdabf8aa60e91585;
    local_90 = 0xce48306873d32868;
    local_88 = 0x7323a57a29d08d6d;
    local_80 = 0xe1ea56d8;
    local_7c = 0x605f;
    local_7a = 0x5a;
    if (iVar1 == 0x2f) {
        if (iVar1 == 0) {
            uVar3 = 1;
        }
    }
    uVar3 = 0;

    return uVar3;
}

void custom_encrypt(long param_1, int param_2, uint param_3) {
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
        *(byte *)(local_20 + local_c) = *(byte *)(local_20 + local_c) ^ local_d;
        *(byte *)(local_20 + local_c) =
            *(char *)(local_20 + local_c) << 3 | *(byte *)(local_20 + local_c) >> 5;
        *(char *)(local_20 + local_c) = *(char *)(local_20 + local_c) + -0x5b;
    }
    return;
}

int prng(uint *param_1) {
    *param_1 = *param_1 * 0x41c64e6d + 0x3039 & 0x7fffffff;
    return (int)*param_1 >> 0x10;
}

int main(void) {
    time_t tVar1;
    undefined8 uVar2;
    long in_FS_OFFSET;
    char local_78[104];
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    tVar1 = time((time_t *)0x0);
    srand((uint)tVar1);
    // anti_debug_ptrace();
    // anti_debug_timing();
    printf("Enter the flag: ");
    scanf("%s", local_78);  // Usamos scanf estándar en lugar de __isoc99_scanf
    uVar2 = verify_flag(local_78);
    printf("%llu\n",uVar2);
    if ((int)uVar2 == 0) {
        puts("Incorrect flag.");
    } else {
        puts("Correct flag!");
    }

    return 0;
}
