// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B7164(u8 *, M2C_UNK);                 /* extern */

s32 func_80001724(u8 *arg0) {
    if ((func_800B7164(arg0, 0x11C7) != 0) && (M2C_FIELD(arg0, f32 *, 0x98) < 60.0f)) {
        return 1;
    }
    return 0;
}
