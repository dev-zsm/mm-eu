// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_horse_link_child.h"

void func_80001060(EnHorseLinkChild* this, PlayState* play) {
    s16 yawTowardsPlayer;

    if (gHorsePlayedEponasSong) {
        gHorsePlayedEponasSong = false;
        Audio_PlaySfx_AtPos(&this->actor.projectedPos, NA_SE_EV_KID_HORSE_NEIGH);
        EnHorseLinkChild_SetupActionFunc4(this);
        return;
    }

    this->actor.speed = 0.0f;
    yawTowardsPlayer = Actor_WorldYawTowardActor(&this->actor, &GET_PLAYER(play)->actor) - this->actor.world.rot.y;

    if ((Math_CosS(yawTowardsPlayer) < 0.7071f) && (this->animIndex == OOT_CHILD_EPONA_ANIM_WALK)) {
        Horse_RotateToPoint(&this->actor, &GET_PLAYER(play)->actor.world.pos, 0x12C);
    }

    if (SkelAnime_Update(&this->skin.skelAnime)) {
        if (Math_CosS(yawTowardsPlayer) < 0.0f) {
            this->animIndex = OOT_CHILD_EPONA_ANIM_WALK;
            Animation_Change(&this->skin.skelAnime, sAnimations[this->animIndex], sAnimPlaySpeeds[this->animIndex],
                             0.0f, Animation_GetLastFrame(sAnimations[OOT_CHILD_EPONA_ANIM_WALK]), ANIMMODE_ONCE,
                             -5.0f);
        } else {
            EnHorseLinkChild_SetupActionFunc5(this);
        }
    }
}
