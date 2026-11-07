// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_kin2_shelf.h"

s32 ref_func_80B6FE48(BgKin2Shelf* this, PlayState* play) {
    s32 params = BGKIN2SHELF_GET_1(&this->dyna.actor);
    u8 temp_v1 = ref_D_80B70778[params] & this->unk_164;

    if ((this->unk_166 != 0) && (this->unk_167 != 0)) {
        return false;
    }

    if ((this->unk_166 == 0) && (this->unk_167 == 0)) {
        return temp_v1 != 0;
    }

    if (this->unk_166 != 0) {
        return temp_v1 & (0x8 | 0x2);
    }

    return temp_v1 & 5;
}
