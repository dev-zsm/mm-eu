// FLAGS: -O1 -g0 -mips2
#include "types.h"

s32 __osSpGetStatus(void);
void osDpGetStatus(void);

void RcpUtils_PrintRegisterStatus(void) {
    s32 sp1C;

    sp1C = __osSpGetStatus();
    osDpGetStatus();
}
