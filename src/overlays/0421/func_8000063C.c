// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokei_step.h"

void ObjTokeiStep_Init(Actor* thisx, PlayState* play) {
    ObjTokeiStep* this = (ObjTokeiStep*)thisx;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_Init(&this->dyna, 0);
    if ((play->sceneId == SCENE_CLOCKTOWER) && (gSaveContext.sceneLayer == 2) && (play->csCtx.scriptIndex == 0)) {
        DynaPolyActor_LoadMesh(play, &this->dyna, &gClocktowerPanelCol);
        ObjTokeiStep_InitSteps(this);
        ObjTokeiStep_SetupBeginOpen(this);
    } else if (((CURRENT_DAY == 3) && (CURRENT_TIME < CLOCK_TIME(6, 0))) || (gSaveContext.save.day >= 4)) {
        this->dyna.actor.draw = ObjTokeiStep_DrawOpen;
        ObjTokeiStep_InitStepsOpen(this);
        ObjTokeiStep_SetupDoNothingOpen(this);
    } else {
        DynaPolyActor_LoadMesh(play, &this->dyna, &gClocktowerPanelCol);
        ObjTokeiStep_InitSteps(this);
        ObjTokeiStep_SetupDoNothing(this);
    }
}
