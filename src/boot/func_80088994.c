// FLAGS: -O1 -g0 -mips2
#include "types.h"

s32 __osSpDeviceBusy(void);
void __osSpSetStatus(s32 arg0);

void osSpTaskStartGo(s32 arg0) {
    if (__osSpDeviceBusy() != 0) {
        do {
        } while (__osSpDeviceBusy() != 0);
    }
    __osSpSetStatus(0x125);
}
