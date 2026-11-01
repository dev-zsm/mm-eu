// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "code_funcs.h"

extern s32 D_801BBBC0;

void Debug_ClearTextDrawFlags(void) {
    D_801BBBC0 = 0;
}
