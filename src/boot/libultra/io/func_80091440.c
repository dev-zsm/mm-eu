// FLAGS: -O2 -g0 -mips2
#include "os_sp.h"

u32 osDpGetStatus(void) {
    return IO_READ(DPC_STATUS_REG);
}
