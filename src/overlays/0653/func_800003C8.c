// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80137C58(u8 *, s32, u8 *);             /* extern */
M2C_UNK func_80C04BD0(u8 *);                      /* extern */
M2C_UNK func_80C04CD0(u8 *);                      /* extern */
s32 func_80C061B4(u8 *);                          /* extern */

void func_800003C8(u8 *arg0, M2C_UNK arg1) {
    if (func_80137C58(arg0 + 0x1E4, M2C_FIELD(arg0, s32 *, 0x1F4), arg0) != 0) {
        if (func_80C061B4(arg0) != 0) {
            func_80C04CD0(arg0);
            return;
        }
        func_80C04BD0(arg0);
    }
}
