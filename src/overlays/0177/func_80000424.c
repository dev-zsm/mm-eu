// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lightswitch.h"

void ObjLightswitch_PlayCinema(ObjLightswitch* this, PlayState* play) {
    if (CutsceneManager_IsNext(this->actor.csId)) {
        CutsceneManager_StartWithPlayerCs(this->actor.csId, &this->actor);
        ObjLightswitch_UpdateSwitchFlags(this, play, this->switchFlagSetType);
        this->cutsceneTimer = 50;
        this->setupFunc(this);
    } else {
        CutsceneManager_Queue(this->actor.csId);
    }
}
