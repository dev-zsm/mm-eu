// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hugebombiwa.h"

void ref_func_80A54C04(ObjHugebombiwa* this, PlayState* play) {
    s32 pad;

    if (this->collider.base.acFlags & AC_HIT) {
        this->unk_4B3 = 5;
    }

    if (ref_func_80A54A0C(this)) {
        CutsceneManager_Queue(this->actor.csId);
        ref_func_80A54CD8(this);
        return;
    }

    this->collider.base.acFlags &= ~AC_HIT;

    if (this->unk_4B3 > 0) {
        this->unk_4B3--;
        if (this->unk_4B3 == 0) {
            this->collider.base.colMaterial = COL_MATERIAL_HARD;
        } else {
            this->collider.base.colMaterial = COL_MATERIAL_NONE;
        }
    }

    CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
}
