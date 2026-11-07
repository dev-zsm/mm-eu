// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mure2.h"

void ObjMure2_Init(Actor* thisx, PlayState* play) {
    ObjMure2* this = (ObjMure2*)thisx;

    Actor_ProcessInitChain(&this->actor, sInitChain);
    if (play->csCtx.state != CS_STATE_IDLE) {
        this->actor.cullingVolumeDistance += 1200.0f;
    }
    ref_func_809613B0(this);
}
