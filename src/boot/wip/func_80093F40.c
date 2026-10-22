// FLAGS: -O2 -g0 -mips2
#include "types.h"

void __osSiGetAccess(s32);
void __osSiRelAccess(void);
void __osSiRawStartDma(s32, u8 *);
void osRecvMesg(s32, s32, s32);
s32 __osPfsGetStatus(s32, s32);
s32 __osContAddressCrc(u16);
s32 __osContDataCrc(s32);
void bcopy(s32, u8 *, s32);

extern s32 D_800981A0;
extern u8 D_8009D2E0;
extern u8 D_8009E9A0[];

s32 __osContRamWrite(s32 arg0, s32 arg1, u16 arg2, s32 arg3, s32 arg4) {
    u8 *s0;
    u8 *s3;
    u8 *pf;
    s32 *pa;
    s32 sp40;
    s32 sp44;
    s32 s4;
    s32 v1;
    s32 n;
    s32 cond;
    u8 s2;
    u16 x;

    x = arg2;
    if (arg4 != 1 && x < 7 && x != 0) {
        return 0;
    }
    s4 = 2;
    __osSiGetAccess(arg0);
    sp44 = x >> 3;
    sp40 = x << 5;
    s3 = D_8009E9A0;
    pf = &D_8009D2E0;
    pa = &D_800981A0;

    for (;;) {
        s0 = s3;
        if (*pf != 3 || arg1 != *pa) {
            *pf = 3;
            *pa = arg1;
            if (arg1 > 0) {
                n = 0;
                do {
                    *s0 = 0;
                    s0 += 1;
                    n += 1;
                } while (n != arg1);
            }
            *(s32 *)(s3 + 0x3C) = 1;
            s0[0] = 0xFF;
            s0[1] = 0x23;
            s0[2] = 1;
            s0[3] = 3;
            s0[0x26] = 0xFF;
            s0[0x27] = 0xFE;
        } else {
            s0 = s3 + arg1;
        }

        s0[4] = (u8) sp44;
        s0[5] = (u8) (__osContAddressCrc(x) | sp40);
        bcopy(arg3, s0 + 6, 0x20);
        __osSiRawStartDma(1, s3);
        s2 = (u8) __osContDataCrc(arg3);
        osRecvMesg(arg0, 0, 1);
        __osSiRawStartDma(0, s3);
        osRecvMesg(arg0, 0, 1);

        v1 = (s0[2] & 0xC0) >> 4;
        if (v1 != 0) {
            v1 = 1;
            break;
        }
        if (s0[0x26] == s2) {
            break;
        }
        v1 = __osPfsGetStatus(arg0, arg1);
        if (v1 != 0) {
            break;
        }
        v1 = 4;
        cond = s4 >= 0;
        s4 -= 1;
        if (!cond) {
            break;
        }
    }

    __osSiRelAccess();
    return v1;
}
