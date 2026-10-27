// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_801ED330;

void AnimTaskQueue_SetNextGroup(s32 arg0) {
    D_801ED330 *= 2;
}
