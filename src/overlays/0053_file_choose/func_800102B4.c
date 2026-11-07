#include "types.h"
typedef struct { u8 pad0[0x2448C]; s16 a2448C; u8 pad1[0x7C]; s16 a2450A; } A;
void func_800102B4(A *a) {
    a->a2450A += 0x28;
    if (a->a2450A >= 0xFF) {
        a->a2450A = 0xFF;
        a->a2448C += 1;
    }
}
