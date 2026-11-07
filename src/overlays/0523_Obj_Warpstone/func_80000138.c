// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_warpstone.h"

s32 ObjWarpstone_BeginOpeningCutscene(ObjWarpstone* this, PlayState* play) {
    if ((this->dyna.actor.csId <= CS_ID_NONE) || CutsceneManager_IsNext(this->dyna.actor.csId)) {
        CutsceneManager_StartWithPlayerCs(this->dyna.actor.csId, &this->dyna.actor);
        ObjWarpstone_SetupAction(this, ObjWarpstone_PlayOpeningCutscene);
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_OWL_WARP_SWITCH_ON);
    } else {
        CutsceneManager_Queue(this->dyna.actor.csId);
    }
    return true;
}
