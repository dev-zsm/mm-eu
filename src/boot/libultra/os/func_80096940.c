// FLAGS: -O1 -g0 -mips2
#include "sdk/os_internal.h"

void __osSetHWIntrRoutine(OSHWIntr interrupt, s32 (*handler)(void), void *stackEnd) {
    register OSIntMask saveMask = __osDisableInt();

    D_80097FD0[interrupt].handler = handler;
    D_80097FD0[interrupt].stackEnd = stackEnd;
    __osRestoreInt(saveMask);
}
