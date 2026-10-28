// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8013C01C(u8 *, M2C_UNK *, s32, u8 *);  /* extern */
extern M2C_UNK D_80BE2D20;

s32 func_8000002C(u8 *arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_t0;
    s32 var_v1;

    var_v1 = 0;
    var_t0 = 0;
    if ((arg1 == 0) || (arg1 == 1)) {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x250);
        if ((temp_v0 != 0) && (temp_v0 != 1)) {
            goto block_6;
        }
    } else if (arg1 != M2C_FIELD(arg0, s32 *, 0x250)) {
block_6:
        var_v1 = 1;
    }
    if (var_v1 != 0) {
        M2C_FIELD(arg0, s32 *, 0x250) = arg1;
        var_t0 = func_8013C01C(arg0 + 0x144, &D_80BE2D20, arg1, arg0);
        M2C_FIELD(arg0, f32 *, 0x238) = (f32) M2C_FIELD(arg0, f32 *, 0x160);
    }
    return var_t0;
}
