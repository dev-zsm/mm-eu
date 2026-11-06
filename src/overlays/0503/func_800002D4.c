// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_kin2_fence.h"

void BgKin2Fence_HandleMaskCode(BgKin2Fence* this, PlayState* play) {
    s32 hitMask;
    s32 nextMask;

    if (this->collider.base.acFlags & AC_HIT) {
        hitMask = BgKin2Fence_CheckHitMask(this);
        if (hitMask >= 0) {
            nextMask = (s8)gSaveContext.save.saveInfo.spiderHouseMaskOrder[this->masksHit];
            if (hitMask == nextMask) {
                Audio_PlaySfx(NA_SE_SY_TRE_BOX_APPEAR);
                this->masksHit += 1;
                BgKin2Fence_SpawnEyeSparkles(this, play, nextMask);
            } else {
                Audio_PlaySfx(NA_SE_SY_ERROR);
                this->masksHit = 0;
            }
        }
        this->collider.base.acFlags &= ~AC_HIT;
        this->cooldownTimer = 5;
        if (this->masksHit > 5) {
            BgKin2Fence_SetupPlayOpenCutscene(this);
            return;
        }
    } else {
        if (this->cooldownTimer > 0) {
            this->cooldownTimer -= 1;
            return;
        }
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
    }
}
