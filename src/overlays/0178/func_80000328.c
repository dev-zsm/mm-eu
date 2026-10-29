// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x1C];
    s16 v;
} T;

void func_80000328(s16 *a, T *b, s32 c) {
    s32 k = b->v & 3;

    c = (b->v >> 8) & 0x1F;
    if (k == 2) {
        *a = c << 4;
    } else {
        *a = c << 8;
    }
}
