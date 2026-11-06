// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lightblock.h"

void ObjLightblock_PlayCutscene(ObjLightblock* this, PlayState* play) {
    if (CutsceneManager_IsNext(this->dyna.actor.csId)) {
        CutsceneManager_StartWithPlayerCs(this->dyna.actor.csId, &this->dyna.actor);
        Flags_SetSwitch(play, LIGHTBLOCK_GET_DESTROYED_SWITCH_FLAG(&this->dyna.actor));
        ObjLightblock_SpawnEffect(this, play);
        ObjLightblock_SetupFadeAway(this);
    } else {
        CutsceneManager_Queue(this->dyna.actor.csId);
    }
}
