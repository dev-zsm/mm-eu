// FLAGS: -O2 -g0 -mips2
#include "types.h"

s32 __osSiDeviceBusy(void);

s32 __osSiRawWriteIo(s32 a0, s32 a1) {
    if (__osSiDeviceBusy() != 0) {
        return -1;
    }
    *(s32 *)((u32)a0 | 0xA0000000) = a1;
    return 0;
}
