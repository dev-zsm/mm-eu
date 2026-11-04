// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_oceff_spot.h"

void OceffSpot_Destroy(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    OceffSpot* this = (OceffSpot*)thisx;

    LightContext_RemoveLight(play, &play->lightCtx, this->lightNode1);
    LightContext_RemoveLight(play, &play->lightCtx, this->lightNode2);
    Magic_Reset(play);
}
