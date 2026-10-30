// FLAGS: -O2 -g0
#include "os_sp.h"

void __osPiGetAccess(void) {
    OSMesg dummy;

    if (D_80098090 == 0) {
        __osPiCreateAccessQueue();
    }
    osRecvMesg(&D_8009E7C8, &dummy, OS_MESG_BLOCK);
}
