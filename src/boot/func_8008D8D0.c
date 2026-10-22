// FLAGS: -O2 -g0 -mips2
#include "types.h"

void __osSiGetAccess(s32 a0);
void __osPackRequestData(s32 a0);
s32 __osSiRawStartDma(s32 a0, u8 *a1);
void osRecvMesg(s32 a0, s32 a1, s32 a2);
void __osSiRelAccess(void);

extern u8 D_8009D2E0;
extern u8 D_8009D2A0[];

s32 osContStartQuery(s32 a0) {
    s32 ret;

    __osSiGetAccess(a0);
    if (D_8009D2E0 != 0) {
        __osPackRequestData(0);
        __osSiRawStartDma(1, D_8009D2A0);
        osRecvMesg(a0, 0, 1);
    }
    ret = __osSiRawStartDma(0, D_8009D2A0);
    D_8009D2E0 = 0;
    __osSiRelAccess();
    return ret;
}
