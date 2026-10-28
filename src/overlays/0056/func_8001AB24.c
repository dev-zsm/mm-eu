// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8082F298(u8 *);                          /* extern */
M2C_UNK func_80832950(s32, u8 *, M2C_UNK, s32);   /* extern */
s32 func_80832CA4(u8 *);                          /* extern */
M2C_UNK func_80832F14(s32, u8 *, s32);            /* extern */
s32 func_80838D90(s32, u8 *);                     /* extern */
s32 func_80839D98(s32, u8 *);                     /* extern */

s32 func_8001AB24(u8 *arg0, s32 arg1) {
    s32 sp24;
    s32 temp_v0;

    if (func_80839D98(arg1, arg0) == 0) {
        if (func_80838D90(arg1, arg0) != 0) {
            temp_v0 = func_80832CA4(arg0);
            sp24 = temp_v0;
            func_80832F14(arg1, arg0, temp_v0);
            if ((sp24 >= 0x1E) || ((M2C_FIELD(arg0, u8 *, 0x14B) == 0) && (func_8082F298(arg0) != 0))) {
                M2C_FIELD(arg0, s32 *, 0xA70) = (s32) (M2C_FIELD(arg0, s32 *, 0xA70) | 0x20000);
                func_80832950(arg1, arg0, 0, sp24 < 0x1E);
            }
            goto block_7;
        }
        return 0;
    }
block_7:
    return 1;
}
