// FLAGS: -O2 -g0
#include "os_sp.h"

void __osPiCreateAccessQueue(void) {
    D_80098090 = 1;
    osCreateMesgQueue(&D_8009E7C8, (OSMesg *)D_8009E7C0, 1);
    osSendMesg(&D_8009E7C8, NULL, OS_MESG_NOBLOCK);
}
