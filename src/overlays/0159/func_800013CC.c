// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void ref_func_8093FC6C(EnGoroiwa* this, PlayState* play) {
    s32 i;
    Vec3f spC0;
    Vec3f spB4;
    Vec3f spA8;
    s16 temp_s3;
    s16 phi_s0;
    s16 temp;
    s32 pad;
    s32 sp80;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f28;

    temp_f24 = (this->actor.scale.x + 0.1f) * 0.5f;
    sp80 = temp_f24 * 150.0f;
    temp_f28 = this->actor.scale.x * 600.0f;
    temp = 0x10000 / sp80;

    for (i = 0, phi_s0 = 0; i < sp80; i++, phi_s0 += temp) {
        temp_s3 = Rand_Next() >> 0x10;
        temp_f20 = Math_SinS(temp_s3);
        temp_f22 = Math_CosS(temp_s3);

        spC0.x = Math_SinS(phi_s0);
        spC0.z = Math_CosS(phi_s0);

        spB4.x = 2.0f * spC0.x;
        spB4.y = (2.0f * Rand_ZeroOne()) + 1.0f;
        spB4.z = 2.0f * spC0.z;

        spC0.x *= temp_f22 * temp_f28;
        spC0.y = temp_f20 * temp_f28;
        spC0.z *= (temp_f22 * temp_f28);

        spC0.x += this->actor.world.pos.x;
        spC0.y += this->actor.world.pos.y;
        spC0.z += this->actor.world.pos.z;

        spA8.x = spB4.x * -0.02f;
        spA8.y = spB4.y * -0.05f;
        spA8.z = spB4.z * -0.02f;

        EffectSsIceSmoke_Spawn(play, &spC0, &spB4, &spA8, ((s32)(Rand_ZeroOne() * 170.0f) + 150) * temp_f24 * 10.0f);
    }

    for (i = 0, phi_s0 = 0; i < sp80; i++, phi_s0 += temp) {
        temp_f20 = (Rand_ZeroOne() * (450.0f * this->actor.scale.x)) + 50.0f;

        spC0.x = Math_SinS(phi_s0);
        spC0.z = Math_CosS(phi_s0);

        spB4.x = spC0.x * 30.0f * temp_f24;
        spB4.y = 0.0f;
        spB4.z = spC0.z * 30.0f * temp_f24;

        spA8.x = spB4.x * -0.02f;
        spA8.y = 0.03f;
        spA8.z = spB4.z * -0.02f;

        spC0.x = (spC0.x * temp_f20) + this->actor.world.pos.x;
        spC0.y = (Rand_ZeroOne() * 20.0f) + this->actor.world.pos.y;
        spC0.z = (spC0.z * temp_f20) + this->actor.world.pos.z;

        EffectSsIceSmoke_Spawn(play, &spC0, &spB4, &spA8, (s32)(Rand_ZeroOne() * 1400.0f * temp_f24) + 100);
    }
}
