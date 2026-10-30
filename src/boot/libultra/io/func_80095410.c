// FLAGS: -O2 -g0 -mips2
#include "os_sp.h"

u32 __osSpGetStatus(void) {
    return IO_READ(SP_STATUS_REG);
}
