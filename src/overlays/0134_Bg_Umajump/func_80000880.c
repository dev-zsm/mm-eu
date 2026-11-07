// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_umajump.h"

void BgUmajump_Draw(Actor* thisx, PlayState* play) {
    BgUmajump* this = (BgUmajump*)thisx;

    if (this->dyna.bgId != BGACTOR_NEG_ONE) {
        Gfx_DrawDListOpa(play, gHorseJumpFenceDL);
    }
}
