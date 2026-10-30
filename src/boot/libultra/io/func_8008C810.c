// FLAGS: -O2 -g3
#include "ultra64.h"

s32 __osPiRawStartDma(s32 direction, u32 cartAddr, void *dramAddr, u32 size) {
    volatile u32 *reg;
    u32 stat;

    reg = (volatile u32 *)PI_STATUS_REG;
    stat = *reg;
    while (stat & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) {
        stat = *reg;
    }
    IO_WRITE(PI_DRAM_ADDR_REG, osVirtualToPhysical(dramAddr));
    IO_WRITE(PI_CART_ADDR_REG, (D_80000308 | cartAddr) & 0x1FFFFFFF);
    switch (direction) {
        case OS_READ:
            IO_WRITE(PI_WR_LEN_REG, size - 1);
            break;
        case OS_WRITE:
            IO_WRITE(PI_RD_LEN_REG, size - 1);
            break;
        default:
            return -1;
    }
    return 0;
}
