// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_801F3644;

void Matrix_Pop(void) {
    D_801F3644 -= 0x40;
}
