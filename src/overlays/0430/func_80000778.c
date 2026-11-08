// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0430.h"

M2C_UNK func_800B6490(s32);                         /* extern */
s32 func_800B8400(s32, s32);                        /* extern */
M2C_UNK func_80151DF4(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_80000778(Actor *thisx, PlayState *play) {
    if (func_800B8400(thisx, play) != 0) {
        func_80151DF4(play, 0x107D, 0);
        func_800B6490(thisx);
    }
}
