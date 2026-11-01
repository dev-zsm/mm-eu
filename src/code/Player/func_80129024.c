#include "types.h"
#include "generated/code_funcs.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

extern Vec3f D_801C19E4[];

void Player_SetFeetPos(s32 arg0, u8 *arg1, s32 arg2) {
    Vec3f *pos = &D_801C19E4[arg1[0x14B]];

    Actor_SetFeetPos(arg1, arg2, 9, pos, 6, pos);
}
