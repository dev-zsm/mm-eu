// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_kin2_fence.h"

void BgKin2Fence_PlayOpenCutscene(BgKin2Fence* this, PlayState* play) {
    if (CutsceneManager_IsNext(this->dyna.actor.csId)) {
        CutsceneManager_StartWithPlayerCs(this->dyna.actor.csId, &this->dyna.actor);
        Flags_SetSwitch(play, BG_KIN2_FENCE_GET_SWITCH_FLAG(&this->dyna.actor));
        BgKin2Fence_SetupWaitBeforeOpen(this);
        return;
    }
    CutsceneManager_Queue(this->dyna.actor.csId);
}
