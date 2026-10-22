// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3s32;

extern s32 D_801BADDC;

s32 Collider_InitCylinderDim(s32 arg0, Vec3s32 *arg1) {
    *(Vec3s32 __unaligned *)arg1 = *(Vec3s32 *)&D_801BADDC;
    return 1;
}
