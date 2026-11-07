// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_flowerpot.h"

void ref_func_80A1BD80(ObjFlowerpot* this, PlayState* play) {
    s32 i;
    Vec3f spC8;
    Vec3f spBC;
    Vec3f spB0;
    f32 temp_f20;
    s16 phi_s1;
    s32 phi_s0;

    spC8.x = this->actor.world.pos.x;
    spC8.y = this->actor.world.pos.y;
    spC8.z = this->actor.world.pos.z;

    for (i = 0, phi_s1 = 0; i < 14; i++, phi_s1 += 0x1249) {
        temp_f20 = (Rand_ZeroOne() * 8.0f) + 2.0f;

        spBC.x = Math_SinS((s32)(Rand_ZeroOne() * 4681.0f) + phi_s1) * temp_f20;
        spBC.y = Rand_ZeroOne() * 20.0f;
        spBC.z = Math_CosS((s32)(Rand_ZeroOne() * 4681.0f) + phi_s1) * temp_f20;

        spB0.x = spBC.x * 0.17f;
        spB0.y = (Rand_ZeroOne() * 5.0f) + 1.4f;
        spB0.z = spBC.z * 0.17f;

        Math_Vec3f_Sum(&spBC, &spC8, &spBC);

        if (Rand_ZeroOne() < 0.2f) {
            phi_s0 = 64;
        } else {
            phi_s0 = 32;
        }

        EffectSsKakera_Spawn(play, &spBC, &spB0, &spBC, -240, phi_s0, 40, 0, 0, (Rand_ZeroOne() * 20.0f) + 10.6f, 0, 0,
                             42, -1, OBJECT_FLOWERPOT, object_flowerpot_DL_0015B0);
    }

    spBC.y = this->actor.world.pos.y + this->actor.depthInWater;

    for (phi_s1 = 0, i = 0; i < 4; i++, phi_s1 += 0x4000) {
        spBC.x = this->actor.world.pos.x + (Math_SinS((s32)(Rand_ZeroOne() * 7200.0f) + phi_s1) * 15.0f);
        spBC.z = this->actor.world.pos.z + (Math_CosS((s32)(Rand_ZeroOne() * 7200.0f) + phi_s1) * 15.0f);
        EffectSsGSplash_Spawn(play, &spBC, NULL, NULL, 0, 200);
    }

    spBC.x = this->actor.world.pos.x;
    spBC.z = this->actor.world.pos.z;
    EffectSsGSplash_Spawn(play, &spBC, NULL, NULL, 0, 350);
    EffectSsGRipple_Spawn(play, &spBC, 150, 650, 0);
}
