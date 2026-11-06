// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_nozoki.h"

s32 ref_func_80BA26A8(ObjNozoki* this) {
    if (this->csId <= CS_ID_NONE) {
        return true;
    }

    if (CutsceneManager_IsNext(this->csId)) {
        CutsceneManager_StartWithPlayerCs(this->csId, &this->dyna.actor);
        return true;
    }

    CutsceneManager_Queue(this->csId);
    return false;
}
