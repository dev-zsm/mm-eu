// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

s32 ref_func_80A236D4(ObjIceblock* this, Vec3f* arg1) {
    f32 sp2C;
    f32 sp28;
    s16 sp26;
    s32 sp20;

    sp26 = Math_Vec3f_Yaw(&this->dyna.actor.world.pos, arg1);
    sp2C = Math_SinS(sp26) * this->dyna.actor.speed;
    sp2C = fabsf(sp2C) + 0.01f;

    sp28 = Math_CosS(sp26) * this->dyna.actor.speed;
    sp28 = fabsf(sp28) + 0.01f;

    sp20 = Math_StepToF(&this->dyna.actor.world.pos.x, arg1->x, sp2C);
    sp20 &= 1;
    sp20 &= Math_StepToF(&this->dyna.actor.world.pos.z, arg1->z, sp28);
    return sp20;
}
