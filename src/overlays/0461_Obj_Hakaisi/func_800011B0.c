// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hakaisi.h"

void ref_func_80B15330(ObjHakaisi* this, PlayState* play) {
    s32 pad;
    MtxF sp34;

    this->dyna.actor.velocity.y += this->dyna.actor.gravity;
    Actor_UpdatePos(&this->dyna.actor);

    if (this->dyna.actor.bgCheckFlags & BGCHECKFLAG_GROUND_TOUCH) {
        ref_func_80B14B6C(this, play, this->dyna.actor.world.pos, 40);
        ref_func_80B14CF8(play, this->dyna.actor.world.pos, 100, 30, 10);
        Actor_Kill(&this->dyna.actor);
    }

    Matrix_RotateAxisS(this->unk_19C, &this->unk_184, MTXMODE_NEW);
    Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_APPLY);
    Matrix_RotateXS(this->dyna.actor.shape.rot.x, MTXMODE_APPLY);
    Matrix_RotateZS(this->dyna.actor.shape.rot.z, MTXMODE_APPLY);
    Matrix_Get(&sp34);

    Matrix_MtxFToYXZRot(&sp34, &this->dyna.actor.shape.rot, false);
}
