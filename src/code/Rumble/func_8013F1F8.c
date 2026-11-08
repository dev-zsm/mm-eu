// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

extern s8 D_801EE355;

void Rumble_SetUpdateEnabled(s32 updateEnabled) {
    D_801EE355 = updateEnabled != 0;
}
