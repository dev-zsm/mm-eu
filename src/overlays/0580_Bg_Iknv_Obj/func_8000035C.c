// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_iknv_obj.h"

s32 ref_func_80BD7E0C(BgIknvObj* this, s16 targetRotation, PlayState* play) {
    this->dyna.actor.shape.yOffset = 0.0f;
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
    if (targetRotation != this->dyna.actor.shape.rot.y) {
        Math_SmoothStepToS(&this->dyna.actor.shape.rot.y, targetRotation, 2, 0x64, 0x64);
        this->dyna.actor.world.rot.y = this->dyna.actor.shape.rot.y;
        if ((play->gameplayFrames % 2) != 0) {
            this->dyna.actor.shape.yOffset = 5.0f;
        }
        Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_STONEDOOR_OPEN_S - SFX_FLAG);
        return false;
    }
    Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_STONEDOOR_STOP);
    return true;
}
