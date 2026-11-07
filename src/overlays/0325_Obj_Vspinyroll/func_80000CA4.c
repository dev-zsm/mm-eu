// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_vspinyroll.h"

void ObjVspinyroll_Update(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    ObjVspinyroll* this = (ObjVspinyroll*)thisx;

    this->actionFunc(this, play);

    this->unk_3C6 += this->unk_3C0;

    Collider_UpdateCylinder(&this->dyna.actor, &this->collider);
    CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.base);
    CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
}
