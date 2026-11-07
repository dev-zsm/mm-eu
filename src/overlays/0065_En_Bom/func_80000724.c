// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bom.h"

void EnBom_WaitForRelease(EnBom* this, PlayState* play) {
    
    if (Actor_HasNoParent(&this->actor, play)) {
        this->actionFunc = EnBom_Move;
        this->actor.room = play->roomCtx.curRoom.num;
        this->actor.flags &= ~ACTOR_FLAG_FREEZE_EXCEPTION;
        this->actor.bgCheckFlags &= ~BGCHECKFLAG_GROUND;
        Math_Vec3s_ToVec3f(&this->actor.prevPos, &this->actor.home.rot);
        if (this->isPowderKeg) {
            gSaveContext.powderKegTimer = 0;
        }
        EnBom_Move(this, play);
    } else {
        Math_Vec3f_ToVec3s(&this->actor.home.rot, &this->actor.parent->world.pos);
        if (this->isPowderKeg) {
            gSaveContext.powderKegTimer = this->timer;
        }
    }
    Math_ScaledStepToS(&this->unk_1FA, 0, 0x7D0);
}
