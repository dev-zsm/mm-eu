// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mm.h"

void ref_func_8096611C(EnMm* this, PlayState* play) {
    if (Actor_HasNoParent(&this->actor, play)) {
        EnMm_SetupAction(this, ref_func_80965DB4);
        this->actor.room = play->roomCtx.curRoom.num;
        this->actor.bgCheckFlags &= ~BGCHECKFLAG_GROUND;
        Math_Vec3s_ToVec3f(&this->actor.prevPos, &this->actor.home.rot);
        gSaveContext.unk_1014 = 0;
    } else {
        Math_Vec3f_ToVec3s(&this->actor.home.rot, &this->actor.parent->world.pos);
    }
    Math_ScaledStepToS(&this->unk_190, 0, 0x7D0);
}
