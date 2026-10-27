// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_801ED330;
extern s32 D_801ED334;

void AnimTaskQueue_DisableTransformTasksForGroup(s32 arg0) {
    D_801ED334 |= D_801ED330;
}
