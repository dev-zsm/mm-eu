// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_comb.h"

void ref_func_8098D47C(ObjComb* this, PlayState* play) {
    Vec3f spD4;
    Vec3f spC8;
    Vec3f spBC;
    f32 temp_f20;
    s16 temp_s1 = 0;
    s16 temp_f10;
    s32 phi_s0;
    s32 phi_v0;
    s32 i;

    for (i = 0; i < 21; i++) {
        temp_s1 += 0x4E20;
        temp_f20 = Rand_ZeroOne() * 10.0f;

        spD4.x = Math_SinS(temp_s1) * temp_f20;
        spD4.y = i * 0.25f;
        spD4.z = Math_CosS(temp_s1) * temp_f20;

        Math_Vec3f_Sum(&spD4, &this->actor.world.pos, &spC8);

        spBC.x = (Rand_ZeroOne() - 0.5f) + (spD4.x * 0.5f);
        spBC.y = Rand_ZeroOne() + (spD4.y * 0.6f) + 6.0f;
        spBC.z = (Rand_ZeroOne() - 0.5f) + (spD4.z * 0.5f);

        temp_f10 = (Rand_ZeroOne() * 72.0f) + 25.0f;
        if (temp_f10 < 40) {
            phi_s0 = -100;
        } else if (temp_f10 < 70) {
            phi_s0 = -180;
        } else {
            phi_s0 = -240;
        }

        if (Rand_ZeroOne() < 0.2f) {
            phi_v0 = 0x40;
        } else {
            phi_v0 = 0x20;
        }

        EffectSsKakera_Spawn(play, &spC8, &spBC, &spC8, phi_s0, phi_v0, 40, 0, 0, temp_f10, 0, 0, 80, -1, OBJECT_COMB,
                             gBeehiveFragmentDL);
    }
}
