// FLAGS: -O2 -g0 -mips2
#include "types.h"
f32 func_800969D0(f32 arg0, f32 arg1) {
    if (arg1 == 0.0f) {
        return 0.0f;
    }
    return arg0 - ((f32)(s32)(arg0 / arg1) * arg1);
}
