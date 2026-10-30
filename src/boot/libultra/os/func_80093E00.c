// FLAGS: -O1 -g0 -mips2
#include "ultra64.h"

void osYieldThread(void) {
    register OSIntMask saveMask;

    saveMask = __osDisableInt();
    D_80098010->state = OS_STATE_RUNNABLE;
    func_800892E4(&D_80098008);
    __osRestoreInt(saveMask);
}
