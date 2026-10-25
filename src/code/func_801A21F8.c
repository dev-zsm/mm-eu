// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

extern u8 D_801F4C2C;
extern Vec3f D_801F4C30;
extern s16 D_801F4C3C;
extern f32 D_801F4C40;
extern f32 D_801F4C44;
extern f32 D_801F4C48;
extern f32 D_801F4C4C;

void Audio_SetObjSoundProperties(u8 channel, Vec3f *pos, s16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    D_801F4C2C = channel;
    D_801F4C30.x = pos->x;
    D_801F4C30.y = pos->y;
    D_801F4C30.z = pos->z;
    D_801F4C3C = arg2;
    D_801F4C40 = arg3;
    D_801F4C44 = arg4;
    D_801F4C48 = arg5;
    D_801F4C4C = arg6;
}
