// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u8 pad0[0x15C]; void *p15C; u8 pad1[0x4C]; s16 s1AC; s16 s1AE; } S0153;
extern u8 D_8091D098[];

void func_80001898(S0153 *a0) {
    a0->s1AC = 0;
    a0->s1AE = 0xBB8;
    a0->p15C = D_8091D098;
}
