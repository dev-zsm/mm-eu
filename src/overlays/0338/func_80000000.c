// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ladder.h"

void BgLadder_Init(Actor* thisx, PlayState* play) {
    BgLadder* this = (BgLadder*)thisx;
    BgLadderSize size;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);

    this->switchFlag = BGLADDER_GET_SWITCH_FLAG(thisx);
    thisx->params = BGLADDER_GET_SIZE(thisx);
    DynaPolyActor_Init(&this->dyna, 0);
    size = thisx->params;

    if (size == LADDER_SIZE_12RUNG) {
        DynaPolyActor_LoadMesh(play, &this->dyna, &gWoodenLadder12RungCol);
    } else if (size == LADDER_SIZE_16RUNG) {
        DynaPolyActor_LoadMesh(play, &this->dyna, &gWoodenLadder16RungCol);
    } else if (size == LADDER_SIZE_20RUNG) {
        DynaPolyActor_LoadMesh(play, &this->dyna, &gWoodenLadder20RungCol);
    } else if (size == LADDER_SIZE_24RUNG) {
        DynaPolyActor_LoadMesh(play, &this->dyna, &gWoodenLadder24RungCol);
    } else {
        Actor_Kill(&this->dyna.actor);
        return;
    }

    if (Flags_GetSwitch(play, this->switchFlag)) {
        
        this->alpha = 255;
        this->dyna.actor.flags &= ~ACTOR_FLAG_UPDATE_CULLING_DISABLED; 
        this->action = BgLadder_DoNothing;
    } else {
        
        this->alpha = 5;
        DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
        this->dyna.actor.draw = NULL;
        this->action = BgLadder_Wait;
    }
}
