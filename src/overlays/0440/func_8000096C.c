// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_UpdateFeathers(PlayState* play, OwlWarpFeather* feathers, EnTest7* this, s32 arg3, s32 arg4) {
    s32 pad;
    s32 i;
    f32 temp_f28;
    f32 temp_f0;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f26;
    f32 temp_f2;
    Vec3f sp8C;
    OwlWarpFeather* feather;
    s16 phi_s1;

    for (i = 0; i < OWL_WARP_NUM_FEATHERS; i++) {
        feather = &feathers[i];

        if (feather->type == OWL_WARP_FEATHER_TYPE_DISABLED) {
            continue;
        }

        if (feather->type == OWL_WARP_FEATHER_TYPE_1) {
            EnTest7_UpdateFeatherType1(play, feather);
        } else {
            EnTest7_UpdateFeatherType2(play, feather);
        }

        if (arg3) {
            temp_f22 = feather->pos.x - this->actor.world.pos.x;
            temp_f24 = feather->pos.z - this->actor.world.pos.z;
            temp_f0 = SQ(temp_f22) + SQ(temp_f24);

            phi_s1 = -0x2710;
            if (temp_f0 > SQ(20.0f)) {
                phi_s1 /= ((temp_f0 - SQ(20.0f)) * 0.00125f) + 1.0f;
            }

            temp_f26 = (temp_f22 * Math_CosS(phi_s1)) - (temp_f24 * Math_SinS(phi_s1));
            temp_f28 = (temp_f22 * Math_SinS(phi_s1)) + (temp_f24 * Math_CosS(phi_s1));

            feather->pos.x = this->actor.world.pos.x + temp_f26;
            feather->pos.z = this->actor.world.pos.z + temp_f28;

            temp_f22 = feather->velocity.x;
            temp_f24 = feather->velocity.z;

            feather->velocity.x = (temp_f22 * Math_CosS(phi_s1)) - (temp_f24 * Math_SinS(phi_s1));
            feather->velocity.z = (temp_f22 * Math_SinS(phi_s1)) + (temp_f24 * Math_CosS(phi_s1));

            temp_f22 = feather->accel.x;
            temp_f24 = feather->accel.z;

            feather->accel.x = (temp_f22 * Math_CosS(phi_s1)) - (temp_f24 * Math_SinS(phi_s1));
            feather->accel.z = (temp_f22 * Math_SinS(phi_s1)) + (temp_f24 * Math_CosS(phi_s1));
        }

        if (arg4) {
            sp8C.x = feather->pos.x - this->actor.world.pos.x;
            sp8C.y = feather->pos.y - (this->actor.world.pos.y + 40.0f);
            sp8C.z = feather->pos.z - this->actor.world.pos.z;

            temp_f2 = 1.0f - (0.5f / ((Math3D_Vec3fMagnitude(&sp8C) / 500.0f) + 1.0f));

            sp8C.x *= temp_f2;
            sp8C.y *= temp_f2;
            sp8C.z *= temp_f2;

            feather->pos.x = this->actor.world.pos.x + sp8C.x;
            feather->pos.y = this->actor.world.pos.y + sp8C.y + 40.0f;
            feather->pos.z = this->actor.world.pos.z + sp8C.z;
        }
    }
}
