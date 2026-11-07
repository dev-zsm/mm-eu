// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_block.h"

void ref_func_80B7F1A8(BgIkanaBlock* this) {
    f32 temp_f0;
    f32* phi_v0;
    s32 phi_v0_2;

    if (this->unk_17A & (0x2 | 0x1)) {
        this->unk_164 = &this->dyna.actor.world.pos.x;
        phi_v0 = &this->dyna.actor.home.pos.x;
    } else {
        this->unk_164 = &this->dyna.actor.world.pos.z;
        phi_v0 = &this->dyna.actor.home.pos.z;
    }

    temp_f0 = (*this->unk_164 - *phi_v0) * 0.016666668f;

    if (temp_f0 >= 0.0f) {
        temp_f0 += 0.5f;
    } else {
        temp_f0 -= 0.5f;
    }

    if (this->unk_17A & (0x4 | 0x1)) {
        phi_v0_2 = 1;
    } else {
        phi_v0_2 = -1;
    }

    this->unk_168 = *phi_v0 + (((s32)temp_f0 + phi_v0_2) * 60.0f);
    this->unk_16C = 0.0f;
    this->unk_17C &= ~7;
    this->unk_17C |= 2;
    this->actionFunc = ref_func_80B7F290;
}
