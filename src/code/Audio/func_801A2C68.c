// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

extern Vec3f D_801F4C60;
extern u8 D_801F4C70;
extern u8 D_801F4C71;
extern u8 D_801F4C73;

void Audio_PlaySubBgmAtPosWithFilter(Vec3f *pos, u8 arg1, s32 arg2) {
    D_801F4C60.x = pos->x;
    D_801F4C60.y = pos->y;
    D_801F4C60.z = pos->z;
    D_801F4C70 = arg1;
    D_801F4C71 |= 1;
    D_801F4C73 = 4;
}
