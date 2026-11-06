// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball.h"

void ref_func_80B03688(ObjSnowball* this, PlayState* play) {
    s32 i;
    Vec3f spB8;
    Vec3f spAC;
    Vec3f spA0;
    s32 pad[2];
    f32 temp_f20;
    f32 temp_f22 = sqrtf(this->unk_20C);
    s16 temp_s3;
    s32 phi_s0;

    if (this->unk_210 == 0) {
        for (i = 0, phi_s0 = 0; i < 10; i++, phi_s0 += 0x1999) {
            temp_f20 = (Rand_ZeroOne() * (45.0f * this->unk_20C)) + 50.0f;

            spB8.x = Math_SinS((s32)(Rand_ZeroOne() * 6553.6f) + phi_s0) * temp_f20;
            spB8.y = Rand_ZeroOne() * 20.0f;
            spB8.z = Math_CosS((s32)(Rand_ZeroOne() * 6553.6f) + phi_s0) * temp_f20;

            spAC.x = spB8.x * 0.06f;
            spAC.y = 0.0f;
            spAC.z = spB8.z * 0.06f;

            spA0.x = spAC.x * -0.08f;
            spA0.y = 0.3f;
            spA0.z = spAC.z * -0.08f;

            spB8.x += this->actor.home.pos.x;
            spB8.y += this->actor.home.pos.y;
            spB8.z += this->actor.home.pos.z;

            temp_s3 = (s32)(Rand_ZeroOne() * 60.0f * temp_f22) + 70;

            ref_func_800B0E48(play, &spB8, &spAC, &spA0, &ref_D_80B04FB4, &ref_D_80B04FB8, temp_s3,
                          (s32)(Rand_ZeroOne() * 70.0f * temp_f22) + 70);
        }
    } else {
        for (i = 0, phi_s0 = 0; i < 18; i++, phi_s0 += 0xE38) {
            temp_f20 = (Rand_ZeroOne() * (45.0f * this->unk_20C)) + 50.0f;

            spB8.x = Math_SinS((s32)(Rand_ZeroOne() * 3640.889f) + phi_s0);
            spB8.z = Math_CosS((s32)(Rand_ZeroOne() * 3640.889f) + phi_s0);

            spAC.x = spB8.x * 3.0f * temp_f22;
            spAC.y = 0.0f;
            spAC.z = spB8.z * 3.0f * temp_f22;

            spA0.x = spAC.x * -0.02f;
            spA0.y = 0.03f;
            spA0.z = spAC.z * -0.02f;

            spB8.x = (spB8.x * temp_f20) + this->actor.home.pos.x;
            spB8.y = (Rand_ZeroOne() * 20.0f) + this->actor.home.pos.y;
            spB8.z = (spB8.z * temp_f20) + this->actor.home.pos.z;

            EffectSsIceSmoke_Spawn(play, &spB8, &spAC, &spA0, (s32)(Rand_ZeroOne() * 140.0f * temp_f22) + 100);
        }
    }
}
