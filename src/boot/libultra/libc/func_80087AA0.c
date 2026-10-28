// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void _Printf(s32 a0, void *a1, s32 a2, s32 a3);

void vaprintf(s32 *arg0, s32 arg1, s32 arg2) {
    _Printf(*arg0, arg0, arg1, arg2);
}

