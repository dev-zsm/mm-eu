// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8092605C();                                /* extern */
M2C_UNK func_809264C0(u8 *);                      /* extern */

void func_80003670(u8 *arg0) {
    s16 temp_v0;

    if (func_8092605C() == 0) {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C8);
        if (temp_v0 > 0) {
            M2C_FIELD(arg0, s16 *, 0x1C8) = (s16) (temp_v0 - 1);
            return;
        }
        func_809264C0(arg0);
    }
}
