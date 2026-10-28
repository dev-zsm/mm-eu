// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800C5FD8(s32, s32, s32);                   /* extern */

s32 func_80000C44(u8 *arg0, s32 arg1) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0x494);
    if (temp_v0 != NULL) {
        return func_800C5FD8(arg1 + 0x830, M2C_FIELD(temp_v0, s32 *, 8), arg1);
    }
    return 0;
}
