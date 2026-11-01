// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u8 D_801E6EF0;
extern u8 *D_801EB7E0;

void func_80000074(void) {
    u8 *p = &D_801E6EF0;
    u16 t;

    t = *(u16 *)(p + 0xC) + *(u16 *)(D_801EB7E0 + 0x32);
    *(volatile u16 *)(p + 0xC) = t;
    *(u16 *)(p + 0xC) = *(u16 *)(p + 0x16) + t;
}
