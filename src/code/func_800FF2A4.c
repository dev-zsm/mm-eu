// FLAGS: -O2 -g3 -mips2
#include "types.h"

f32 func_8008704C();                                /* extern */

s16 Rand_S16OffsetStride(s16 arg0, s16 arg1, s16 arg2) {
    return (s16) (((s16) (s32) (func_8008704C() * (f32) arg2) * arg1) + arg0);
}
