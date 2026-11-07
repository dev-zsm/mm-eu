// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A252DC(ObjIceblock* this, s32 arg1) {
    s32 phi_v0;
    s32 i;

    if (this->unk_2B0 == 1) {
        phi_v0 = true;
    } else if (this->unk_2B0 == 2) {
        phi_v0 = (this->dyna.pushForce > 0.0f);
    } else {
        phi_v0 = false;
    }

    for (i = 0; i < ARRAY_COUNT(this->unk_26E); i++) {
        if ((arg1 == i) && phi_v0) {
            this->unk_26E[i]++;
        } else if (this->unk_26E[i] > 0) {
            this->unk_26E[i]--;
        }
    }
}
