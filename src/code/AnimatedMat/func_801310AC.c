// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 AnimatedMat_Lerp(s32 arg0, s32 arg1, f32 arg2) {
    return (s32) ((f32) (arg1 - arg0) * arg2) + arg0;
}
