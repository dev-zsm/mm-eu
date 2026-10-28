// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8013DD10(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_80A23848(u8 *, u8 *);                  /* extern */

s32 func_800003AC(u8 *arg0, u8 *arg1) {
    s32 temp_v0;

    if (func_80A23848(arg0, arg1) != 0) {
        temp_v0 = func_8013DD10(arg1, 0, 7, 0x233);
        if (temp_v0 != 0) {
            M2C_FIELD(arg0, s32 *, 0x730) = temp_v0;
        }
        M2C_FIELD(arg1, s8 *, 0x1682E) = 0x44;
        return 1;
    }
    return 0;
}
