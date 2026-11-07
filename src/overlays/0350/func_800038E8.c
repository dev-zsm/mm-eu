// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5EA48(Actor* thisx, PlayState* play) {
    EnKusa2* this = (EnKusa2*)thisx;

    if (this->unk_1CF == 0xFF) {
        Gfx_DrawDListOpa(play, gKusaBushType1DL);
    } else {
        ref_func_80A5E80C(play, this->unk_1CF);
    }
}
