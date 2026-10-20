// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern void *D_80096D80;

void func_800848CC(u32 a0, u16 a1, u16 a2) {
    *(u32 *)D_80096D80 = a0;
    *(u16 *)((u8 *)D_80096D80 + 4) = a1;
    *(u16 *)((u8 *)D_80096D80 + 6) = a2;
}
