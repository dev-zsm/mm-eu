// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_8009D2A0[];
extern u8 D_8009D2E0;

void __osSiGetAccess(s32 a0);
void __osPackReadData(void);
s32 __osSiRawStartDma(s32 a0, void *a1);
void osRecvMesg(s32 a0, s32 a1, s32 a2);
void __osSiRelAccess(void);

s32 osContStartReadData(s32 arg0) {
    s32 ret;

    __osSiGetAccess(arg0);
    if (D_8009D2E0 != 1) {
        __osPackReadData();
        __osSiRawStartDma(1, D_8009D2A0);
        osRecvMesg(arg0, 0, 1);
    }
    ret = __osSiRawStartDma(0, D_8009D2A0);
    D_8009D2E0 = 1;
    __osSiRelAccess();
    return ret;
}
