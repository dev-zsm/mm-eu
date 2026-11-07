// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_spinyroll.h"

void ObjSpinyroll_Update(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    ObjSpinyroll* this = (ObjSpinyroll*)thisx;

    if (this->collider.base.atFlags & AT_HIT) {
        this->collider.base.atFlags &= ~AT_HIT;
        ref_func_80A1DCCC(this);
    }

    this->actionFunc(this, play);

    this->unk_4E0 += this->unk_4DA;
    ref_func_80A1DC5C(this);
    ref_func_80A1DB2C(thisx);

    CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.base);
    CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
}
