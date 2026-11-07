// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_ice_poly.h"

void ref_func_80931E58(ObjIcePoly* this, PlayState* play) {
    if (CutsceneManager_IsNext(this->actor.csId)) {
        CutsceneManager_StartWithPlayerCs(this->actor.csId, &this->actor);
        if (this->unk_14A == 1) {
            ref_func_80931828(this, play);
            Actor_Kill(&this->actor);
            return;
        }

        this->unk_14A = 40;
        Actor_PlaySfx(&this->actor, NA_SE_EV_ICE_MELT);
        this->actionFunc = ref_func_80931EEC;
    } else {
        CutsceneManager_Queue(this->actor.csId);
    }
}
