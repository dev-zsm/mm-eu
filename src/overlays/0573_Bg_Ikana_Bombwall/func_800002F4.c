// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_bombwall.h"

void ref_func_80BD4A14(BgIkanaBombwall* this, PlayState* play) {
    s32 i;
    Vec3f pos;
    Vec3f velocity;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs3;
    s16 scale;
    s16 angle;
    s32 gravity;
    s16 phi_v0;
    s32 phi_v1;

    temp_fs3 = 0.0f;

    for (i = 0, angle = 0; i < 28; i++, angle += 0x924) {
        temp_fs3 += 20.0f + (Rand_ZeroOne() * 10.0f);
        if (temp_fs3 > 60.0f) {
            temp_fs3 -= 60.0f;
        }

        temp_fs0 = Math_SinS(angle);
        temp_fs1 = Math_CosS(angle);

        pos.x = (temp_fs0 * temp_fs3) + this->dyna.actor.world.pos.x;
        pos.y = this->dyna.actor.world.pos.y;
        pos.z = (temp_fs1 * temp_fs3) + this->dyna.actor.world.pos.z;

        velocity.x = ((Rand_ZeroOne() - 0.5f) * 3.0f * temp_fs0) + ((temp_fs0 * temp_fs3) * (1.0f / 30.0f));
        velocity.y = (Rand_ZeroOne() * 18.0f) + 4.0f;
        velocity.z = ((Rand_ZeroOne() - 0.5f) * 3.0f * temp_fs1) + ((temp_fs1 * temp_fs3) * (1.0f / 30.0f));

        scale = (Rand_Next() % 4) + (i >> 1) + 6;

        if ((i & 3) == 0) {
            phi_v0 = 32;
        } else {
            phi_v0 = 64;
        }

        if (scale >= 15) {
            phi_v0 |= 1;
            phi_v1 = 1;
            gravity = -550;
        } else {
            phi_v1 = 0;
            gravity = -400;
        }

        EffectSsKakera_Spawn(play, &pos, &velocity, &pos, gravity, phi_v0, 30, 0, 0, scale, phi_v1, 0, 50, -1,
                             OBJECT_IKANA_OBJ, object_ikana_obj_DL_000288);

        if ((i & 3) == 0) {
            pos.y += 30.0f;
            ref_func_800BBFB0(play, &pos, 50.0f, 2, 70, 110, 1);
        }
    }
}
