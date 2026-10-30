// FLAGS: -O2 -g0 -mips2
#include "ultra64.h"

s32 osEPiWriteIo(OSPiHandle *handle, u32 devAddr, u32 data) {
    s32 ret;

    __osPiGetAccess();
    ret = __osEPiRawWriteIo(handle, devAddr, data);
    __osPiRelAccess();
    return ret;
}
