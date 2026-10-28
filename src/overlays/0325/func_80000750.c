// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8017B9A8(s32, s32);                        /* extern */
s32 func_80A21940();                                /* extern */
extern f32 D_80A2224C;

s32 func_80000750(void) {
    s32 temp_v0;

    temp_v0 = func_80A21940();
    if ((temp_v0 != 0) && (D_80A2224C < func_8017B9A8(temp_v0 + 0x24, temp_v0 + 0x108))) {
        return 1;
    }
    return 0;
}
