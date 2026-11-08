// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

extern s32 D_801ED330;
extern s32 D_801ED334;

void AnimTaskQueue_DisableTransformTasksForGroup(struct PlayState *play) {
    D_801ED334 |= D_801ED330;
}
