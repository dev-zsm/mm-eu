// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball2.h"

void ref_func_80B39108(ObjSnowball2* this, PlayState* play) {
    s32 phi_s5;
    s16 phi_s1;
    s32 phi_v0;
    s32 i;
    u32 temp;
    s32 temp_s3;
    Vec3f spDC;
    Vec3f spD0;
    f32 temp_f2;
    f32 spC8 = this->actor.world.pos.y + (this->actor.shape.yOffset * this->actor.scale.y);
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;

    for (i = 0, phi_s5 = 0; i < 11; i++, phi_s5 += (0x10000 / 11)) {
        temp_s3 = (s32)(Rand_ZeroOne() * 5957.0f) + phi_s5;

        if ((Rand_Next() >> 0x1E) == 0) {
            phi_s1 = 0x20;
        } else {
            phi_s1 = 0x40;
        }

        if ((i & 3) == 0) {
            phi_s1 |= 1;
        }

        temp_f0 = Rand_ZeroOne();
        temp_f20 = (1.0f - SQ(temp_f0)) * 12.0f;
        temp_f22 = Math_SinS(temp_s3);
        temp_f24 = Math_CosS(temp_s3);
        temp_f12 = (Rand_ZeroOne() * 1.6f) - 0.8f;
        temp_f2 = fabsf(temp_f12) * temp_f12;

        spDC.x = temp_f22 * 4.0f;
        spDC.y = (temp_f2 * 6.0f) + 9.0f;
        spDC.z = temp_f24 * 4.0f;

        spD0.x = (temp_f22 * temp_f20) + this->actor.world.pos.x;
        spD0.y = (temp_f2 * temp_f20) + spC8;
        spD0.z = (temp_f24 * temp_f20) + this->actor.world.pos.z;
        temp = Rand_Next();

        if ((i & 3) == 0) {
            phi_v0 = 1;
        } else {
            phi_v0 = 0;
        }

        EffectSsKakera_Spawn(play, &spD0, &spDC, &spD0, -300, phi_s1, 30, 0, 0, (temp >> 0x1D) + 8, phi_v0, 0, 50, -1,
                             OBJECT_GOROIWA, ref_D_80B3A91C[i & 3]);

        spD0.x += (Rand_ZeroOne() - 0.5f) * 40.0f;
        spD0.y += (Rand_ZeroOne() - 0.3f) * 45.0f;
        spD0.z += (Rand_ZeroOne() - 0.5f) * 40.0f;

        ref_func_800B0E48(play, &spD0, &gZeroVec3f, &ref_D_80B3A92C, &ref_D_80B3A914, &ref_D_80B3A918,
                      (s32)(Rand_ZeroOne() * 70.0f) + 10, (s32)(Rand_ZeroOne() * 100.0f) + 10);
    }
    spD0.y = (temp_f2 * temp_f20) + spC8;
}
