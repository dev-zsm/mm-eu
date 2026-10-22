// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u64 osGetTime(void);
extern void Fault_Sleep(s32);
extern u8 *D_8009C220;

void Fault_Wait5Seconds(void) {
    u8 pad[8];
    u64 start;
    u64 now;

    start = osGetTime();
    do {
        Fault_Sleep(0x10);
        now = osGetTime();
    } while (now - start < 0xDF84759ULL);
    D_8009C220[0x7CF] = 1;
}
