// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 __osSiDeviceBusy(void);

s32 __osSiRawReadIo(u32 arg0, s32 *arg1) {
    if (__osSiDeviceBusy() != 0) {
        return -1;
    }
    *arg1 = *(s32 *)(arg0 | 0xA0000000);
    return 0;
}
