// FLAGS: -O2 -g0
#include "sdk/os_sp.h"

void __osSiRelAccess(void) {
    osSendMesg(&D_8009D288, NULL, OS_MESG_NOBLOCK);
}
