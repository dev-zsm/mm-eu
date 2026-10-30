// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u8 pad0[0x15C]; f32 a; u8 pad1[0x374 - 0x160]; f32 b; } S;
extern void func_80A5D47C();

void func_8000170C(S *s) {
    f32 x = s->a;
    if (s->b <= x) {
        func_80A5D47C();
    }
}
