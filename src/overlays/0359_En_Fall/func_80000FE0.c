// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

void EnFall_MoonsTear_Fall(EnFall* this, PlayState* play) {
    s32 pad;

    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_517) &&
        (play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_517)]->id == 2) &&
        (this->actor.draw == NULL)) {
        EnFall_MoonsTear_Initialize(this);
    }

    if (this->actor.draw != NULL) {
        if (Math_Vec3f_StepTo(&this->actor.world.pos, &this->actor.home.pos, this->actor.speed) <= 0.0f) {
            Actor_PlaySfx(&this->actor, NA_SE_EV_GORON_BOUND_1);
            SET_WEEKEVENTREG(WEEKEVENTREG_74_80);
            SET_WEEKEVENTREG(WEEKEVENTREG_74_20);
            Actor_SpawnAsChild(&play->actorCtx, &this->actor, play, ACTOR_EN_TEST, this->actor.world.pos.x,
                               this->actor.world.pos.y, this->actor.world.pos.z, 0, 0, 0, -2);
            Actor_Spawn(&play->actorCtx, play, ACTOR_EN_CLEAR_TAG, this->actor.world.pos.x, this->actor.world.pos.y,
                        this->actor.world.pos.z, 0, 0, 0, CLEAR_TAG_PARAMS(CLEAR_TAG_LARGE_EXPLOSION));
            this->actor.draw = NULL;
            this->actionFunc = EnFall_MoonsTear_DoNothing;
        } else {
            Actor_PlaySfx_Flagged(&this->actor, NA_SE_EV_MOONSTONE_FALL - SFX_FLAG);
        }
    }
}
