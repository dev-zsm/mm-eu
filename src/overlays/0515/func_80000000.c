// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_balance.h"

void ref_func_80B823B0(BgDblueBalance* this) {
    s32 pad;
    Vec3f sp28;

    Matrix_Translate(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y, this->dyna.actor.world.pos.z,
                     MTXMODE_NEW);
    Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_APPLY);
    Matrix_RotateZS(this->dyna.actor.shape.rot.z, MTXMODE_APPLY);

    sp28.x = -138.28f;
    sp28.y = 0.0f;
    sp28.z = 0.0f;

    if (this->unk_15C != NULL) {
        Matrix_MultVec3f(&sp28, &this->unk_15C->dyna.actor.world.pos);
    }

    sp28.x = 138.28f;
    if (this->unk_160 != NULL) {
        Matrix_MultVec3f(&sp28, &this->unk_160->dyna.actor.world.pos);
    }
}
