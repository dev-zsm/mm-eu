// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_rr.h"

void EnRr_Update(Actor* thisx, PlayState* play) {
    EnRr* this = (EnRr*)thisx;
    EnRrStruct* ptr;
    s32 i;

    this->unk_1E4++;

    if (this->unk_1EE == 0) {
        this->unk_1E8++;
    }

    if (this->unk_1E6 != 0) {
        this->unk_1E6--;
    }

    if (this->unk_1F0 != 0) {
        this->unk_1F0--;
    }

    Actor_SetFocus(&this->actor, this->actor.scale.y * 2000.0f);
    ref_func_808FAE50(this, play);

    if (!ref_func_808FAA94(this, play)) {
        ref_func_808FAC80(this, play);
    }

    this->actionFunc(this, play);

    if (this->actor.params == LIKE_LIKE_PARAM_2) {
        
        
        this->actor.speed = 0.0f;
    } else {
        Math_StepToF(&this->actor.speed, 0.0f, 0.1f);
    }

    Actor_MoveWithGravity(&this->actor);
    Actor_UpdateBgCheckInfo(play, &this->actor, 30.0f, this->collider1.dim.radius, 0.0f,
                            UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_4 | UPDBGCHECKINFO_FLAG_8 |
                                UPDBGCHECKINFO_FLAG_10 | UPDBGCHECKINFO_FLAG_40);
    ref_func_808FB794(this, play);

    if (this->unk_1FC > 0) {
        Player* player = GET_PLAYER(play);

        if (!(player->stateFlags2 & PLAYER_STATE2_80)) {
            this->unk_1FC--;
            if (this->unk_1FC == 0) {
                this->collider1.base.ocFlags1 |= OC1_TYPE_PLAYER;
            }
        }
    }

    Collider_UpdateCylinder(&this->actor, &this->collider1);

    if ((this->actionFunc != ref_func_808FB42C) && (this->actionFunc != ref_func_808FB398)) {
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider1.base);
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider2.base);
        if ((this->unk_1F0 == 0) && (this->actionFunc == ref_func_808FB088) && (this->unk_1EE == 0)) {
            CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider1.base);
            CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider2.base);
        } else {
            this->collider2.base.atFlags &= ~AT_HIT;
            this->collider1.base.atFlags &= ~AT_HIT;
        }
    } else {
        this->collider2.base.atFlags &= ~AT_HIT;
        this->collider1.base.atFlags &= ~AT_HIT;
        this->collider2.base.acFlags &= ~AC_HIT;
        this->collider1.base.acFlags &= ~AC_HIT;
    }

    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider1.base);

    if (this->unk_1EE == 0) {
        Math_ScaledStepToS(&this->unk_1F4, this->unk_1F6, 50);
        Math_ScaledStepToS(&this->unk_1F8, 0x3000, 0xA4);
        Math_ScaledStepToS(&this->unk_1FA, 0x1000, 0x29);
        Math_StepToF(&this->unk_200, this->unk_204, 0.0015f);
        Math_StepToF(&this->unk_208, this->unk_20C, 20.0f);

        for (i = 0; i < ARRAY_COUNT(this->unk_324); i++) {
            ptr = &this->unk_324[i];
            Math_SmoothStepToS(&ptr->unk_1A.x, ptr->unk_14, 5, this->unk_210 * 0x3E8, 0);
            Math_SmoothStepToS(&ptr->unk_1A.z, ptr->unk_18, 5, this->unk_210 * 0x3E8, 0);
            Math_StepToF(&ptr->unk_08, ptr->unk_0C, this->unk_210 * 0.2f);
            Math_StepToF(&ptr->unk_00, ptr->unk_04, this->unk_210 * 300.0f);
        }

        Math_StepToF(&this->unk_210, 1.0f, 0.2f);
    }

    if (this->drawDmgEffAlpha > 0.0f) {
        if (this->drawDmgEffType != ACTOR_DRAW_DMGEFF_FROZEN_NO_SFX) {
            Math_StepToF(&this->drawDmgEffAlpha, 0.0f, 0.05f);
            this->drawDmgEffScale = (this->drawDmgEffAlpha + 1.0f) * 0.425f;
            this->drawDmgEffScale = CLAMP_MAX(this->drawDmgEffScale, 0.85f);
        } else if (!Math_StepToF(&this->drawDmgEffFrozenSteamScale, 0.85f, 0.02125f)) {
            Actor_PlaySfx_Flagged(&this->actor, NA_SE_EV_ICE_FREEZE - SFX_FLAG);
        }
    }
}
