#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0447.h"

M2C_UNK func_800B6490(s32);                         /* extern */
s32 func_800BAE44(s32, s32, s32, M2C_UNK, f32, f32, f32, s32, s32, s32, s32); /* extern */

s32 func_80001D60(s32 arg0, s32 arg1, M2C_UNK arg2) {
    s32 var_v1;

    var_v1 = 0;
    if (func_800BAE44(arg1 + 0x1CA0, arg0, arg1, 0x17D, 116.0f, 26.0f, -219.0f, 0, -0x3F46, 0, 0) != 0) {
        func_800B6490(arg0);
        var_v1 = 1;
    }
    return var_v1;
}
