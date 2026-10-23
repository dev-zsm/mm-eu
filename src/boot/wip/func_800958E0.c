// FLAGS: -O2 -g0 -mips2
// best attempt: loop gets unrolled by IDO (ROM: single 8-iteration loop, size 0x64); tried -O1/-O2, do/while/for/goto, m<end / m!=end
#include "types.h"

void guMtxF2L(f32 *mf, u32 *m) {
    s32 e1;
    s32 e2;
    u32 *end = m + 8;

    do {
        e1 = mf[0] * 65536.0f;
        e2 = mf[1] * 65536.0f;
        mf += 2;
        m++;
        m[-1] = ((u32)e1 & 0xFFFF0000) | ((u32)e2 >> 16);
        m[7] = ((u32)e1 << 16) | (e2 & 0xFFFF);
    } while (m < end);
}
