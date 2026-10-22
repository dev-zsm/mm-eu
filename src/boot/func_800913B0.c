// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 D_8009800C;

s32 __osGetActiveQueue(void) {
    return D_8009800C;
}
