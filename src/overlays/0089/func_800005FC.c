// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_800B6BCC(s32, s32);                        /* extern */
s32 func_800B7164(u8 *, M2C_UNK);                 /* extern */
s32 func_801244EC(u8 *);                          /* extern */

s32 func_800005FC(u8 *arg0, u8 *arg1) {
    if ((func_801244EC(arg1) != 0x10) && (func_800B6BCC(M2C_FIELD(arg1, s32 *, 0x1CCC), arg0 + 0x200) < M2C_FIELD(arg0, f32 *, 0x1F0)) && (func_800B7164(arg0, 0x5000) != 0)) {
        return 1;
    }
    return 0;
}
