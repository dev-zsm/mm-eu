// FLAGS: -O2 -g3 -mips2
#include "types.h"

f32 func_800CAFC0(f32 arg0) {
    f32 var_f2;

    if (arg0 >= 0.0f) {
        var_f2 = arg0;
    } else {
        var_f2 = -arg0;
    }
    return var_f2;
}
