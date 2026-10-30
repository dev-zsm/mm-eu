// FLAGS: -O2 -g0
#include "os_sp.h"

void __osPiRelAccess(void) {
    osSendMesg(&D_8009E7C8, NULL, OS_MESG_NOBLOCK);
}
