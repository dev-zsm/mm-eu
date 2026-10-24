// FLAGS: -O2 -g3 -mips2
#include "types.h"
s32 func_80088070(void *, u32 *, s32);
extern u8 D_801F4980[];
extern u8 *D_801F49D8[];
void func_801939DC(void) {
    s32 pad;
    u32 sp20;
    u8 *p;
    if (func_80088070(D_801F4980, &sp20, 0) != -1) {
        p = D_801F49D8[sp20 >> 0x18];
        if (p != NULL) {
            *p = 0;
        }
    }
}
