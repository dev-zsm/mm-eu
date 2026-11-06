// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_block.h"

void ref_func_80B7EA60(BgIkanaBlock* this) {
    s32 phi_v0;

    this->unk_17A &= ~(0x8 | 0x4 | 0x2 | 0x1);

    if (fabsf(this->dyna.pushForce) > 0.1f) {
        if (this->dyna.pushForce > 0.0f) {
            phi_v0 = this->dyna.yRotation;
        } else {
            phi_v0 = BINANG_ROT180(this->dyna.yRotation);
        }

        if ((phi_v0 < -0x6000) || (phi_v0 >= 0x6000)) {
            this->unk_17A |= 8;
        } else if (phi_v0 < -0x2000) {
            this->unk_17A |= 2;
        } else if (phi_v0 < 0x2000) {
            this->unk_17A |= 4;
        } else {
            this->unk_17A |= 1;
        }
    }
}
