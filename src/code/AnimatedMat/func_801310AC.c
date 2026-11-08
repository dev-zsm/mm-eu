// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

s32 AnimatedMat_Lerp(s32 min, s32 max, f32 norm) {
    return (s32) ((f32) (max - min) * norm) + min;
}
