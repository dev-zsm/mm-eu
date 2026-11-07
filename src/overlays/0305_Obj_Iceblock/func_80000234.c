// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A232C4(ObjIceblock* this, s32 arg1) {
    static s16 ref_D_80A26E80[] = { 1, -1, 0, 0 };
    static s16 ref_D_80A26E88[] = { 0, 0, 1, -1 };

    this->unk_276 += ref_D_80A26E80[arg1];
    this->unk_278 += ref_D_80A26E88[arg1];

    if ((arg1 == 0) || (arg1 == 1)) {
        this->unk_264 = &this->dyna.actor.world.pos.x;
        this->unk_268 = this->dyna.actor.home.pos.x + (this->unk_276 * 60);
    } else {
        this->unk_264 = &this->dyna.actor.world.pos.z;
        this->unk_268 = this->dyna.actor.home.pos.z + (this->unk_278 * 60);
    }
    this->unk_26C = arg1;
}
