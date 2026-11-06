// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_slime.h"

void EnSlime_Update(Actor* thisx, PlayState* play) {
    EnSlime* this = (EnSlime*)thisx;
    s32 pad;
    Player* player = GET_PLAYER(play);

    EnSlime_UpdateDamage(this, play);
    this->actionFunc(this, play);

    
    thisx->shape.shadowAlpha = this->iceBlockTimer;
    if (this->iceBlockTimer == ICE_BLOCK_UNUSED) {
        if (thisx->scale.y > 0.0001f) {
            thisx->lockOnArrowOffset = 60.0f / thisx->scale.y;
        }

        if (this->collider.base.ocFlags1 & OC1_ON) {
            Actor_MoveWithGravity(thisx);
            Actor_UpdateBgCheckInfo(play, thisx, 20.0f, 35.0f, 40.0f,
                                    UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_4 | UPDBGCHECKINFO_FLAG_8 |
                                        UPDBGCHECKINFO_FLAG_10);
        }

        Collider_UpdateCylinder(thisx, &this->collider);
        this->collider.dim.radius = sCylinderInit.dim.radius * (100.0f * thisx->scale.z);
        this->collider.dim.height = sCylinderInit.dim.height * (100.0f * thisx->scale.y);

        if (this->actionFunc == EnSlime_Jump) {
            CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.base);
        }

        if (this->collider.base.acFlags & AC_ON) {
            CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
        }

        if (player->stateFlags3 & PLAYER_STATE3_100) {
            this->collider.base.ocFlags1 &= ~OC1_TYPE_PLAYER;
        } else {
            this->collider.base.ocFlags1 |= OC1_TYPE_PLAYER;
        }

        if (this->collider.base.ocFlags1 & OC1_ON) {
            CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
        }

        Actor_SetFocus(thisx, 15.0f);
        if (this->drawDmgEffAlpha > 0.0f) {
            if (this->drawDmgEffType != ACTOR_DRAW_DMGEFF_FROZEN_NO_SFX) {
                Math_StepToF(&this->drawDmgEffAlpha, 0.0f, 0.05f);
                this->drawDmgEffScale = (this->drawDmgEffAlpha + 1.0f) * 0.2f;
                this->drawDmgEffScale = CLAMP_MAX(this->drawDmgEffScale, 0.4f);
            } else if (!Math_StepToF(&this->drawDmgEffFrozenSteamScale, 0.4f, 0.01f)) {
                Actor_PlaySfx_Flagged(thisx, NA_SE_EV_ICE_FREEZE - SFX_FLAG);
            }
        }
    }
}
