// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_demo.h"

void ref_func_80983678(ObjDemo* this, PlayState* play) {
    ref_func_80983634(play);
    if ((this->actor.xzDistToPlayer < this->xzRange) && (fabsf(this->actor.playerHeightRel) < this->yRange)) {
        if (this->unk_148 == 1) {
            CutsceneManager_Stop(CS_ID_GLOBAL_DOOR);
        }
        CutsceneManager_Queue(this->actor.csId);
        this->actionFunc = ref_func_80983704;
    }
}
