// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_waterfall.h"

void ref_func_80B83EA4(BgDblueWaterfall* this, PlayState* play) {
    s32 i;
    s32 temp_s1;
    Vec3f spD4;
    Vec3f spC8;
    Vec3f spBC;
    Vec3f spB0;
    Vec3f spA4;
    Vec3f sp98;
    s32 phi_s3;

    if (this->collider.elem.acElemFlags & ACELEM_HIT) {
        f32 temp_f0_2;
        f32 temp_f20;

        spB0.x = this->collider.elem.acDmgInfo.hitPos.x;
        spB0.y = this->collider.elem.acDmgInfo.hitPos.y;
        spB0.z = this->collider.elem.acDmgInfo.hitPos.z;

        sp98.x = spB0.x - this->actor.world.pos.x;
        sp98.y = 0.0f;
        sp98.z = spB0.z - this->actor.world.pos.z;

        if (!ref_func_80B83C80(&sp98, &spA4)) {
            Math_Vec3f_Copy(&spA4, &gZeroVec3f);
        }

        sp98.y = 0.0f;
        spBC.y = -1.4f;

        for (i = 0, phi_s3 = 0; i < 15; i++, phi_s3 += 0x1111) {
            temp_s1 = (s32)(Rand_ZeroOne() * 4369.0f) + phi_s3;
            temp_f0_2 = Rand_ZeroOne();
            temp_f20 = 1.0f - SQ(temp_f0_2);

            sp98.x = Math_SinS(temp_s1) * temp_f20;
            sp98.z = Math_CosS(temp_s1) * temp_f20;
            temp_f20 *= 5.0f;

            spD4.x = (sp98.x * temp_f20) + spB0.x;
            spD4.y = ((Rand_ZeroOne() * 16.0f) - 8.0f) + spB0.y;
            spD4.z = (sp98.z * temp_f20) + spB0.z;

            spC8.x = ((2.0f * Rand_ZeroOne()) - 1.0f) + ((spA4.x * 3.0f) + (sp98.x * 5.0f));
            spC8.y = (Rand_ZeroOne() * 10.0f) + 5.0f;
            spC8.z = ((2.0f * Rand_ZeroOne()) - 1.0f) + ((spA4.z * 3.0f) + (sp98.z * 5.0f));

            spBC.x = spC8.x * -0.02f;
            spBC.z = spC8.z * -0.02f;

            EffectSsEnIce_Spawn(play, &spD4, (Rand_ZeroOne() * 0.3f) + 0.1f, &spC8, &spBC, &ref_D_80B8539C, &ref_D_80B853A0,
                                30);
        }
    }
}
