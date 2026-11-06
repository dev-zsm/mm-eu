// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bat.h"

void EnBat_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    EnBat* this = (EnBat*)thisx;

    if (this->actor.room == -1) {
        sAlreadySpawned = true;
    }

    EnBat_UpdateDamage(this, play);
    this->actionFunc(this, play);

    if (this->actionFunc != EnBat_Stunned) {
        Math_StepToF(&this->actor.shape.yOffset, 2000.0f, 200.0f);
    }

    if (this->actionFunc != EnBat_Perch) {
        Vec3f prevPos;

        this->actor.world.rot.y = this->actor.shape.rot.y;
        this->actor.world.rot.x = -this->actor.shape.rot.x;
        Math_Vec3f_Copy(&prevPos, &this->actor.prevPos);

        if ((this->actor.colChkInfo.health != 0) && (this->actionFunc != EnBat_Stunned)) {
            Actor_MoveWithoutGravity(&this->actor);
        } else {
            Actor_MoveWithGravity(&this->actor);
        }

        if (this->actionFunc == EnBat_DiveAttack) {
            Actor_UpdateBgCheckInfo(play, &this->actor, 12.0f, 15.0f, 50.0f,
                                    UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_4);
        } else if ((this->actionFunc != EnBat_FlyIdle) ||
                   ((this->actor.xzDistToPlayer < 400.0f) && (this->actor.projectedPos.z > 0.0f))) {
            if (this->paramFlags & BAD_BAT_PARAMFLAG_0) {
                Actor_UpdateBgCheckInfo(play, &this->actor, 12.0f, 15.0f, 50.0f,
                                        UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_4);
            } else {
                Actor_UpdateBgCheckInfo(play, &this->actor, 12.0f, 15.0f, 50.0f, UPDBGCHECKINFO_FLAG_4);
            }
        } else {
            Math_Vec3f_Copy(&this->actor.prevPos, &prevPos);
        }

        Actor_SetFocus(&this->actor, this->actor.shape.yOffset * 0.01f);
        this->collider.dim.worldSphere.center.x = this->actor.focus.pos.x;
        this->collider.dim.worldSphere.center.y = this->actor.focus.pos.y;
        this->collider.dim.worldSphere.center.z = this->actor.focus.pos.z;
    }

    if (this->collider.base.atFlags & AT_ON) {
        CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.base);
    }
    if (this->actionFunc == EnBat_DiveAttack) {
        CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
    }
    if (this->collider.base.acFlags & AC_ON) {
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
    }

    if (this->drawDmgEffAlpha > 0.0f) {
        if (this->drawDmgEffType != ACTOR_DRAW_DMGEFF_FROZEN_NO_SFX) {
            Math_StepToF(&this->drawDmgEffAlpha, 0.0f, 0.05f);
            this->drawDmgEffScale = (this->drawDmgEffAlpha + 1.0f) * 0.225f;
            this->drawDmgEffScale = CLAMP_MAX(this->drawDmgEffScale, 0.45f);
        } else if (!Math_StepToF(&this->drawDmgEffFrozenSteamScale, 0.45f, 0.45f / 40.0f)) {
            Actor_PlaySfx_Flagged(&this->actor, NA_SE_EV_ICE_FREEZE - SFX_FLAG);
        }
    }
}
