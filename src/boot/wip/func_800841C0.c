// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern u8 *D_80096D80;
s32 FaultDrawer_ColorToPrintColor(u16 key) { u8 *ctx = D_80096D80; u8 *c2 = ctx; u8 *p; s32 i; s32 k = key;
    if (key == *(u16 *)(ctx + 0x20)) return 0;
    if (k == *(u16 *)(c2 + 0x22)) return 1;
    p = ctx + 4;
    for (i = 2; i != 10; i += 4, p += 8) {
        if (k == *(u16 *)(p + 0x20)) return i;
        if (k == *(u16 *)(p + 0x22)) return i + 1;
        if (k == *(u16 *)(p + 0x24)) return i + 2;
        if (k == *(u16 *)(p + 0x26)) return i + 3;
    }
    return -1;
}
