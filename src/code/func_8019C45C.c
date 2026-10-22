// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 func_8019C418(void);
extern u8 D_801F4D58[];

u8 func_8019C45C(void) {
    s32 idx = func_8019C418();
    u8 b = idx;

    if (idx < 0x18) {
        return D_801F4D58[b];
    }
    return 0xFF;
}
