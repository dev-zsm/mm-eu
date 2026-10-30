// FLAGS: -O1 -g0 -mips2
#include "ultra64.h"

void __osSetTimerIntr(OSTime time) {
    OSTime newTime;
    OSIntMask saveMask;

    if (time < 0x1D4) {
        time = 0x1D4;
    }
    saveMask = __osDisableInt();
    D_8009E990 = osGetCount();
    newTime = time + D_8009E990;
    __osSetCompare((u32)newTime);
    __osRestoreInt(saveMask);
}
