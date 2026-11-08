// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
#include "generated/code_funcs.h"

extern s32 func_80092400(u16 arg0);
extern f32 D_801D5B10;

f32 Math_CosS(s16 angle) {
    return func_80092400(angle) * D_801D5B10;
}
