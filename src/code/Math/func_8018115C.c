// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
s32 func_80180F74(void);
extern f32 D_801D7A70;
f32 Math_Atan2F(void) {
    f32 r = func_80180F74();
    return r * D_801D7A70;
}
