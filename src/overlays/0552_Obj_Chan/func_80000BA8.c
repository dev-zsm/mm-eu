// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_chan.h"

void ObjChan_CreateSmashEffects(ObjChan* this, PlayState* play) {
    s16 new_var = 0;
    s32 phi_s0;
    Vec3f spDC;
    Vec3f spD0;
    f32 temp_f0;
    f32 new_var2;
    s16 temp_s1 = 0;
    s32 temp_s2;
    f32 spAC;
    f32 spA8 = new_var + 15.0f;
    f32 spA4 = new_var + (spAC = 110.0f);

    for (temp_s2 = 0, temp_s1 = 0; temp_s2 != 18; temp_s2++, temp_s1 += 0x4E20) {
        f32 sin = Math_SinS(temp_s1);
        f32 cos = Math_CosS(temp_s1);

        spDC.x = sin * 8.0f;
        spDC.y = Rand_ZeroOne() * 12.0f + 2.0f;
        spDC.z = cos * 8.0f;
        spD0.x = spDC.x * 0.23f;
        spD0.y = Rand_ZeroOne() * 5.0f + 2.5f;
        spD0.z = spDC.z * 0.23f;
        temp_f0 = Rand_ZeroOne();
        if (temp_f0 < 0.2f) {
            phi_s0 = 0x60;
        } else if (temp_f0 < 0.6f) {
            phi_s0 = 0x40;
        } else {
            phi_s0 = 0x20;
        }
        new_var2 = spA4 * Rand_ZeroOne();
        EffectSsKakera_Spawn(play, &spDC, &spD0, &this->actor.world.pos, -260, phi_s0, 20, 0, 0, spA8 + new_var2, 0, 0,
                             50, -1, OBJECT_TSUBO, gPotShardDL);
    }
    ref_func_800BBFB0(play, &this->actor.world.pos, 30.0f, 2, 20, 50, true);
    ref_func_800BBFB0(play, &this->actor.world.pos, 30.0f, 2, 10, 80, true);
}
