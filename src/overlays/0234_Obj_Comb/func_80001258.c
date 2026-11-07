// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u8 pad0[0x13C]; s32 w13C; u8 pad1[4]; void *p144; u8 pad2[0x6C]; u8 b1B4; } S0234;
extern u8 D_80972DF8[];

void func_80001258(S0234 *a0) {
    a0->w13C = 0;
    a0->b1B4 = 0x14;
    a0->p144 = D_80972DF8;
}
