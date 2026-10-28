// FLAGS: -O1 -g0 -mips2
#include "types.h"

extern u32 __osDisableInt(void);
extern u32 osGetCount(void);
extern void __osRestoreInt(u32 a0);
extern u64 D_8009E980;
extern u32 D_8009E988;

u64 osGetTime(void) {
    u32 tmptime;
    u32 elapseCount;
    u64 currentCount;
    register u32 saveMask;

    saveMask = __osDisableInt();
    tmptime = osGetCount();
    elapseCount = tmptime - D_8009E988;
    currentCount = D_8009E980;
    __osRestoreInt(saveMask);
    return currentCount + elapseCount;
}
