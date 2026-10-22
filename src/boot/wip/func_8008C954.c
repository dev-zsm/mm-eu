// FLAGS: -O2 -g0
#include "types.h"
s32 __osIdCheckSum(u16 *a0, u16 *a1, u16 *a2) {
    u16 *q;
    s32 v;
    *a2 = 0;
    *a1 = 0;
    v = a0[0];
    *a1 = v;
    *a2 += ~v;
    v = a0[1];
    *a1 += v;
    *a2 += ~v;
    q = a0 + 2;
    do {
        v = q[0];
        *a1 += v;
        *a2 += ~v;
        v = q[1];
        *a1 += v;
        *a2 += ~v;
        v = q[2];
        *a1 += v;
        *a2 += ~v;
        v = q[3];
        *a1 += v;
        *a2 += ~v;
        q += 4;
    } while (q != a0 + 14);
    return 0;
}
