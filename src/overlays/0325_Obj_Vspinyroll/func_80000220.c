// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_vspinyroll.h"

s32 ref_func_80A3C700(ObjVspinyroll* this) {
    s32 pad;
    s32 sp30 = this->unk_398 ^ 1;
    Vec3f sp24;

    Math_StepToF(&this->dyna.actor.speed, this->unk_394, this->unk_394 * 0.2f);

    this->dyna.actor.world.pos.x += this->dyna.actor.speed * this->unk_3B4.x;
    this->dyna.actor.world.pos.y += this->dyna.actor.speed * this->unk_3B4.y;
    this->dyna.actor.world.pos.z += this->dyna.actor.speed * this->unk_3B4.z;

    Math_Vec3f_Diff(&this->unk_39C[sp30], &this->dyna.actor.world.pos, &sp24);
    return Math3D_Vec3fMagnitudeSq(&sp24) < (SQ(this->dyna.actor.speed) + 0.05f);
}
