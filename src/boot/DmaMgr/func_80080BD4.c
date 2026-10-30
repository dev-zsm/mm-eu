// FLAGS: -O2 -g3 -mips2
#include "dmamgr.h"

// Serves requests until a NULL one arrives (see DmaMgr_Stop).
void DmaMgr_ThreadEntry(void *arg) {
    DmaRequest *req;
    DmaRequest *cur; /* matching: the second pointer keeps IDO's register choice */

    for (;;) {
        osRecvMesg(&D_8009B690, (OSMesg *)&req, OS_MESG_BLOCK);
        if (req == NULL) {
            break;
        }
        cur = req;
        DmaMgr_ProcessRequest(cur);
        if (cur->notifyQueue != NULL) {
            osSendMesg(cur->notifyQueue, cur->notifyMsg, OS_MESG_NOBLOCK);
        }
    }
}
