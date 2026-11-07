// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_flowerpot.h"

void ref_func_80A1C0FC(ObjFlowerpot* this, PlayState* play) {
    Vec3f spC4;
    Vec3f spB8;
    Vec3f spAC;
    f32 temp_f20;
    s16 phi_s0;
    s32 i;

    ref_func_80A1BA04(this, &spC4);

    for (i = 0, phi_s0 = 0; i < 10; i++, phi_s0 += 0x1999) {
        temp_f20 = (Rand_ZeroOne() * 18.0f) + 2.0f;

        spB8.x = Math_SinS((s32)(Rand_ZeroOne() * 6553.0f) + phi_s0) * temp_f20;
        spB8.y = Rand_ZeroOne() * 15.0f;
        spB8.z = Math_CosS((s32)(Rand_ZeroOne() * 6553.0f) + phi_s0) * temp_f20;

        spAC.x = spB8.x * 0.23f;
        spAC.y = (Rand_ZeroOne() * 8.0f) + 1.5f;
        spAC.z = spB8.z * 0.23f;

        Math_Vec3f_Sum(&spB8, &spC4, &spB8);
        EffectSsKakera_Spawn(play, &spB8, &spAC, &spB8, -100, 64, 40, 0, 0, (Rand_ZeroOne() * 16.0f) + 14.0f, 0, 0, 80,
                             -1, OBJECT_FLOWERPOT, object_flowerpot_DL_0014F0);
    }
}
