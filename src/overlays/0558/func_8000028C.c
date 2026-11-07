// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_f40_switch.h"

void BgF40Switch_Init(Actor* thisx, PlayState* play) {
    BgF40Switch* this = (BgF40Switch*)thisx;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    this->dyna.actor.scale.y = 0.165f;
    this->actionFunc = BgF40Switch_IdleUnpressed;
    this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y + 1.0f;
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    DynaPolyActor_LoadMesh(play, &this->dyna, &gStoneTowerFloorSwitchCol);
#if MM_VERSION >= N64_US
    if (!sBgF40SwitchGlobalsInitialized) {
        sBgF40SwitchLastUpdateFrame = play->gameplayFrames;
        sBgF40SwitchGlobalsInitialized = true;
    }
#endif
}
