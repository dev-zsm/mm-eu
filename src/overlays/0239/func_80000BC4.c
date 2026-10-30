// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct { u8 p0[0x92]; s16 u92; u8 p1[0x2A]; s16 uBE; u8 p2[0x64]; s32 u124; } A;
extern void func_800B8C4C();
extern void func_80976178();

void func_80000BC4(A *a) {
    a->u124 = 0;
    a->uBE = a->u92;
    func_800B8C4C(a, 0x383C);
    func_80976178(a);
}
