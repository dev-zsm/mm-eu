// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800F1E2C();                                /* extern */
s32 func_80831AF4(u8 *);                          /* extern */

s32 func_80004A0C(u8 *arg0) {
    if ((M2C_FIELD(arg0, s8 *, 0xA86) >= 0) && (func_800F1E2C() != M2C_FIELD(arg0, s8 *, 0xA86))) {
        return func_80831AF4(arg0);
    }
    return 1;
}
