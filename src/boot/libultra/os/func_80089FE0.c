// FLAGS: -O1 -g0 -mips2
#include "ultra64.h"

extern u8 D_800895C0[]; /* return address of a thread whose entry function returns */

void osCreateThread(OSThread *t, OSId id, void (*entry)(void *), void *arg, void *sp, OSPri pri) {
    register OSIntMask saveMask;
    OSIntMask mask;

    t->id = id;
    t->priority = pri;
    t->next = NULL;
    t->queue = NULL;
    t->context.pc = (u32)entry;
    t->context.a0 = (s64)(s32)arg;
    t->context.sp = (s64)(s32)sp - 0x10;
    t->context.ra = (s64)(s32)D_800895C0;
    mask = OS_IM_ALL;
    t->context.sr = SR_IMASK | SR_EXL | SR_IE;
    t->context.rcp = (mask & RCP_IMASK) >> 16;
    t->context.fpcsr = FPCSR_FS | FPCSR_EV;
    t->fp = 0;
    t->state = OS_STATE_STOPPED;
    t->flags = 0;
    saveMask = __osDisableInt();
    t->tlnext = D_8009800C;
    D_8009800C = t;
    __osRestoreInt(saveMask);
}
