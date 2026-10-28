// FLAGS: -O2 -g0 -mips2
#include "types.h"

void __osPiGetAccess(void);
s32 __osPiRelAccess(void);
s32 __osEPiRawWriteIo(s32, s32, s32);

s32 osEPiWriteIo(s32 arg0, s32 arg1, s32 arg2) {
    s32 ret;

    __osPiGetAccess();
    ret = __osEPiRawWriteIo(arg0, arg1, arg2);
    __osPiRelAccess();
    return ret;
}
