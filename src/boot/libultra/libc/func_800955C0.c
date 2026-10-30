// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
// viRetrace is a function-static in the original; temp is always zero and only shapes the code generation
#include "libultra_libc.h"

void viMgrMain(void *args) {
    OSDevMgr *dmArgs;
    static u16 viRetrace;
    u32 addTime;
    OSIoMesg *mesg;
    u32 temp;

    mesg = 0;
    temp = 0;
    viRetrace = __osViGetCurrentContext()->retraceCount;
    if (viRetrace == 0) {
        viRetrace = 1;
    }
    dmArgs = (OSDevMgr *)args;
    for (;;) {
        osRecvMesg(dmArgs->evtQueue, (OSMesg *)&mesg, OS_MESG_BLOCK);
        switch (mesg->hdr.type) {
            case OS_MESG_TYPE_VRETRACE:
                __osViSwapContext();
                viRetrace--;
                if (viRetrace == 0) {
                    OSViContext *ctx = __osViGetCurrentContext();

                    if (ctx->msgq != NULL) {
                        osSendMesg(ctx->msgq, ctx->msg, OS_MESG_NOBLOCK);
                    }
                    viRetrace = ctx->retraceCount;
                }
                D_8009E98C++;
                if (temp) {
                    D_8009E980 = osGetCount();
                }
                addTime = D_8009E988;
                D_8009E988 = osGetCount();
                addTime = D_8009E988 - addTime;
                D_8009E980 = addTime + D_8009E980;
                break;
            case OS_MESG_TYPE_COUNTER:
                __osTimerInterrupt();
                break;
        }
    }
}
