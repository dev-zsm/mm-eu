// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

void EnFall_FireRing_Update(Actor* thisx, PlayState* play) {
    EnFall* this = (EnFall*)thisx;

    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_450) &&
        play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_450)]->id == 5) {
        if (!(this->flags & FLAG_FIRE_RING_APPEARS)) {
            Actor_PlaySfx(&this->actor, NA_SE_IT_DM_RING_EXPLOSION);
        }
        this->flags |= FLAG_FIRE_RING_APPEARS;
    }
    if (this->flags & FLAG_FIRE_RING_APPEARS) {
        this->fireRingAlpha += 1 / 30.0f;
        if (this->fireRingAlpha > 1.0f) {
            this->fireRingAlpha = 1.0f;
        }
        if (this->actor.scale.x < 18.0f) {
            this->actor.scale.x += 0.2f;
        }
        this->actor.scale.z = this->actor.scale.x;
        this->actor.scale.y = Math_SinS(this->fireWallYScale) * 5.0f;
        if (this->fireWallYScale < 0x4000) {
            this->fireWallYScale += 0x147;
        }
    }
}
