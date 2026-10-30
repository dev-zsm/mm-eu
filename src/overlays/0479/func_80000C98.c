// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u8 pad[0x27C]; u16 f; } S;

s32 func_80000C98(s32 a0, s32 a1, s32 *a2, s32 a3, s32 a4, S *a5) {
    s32 ret = 0;
    if (!(a5->f & 1) && a1 == 0xE) {
        *a2 = 0;
    }
    return ret;
}
