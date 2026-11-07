// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_skateblock.h"

void ref_func_80A211F4(ObjSkateblock* this, s32 arg1) {
    s32 i;
    s32 phi_v0 = false;

    if (this->dyna.pushForce > 0.0f) {
        phi_v0 = true;
    }

    for (i = 0; i < ARRAY_COUNT(this->unk_172); i++) {
        if ((arg1 == i) && phi_v0) {
            this->unk_172[i]++;
        } else if (this->unk_172[i] > 0) {
            this->unk_172[i]--;
        }
    }
}
