// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 b[8];
} Entry;

extern s8 D_8009D2E0;
extern u8 D_8009D2E1;
extern u8 D_8009E9A0[];

void __osPfsRequestData(u8 arg0) {
    s32 i;
    Entry sp4;
    u8 *p;

    p = D_8009E9A0;
    D_8009D2E0 = arg0 & 0xFF;
    *(s32 *)(p + 0x3C) = 1;
    sp4.b[0] = 0xFF;
    sp4.b[1] = 1;
    sp4.b[2] = 3;
    sp4.b[3] = arg0;
    sp4.b[4] = 0xFF;
    sp4.b[5] = 0xFF;
    sp4.b[6] = 0xFF;
    sp4.b[7] = 0xFF;
    i = 0;
    if (D_8009D2E1 > 0) {
        do {
            i++;
            *(Entry *)p = sp4;
            p += 8;
        } while (i < D_8009D2E1);
    }
    *p = 0xFE;
}
