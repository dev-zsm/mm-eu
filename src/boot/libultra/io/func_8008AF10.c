// FLAGS: -O2 -g0 -mips2
#include "os_sp.h"

s32 __osSiRawStartDma(s32 direction, void *dramAddr) {
    if (IO_READ(SI_STATUS_REG) & (SI_STATUS_DMA_BUSY | SI_STATUS_IO_BUSY)) {
        return -1;
    }
    if (direction == OS_WRITE) {
        func_8008A780(dramAddr, 0x40);
    }
    IO_WRITE(SI_DRAM_ADDR_REG, osVirtualToPhysical(dramAddr));
    if (direction == OS_READ) {
        IO_WRITE(SI_PIF_ADDR_RD64B_REG, 0x1FC007C0);
    } else {
        IO_WRITE(SI_PIF_ADDR_WR64B_REG, 0x1FC007C0);
    }
    if (direction == OS_READ) {
        osInvalDCache(dramAddr, 0x40);
    }
    return 0;
}
