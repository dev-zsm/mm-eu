// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_f40_swlift.h"

void BgF40Swlift_Init(Actor* thisx, PlayState* play) {
    BgF40Swlift* this = (BgF40Swlift*)thisx;
    s32 index;
    s32 pad;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    index = BG_F40_SWLIFT_GET_INDEX(thisx);
    if ((index < 0) || (index >= 5)) { 
        Actor_Kill(&this->dyna.actor);
        return;
    }

    sHeights[index] = this->dyna.actor.world.pos.y;
    sSwitchFlags[index] = BG_F40_SWLIFT_GET_SWITCH_FLAG(thisx);
    if (index != 0) {
        Actor_Kill(&this->dyna.actor);
        return;
    }

    DynaPolyActor_LoadMesh(play, &this->dyna, &gStoneTowerVerticallyOscillatingPlatformCol);
    this->dyna.actor.params = 0;
}
