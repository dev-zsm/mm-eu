// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800C9764(s32, s32, u8, u8 *);            /* extern */

s32 func_80000244(u8 *arg0, s32 arg1) {
    if ((M2C_FIELD(arg0, s16 *, 0x1C) == -2) && (M2C_FIELD(arg0, u16 *, 0x90) & 1) && (func_800C9764(arg1 + 0x830, M2C_FIELD(arg0, s32 *, 0x80), M2C_FIELD(arg0, u8 *, 0x85), arg0) == 5)) {
        return 1;
    }
    return 0;
}
