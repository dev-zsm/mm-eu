// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(M2C_UNK, s32);                    /* extern */
M2C_UNK func_800B5B64(M2C_UNK, s32);                /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
s32 func_800B8254(u8 *, M2C_UNK);                 /* extern */
s32 func_80A11A4C(u8 *, M2C_UNK);                 /* extern */

void func_800003EC(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;
    s32 temp_a1;

    if (func_80A11A4C(arg0, arg1) == 0) {
        if (func_800B8254(arg0, arg1) != 0) {
            temp_a1 = (s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0x7F00) >> 8;
            if (temp_a1 != 0x7F) {
                func_800B5B64(arg1, temp_a1);
            }
            func_800B6490(arg0);
            return;
        }
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x16);
        if ((temp_v0 >= 0) || (temp_v0 < -0x80) || (func_800B5B20(arg1, -1 - temp_v0) != 0)) {
            M2C_FIELD(arg0, M2C_UNK (**)(u8 *, M2C_UNK), 0x144)(arg0, arg1);
        }
    }
}
