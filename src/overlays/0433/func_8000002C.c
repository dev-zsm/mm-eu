// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8013C01C(u8 *, M2C_UNK *, s32, u8 *);  /* extern */
extern M2C_UNK D_80ACBF48;

s32 func_8000002C(u8 *arg0, s32 arg1) {
    s32 var_v0;
    s32 var_v1;

    var_v0 = 0;
    var_v1 = 0;
    if (arg1 != M2C_FIELD(arg0, s32 *, 0x2E8)) {
        var_v0 = 1;
    }
    if (var_v0 != 0) {
        M2C_FIELD(arg0, s32 *, 0x2E8) = arg1;
        var_v1 = func_8013C01C(arg0 + 0x148, &D_80ACBF48, arg1, arg0);
        M2C_FIELD(arg0, f32 *, 0x2CC) = (f32) M2C_FIELD(arg0, f32 *, 0x164);
    }
    return var_v1;
}
