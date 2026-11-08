// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_comb.h"

void ref_func_8098CEAC(ObjComb* this, PlayState* play) {
    Vec3f spDC;
    Vec3f spD0;
    Vec3f spC4;
    s32 i;
    f32 temp_f20;
    s16 temp_s2 = 0;
    s16 temp_f10;
    s32 phi_s0;
    s32 phi_v0;
    s32 phi_s1;

    for (i = 0; i < 31; i++) {
        temp_s2 += 0x4E20;
        temp_f20 = Rand_ZeroOne() * 10.0f;

        spDC.x = Math_SinS(temp_s2) * temp_f20;
        spDC.y = (i - 15) * 0.7f;
        spDC.z = Math_CosS(temp_s2) * temp_f20;

        Math_Vec3f_Sum(&spDC, &this->actor.world.pos, &spD0);

        spC4.x = (Rand_ZeroOne() - 0.5f) + (spDC.x * 0.5f);
        spC4.y = (Rand_ZeroOne() - 0.5f) + (spDC.y * 0.6f);
        spC4.z = (Rand_ZeroOne() - 0.5f) + (spDC.z * 0.5f);

        temp_f10 = (Rand_ZeroOne() * 72.0f) + 25.0f;

        if (temp_f10 < 40) {
            phi_s0 = -200;
            phi_s1 = 40;
        } else if (temp_f10 < 70) {
            phi_s0 = -280;
            phi_s1 = 30;
        } else {
            phi_s0 = -340;
            phi_s1 = 20;
        }

        temp_f20 = Rand_ZeroOne();
        if (temp_f20 < 0.1f) {
            phi_v0 = 0x60;
        } else if (temp_f20 < 0.8f) {
            phi_v0 = 0x40;
        } else {
            phi_v0 = 0x20;
        }
        EffectSsKakera_Spawn(play, &spD0, &spC4, &spD0, phi_s0, phi_v0, phi_s1, 4, 0, temp_f10, 0, 0, 60, -1,
                             OBJECT_COMB, gBeehiveFragmentDL);
    }

    spD0.x = this->actor.world.pos.x;
    spD0.y = this->actor.world.pos.y - 10.0f;
    spD0.z = this->actor.world.pos.z;

    ref_func_800BBFB0(play, &spD0, 40.0f, 6, 70, 60, 1);
}
