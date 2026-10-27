// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

extern u8 D_801D3E04;
extern Vec3f D_801F4C50;
extern f32 D_801F4C6C;
extern u8 D_801F4C70;
extern u8 D_801F4C71;
extern u8 D_801F4C73;

void Audio_PlaySubBgmAtPos(Vec3f *pos, u8 seqId, f32 maxDist) {
    if (D_801D3E04 != 12) {
        D_801F4C50.x = pos->x;
        D_801F4C50.y = pos->y;
        D_801F4C50.z = pos->z;
        D_801F4C70 = seqId;
        D_801F4C6C = maxDist;
        D_801F4C71 |= 2;
        D_801F4C73 = 4;
    }
}
