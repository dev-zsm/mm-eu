// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_pzlblock.h"

s32 ref_func_809A3448(ObjPzlblock* this) {
    s16 temp_v0;

    if (fabsf(this->dyna.pushForce) > 0.1f) {
        temp_v0 = BINANG_ADD(this->dyna.yRotation, 0x2000);

        if (this->dyna.pushForce < 0.0f) {
            temp_v0 = BINANG_ROT180(temp_v0);
        }

        if (temp_v0 < -0x4000) {
            return 3;
        }

        if (temp_v0 < 0) {
            return 1;
        }

        if (temp_v0 < 0x4000) {
            return 2;
        }
        return 0;
    }
    return -1;
}
