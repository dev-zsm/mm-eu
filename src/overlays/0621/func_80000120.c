// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikninside.h"

void ref_func_80C07230(BgIkninside* this, PlayState* play) {
    if (this->dyna.actor.csId == CS_ID_NONE) {
        this->actionFunc = ref_func_80C07220;
    } else if (CutsceneManager_GetCurrentCsId() == CS_ID_GLOBAL_TALK) {
        CutsceneManager_Stop(CS_ID_GLOBAL_TALK);
        CutsceneManager_Queue(this->dyna.actor.csId);
    } else if (CutsceneManager_IsNext(this->dyna.actor.csId)) {
        CutsceneManager_StartWithPlayerCs(this->dyna.actor.csId, &this->dyna.actor);
        this->actionFunc = ref_func_80C07220;
    } else {
        CutsceneManager_Queue(this->dyna.actor.csId);
    }
}
