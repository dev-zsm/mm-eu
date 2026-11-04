// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hgdoor.h"

void ObjHgdoor_StopCs(ObjHgdoor* this, PlayState* play) {
    if (this->timer++ > 80) {
        if (!CutsceneManager_IsNext(this->csId)) {
            CutsceneManager_Stop(this->csId);
        }
    }
}
