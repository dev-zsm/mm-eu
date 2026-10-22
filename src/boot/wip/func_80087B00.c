// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern void osCreateMesgQueue(void *a, void *b, u32 c);
extern void osSetTimer(void *p, u64 x, u32 e5, u32 e6, void *e7, u32 e8);
extern void osRecvMesg(void *a, u32 b, u32 c);
void csleep(u64 x) {
    u8 e[0x14]; u32 sp50; u32 sp4C; u8 pad28[0x24];
    osCreateMesgQueue(&sp50, &sp4C, 1);
    osSetTimer(pad28, x, 0, 0, &sp50, 0);
    osRecvMesg(&sp50, 0, 1);
}
