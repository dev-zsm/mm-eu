// FLAGS: -O2 -g0 -mips2
#include "sdk/os_sp.h"

void osSpTaskYield(void) {
    __osSpSetStatus(SPSTATUS_SET_SIG0);
}
