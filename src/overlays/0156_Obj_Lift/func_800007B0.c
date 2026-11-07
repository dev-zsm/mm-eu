// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u8 pad0[0x13C]; s32 w13C; u8 pad1[0x1C]; void *p15C; u8 pad2[6]; s16 s166; u8 pad3[0x10]; s16 s178; } S0156;
extern u8 D_80922680[];

void func_800007B0(S0156 *a0) {
    a0->s166 = a0->s178;
    a0->p15C = D_80922680;
    a0->w13C = 0;
}
