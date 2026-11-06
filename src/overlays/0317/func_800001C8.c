// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bell.h"

s32 ref_func_80A356D8(ObjBell* this) {
    f32 scaleProjection;

    this->unk_212 = this->dyna.actor.world.rot.y;
    if (this->unk_20C >= 0x4000 || this->unk_20C <= -0x4000) {
        this->unk_212 -= 0x8000;
    }
    scaleProjection = Math_SinS(this->unk_20C) * this->unk_21C;
    this->dyna.actor.world.rot.x = this->dyna.actor.home.rot.x;
    this->unk_220 = scaleProjection;
    this->dyna.actor.world.rot.x += TRUNCF_BINANG(scaleProjection);
    Math_ApproachF(&this->unk_21C, 0.0f, 0.03f, 70.0f);
    if (this->unk_21C > 0.0f) {
        this->unk_20C -= 0x800;
    }
    return false;
}
