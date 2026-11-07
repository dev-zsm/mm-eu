// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_dnb.h"

void ref_func_80A4FDD0(EnDnbEffect* effect, EnDnb* this, s16* alloc, s32 idx) {
    Vec3f sp1C;
    s32 idx2 = idx * 3;

    sp1C.x = alloc[idx2 + 0] + this->dyna.actor.world.pos.x;
    sp1C.y = alloc[idx2 + 1] + this->dyna.actor.world.pos.y;
    sp1C.z = alloc[idx2 + 2] + this->dyna.actor.world.pos.z;
    effect->unk_00 = sp1C;
    effect->unk_0C = sp1C;
    effect->unk_24 = Math_Vec3f_Yaw(&this->dyna.actor.world.pos, &sp1C);
    effect->unk_18 = gZeroVec3s;
}
