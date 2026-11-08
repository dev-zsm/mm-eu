// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

extern s32 D_801ED330;

void AnimTaskQueue_SetNextGroup(struct PlayState *play) {
    D_801ED330 *= 2;
}
