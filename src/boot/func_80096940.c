// FLAGS: -O1 -g0 -mips2
#include "types.h"
typedef struct { s32 (*handler)(void); void *stackEnd; } HwIntr;
extern HwIntr D_80097FD0[];
u32 __osDisableInt(void); void __osRestoreInt(u32 m);
void __osSetHWIntrRoutine(s32 interrupt, s32 (*handler)(void), void *stackEnd) {
    register u32 saveMask = __osDisableInt();
    D_80097FD0[interrupt].handler = handler;
    D_80097FD0[interrupt].stackEnd = stackEnd;
    __osRestoreInt(saveMask);
}
