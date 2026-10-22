// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_8009D2E0;
extern u8 D_8009E9A0[];

typedef struct Q4 {
    u8 b[4];
} Q4;

void __osPfsRequestOneChannel(s32 n, u8 val) {
    u8 buf[6];
    u8 *p;
    s32 i;

    p = D_8009E9A0;
    D_8009D2E0 = 0xFE;
    *(s32 *)(p + 0x3C) = 1;
    buf[0] = 1;
    buf[1] = 3;
    buf[2] = val;
    buf[3] = 0xFF;
    buf[4] = 0xFF;
    buf[5] = 0xFF;
    i = 0;
    if (n > 0) {
        if (n & 3) {
            do {
                i++;
                *p++ = 0;
            } while (i != (n & 3));
        }
        if (i != n) {
            do {
                i += 4;
                p[0] = 0;
                p[1] = 0;
                p[2] = 0;
                p[3] = 0;
                p += 4;
            } while (i != n);
        }
    }
    *(Q4 *)p = *(Q4 *)buf;
    p[4] = buf[4];
    p[5] = buf[5];
    p[6] = 0xFE;
}
