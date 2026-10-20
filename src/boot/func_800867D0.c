// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern f32 func_800884F0(f32 a0);
extern f32 func_800920E0(f32 a0);

f32 func_800867D0(f32 arg0) {
    f32 sp1C;

    sp1C = func_800884F0(arg0);
    return sp1C / func_800920E0(arg0);
}

