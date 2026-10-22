// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_800983BC;

void osViExtendVStart(s32 a) {
    *(s32 *)&D_800983BC = a;
}
