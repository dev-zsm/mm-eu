// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0619.h"

s32 func_800B8400();                                /* extern */
M2C_UNK func_80BEB3CC(u8 *);                      /* extern */

void func_800001FC(ObjMoonStone *this) {
    if (func_800B8400() != 0) {
        M2C_FIELD(this, s8 *, 0xB7) = 0;
        func_80BEB3CC(this);
    }
}
