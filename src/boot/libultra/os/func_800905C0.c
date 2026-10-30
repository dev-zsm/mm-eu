// FLAGS: -O1 -g0 -mips2
#include "ultra64.h"

OSTime osGetTime(void) {
    u32 tmptime;
    u32 elapseCount;
    OSTime currentCount;
    register OSIntMask saveMask;

    saveMask = __osDisableInt();
    tmptime = osGetCount();
    elapseCount = tmptime - D_8009E988;
    currentCount = D_8009E980;
    __osRestoreInt(saveMask);
    return currentCount + elapseCount;
}
