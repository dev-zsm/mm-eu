// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hugebombiwa.h"

void ref_func_80A541F4(ObjHugebombiwa* this, PlayState* play) {
    static s16 ref_D_80A55D50[] = { 24, 17, 13, 7, 6, 5, 3, 2 };
    s32 i;
    s32 pad[2];
    s32 phi_s2;
    Vec3f spF4;
    Vec3f spE8;
    Vec3f spDC;
    Vec3f spD0;
    Vec3f spC4;
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    s32 phi_s0;
    f32 phi_f30;

    for (i = 0, phi_s2 = 0, phi_f30 = 0.0f; i < 13; i++, phi_s2 += 0x4E20, phi_f30 += (230.0f / 13)) {
        temp_f0 = Rand_ZeroOne();
        temp_f22 = (1.0f - SQ(temp_f0)) * 120.0f;
        temp_f20 = Math_SinS(phi_s2 & 0xFFFF);
        temp_f24 = Math_CosS(phi_s2 & 0xFFFF);

        spF4.x = (temp_f20 * temp_f22) + this->actor.world.pos.x;
        spF4.y = this->actor.world.pos.y + phi_f30;
        spF4.z = (temp_f24 * temp_f22) + this->actor.world.pos.z;

        spE8.x = temp_f20 * 10.0f;
        spE8.y = (Rand_ZeroOne() * 18.0f) + 10.0f;
        spE8.z = temp_f24 * 10.0f;

        EffectSsKakera_Spawn(play, &spF4, &spE8, &spF4, -650, 37, 15, 0, 0, ref_D_80A55D50[i & 7], 1, 0, 60, -1,
                             OBJECT_BOMBIWA, object_bombiwa_DL_0009E0);

        spDC.x = ((Rand_ZeroOne() - 0.5f) * 230.0f) + spF4.x;
        spDC.y = ((Rand_ZeroOne() - 0.2f) * 200.0f) + spF4.y;
        spDC.z = ((Rand_ZeroOne() - 0.5f) * 230.0f) + spF4.z;

        spD0.x = temp_f20 * 7.0f;
        spD0.y = -7.0f;
        spD0.z = temp_f24 * 7.0f;

        spC4.x = temp_f20 * -0.07f;
        spC4.y = 0.24f;
        spC4.z = temp_f24 * -0.07f;

        ref_func_800B12F0(play, &spDC, &spD0, &spC4, (s32)(Rand_ZeroOne() * 800.0f) + 1000, -49, 20);

        spDC.x = ((Rand_ZeroOne() - 0.5f) * 160.0f) + spF4.x;
        spDC.y = ((Rand_ZeroOne() - 0.2f) * 140.0f) + spF4.y;
        spDC.z = ((Rand_ZeroOne() - 0.5f) * 160.0f) + spF4.z;

        spD0.x = temp_f20 * 15.0f;
        spD0.y = 0.0f;
        spD0.z = temp_f24 * 15.0f;

        spC4.x = temp_f20 * -0.09f;
        spC4.y = 0.3f;
        spC4.z = temp_f24 * -0.09f;

        ref_func_800B12F0(play, &spDC, &spD0, &spC4, (s32)(Rand_ZeroOne() * 100.0f) + 40,
                      (s32)(Rand_ZeroOne() * 200.0f) + 20, 10);
    }
}
