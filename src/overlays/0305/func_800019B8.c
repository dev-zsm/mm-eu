// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800C60A4(s32, s32, s32, u8 *);       /* extern */

void func_800019B8(u8 *arg0, s32 arg1) {
    if (!(M2C_FIELD(arg0, s32 *, 0x1B0) & 0x10) && !(M2C_FIELD(arg0, u8 *, 0x16E) & 2)) {
        func_800C60A4(arg1, arg1 + 0x880, M2C_FIELD(arg0, s32 *, 0x144), arg0);
        M2C_FIELD(arg0, s32 *, 0x1B0) = (s32) (M2C_FIELD(arg0, s32 *, 0x1B0) | 0x10);
    }
}
