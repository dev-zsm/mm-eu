// FLAGS: -O2 -g0 -mips2
#include "types.h"

void CollisionCheck_OC_CylVsSphere(s32, s32, s32, s32);

void CollisionCheck_OC_SphereVsCyl(s32 a0, s32 a1, s32 a2, s32 a3) {
    CollisionCheck_OC_CylVsSphere(a0, a1, a3, a2);
}
