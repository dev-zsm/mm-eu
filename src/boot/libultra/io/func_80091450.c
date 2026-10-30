// FLAGS: -O2 -g0 -mips2
#include "os_sp.h"

void osDpSetStatus(u32 status) {
    IO_WRITE(DPC_STATUS_REG, status);
}
