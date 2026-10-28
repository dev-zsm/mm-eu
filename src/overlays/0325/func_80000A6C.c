// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800FEC70(u8 *, M2C_UNK, s16, u8 *);    /* extern */
M2C_UNK func_80A21CFC(u8 *);                      /* extern */

void func_80000A6C(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    if (func_800FEC70(arg0 + 0x3C0, 0, M2C_FIELD(arg0, s16 *, 0x3C4), arg0) != 0) {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x3C8);
        if (temp_v0 > 0) {
            M2C_FIELD(arg0, s16 *, 0x3C8) = (s16) (temp_v0 - 1);
            if (M2C_FIELD(arg0, s16 *, 0x3C8) <= 0) {
                func_80A21CFC(arg0);
            }
        }
    }
}
