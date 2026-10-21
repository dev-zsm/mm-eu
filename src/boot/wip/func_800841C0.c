// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u8 *D_80096D80;

s32 func_800841C0(s32 a0) {
    u8 *ctx;
    u8 *p;
    s32 i;
    u16 key = a0;

    ctx = D_80096D80;
    if (key == *(u16 *)(ctx + 0x20)) {
        return 0;
    }
    if (key == *(u16 *)(ctx + 0x22)) {
        return 1;
    }
    p = ctx + 4;
    i = 2;
    do {
        if (key == *(u16 *)(p + 0x20)) {
            return i;
        }
        if (key == *(u16 *)(p + 0x22)) {
            return i + 1;
        }
        if (key == *(u16 *)(p + 0x24)) {
            return i + 2;
        }
        if (key == *(u16 *)(p + 0x26)) {
            return i + 3;
        }
        i += 4;
        p += 8;
    } while (i != 10);
    return -1;
}
