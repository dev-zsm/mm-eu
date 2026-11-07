// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_ghaka.h"

void ref_func_80B3C39C(ObjGhaka* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    s16 yaw = this->dyna.actor.yawTowardsPlayer - this->dyna.actor.shape.rot.y;

    if (Actor_TalkOfferAccepted(&this->dyna.actor, &play->state)) {
        ref_func_80B3C29C(this);
    } else if ((this->dyna.actor.xzDistToPlayer < 100.0f) || this->dyna.actor.isLockedOn) {
        if ((yaw <= -0x5556) || (yaw >= 0x5556)) {
            Actor_OfferTalkNearColChkInfoCylinder(&this->dyna.actor, play);
            if (player->transformation == PLAYER_FORM_GORON) {
                this->dyna.actor.textId = 0xCF3;
            } else {
                this->dyna.actor.textId = 0xCF2;
            }
        }
    }

    if ((this->dyna.pushForce < 0.0f) && !CHECK_WEEKEVENTREG(WEEKEVENTREG_20_20) &&
        (player->transformation == PLAYER_FORM_GORON)) {
        ref_func_80B3C2B0(this);
    } else {
        player->stateFlags2 &= ~PLAYER_STATE2_10;
        this->dyna.pushForce = 0.0f;
    }
}
