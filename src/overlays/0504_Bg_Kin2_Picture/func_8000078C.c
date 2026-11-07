// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_kin2_picture.h"

void BgKin2Picture_Fall(BgKin2Picture* this, PlayState* play) {
    if (this->paintingTimer > 0) {
        this->paintingTimer--;

        if (this->paintingTimer == 0) {
            BgKin2Picture_SpawnSkulltula(this, play);
        }
    }

    Actor_MoveWithGravity(&this->dyna.actor);
    Actor_UpdateBgCheckInfo(play, &this->dyna.actor, 0.0f, 0.0f, 0.0f, UPDBGCHECKINFO_FLAG_4);

    if (this->dyna.actor.bgCheckFlags & BGCHECKFLAG_GROUND) {
        Math_StepToS(&this->step, 0x7D0, 0x78);

        if (this->landTimer < 3) {
            this->landTimer++;

            if (this->dyna.actor.velocity.y <= 0.01f) {
                this->dyna.actor.velocity.y *= -0.7f;

                if (this->dyna.actor.velocity.y > 6.0f) {
                    this->dyna.actor.velocity.y = 6.0f;
                }

                if (this->landTimer < 3) {
                    Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_SMALL_WOODPLATE_BOUND_0);
                }
            }
        }
    }

    Actor_SetFocus(&this->dyna.actor, 23.0f);

    if (!this->hasSpawnedDust && (this->dyna.actor.shape.rot.x > 0x3300)) {
        BgKin2Picture_SpawnDust(this, play);
        this->hasSpawnedDust = true;
    }

    if (Math_ScaledStepToS(&this->dyna.actor.shape.rot.x, 0x4000, this->step)) { 
        this->dyna.actor.shape.yOffset = 40.0f;

        if (this->cutsceneStarted) {
            CutsceneManager_Stop(this->dyna.actor.csId);
        }

        DynaPoly_EnableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_WOODPLATE_BROKEN);
        BgKin2Picture_SetupDoNothing(this);
    } else {
        this->dyna.actor.shape.yOffset = Math_SinS(this->dyna.actor.shape.rot.x) * 40.0f;
    }
}
