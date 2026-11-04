// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
s32 Math_Atan2S(void);
extern f32 D_801D7A70;
f32 Math_Atan2F(void) {
    f32 r = Math_Atan2S();
    return r * D_801D7A70;
}
