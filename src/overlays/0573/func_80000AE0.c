// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_bombwall.h"

void BgIkanaBombwall_Draw(Actor* thisx, PlayState* play) {
    Gfx_DrawDListOpa(play, ref_D_80BD52E0[BGIKANABOMBWALL_GET_100(thisx)]);
}
