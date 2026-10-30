// FLAGS: -O2 -g0
#include "dmamgr.h"

// Wakes the DMA thread with a NULL request, which makes DmaMgr_ThreadEntry return.
void DmaMgr_Stop(void) {
    osSendMesg(&D_8009B690, NULL, OS_MESG_BLOCK);
}
