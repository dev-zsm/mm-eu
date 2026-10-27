// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern f32 D_801AF81C;

void Actor_SetMovementScale(s32 arg0) {
    D_801AF81C = (f32) arg0 * 0.5f;
}
