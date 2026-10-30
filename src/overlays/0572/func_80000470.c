#include "types.h"

typedef struct { u8 p0[0x16]; s16 unk16; u8 p1[4]; s16 unk1C; u8 p2[0xBE - 0x1E]; s16 unkBE; u8 p3[0x162 - 0xC0]; s16 unk162; } A;

void func_80000470(A *a0) {
    a0->unkBE = a0->unk16;
    if (a0->unk1C & 0x8000) {
        a0->unkBE += a0->unk162;
        return;
    }
    a0->unkBE -= a0->unk162;
}
