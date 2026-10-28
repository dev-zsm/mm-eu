// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800C625C(s32, s32, s32, u8 *);       /* extern */

void func_800000C4(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, u8 *, 0x2BA) != 0) {
        func_800C625C(arg1, arg1 + 0x880, M2C_FIELD(arg0, s32 *, 0x144), arg0);
    }
}
