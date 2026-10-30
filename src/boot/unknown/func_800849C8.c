// FLAGS: -O2 -g3 -mips2
#include "os_internal.h"
#include "rcputils.h"

void func_800849C8(void) {
    RcpUtils_PrintRegisterStatus();
    osDpSetStatus(0x28);
    __osSpSetStatus(0x4082);
    RcpUtils_PrintRegisterStatus();
}
