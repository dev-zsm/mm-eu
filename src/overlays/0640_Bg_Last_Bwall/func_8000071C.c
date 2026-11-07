// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_last_bwall.h"

void BgLastBwall_Draw(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    BgLastBwall* this = (BgLastBwall*)thisx;

    Gfx_DrawDListOpa(play, ref_D_80C18A48[this->type].dList);
}
