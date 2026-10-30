// FLAGS: -O1 -g0 -mips2
#include "os_sp.h"

void osSpTaskStartGo(OSTask *task) {
    if (__osSpDeviceBusy() != 0) {
        do {
        } while (__osSpDeviceBusy() != 0);
    }
    __osSpSetStatus(SPSTATUS_CLEAR_HALT | SPSTATUS_CLEAR_BROKE | SPSTATUS_CLEAR_SSTEP | SPSTATUS_SET_INTR_BREAK);
}
