// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u8 *D_80096D80;
extern u8 D_800992F4[];

void func_8008198C(void *fmt, ...);

void FaultDrawer_SetCursor(s32 a0, s32 a1) {
    if (D_80096D80[0x35] != 0) {
        func_8008198C(D_800992F4,
                      (a1 - *(u16 *)(D_80096D80 + 0x8)) /
                          (*(s8 *)(D_80096D80 + 0x1F) + *(u8 *)(D_80096D80 + 0x1D)),
                      (a0 - *(u16 *)(D_80096D80 + 0xC)) /
                          (*(s8 *)(D_80096D80 + 0x1E) + *(u8 *)(D_80096D80 + 0x1C)));
    }
    *(u16 *)(D_80096D80 + 0x14) = a0;
    *(u16 *)(D_80096D80 + 0x16) = a1;
}
