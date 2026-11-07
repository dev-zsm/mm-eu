// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bigicicle.h"

void ref_func_80AE8DE4(ObjBigicicle* this, PlayState* play) {
    s32 i;
    Vec3f sp98;
    Vec3f sp8C;
    f32 temp_f20 = this->actor.scale.x * (50.0f / 3.0f);

    for (i = 0; i < 10; i++) {
        sp98.x = (Rand_CenteredFloat(4.0f) * temp_f20) + this->actor.world.pos.x;
        sp98.y = ((Rand_ZeroFloat(20.0f) - 35.0f) * temp_f20) + this->actor.world.pos.y;
        sp98.z = (Rand_CenteredFloat(4.0f) * temp_f20) + this->actor.world.pos.z;

        sp8C.x = Rand_CenteredFloat(13.0f);
        sp8C.y = Rand_ZeroFloat(2.0f);
        sp8C.z = Rand_CenteredFloat(13.0f);

        EffectSsHahen_Spawn(play, &sp98, &sp8C, &ref_D_80AE987C, HAHEN_XLU, (Rand_ZeroFloat(20.0f) + 30.0f) * temp_f20,
                            OBJECT_BIGICICLE, 40, object_bigicicle_DL_0009B0);
    }

    sp98.x = this->actor.world.pos.x;
    sp98.y = this->actor.world.pos.y - (25.0f * temp_f20);
    sp98.z = this->actor.world.pos.z;

    SoundSource_PlaySfxAtFixedWorldPos(play, &sp98, 40, NA_SE_EV_ICE_PIECE);
}
