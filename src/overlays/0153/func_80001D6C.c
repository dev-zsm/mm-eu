// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8091BF58();                                /* extern */
M2C_UNK func_8091D594(u8 *);                      /* extern */

void func_80001D6C(u8 *arg0) {
    if (func_8091BF58() != 0) {
        M2C_FIELD(arg0, s16 *, 0x1B2) = 0x64;
        return;
    }
    if (M2C_FIELD(arg0, s16 *, 0x1B2) <= 0) {
        func_8091D594(arg0);
    }
}
