// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8013C01C(u8 *, M2C_UNK *, s32, u8 *);  /* extern */
extern M2C_UNK D_80BA84B4;

s32 func_8000002C(u8 *arg0, s32 arg1) {
    s32 var_v1;

    var_v1 = 0;
    if (arg1 != M2C_FIELD(arg0, s32 *, 0x36C)) {
        M2C_FIELD(arg0, s32 *, 0x36C) = arg1;
        var_v1 = func_8013C01C(arg0 + 0x144, &D_80BA84B4, arg1, arg0);
        M2C_FIELD(arg0, f32 *, 0x344) = (f32) M2C_FIELD(arg0, f32 *, 0x160);
    }
    return var_v1;
}
