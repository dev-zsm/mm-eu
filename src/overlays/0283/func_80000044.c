// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8017B2E8(f32, f32, M2C_UNK, M2C_UNK, f32, f32); /* extern */
extern u8 D_801E7EFD;
extern f32 D_809B5168;
extern f32 D_809B516C;

s32 func_80000044(u8 *arg0) {
    if (!(D_801E7EFD & 1)) {
        if (func_8017B2E8(-466.0f, -386.0f, 0xC42BC000, 0x43410000, M2C_FIELD(arg0, f32 *, 0), M2C_FIELD(arg0, f32 *, 8)) != 0) {
            return 1;
        }
        goto block_5;
    }
    if (func_8017B2E8(D_809B5168, D_809B516C, 0xC458C000, 0xC444C000, M2C_FIELD(arg0, f32 *, 0), M2C_FIELD(arg0, f32 *, 8)) != 0) {
        return 2;
    }
block_5:
    return 0;
}
