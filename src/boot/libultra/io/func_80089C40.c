// FLAGS: -O2 -g0
#include "os_sp.h"

void __osSiCreateAccessQueue(void) {
    D_80098020 = 1;
    osCreateMesgQueue(&D_8009D288, (OSMesg *)D_8009D280, 1);
    osSendMesg(&D_8009D288, NULL, OS_MESG_NOBLOCK);
}
