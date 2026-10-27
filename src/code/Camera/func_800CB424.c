// FLAGS: -O2 -g3 -mips2
#include "types.h"

s16 Camera_AngleDiffAndScale(s16 arg0, s16 arg1, f32 arg2) {
    return (s16) (s32) ((f32) (s16) (arg0 - arg1) * arg2);
}
