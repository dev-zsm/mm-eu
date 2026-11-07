// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_tobira01.h"

void BgTobira01_Init(Actor* thisx, PlayState* play) {
    BgTobira01* this = (BgTobira01*)thisx;

    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    DynaPolyActor_LoadMesh(play, &this->dyna, &gGoronDoorCol);
    CLEAR_WEEKEVENTREG(WEEKEVENTREG_GATEKEEPER_OPENED_GORON_SHRINE);
    Actor_SetScale(&this->dyna.actor, 1.0f);
    this->timer = gSaveContext.save.isNight;
    this->posYTick = 0;
    this->actionFunc = BgTobira01_Action;
}
