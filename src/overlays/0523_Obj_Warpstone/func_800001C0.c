// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_warpstone.h"

s32 ObjWarpstone_PlayOpeningCutscene(ObjWarpstone* this, PlayState* play) {
    if (this->openingCSTimer++ >= OBJ_WARPSTONE_TIMER_ACTIVATE_THRESHOLD) {
        CutsceneManager_Stop(this->dyna.actor.csId);
        Sram_ActivateOwl(OBJ_WARPSTONE_GET_OWL_WARP_ID(&this->dyna.actor));
        ObjWarpstone_SetupAction(this, ObjWarpstone_OpenedIdle);
    } else if (this->openingCSTimer < OBJ_WARPSTONE_TIMER_OPEN_THRESHOLD) {
        Math_StepToF(&this->dyna.actor.velocity.x, 0.01f, 0.001f);
        Math_StepToS(&this->dyna.actor.home.rot.x, 0xFF, 0x12);
    } else {
        Math_StepToF(&this->dyna.actor.velocity.x, 20.0f, 0.01f);
        if (this->dyna.actor.velocity.x > 0.2f) {
            this->modelIndex = SEK_MODEL_OPENED;
            Math_StepToS(&this->dyna.actor.home.rot.x, 0, 0x14);
        }
    }
    return true;
}
