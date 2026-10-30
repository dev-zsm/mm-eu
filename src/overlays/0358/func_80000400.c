// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern s32 D_80A506F4;
s32 func_80000400(u8 *a) {
    return D_80A506F4 >= 4 && *(s32 *)(a + 0x34C) == 0;
}
