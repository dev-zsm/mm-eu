// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_ocarinalift.h"

void ObjOcarinalift_Update(Actor* thisx, PlayState* play) {
    ObjOcarinalift* this = (ObjOcarinalift*)thisx;

    this->actionFunc(this, play);
    Actor_SetFocus(&this->dyna.actor, 10.0f);
    if (this->cutsceneTimer > 0) {
        this->cutsceneTimer--;
        if (this->cutsceneTimer == 0) {
            CutsceneManager_Stop(this->dyna.actor.csId);
        }
    }
}
