// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_800FF72C(s32, s32);                        /* extern */
s32 func_80ABFD70();                                /* extern */

f32 func_800002BC(u8 *arg0) {
    s32 pad;
    s32 sp18;
    s32 temp_v0;

    sp18 = M2C_FIELD(arg0, s32 *, 0x1CCC);
    temp_v0 = func_80ABFD70();
    if (temp_v0 != 0) {
        return func_800FF72C(sp18 + 0x24, temp_v0 + 8);
    }
    return 80.0f;
}
