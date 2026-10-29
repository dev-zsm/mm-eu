// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
// viRetrace is a function-static in the original; temp is always zero and only shapes the code generation
#include "types.h"

typedef struct {
    u8 pad0[2];
    u16 retraceCount;
    u8 pad4[0xC];
    void *msgq;
    void *msg;
} ViContext;

typedef struct {
    u16 type;
} ViMsg;

typedef struct {
    u8 pad0[0xC];
    void *evtQueue;
} DevMgr;

extern u64 D_8009E980;
extern u32 D_8009E988;
extern u32 D_8009E98C;

ViContext *__osViGetCurrentContext(void);
s32 osRecvMesg(void *a, void *b, s32 c);
void __osTimerInterrupt(void);
void __osViSwapContext(void);
void osSendMesg(void *a, void *b, s32 c);
u32 osGetCount(void);

void viMgrMain(void *arg) {
    DevMgr *dmArgs;
    static u16 viRetrace;
    u32 addTime;
    ViMsg *mesg;
    u32 temp;

    mesg = 0;
    temp = 0;
    viRetrace = __osViGetCurrentContext()->retraceCount;
    if (viRetrace == 0) {
        viRetrace = 1;
    }
    dmArgs = (DevMgr *)arg;
    for (;;) {
        osRecvMesg(dmArgs->evtQueue, &mesg, 1);
        switch (mesg->type) {
            case 13:
                __osViSwapContext();
                viRetrace--;
                if (viRetrace == 0) {
                    ViContext *ctx = __osViGetCurrentContext();
                    if (ctx->msgq != 0) {
                        osSendMesg(ctx->msgq, ctx->msg, 0);
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
            case 14:
                __osTimerInterrupt();
                break;
        }
    }
}
