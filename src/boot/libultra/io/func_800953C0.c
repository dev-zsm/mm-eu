// FLAGS: -O2 -g0 -mips2
#include "os_sp.h"

s32 __osSiRawWriteIo(u32 devAddr, u32 data) {
    if (__osSiDeviceBusy() != 0) {
        return -1;
    }
    IO_WRITE(devAddr | K1BASE, data);
    return 0;
}
