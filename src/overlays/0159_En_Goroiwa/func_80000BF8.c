// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

s32 ref_func_8093F498(EnGoroiwa* this) {
    s32 pad;
    f32 temp_f0;
    Vec3f sp2C;
    Vec3s* temp_v0 = &this->pathPoints[this->unk_1D8];

    sp2C.x = temp_v0->x;
    sp2C.y = temp_v0->y;
    sp2C.z = temp_v0->z;

    Math_StepToF(&this->actor.speed, ref_D_80942DFC[this->unk_1E4], 0.3f);
    Math_Vec3f_Diff(&sp2C, &this->actor.world.pos, &this->actor.velocity);

    temp_f0 = Math3D_Vec3fMagnitude(&this->actor.velocity);
    if ((this->actor.speed + 1.0f) < temp_f0) {
        Math_Vec3f_Scale(&this->actor.velocity, this->actor.speed / temp_f0);
        this->actor.world.pos.x += this->actor.velocity.x;
        this->actor.world.pos.y += this->actor.velocity.y;
        this->actor.world.pos.z += this->actor.velocity.z;
        this->unk_1E5 &= ~0x40;
        return false;
    }

    this->actor.world.pos.x = sp2C.x;
    this->actor.world.pos.y = sp2C.y;
    this->actor.world.pos.z = sp2C.z;
    this->unk_1E5 |= 0x40;
    return true;
}
