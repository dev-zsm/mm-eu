// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[2];
    u16 f2;
    u8 pad4[0xC];
    void *f10;
    s32 f14;
} Hdr800955C0;

typedef struct {
    u8 pad0[0xC];
    void *pC;
} Arg800955C0;

extern u16 D_8009FC70;
extern u32 D_8009E980;
extern u32 D_8009E988;
extern s32 D_8009E98C;

Hdr800955C0 *__osViGetCurrentContext(void);
s32 osRecvMesg(void *a, void **b, s32 c);
void __osTimerInterrupt(void);
void __osViSwapContext(void);
void osSendMesg(void *a, s32 b, s32 c);
u32 osGetCount(void);

void viMgrMain(Arg800955C0 *arg) {
    void *p;
    Hdr800955C0 *h;
    u32 *s1;
    u32 *s2;
    s32 *s3;
    u32 prev;
    u32 now;
    u32 diff;
    u32 lo;

    p = 0;
    h = __osViGetCurrentContext();
    D_8009FC70 = h->f2;
    if (h->f2 == 0) {
        D_8009FC70 = 1;
    }
    s1 = (u32 *)&D_8009E980;
    s2 = (u32 *)&D_8009E988;
    s3 = (s32 *)&D_8009E98C;

    while (1) {
        while (1) {
            osRecvMesg(arg->pC, &p, 1);
            if (*(u16 *)p == 0xD) {
                break;
            }
            if (*(u16 *)p == 0xE) {
                __osTimerInterrupt();
            }
        }
        __osViSwapContext();
        D_8009FC70 = D_8009FC70 - 1;
        if (D_8009FC70 == 0) {
            h = __osViGetCurrentContext();
            if (h->f10 != 0) {
                osSendMesg(h->f10, h->f14, 0);
            }
            D_8009FC70 = h->f2;
        }
        *s3 = *s3 + 1;
        prev = *s2;
        now = osGetCount();
        diff = now - prev;
        lo = s1[1] + diff;
        s1[0] = s1[0] + (lo < s1[1]);
        *s2 = now;
        s1[1] = lo;
    }
}
