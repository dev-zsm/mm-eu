// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s8 D_801EE355;

void Rumble_SetUpdateEnabled(s32 arg0) {
    D_801EE355 = arg0 != 0;
}
