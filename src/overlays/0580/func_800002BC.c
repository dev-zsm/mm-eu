// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_iknv_obj.h"

void BgIknvObj_UpdateWaterwheel(BgIknvObj* this, PlayState* play) {
    if (CHECK_WEEKEVENTREG(WEEKEVENTREG_IKANA_SPRING_RESTORED)) {
        this->dyna.actor.shape.rot.z -= 0x64;
        Actor_PlaySeq_FlaggedMusicBoxHouse(&this->dyna.actor);
        Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_WOOD_WATER_WHEEL - SFX_FLAG);
    }

    if ((play->csCtx.state != CS_STATE_IDLE) && (gSaveContext.sceneLayer == 1) && (play->csCtx.scriptIndex == 4) &&
        (play->csCtx.curFrame == 1495)) {
        Audio_PlaySfx_2(NA_SE_EV_DOOR_UNLOCK);
    }
}
