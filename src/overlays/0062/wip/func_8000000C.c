// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_8000000C(s32 *a0, s32 a1, s32 *a2) {
    s32 t6;
    s32 t7;

    t7 = a2[0];
    a0[0] = t7;
    t6 = a2[1];
    a0[1] = t6;
    t7 = a2[2];
    a0[3] = 0;
    a0[4] = 0;
    a0[5] = 0;
    a0[6] = 0;
    a0[7] = 0;
    a0[2] = t7;
}
