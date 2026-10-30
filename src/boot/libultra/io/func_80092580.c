// FLAGS: -O2 -g0 -mips2
#include "os_vi.h"

void osViSetEvent(OSMesgQueue *mq, OSMesg msg, u32 retraceCount) {
    OSIntMask mask;

    mask = __osDisableInt();
    D_800982B4->msgq = mq;
    D_800982B4->msg = msg;
    D_800982B4->retraceCount = retraceCount;
    __osRestoreInt(mask);
}
