// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_skateblock.h"

void ref_func_80A21D1C(ObjSkateblock* this) {
    f32 sp4;
    f32 temp_f14;
    f32 temp_f16;
    f32 temp_f6;
    f32 phi_f2;

    temp_f14 = this->dyna.actor.world.pos.x - this->dyna.actor.home.pos.x;
    phi_f2 = ((temp_f14 >= 0.0f) ? 0.5f : -0.5f);
    sp4 = ((s32)(phi_f2 + temp_f14) / 30) * 30;
    temp_f14 -= sp4;

    if (fabsf(temp_f14) < 3.0f) {
        this->dyna.actor.world.pos.x = this->dyna.actor.home.pos.x + sp4;
    }

    temp_f16 = this->dyna.actor.world.pos.z - this->dyna.actor.home.pos.z;
    phi_f2 = ((temp_f16 >= 0.0f) ? 0.5f : -0.5f);
    temp_f6 = ((s32)(phi_f2 + temp_f16) / 30) * 30;
    temp_f16 -= temp_f6;

    if (fabsf(temp_f16) < 3.0f) {
        this->dyna.actor.world.pos.z = this->dyna.actor.home.pos.z + temp_f6;
    }
}
