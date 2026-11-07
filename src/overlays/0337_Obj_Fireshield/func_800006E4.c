// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_fireshield.h"

void ref_func_80A4D174(ObjFireshield* this) {
    s32 temp_v0 = OBJFIRESHIELD_GET_FLAGS(&this->actor);
    s32 temp_v1 = 1 << (temp_v0 & 0x1F);

    if (!(ref_D_80A4D864[(temp_v0 & ~0x1F) >> 5] & temp_v1)) {
        this->unk_1A7 = 1;
        ref_D_80A4D864[(temp_v0 & ~0x1F) >> 5] |= temp_v1;
    }
}
