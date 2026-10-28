// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B5B4CC();                            /* extern */

s32 func_800008C0(u8 *arg0) {
    if (M2C_FIELD(arg0, u16 *, 0x328) & 0x10) {
        func_80B5B4CC();
    }
    return 1;
}
