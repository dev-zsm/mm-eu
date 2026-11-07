// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lift.h"

void ref_func_8093DC90(Actor* thisx, PlayState* play) {
    ObjLift* this = (ObjLift*)thisx;
    Vec3f pos;
    Vec3s rot;

    Math_Vec3f_Sum(&this->dyna.actor.world.pos, &this->unk_168, &pos);
    rot.x = this->unk_174 + this->dyna.actor.home.rot.x;
    rot.y = this->dyna.actor.home.rot.y;
    rot.z = this->unk_176 + this->dyna.actor.home.rot.z;
    Matrix_SetTranslateRotateYXZ(pos.x, pos.y, pos.z, &rot);
    Matrix_Scale(this->dyna.actor.scale.x, this->dyna.actor.scale.y, this->dyna.actor.scale.z, MTXMODE_APPLY);
    Gfx_DrawDListOpa(play, gDampeGraveBrownElevatorDL);
}
