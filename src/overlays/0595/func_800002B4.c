// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u8 pad0[0x254]; void *p254; u8 pad1[0x278 - 0x258]; s16 s278; } S;
extern u8 D_80BCCB8C[];
extern void func_80BCCA34();

void func_800002B4(S *s) {
    func_80BCCA34(s, 0);
    s->s278 = 0;
    s->p254 = D_80BCCB8C;
}
