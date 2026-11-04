// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_dharma.h"

void BgIkanaDharma_WaitForHit(BgIkanaDharma* this, PlayState* play) {
    s32 wasHit = (this->collider.base.acFlags & AC_HIT) != 0;
    Player* player = GET_PLAYER(play);
    BgIkanaDharma* this2 = this;
    s32 tempAngle1;
    s32 tempAngle2;

    if (wasHit) {
        this->collider.base.acFlags &= ~AC_HIT;
    }

    if (wasHit && (sFirstHitBgIkanaDharma == NULL)) {
        sFirstHitBgIkanaDharma = this2;
        Flags_SetSwitch(play, BGIKANADHARMA_GET_SWITCH_FLAG(&this->dyna.actor));
        tempAngle1 = BINANG_ADD(this->dyna.actor.yawTowardsPlayer, 0x8000);
        tempAngle2 = (BINANG_SUB(player->actor.shape.rot.y, tempAngle1) >> 1);
        this->dyna.actor.world.rot.y = tempAngle1 + tempAngle2 + 0xF000;
        this->dyna.actor.speed = 20.0f;
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_DARUMA_VANISH);
        BgIkanaDharma_SetupStartCutscene(this);
    } else if (CHECK_FLAG_ALL(this->dyna.actor.flags, ACTOR_FLAG_INSIDE_CULLING_VOLUME) &&
               (sFirstHitBgIkanaDharma == NULL) && (this->dyna.actor.xzDistToPlayer < 420.0f)) {
        tempAngle1 = BINANG_SUB(this->dyna.actor.yawTowardsPlayer, player->actor.shape.rot.y);
        tempAngle1 = ABS_ALT(tempAngle1);

        if (tempAngle1 > 0x4000) {
            Collider_UpdateCylinder(&this->dyna.actor, &this->collider);
            CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
        }
    }
}
