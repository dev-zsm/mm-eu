// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 func_80091C00(void);
extern void func_80091C70(s32 a0);
extern u16 *D_800982B4;

void func_8008B010(u8 arg0) {
    s32 temp_a0;

    temp_a0 = func_80091C00();
    if (arg0 != 0) {
        *D_800982B4 |= 0x20;
    } else {
        *D_800982B4 &= 0xFFDF;
    }
    func_80091C70(temp_a0);
}
