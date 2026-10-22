// FLAGS: -O2 -g3 -mips2
#include "types.h"

void CollisionCheck_OC_JntSphVsSphere(void *, void *, void *, void *);

void CollisionCheck_OC_SphereVsJntSph(void *a0, void *a1, void *a2, void *a3) {
    CollisionCheck_OC_JntSphVsSphere(a0, a1, a3, a2);
}
