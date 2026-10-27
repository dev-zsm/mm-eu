#include "types.h"

extern void osGetThreadId(s32 arg0);
extern void Fault_AddHungupAndCrash(s32 arg0, s32 arg1);

void _dbg_hungup(s32 arg0, s32 arg1) {
    osGetThreadId(0);
    Fault_AddHungupAndCrash(arg0, arg1);
}

