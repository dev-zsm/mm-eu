// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E0FAC(s32, u8 *, u8 *);         /* extern */

void func_800005A4(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x1C) == 0) {
        func_800E0FAC(arg1, arg0 + 0x144, arg0);
        func_800E0FAC(arg1, arg0 + 0x190, arg0);
    }
}
