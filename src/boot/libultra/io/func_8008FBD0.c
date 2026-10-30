// FLAGS: -O2 -g0 -mips2
#include "os_sp.h"

s32 __osSiDeviceBusy(void) {
    u32 status;

    status = IO_READ(SI_STATUS_REG);
    if (status & (SI_STATUS_DMA_BUSY | SI_STATUS_IO_BUSY)) {
        return 1;
    }
    return 0;
}
