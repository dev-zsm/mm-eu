// FLAGS: -O1 -g0 -mips2
#include "ultra64.h"

void __osGetHWIntrRoutine(OSHWIntr interrupt, s32 (**handler)(void), void **stackEnd) {
    *handler = D_80097FD0[interrupt].handler;
    *stackEnd = D_80097FD0[interrupt].stackEnd;
}
