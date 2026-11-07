// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_skateblock.h"

void ref_func_80A2244C(ObjSkateblock* this) {
    this->actionFunc = ref_func_80A224A4;
    this->unk_168 = ref_D_80A22AF8[this->unk_170];
    this->unk_164 = 0.0f;
    this->unk_17A = 15;
    this->dyna.actor.velocity.y = this->dyna.actor.gravity;
    ref_func_80A21F68(this);
}
