// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

s32 ref_func_80A25238(ObjIceblock* this) {
    s16 phi_v0;

    if (fabsf(this->dyna.pushForce) > 0.1f) {
        if (this->dyna.pushForce > 0.0f) {
            phi_v0 = this->dyna.yRotation + 0x2000;
        } else {
            phi_v0 = this->dyna.yRotation - 0x6000;
        }

        if (phi_v0 < -0x4000) {
            return 3;
        }

        if (phi_v0 < 0) {
            return 1;
        }

        if (phi_v0 < 0x4000) {
            return 2;
        }
        return 0;
    }
    return -1;
}
