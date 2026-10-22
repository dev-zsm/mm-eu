// FLAGS: -O2 -g0 -mips2
#include "types.h"

s32 __osSpDeviceBusy(void) {
    s32 v;

    v = *(s32 *)0xA4040010;
    if (v & 0x1C) {
        return 1;
    }
    return 0;
}
