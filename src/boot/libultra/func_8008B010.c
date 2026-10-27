// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 __osDisableInt(void);
extern void __osRestoreInt(s32 a0);
extern u16 *D_800982B4;

void osViBlack(u8 arg0) {
    s32 temp_a0;

    temp_a0 = __osDisableInt();
    if (arg0 != 0) {
        *D_800982B4 |= 0x20;
    } else {
        *D_800982B4 &= 0xFFDF;
    }
    __osRestoreInt(temp_a0);
}
