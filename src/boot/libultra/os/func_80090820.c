// FLAGS: -O1 -g0 -mips2
#include "ultra64.h"

void __osSetGlobalIntMask(OSHWIntr mask) {
    register OSIntMask saveMask;

    saveMask = __osDisableInt();
    D_80098050 |= mask;
    __osRestoreInt(saveMask);
}
