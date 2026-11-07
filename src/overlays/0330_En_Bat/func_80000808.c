// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bat.h"

void EnBat_DiveAttack(EnBat* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    s32 isFacingPlayer;
    Vec3f preyPos;

    EnBat_StepAnimation(this, 2);
    isFacingPlayer = Actor_IsFacingPlayer(&this->actor, 0x2800);

    if (isFacingPlayer) {
        s16 pitchTarget;

        preyPos.x = player->actor.world.pos.x;
        preyPos.y = player->actor.world.pos.y + 20.0f;
        preyPos.z = player->actor.world.pos.z;

        pitchTarget = Actor_WorldPitchTowardPoint(&this->actor, &preyPos);
        pitchTarget = CLAMP(pitchTarget, -0x3000, 0x3000);
        Math_SmoothStepToS(&this->actor.shape.rot.x, pitchTarget, 2, 0x400, 0x40);
    } else {
        Math_SmoothStepToS(&this->actor.shape.rot.x, -0x800, 2, 0x100, 0x10);
    }
    if (isFacingPlayer || (this->actor.xzDistToPlayer > 80.0f)) {
        Math_SmoothStepToS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 4, 0xC00, 0xC0);
    }

    this->timer--;

    if ((this->timer == 0) || (this->collider.base.atFlags & AT_HIT) || (Player_GetMask(play) == PLAYER_MASK_STONE) ||
        (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) || (player->stateFlags1 & PLAYER_STATE1_800000) ||
        (this->actor.depthInWater > -40.0f)) {
        if (this->collider.base.atFlags & AT_HIT) {
            this->collider.base.atFlags &= ~AT_HIT;
            Actor_PlaySfx(&this->actor, NA_SE_EN_FFLY_ATTACK);
        }
        this->collider.base.atFlags &= ~AT_ON;
        sNumberAttacking--;
        EnBat_SetupFlyIdle(this);
    } else if ((this->actor.bgCheckFlags & BGCHECKFLAG_WALL) &&
               (ABS_ALT(BINANG_SUB(this->actor.wallYaw, this->actor.yawTowardsPlayer)) > 0x6800)) {
        sNumberAttacking--;
        this->collider.base.atFlags &= ~AT_ON;
        this->actor.bgCheckFlags &= ~BGCHECKFLAG_WALL;
        this->yawTarget = this->actor.wallYaw;
        EnBat_SetupFlyIdle(this);
    }
}
