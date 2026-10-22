// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
f32 Quake_Random();                                /* extern */
M2C_UNK Quake_UpdateShakeInfo(void *, s32, f32, f32);       /* extern */

s16 Quake_CallbackType2(void *arg0, s32 arg1) {
    f32 sp1C;
    s16 var_v1;

    var_v1 = M2C_FIELD(arg0, s16 *, 0x1E);
    if (var_v1 > 0) {
        sp1C = Quake_Random();
        Quake_UpdateShakeInfo(arg0, arg1, sp1C, func_8008704C() * sp1C);
        M2C_FIELD(arg0, s16 *, 0x1E) = (s16) (M2C_FIELD(arg0, s16 *, 0x1E) - 1);
        var_v1 = M2C_FIELD(arg0, s16 *, 0x1E);
    }
    return var_v1;
}
