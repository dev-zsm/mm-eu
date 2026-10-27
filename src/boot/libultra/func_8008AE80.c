// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 __osSpDeviceBusy(void);
extern s32 osVirtualToPhysical(s32 a0);

s32 __osSpRawStartDma(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (__osSpDeviceBusy() != 0) {
        return -1;
    }
    *(s32 *)0xA4040000 = arg1;
    *(s32 *)0xA4040004 = osVirtualToPhysical(arg2);
    if (arg0 == 0) {
        *(s32 *)0xA404000C = arg3 - 1;
    } else {
        *(s32 *)0xA4040008 = arg3 - 1;
    }
    return 0;
}
