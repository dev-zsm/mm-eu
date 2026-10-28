// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8017B9A8(u8 *, s32, u8 *);             /* extern */
extern f32 D_8091F4E8;
extern f32 D_8091F4EC;

s32 func_800000C0(u8 *arg0) {
    s32 temp_v0;
    s32 temp_v1;

    if (M2C_FIELD(arg0, u8 *, 0x155) & 2) {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x14C);
        if (temp_v0 != 0) {
            temp_v1 = *M2C_FIELD(arg0, s32 **, 0x180);
            if (temp_v1 & 0x80000000) {
                if (func_8017B9A8(arg0 + 0x24, temp_v0 + 0x24, arg0) < D_8091F4E8) {
                    return 1;
                }
                goto block_8;
            }
            if ((temp_v1 & 8) && (func_8017B9A8(arg0 + 0x24, temp_v0 + 0x24, arg0) < D_8091F4EC)) {
                return 1;
            }
            goto block_8;
        }
    }
block_8:
    return 0;
}
