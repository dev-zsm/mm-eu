// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hamishi.h"

void ref_func_809A10F4(ObjHamishi* this, PlayState* play) {
    s32 i;
    Vec3f spC8;
    Vec3f spBC;
    f32 temp_f20;
    s16 temp_s0 = 1000;
    s32 gravity;
    s32 phi_v0;

    for (i = 0; i < ARRAY_COUNT(ref_D_809A1AD4); i++) {
        temp_s0 += 0x4E20;
        temp_f20 = Rand_ZeroOne() * 10.0f;

        spBC.x = (Math_SinS(temp_s0) * temp_f20) + this->actor.world.pos.x;
        spBC.y = (Rand_ZeroOne() * 40.0f) + this->actor.world.pos.y + 5.0f;
        spBC.z = (Math_CosS(temp_s0) * temp_f20) + this->actor.world.pos.z;

        temp_f20 = (Rand_ZeroOne() * 10.0f) + 2.0f;
        spC8.x = Math_SinS(temp_s0) * temp_f20;

        spC8.y = (Rand_ZeroOne() * 15.0f) + (Rand_ZeroOne() * i * 2.5f);
        spC8.z = Math_CosS(temp_s0) * temp_f20;

        if (i == 0) {
            phi_v0 = 41;
            gravity = -450;
        } else if (i < 4) {
            phi_v0 = 37;
            gravity = -380;
        } else {
            phi_v0 = 69;
            gravity = -320;
        }

        EffectSsKakera_Spawn(play, &spBC, &spC8, &this->actor.world.pos, gravity, phi_v0, 30, 5, 0, ref_D_809A1AD4[i], 3, 0,
                             70, 1, GAMEPLAY_FIELD_KEEP, gFieldSilverBoulderDebrisDL);
    }

    ref_func_800BBFB0(play, &this->actor.world.pos, 140.0f, 6, 180, 90, 1);
    ref_func_800BBFB0(play, &this->actor.world.pos, 140.0f, 12, 80, 90, 1);
}
