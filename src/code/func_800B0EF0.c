// FLAGS: -O2 -g3 -mips2
#include "types.h"

s16 EffectSs_LerpS16(s16 arg0, s16 arg1, f32 arg2) {
    return (s16) (s32) (((f32) (arg1 - arg0) * arg2) + (f32) arg0);
}
