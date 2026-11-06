// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_encount2.h"

void EnEncount2_Popped(EnEncount2* this, PlayState* play) {
    s32 i;
    Vec3f effPos;

    Math_Vec3f_Copy(&effPos, &this->dyna.actor.world.pos);
    effPos.y += 60.0f;
    Actor_Spawn(&play->actorCtx, play, ACTOR_EN_CLEAR_TAG, effPos.x, effPos.y, effPos.z, 255, 255, 200,
                CLEAR_TAG_PARAMS(CLEAR_TAG_LARGE_EXPLOSION));

    for (i = 0; i < ARRAY_COUNT(this->effects) / 2; ++i) {
        EnEncount2_InitEffects(this, &effPos, 10);
    }

    Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_MUJURA_BALLOON_BROKEN);
    this->deathTimer = 30;
    this->actionFunc = EnEncount2_Die;
}
