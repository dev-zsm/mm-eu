// FLAGS: -O1 -g0 -mips2
#include "rcputils.h"

void RcpUtils_PrintRegisterStatus(void) {
    u32 spStatus;

    spStatus = __osSpGetStatus();
    osDpGetStatus();
}
