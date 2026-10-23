// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern void Collider_InitBase();
s32 Collider_InitTris(s32 a0, s32 *a1) {
    Collider_InitBase(a0, a1);
    a1[6] = 0;
    a1[7] = 0;
    return 1;
}
