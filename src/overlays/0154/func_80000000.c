// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8017B9A8(u8 *, s32, u8 *);             /* extern */
extern f32 D_8091F4E0;
extern f32 D_8091F4E4;

s32 func_80000000(u8 *arg0) {
    s32 temp_v0;
    s32 temp_v1;

    if (M2C_FIELD(arg0, u8 *, 0x155) & 2) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x14C);
        temp_v0 = *M2C_FIELD(arg0, s32 **, 0x180);
        if (temp_v0 & 0x80000000) {
            if ((temp_v1 != 0) && (func_8017B9A8(arg0 + 0x24, temp_v1 + 0x24, arg0) < D_8091F4E0)) {
                return 1;
            }
            goto block_11;
        }
        if (temp_v0 & 8) {
            if ((temp_v1 != 0) && (func_8017B9A8(arg0 + 0x24, temp_v1 + 0x24, arg0) < D_8091F4E4)) {
                return 1;
            }
            goto block_11;
        }
        if (temp_v0 & 0x500) {
            return 1;
        }
        goto block_11;
    }
block_11:
    return 0;
}
