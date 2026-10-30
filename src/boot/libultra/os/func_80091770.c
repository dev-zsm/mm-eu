// FLAGS: -O1 -g0 -mips2
#include "ultra64.h"

void __osResetGlobalIntMask(OSHWIntr mask) {
    register OSIntMask saveMask;

    saveMask = __osDisableInt();
    D_80098050 &= ~(mask & ~OS_IM_RCP);
    __osRestoreInt(saveMask);
}
