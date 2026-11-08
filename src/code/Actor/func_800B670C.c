// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

extern f32 D_801AF81C;

void Actor_SetMovementScale(s32 scale) {
    D_801AF81C = (f32) scale * 0.5f;
}
