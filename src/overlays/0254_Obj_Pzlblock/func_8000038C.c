// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_pzlblock.h"

void ref_func_809A376C(ObjPzlblock* this, s32 arg1) {
    this->unk_176 += ref_D_809A4050[arg1];
    this->unk_178 += ref_D_809A4058[arg1];
    if ((arg1 == 0) || (arg1 == 1)) {
        this->unk_164 = &this->dyna.actor.world.pos.x;
        this->unk_168 = this->dyna.actor.home.pos.x + (this->unk_176 * 60);
    } else {
        this->unk_164 = &this->dyna.actor.world.pos.z;
        this->unk_168 = this->dyna.actor.home.pos.z + (this->unk_178 * 60);
    }
    this->unk_16C = arg1;
}
