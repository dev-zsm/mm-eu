// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A23B88(ObjIceblock* this) {
    f32 f4;
    f32 f2;
    f32 f14;
    f32 f16;
    f32 f6;

    f14 = this->dyna.actor.world.pos.x - this->dyna.actor.home.pos.x;
    f2 = (f14 >= 0.0f) ? (0.5f) : (-0.5f);
    f4 = (((s32)(f2 + f14)) / 30) * 30;
    f14 -= f4;
    if (fabsf(f14) < 3.0f) {
        this->dyna.actor.world.pos.x = this->dyna.actor.home.pos.x + f4;
    }

    f16 = this->dyna.actor.world.pos.z - this->dyna.actor.home.pos.z;
    f2 = (f16 >= 0.0f) ? (0.5f) : (-0.5f);
    f6 = (((s32)(f2 + f16)) / 30) * 30;
    f16 -= f6;
    if (fabsf(f16) < 3.0f) {
        this->dyna.actor.world.pos.z = this->dyna.actor.home.pos.z + f6;
    }
}
