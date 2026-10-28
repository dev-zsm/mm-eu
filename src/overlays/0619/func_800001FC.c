// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8400();                                /* extern */
M2C_UNK func_80BEB3CC(u8 *);                      /* extern */

void func_800001FC(u8 *arg0) {
    if (func_800B8400() != 0) {
        M2C_FIELD(arg0, s8 *, 0xB7) = 0;
        func_80BEB3CC(arg0);
    }
}
