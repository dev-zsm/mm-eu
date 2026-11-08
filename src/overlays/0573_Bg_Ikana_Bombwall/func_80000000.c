// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_bombwall.h"

void ref_func_80BD4720(BgIkanaBombwall* this, PlayState* play) {
    s32 i;
    Vec3f pos;
    Vec3f velocity;
    Vec3f posOffset;
    Vec3f velocityOffset;
    f32 offsetPosX;
    f32 offsetPosY;
    s16 scale;
    s16 phi_s0;
    s16 phi_t0;
    s16 gravity;

    Matrix_Push();
    Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_NEW);
    offsetPosX = 0.0f;
    offsetPosY = 0.0f;

    for (i = 0; i < 30; i++) {
        offsetPosX += 60.0f + (Rand_ZeroOne() * 20.0f);
        if (offsetPosX > 75.0f) {
            offsetPosX -= 150.0f;
        }

        offsetPosY += 5;

        posOffset.x = offsetPosX;
        posOffset.y = offsetPosY;
        posOffset.z = (Rand_ZeroOne() * 20.0f) - 10.0f;

        velocityOffset.x = ((Rand_ZeroOne() - 0.5f) * 5.0f) + (offsetPosX * (4.0f / 75.0f));
        velocityOffset.y = (Rand_ZeroOne() * 7.0f) - 2.0f;
        velocityOffset.z = (Rand_ZeroOne() * 4.0f) - 2.0f;

        Matrix_MultVec3f(&posOffset, &pos);
        Matrix_MultVec3f(&velocityOffset, &velocity);

        pos.x += this->dyna.actor.world.pos.x;
        pos.y += this->dyna.actor.world.pos.y;
        pos.z += this->dyna.actor.world.pos.z;

        
        if (1) {}

        if ((i & 3) == 0) {
            phi_s0 = 32;
            ref_func_800BBFB0(play, &pos, 50.0f, 2, 100, 120, 1);
        } else {
            phi_s0 = 64;
        }

        if (i & 1) {
            phi_s0 |= 1;
            phi_t0 = 1;
        } else {
            phi_t0 = 0;
        }

        scale = ref_D_80BD52C8[i & (ARRAY_COUNT(ref_D_80BD52C8) - 1)];

        
    fake_label:;

        if (scale >= 16) {
            gravity = -550;
        } else {
            gravity = -450;
        }

        EffectSsKakera_Spawn(play, &pos, &velocity, &pos, gravity, phi_s0, 30, 0, 0, scale, phi_t0, 0, 50, -1,
                             OBJECT_IKANA_OBJ, object_ikana_obj_DL_000288);
    }

    Matrix_Pop();
}
