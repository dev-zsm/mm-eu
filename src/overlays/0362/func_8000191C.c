#include "types.h"

typedef struct { u8 pad0[0x144]; void *p144; u8 pad1[0x1E0]; s32 w328; } S0362;
extern u8 D_80A5781C[];

void func_8000191C(S0362 *a0, s32 a1) {
    a0->w328 = 3;
    a0->p144 = D_80A5781C;
}
