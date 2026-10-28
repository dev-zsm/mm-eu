// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80B63AE4();                                /* extern */

s32 func_80000410(u8 *arg0) {
    if (func_80B63AE4() != 0) {
        M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0x88) - M2C_FIELD(arg0, f32 *, 0x170));
        return 1;
    }
    return 0;
}
