// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct Ctx {
    u8 pad0[0x60];
    s32 unk60;
    u8 unk64;
} Ctx;

s32 __osPfsRWInode(void *a0, void *a1, s32 a2, u8 a3);

s32 __osPfsGetNextPage(Ctx *a0, u8 *a1, u16 *a2, u8 *a3) {
    s32 r;
    s32 v;
    u8 b;

    if (*a1 != a3[0]) {
        *a1 = a3[0];
        r = __osPfsRWInode(a0, a2, 0, a3[0]);
        if (r != 0) {
            return r;
        }
    }
    v = a2[a3[1]];
    *(u16 *)a3 = v;
    if ((u16)v >= a0->unk60) {
        if (a3[0] < a0->unk64) {
            b = a3[1];
            if (b > 0 && b < 0x80) {
                return 0;
            }
        }
    }
    if ((u16)v != 1) {
        return 3;
    }
    return 5;
}
