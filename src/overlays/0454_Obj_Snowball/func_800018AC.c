// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball.h"

void ref_func_80B0457C(ObjSnowball* this, PlayState* play) {
    if (CutsceneManager_IsNext(this->actor.csId)) {
        CutsceneManager_StartWithPlayerCs(this->actor.csId, &this->actor);
        ref_func_80B03FF8(this, play);
        this->unk_20B = 1;
        if (this->unk_20A == 0) {
            ref_func_80B04608(this, play);
        } else {
            ref_func_80B046E4(this, play);
        }
    } else {
        CutsceneManager_Queue(this->actor.csId);
    }
}
