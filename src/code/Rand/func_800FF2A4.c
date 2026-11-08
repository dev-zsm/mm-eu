// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

f32 func_8008704C();                                /* extern */

s16 Rand_S16OffsetStride(s16 base, s16 stride, s16 range) {
    return (s16) (((s16) (s32) (func_8008704C() * (f32) range) * stride) + base);
}
