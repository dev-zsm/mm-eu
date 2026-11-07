// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_pzlblock.h"

bool ref_func_809A35EC(ObjPzlblock* this, s32 arg1) {
    s32 temp_v0 = OBJPZLBLOCK_GET_ROTZ(&this->dyna.actor);
    s32 temp_v1 = this->dyna.actor.home.rot.x & 0xF;
    s32 temp;

    if (temp_v0 == 0) {
        return this->unk_176 < temp_v1;
    }

    if (temp_v0 == 1) {
        return -temp_v1 < this->unk_176;
    }

    if (temp_v0 == 2) {
        return this->unk_178 < temp_v1;
    }

    if (temp_v0 == 3) {
        return -temp_v1 < this->unk_178;
    }

    if (temp_v0 == 4) {
        temp = ref_D_809A4050[arg1] + this->unk_176;
        return (temp_v1 >= temp) && (-temp_v1 <= temp);
    }

    if (temp_v0 == 5) {
        temp = ref_D_809A4058[arg1] + this->unk_178;
        return (temp_v1 >= temp) && (-temp_v1 <= temp);
    }

    if (temp_v0 == 6) {
        if ((arg1 == 0) || (arg1 == 1)) {
            temp = ref_D_809A4050[arg1] + this->unk_176;
            return (temp_v1 >= temp) && (-temp_v1 <= temp);
        }

        temp = ref_D_809A4058[arg1] + this->unk_178;
        return (temp_v1 >= temp) && (-temp_v1 <= temp);
    }

    return false;
}
