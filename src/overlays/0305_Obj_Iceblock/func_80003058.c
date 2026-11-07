// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A260E8(ObjIceblock* this) {
    static f32 ref_D_80A26FC0[] = { 14.0f, -14.0f, 14.0f, -14.0f };

    this->unk_260 = ref_D_80A26FC0[this->unk_26C];
    this->unk_25C = 0.0f;
    this->dyna.actor.velocity.y = 0.0f;
    this->stateTimer = 15;
    ref_func_80A24DC4(this);
    this->actionFunc = ref_func_80A26144;
}
