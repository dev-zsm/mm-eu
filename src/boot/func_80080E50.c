// FLAGS: -O2 -g0
#include "types.h"

extern u8 D_8009B690[];
void osSendMesg(void *a, u32 b, u32 c);

// Sends a NULL message to queue D_8009B690, the queue drained by DmaMgr_ThreadEntry.
// Likely osSendMesg with OS_MESG_BLOCK (libultra).
void DmaMgr_Stop(void) {
    osSendMesg(D_8009B690, 0, 1);
}
