// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bigicicle.h"

void ref_func_80AE939C(ObjBigicicle* this, PlayState* play) {
    s32 i;
    Vec3f sp98;
    Vec3f sp8C;
    f32 temp_f20 = this->actor.scale.x * (50.0f / 3.0f);

    for (i = 0; i < 20; i++) {
        sp8C.x = Rand_CenteredFloat(15.0f);
        sp8C.y = Rand_ZeroFloat(7.0f) + 3.0f;
        sp8C.z = Rand_CenteredFloat(15.0f);

        sp98.x = this->actor.world.pos.x + (sp8C.x * 5.0f * temp_f20);
        sp98.y = this->actor.world.pos.y + (sp8C.y * 7.0f * temp_f20);
        sp98.z = this->actor.world.pos.z + (sp8C.z * 5.0f * temp_f20);

        EffectSsHahen_Spawn(play, &sp98, &sp8C, &ref_D_80AE987C, HAHEN_XLU, (Rand_ZeroFloat(30.0f) + 40.0f) * temp_f20,
                            OBJECT_BIGICICLE, 30, object_bigicicle_DL_0009B0);
    }

    SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 40, NA_SE_EV_GLASSBROKEN_IMPACT);
    CutsceneManager_Stop(this->actor.csId);
    Actor_Kill(&this->actor);
}
