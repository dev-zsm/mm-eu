#include "types.h"

typedef struct { u8 pad0[0x14A]; s16 s14A; u8 pad1[0x2D2]; void *p420; } S0267;
extern u8 D_80998F38[];

void func_800020E8(S0267 *a0, s32 a1) {
    a0->p420 = D_80998F38;
    a0->s14A = 0xA;
}
