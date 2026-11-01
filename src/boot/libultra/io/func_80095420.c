// FLAGS: -O2 -g0 -mips2
#include "sdk/os_sp.h"

void __osSpSetStatus(u32 status) {
    IO_WRITE(SP_STATUS_REG, status);
}
