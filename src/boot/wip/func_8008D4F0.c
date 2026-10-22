// FLAGS: -O2 -g0 -mips2
#include "types.h"

u32 osGetMemSize(void) {
    u32 *p;
    u32 sp8;
    u32 sp4;
    u32 sp0;

    sp8 = 0x400000;
    do {
        p = (u32 *)(0xA0000000 + sp8);
        sp4 = p[0];
        sp0 = p[0x3FFFF];
        p[0] = ~p[0];
        p[0x3FFFF] = ~p[0x3FFFF];
        if (p[0] != ~sp4 || p[0x3FFFF] != ~sp0) {
            return sp8;
        }
        p[0] = sp4;
        p[0x3FFFF] = sp0;
        sp8 += 0x100000;
    } while (sp8 < 0x800000);
    return sp8;
}
