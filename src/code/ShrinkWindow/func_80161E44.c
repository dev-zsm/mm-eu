// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_801EE3D4;

void ShrinkWindow_Destroy(void) {
    D_801EE3D4 = 0;
}
