// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

s32 ref_func_8093F5EC(EnGoroiwa* this) {
    s32 pad;
    Vec3s* sp18 = &this->pathPoints[this->unk_1D8];

    if (this->actor.velocity.y < 0.0f) {
        this->actor.velocity.y = 0.0f;
    }

    Math_StepToF(&this->actor.velocity.y, ref_D_80942DFC[this->unk_1E4] * 0.5f, 0.18f);
    this->actor.world.pos.x = sp18->x;
    this->actor.world.pos.z = sp18->z;

    if (Math_StepToF(&this->actor.world.pos.y, sp18->y, fabsf(this->actor.velocity.y))) {
        this->unk_1E5 |= 0x40;
        return true;
    }

    this->unk_1E5 &= ~0x40;
    return false;
}
