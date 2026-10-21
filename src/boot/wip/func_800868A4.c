// FLAGS: -O2 -g3
#include "types.h"

extern f32 D_80099350;

f32 func_800868A4(f32 arg0) {
    f32 *var_v0;
    f32 temp_f0;
    f32 temp_f4;
    f32 temp_f12;
    f32 temp_f16;
    f32 var_f14;
    f32 var_f2;

    temp_f0 = arg0 * arg0;
    var_f2 = arg0;
    var_v0 = &D_80099350;
    var_f14 = arg0 * temp_f0;
    for (;;) {
        temp_f4 = *var_v0;
        var_v0 += 1;
        temp_f12 = temp_f4 * var_f14;
        temp_f16 = var_f2 + temp_f12;
        if (var_f2 == temp_f16) {
            break;
        }
        var_f14 *= temp_f0;
        var_f2 = temp_f16;
    }
    return var_f2;
}
