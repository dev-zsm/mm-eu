// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_wturn.h"

void ObjWturn_AwaitInversion(ObjWturn* this, PlayState* play) {
    if (CutsceneManager_IsNext(this->actor.csId)) {
        ObjWturn_SetupInversionCs(this, play);
    } else {
        CutsceneManager_Queue(this->actor.csId);
    }
}
