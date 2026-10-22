// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_8009E9A0[];

typedef struct Q4 {
    u8 b[4];
} Q4;

void __osPfsGetOneChannelData(s32 n, u8 *out) {
    u8 buf[6];
    u8 *p;
    s32 i;
    s32 t;

    p = D_8009E9A0;
    i = 0;
    if (n > 0) {
        if (n & 3) {
            do {
                i++;
                p++;
            } while (i != (n & 3));
        }
        if (i != n) {
            do {
                i += 4;
                p += 4;
            } while (i != n);
        }
    }
    *(Q4 *)buf = *(Q4 *)p;
    buf[4] = p[4];
    buf[5] = p[5];
    t = (buf[1] & 0xC0) >> 4;
    out[3] = t;
    if (t == 0) {
        *(u16 *)out = (buf[4] << 8) | buf[3];
        out[2] = buf[5];
    }
}
