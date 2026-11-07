// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hakaisi.h"

void ref_func_80B1456C(ObjHakaisi* this, PlayState* play) {
    if (this->csId != CS_ID_NONE) {
        if (CutsceneManager_IsNext(this->csId)) {
            CutsceneManager_StartWithPlayerCs(this->csId, &this->dyna.actor);
        } else {
            CutsceneManager_Queue(this->csId);
        }
    }
    if (this->dyna.actor.colChkInfo.health < 30) {
        ref_func_80B145F4(this);
        DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
    }
}
