// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
f32 func_800870A0(void);
f32 Rand_CenteredFloat(f32 a0) {
    f32 r = func_800870A0();
    return r * a0;
}
