// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

s16 EffectSs_LerpS16(s16 a, s16 b, f32 weight) {
    return (s16) (s32) (((f32) (b - a) * weight) + (f32) a);
}
