// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_comb.h"

void ref_func_8098D6E0(ObjComb* this, PlayState* play) {
    s32 i;
    Vec3f sp70;
    f32 temp_f0;
    f32 temp_f20;
    s32 temp;

    sp70.y = this->actor.world.pos.y + this->actor.depthInWater;

    for (temp = 0, i = 0; i < 8; i++, temp += 0x2000) {
        temp_f0 = Rand_ZeroOne();
        temp_f20 = ((1.0f - SQ(temp_f0)) * 14.0f) + 4.0f;
        sp70.x = this->actor.world.pos.x + (Math_SinS((s32)(Rand_ZeroOne() * 8000.0f) + temp) * temp_f20);
        sp70.z = this->actor.world.pos.z + (Math_CosS((s32)(Rand_ZeroOne() * 8000.0f) + temp) * temp_f20);
        EffectSsGSplash_Spawn(play, &sp70, NULL, NULL, 0, 200);
    }

    sp70.x = this->actor.world.pos.x;
    sp70.z = this->actor.world.pos.z;
    EffectSsGSplash_Spawn(play, &sp70, NULL, NULL, 0, 300);
}
