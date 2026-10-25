#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

extern Vec3f D_801C19E4[];
extern void Actor_SetFeetPos(void *arg0, s32 arg1, s32 arg2, Vec3f *arg3, s32 arg4, Vec3f *arg5);

void Player_SetFeetPos(s32 arg0, u8 *arg1, s32 arg2) {
    Vec3f *pos = &D_801C19E4[arg1[0x14B]];

    Actor_SetFeetPos(arg1, arg2, 9, pos, 6, pos);
}
