// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_comb.h"

bool ref_func_8098CE40(ObjComb* this, PlayState* play) {
    s32 phi_a2 = -1;
    s32 temp_v0 = (OBJCOMB_GET_1F(&this->actor) << 2) | 0xFF01;

    if ((u8)temp_v0 & 3) {
        phi_a2 = ((temp_v0 & 0x3FC) >> 2) & 0xFF;
    }

    return ((phi_a2 < 0) == 1) || !Flags_GetTreasure(play, phi_a2);
}
