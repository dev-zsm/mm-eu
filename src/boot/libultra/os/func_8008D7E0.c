// FLAGS: -O1 -g0 -mips2
#include "ultra64.h"

void osSetEventMesg(OSEvent event, OSMesgQueue *mq, OSMesg msg) {
    register OSIntMask saveMask;
    __OSEventState *entry;

    saveMask = __osDisableInt();
    entry = &D_8009E8E0[event];
    entry->messageQueue = mq;
    entry->message = msg;
    if (event == OS_EVENT_PRENMI) {
        if (D_8009804C != 0 && D_80098100 == 0) {
            osSendMesg(mq, msg, OS_MESG_NOBLOCK);
        }
        D_80098100 = 1;
    }
    __osRestoreInt(saveMask);
}
