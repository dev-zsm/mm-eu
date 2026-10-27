// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 D_80098014;

s32 __osGetCurrFaultedThread(void) {
    return D_80098014;
}
