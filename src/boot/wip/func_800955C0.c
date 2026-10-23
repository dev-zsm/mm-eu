// FLAGS: -O2 -g0 -mips2
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

extern u16 D_8009FC70;
extern u64 D_8009E980;
extern u32 D_8009E988;
extern u32 D_8009E98C;

ViContext *__osViGetCurrentContext(void);
s32 osRecvMesg(void *a, void *b, s32 c);
void __osTimerInterrupt(void);
void __osViSwapContext(void);
void osSendMesg(void *a, void *b, s32 c);
u32 osGetCount(void);

void viMgrMain(DevMgr *dm) {
    ViContext *vc;
    ViMsg *mb;
    u32 count;
    u32 elapsed;

    mb = 0;
    vc = __osViGetCurrentContext();
    D_8009FC70 = vc->retraceCount;
    if (D_8009FC70 == 0) {
        D_8009FC70 = 1;
    }
    while (1) {
        osRecvMesg(dm->evtQueue, &mb, 1);
        switch (mb->type) {
            case 13:
                __osViSwapContext();
                D_8009FC70--;
                if (D_8009FC70 == 0) {
                    vc = __osViGetCurrentContext();
                    if (vc->msgq != 0) {
                        osSendMesg(vc->msgq, vc->msg, 0);
                    }
                    D_8009FC70 = vc->retraceCount;
                }
                D_8009E98C++;
                count = osGetCount();
                elapsed = count - D_8009E988;
                D_8009E988 = count;
                D_8009E980 += elapsed;
                break;
            case 14:
                __osTimerInterrupt();
                break;
        }
    }
}
