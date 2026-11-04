// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_comb.h"

void ObjComb_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjComb* this = (ObjComb*)thisx;
    s32 sp2C = OBJCOMB_GET_8000(&this->actor) | OBJCOMB_GET_80(&this->actor);

    Actor_ProcessInitChain(&this->actor, sInitChain);
    Collider_InitJntSph(play, &this->collider);

    if ((sp2C == 1) && OBJCOMB_GET_10(&this->actor) && CHECK_WEEKEVENTREG(WEEKEVENTREG_83_02)) {
        Actor_Kill(&this->actor);
        return;
    }

    Collider_SetJntSph(play, &this->collider, &this->actor, &sJntSphInit, this->colliderElements);

    if ((sp2C == 0) && Item_CanDropBigFairy(play, OBJCOMB_GET_3F(&this->actor), OBJCOMB_GET_7F00(&this->actor))) {
        this->unk_1B7 = 1;
        this->actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
    }

    if ((sp2C != 2) || !ref_func_8098CE40(this, play)) {
        this->unk_1B8 = -1;
    }
    ref_func_8098DC44(this);
}
