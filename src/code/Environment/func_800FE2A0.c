// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

extern u8 D_801EC6B0;

u8 Environment_IsTimeStopped(void) {
    return D_801EC6B0;
}
