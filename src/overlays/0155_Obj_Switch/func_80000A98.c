// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_switch.h"

void ObjSwitch_TryPlayCutscene(ObjSwitch* this, PlayState* play) {
    if (CutsceneManager_IsNext(this->dyna.actor.csId)) {
        CutsceneManager_StartWithPlayerCs(this->dyna.actor.csId, &this->dyna.actor);
        ObjSwitch_SetSwitchFlagState(this, play, this->nextSwitchFlagState);
        if (this->floorSwitchPlayerSnapState == 1) {
            this->floorSwitchPlayerSnapState = 2;
        }
        this->isPlayingCutscene = true;
        this->setupFunc(this);
    } else {
        CutsceneManager_Queue(this->dyna.actor.csId);
    }
}
