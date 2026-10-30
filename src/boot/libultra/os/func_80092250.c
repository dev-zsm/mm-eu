// FLAGS: -O2 -g0 -mips2
#include "ultra64.h"

s32 osEPiReadIo(OSPiHandle *handle, u32 devAddr, u32 *data) {
    volatile s32 ret; /* matching: the ROM keeps the result in a stack slot */

    __osPiGetAccess();
    ret = __osEPiRawReadIo(handle, devAddr, data);
    __osPiRelAccess();
    return ret;
}
