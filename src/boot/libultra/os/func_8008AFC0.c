// FLAGS: -O2 -g0 -mips2
#include "ultra64.h"

s32 osEPiLinkHandle(OSPiHandle *handle) {
    OSIntMask saveMask;

    saveMask = __osDisableInt();
    handle->next = D_8009807C;
    D_8009807C = handle;
    __osRestoreInt(saveMask);
    return 0;
}
