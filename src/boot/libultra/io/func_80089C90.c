// FLAGS: -O2 -g0
#include "os_sp.h"

void __osSiGetAccess(void) {
    OSMesg dummy;

    if (D_80098020 == 0) {
        __osSiCreateAccessQueue();
    }
    osRecvMesg(&D_8009D288, &dummy, OS_MESG_BLOCK);
}
