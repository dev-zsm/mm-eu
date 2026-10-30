// FLAGS: -O2 -g0 -mips2
#include "os_sp.h"

s32 __osSiRawReadIo(u32 devAddr, u32 *data) {
    if (__osSiDeviceBusy() != 0) {
        return -1;
    }
    *data = IO_READ(devAddr | K1BASE);
    return 0;
}
