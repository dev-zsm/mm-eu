// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF488(s32, f32);                    /* extern */
f32 func_8017B984(s32);                             /* extern */
extern f32 D_80AF3988;

s32 func_800004AC(s32 arg0) {
    f32 temp_f0;

    temp_f0 = func_8017B984(arg0);
    if (temp_f0 < D_80AF3988) {
        return 0;
    }
    func_800FF488(arg0, 1.0f / temp_f0);
    return 1;
}
