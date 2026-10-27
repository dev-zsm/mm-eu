// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_801F3644;

s32 Matrix_GetCurrent(void) {
    return D_801F3644;
}
