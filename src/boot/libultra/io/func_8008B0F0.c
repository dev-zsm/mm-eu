// FLAGS: -O2 -g0 -mips2
#include "os_sp.h"

void osSpTaskYield(void) {
    __osSpSetStatus(SPSTATUS_SET_SIG0);
}
