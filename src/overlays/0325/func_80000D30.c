// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_vspinyroll.h"

void ObjVspinyroll_Draw(Actor* thisx, PlayState* play) {
    ObjVspinyroll* this = (ObjVspinyroll*)thisx;

    Matrix_Translate(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y + 60.0f, this->dyna.actor.world.pos.z,
                     MTXMODE_NEW);
    Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_APPLY);
    Matrix_RotateZS(this->dyna.actor.shape.rot.z + 0x4000, MTXMODE_APPLY);
    Matrix_RotateXS(this->dyna.actor.shape.rot.x + this->unk_3C6, MTXMODE_APPLY);
    Matrix_Scale(0.1f, 0.1f, 0.1f, MTXMODE_APPLY);
    Gfx_DrawDListOpa(play, object_spinyroll_DL_000460);
}
