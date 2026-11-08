// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad[0x454];
    s16 f454;
    s16 f456;
    s16 f458;
    s16 f45A;
    s16 f45C;
} T0285;

extern T0285 *D_801EB7E0;

void func_80000000(s32 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4) {
    D_801EB7E0->f454 = 1;
    D_801EB7E0->f456 = arg1;
    D_801EB7E0->f458 = arg2;
    D_801EB7E0->f45A = arg3;
    D_801EB7E0->f45C = arg4;
}
