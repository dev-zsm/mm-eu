// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0xC];
    f32 c;
    u8 pad1[0x28 - 0x10];
    f32 a;
    u8 pad2[0x68 - 0x2C];
    f32 b;
} T;

s32 func_80000C1C(T *p) {
    f32 b = p->b;
    f32 s = p->a + 2.0f * b;

    if (p->c <= s) {
        return 1;
    }
    return 0;
}
