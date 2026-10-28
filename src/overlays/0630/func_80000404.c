// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80BEF4E0();                                /* extern */
M2C_UNK func_80BEF928(u8 *);                      /* extern */

void func_80000404(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x164);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s16 *, 0x164) = (s16) (temp_v0 - 1);
        return;
    }
    if (func_80BEF4E0() != 0) {
        func_80BEF928(arg0);
    }
}
