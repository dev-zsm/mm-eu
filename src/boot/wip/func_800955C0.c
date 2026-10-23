// FLAGS: -O2 -g0 -mips2
// best attempt: 17 instr differ (the three global addresses get s1..s3 in the opposite order; retrace is a function-static stand-in for the file-static D_8009FC70, so this cannot be linked as is)
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

void viMgrMain(DevMgr *dm) {
    static u16 D_8009FC70x;
    ViContext *vc;
    u32 count;
    ViMsg *mb;
    u32 first;

    mb = 0;
    vc = __osViGetCurrentContext();
    D_8009FC70x = vc->retraceCount;
    if (D_8009FC70x == 0) {
        D_8009FC70x = 1;
    }
    while (1) {
        osRecvMesg(dm->evtQueue, &mb, 1);
        switch (mb->type) {
            case 13:
                __osViSwapContext();
                D_8009FC70x--;
                if (D_8009FC70x == 0) {
                    vc = __osViGetCurrentContext();
                    if (vc->msgq != 0) {
                        osSendMesg(vc->msgq, vc->msg, 0);
                    }
                    D_8009FC70x = vc->retraceCount;
                }
                D_8009E98C++;
                count = D_8009E988;
                first = osGetCount();
                D_8009E988 = first;
                first -= count;
                D_8009E980 += first;
                break;
            case 14:
                __osTimerInterrupt();
                break;
        }
    }
}
