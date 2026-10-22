// FLAGS: -O1 -g3 -mips2
#include "types.h"

extern s8 D_8009E9A0[];
s32 __osSiGetAccess(void);
void __osSiRelAccess(void);
s32 __osSiRawStartDma(s32, s8 *);
void osRecvMesg(s32, s32, s32);

s32 __osContChannelReset(s32 arg0, s32 arg1) {
    s8 *p;
    s32 i;
    s32 ret;
    s32 n;

    __osSiGetAccess();
    p = D_8009E9A0;
    *(s32 *)&D_8009E9A0[0x3C] = 1;
    i = 0;
    if (arg1 > 0) {
        n = arg1 & 3;
        if (n != 0) {
            do {
                i++;
                *p = 0;
                p++;
            } while (n != i);
            if (i == arg1) {
                goto end;
            }
        }
        do {
            i += 4;
            p[0] = 0;
            p[1] = 0;
            p[2] = 0;
            p += 4;
            p[-1] = 0;
        } while (i != arg1);
    }
end:
    p[0] = 0xFD;
    p[1] = 0xFE;
    __osSiRawStartDma(1, D_8009E9A0);
    osRecvMesg(arg0, 0, 1);
    ret = __osSiRawStartDma(0, D_8009E9A0);
    osRecvMesg(arg0, 0, 1);
    __osSiRelAccess();
    return ret;
}
