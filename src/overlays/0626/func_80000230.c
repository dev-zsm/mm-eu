// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kzsaku.h"

void ref_func_80C08CB0(ObjKzsaku* this, PlayState* play) {
    if (this->timer <= 20) {
        if (this->timer == 20) {
            if (CutsceneManager_GetCurrentCsId() == this->dyna.actor.csId) {
                CutsceneManager_Stop(this->dyna.actor.csId);
            }
            this->timer = 21;
        } else {
            this->timer++;
        }
    }
}
