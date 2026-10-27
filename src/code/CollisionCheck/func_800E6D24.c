#include "types.h"

extern void CollisionCheck_OC_JntSphVsCyl();

void CollisionCheck_OC_CylVsJntSph(s32 a0, s32 a1, s32 a2, s32 a3) {
    CollisionCheck_OC_JntSphVsCyl(a0, a1, a3, a2);
}
