// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { u8 pad0[0x15C]; f32 a; u8 pad160[0x1FC]; f32 b; } S;
void func_80A61EFC();
void func_80002148(S *p, s32 b) {
    f32 x = p->a;
    if (p->b <= x) {
        func_80A61EFC();
    }
}
