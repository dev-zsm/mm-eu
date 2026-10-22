// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 D_80098030;
extern u8 D_8009D2A0[];
extern u8 D_8009D2E0;
extern u8 D_8009D2E1;
extern u8 D_8009D308[];
extern u8 D_8009D320[];

s64 osGetTime(void);
void osCreateMesgQueue(void *a0, void *a1, s32 a2);
void osSetTimer(void *a0, s64 a2, s64 a3, void *a4, void *a5);
void osRecvMesg(void *a0, void *a1, s32 a2);
void __osPackRequestData(u8 a0);
void __osContGetInitData(u8 *a0, void *a1);
void __osSiCreateAccessQueue(void);
s32 __osSiRawStartDma(s32 a0, void *a1);

typedef struct {
    u8 a[0x18];
    u8 b[0x20];
    s64 c;
    s32 d;
    u8 e[4];
} Loc;

s32 osContInit(void *arg0, s32 arg1, s32 arg2) {
    Loc L;

    if (D_80098030 != 0) {
        return 0;
    }
    D_80098030 = 1;
    L.c = osGetTime();
    if ((u64)L.c < 0x0165A0BC) {
        osCreateMesgQueue(L.a, L.e, 1);
        osSetTimer(L.b, (s64)0x0165A0BC - L.c, 0, L.a, L.e);
        osRecvMesg(L.a, L.e, 1);
    }
    D_8009D2E1 = 4;
    __osPackRequestData(0);
    __osSiRawStartDma(1, D_8009D2A0);
    osRecvMesg(arg0, L.e, 1);
    L.d = __osSiRawStartDma(0, D_8009D2A0);
    osRecvMesg(arg0, L.e, 1);
    __osContGetInitData(arg1, arg2);
    D_8009D2E0 = 0;
    __osSiCreateAccessQueue();
    osCreateMesgQueue(D_8009D308, D_8009D320, 1);
    return L.d;
}
