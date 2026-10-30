// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

void Fault_Wait5Seconds(void) {
    u8 pad[8]; /* matching: unused, needed for the frame layout */
    OSTime start;
    OSTime now;

    start = osGetTime();
    do {
        Fault_Sleep(0x10);
        now = osGetTime();
    } while (now - start < 5 * OS_CPU_COUNTER + 1ULL);
    D_8009C220->autoScroll = 1;
}
