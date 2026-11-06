// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_pzlblock.h"

bool ref_func_809A34E0(ObjPzlblock* this, s32 arg1) {
    s32 temp_v0 = OBJPZLBLOCK_GET_ROTZ(&this->dyna.actor);

    if (temp_v0 == 0) {
        return arg1 == 0;
    }

    if (temp_v0 == 1) {
        return arg1 == 1;
    }

    if (temp_v0 == 2) {
        return arg1 == 2;
    }

    if (temp_v0 == 3) {
        return arg1 == 3;
    }

    if (temp_v0 == 4) {
        return (arg1 == 0) || (arg1 == 1);
    }

    if (temp_v0 == 5) {
        return (arg1 == 2) || (arg1 == 3);
    }

    if (temp_v0 == 6) {
        if (this->unk_176 != 0) {
            return (arg1 == 0) || (arg1 == 1);
        }

        if (this->unk_178 != 0) {
            return (arg1 == 2) || (arg1 == 3);
        }
        return true;
    }
    return false;
}
