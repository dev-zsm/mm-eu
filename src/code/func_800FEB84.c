// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
// -Wab,-r4300_mul: the ROM has a nop after mul.s before the return
#include "types.h"

extern f32 D_801D5B14;
s32 func_800886B0(u16 angle);

f32 Math_SinS(s16 angle) {
    return func_800886B0(angle) * D_801D5B14;
}
