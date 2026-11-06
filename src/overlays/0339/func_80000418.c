// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mkk.h"

void ref_func_80A4E2E8(EnMkk* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    s32 sp20;

    this->unk_14E--;
    if ((this->actor.params == 1) && (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) && (this->actor.speed > 2.5f) &&
        ((play->gameplayFrames % 3) == 0)) {
        ref_func_80A4E22C(this, play);
    }
    if (this->unk_14E > 0) {
        Math_StepToF(&this->actor.speed, 5.0f, 0.7f);
        sp20 = false;
    } else {
        sp20 = Math_StepToF(&this->actor.speed, 0.0f, 0.7f);
    }
    if ((player->stateFlags3 & PLAYER_STATE3_100) || (Player_GetMask(play) == PLAYER_MASK_STONE)) {
        Math_ScaledStepToS(&this->unk_150, Actor_WorldYawTowardPoint(&this->actor, &this->actor.home.pos), 0x400);
    } else if ((player->stateFlags2 & PLAYER_STATE2_80) || (player->actor.freezeTimer > 0)) {
        Math_ScaledStepToS(&this->unk_150, this->actor.yawTowardsPlayer + 0x8000, 0x400);
    } else {
        Math_ScaledStepToS(&this->unk_150, this->actor.yawTowardsPlayer, 0x400);
    }
    this->actor.shape.rot.y =
        (s32)(Math_SinF(this->unk_14E * ((2 * M_PIf) / 15)) * (614.4f * this->actor.speed)) + this->unk_150;
    Actor_PlaySfx_Flagged(&this->actor, NA_SE_EN_KUROSUKE_MOVE - SFX_FLAG);
    if (sp20) {
        this->unk_14B &= ~2;
        ref_func_80A4E190(this);
    } else if ((this->unk_149 == 0) && !(player->stateFlags3 & PLAYER_STATE3_100) &&
               (Player_GetMask(play) != PLAYER_MASK_STONE) && (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) &&
               Actor_IsFacingPlayer(&this->actor, 0x1800) && (this->actor.xzDistToPlayer < 120.0f) &&
               (fabsf(this->actor.playerHeightRel) < 100.0f)) {
        ref_func_80A4E58C(this);
    }
}
