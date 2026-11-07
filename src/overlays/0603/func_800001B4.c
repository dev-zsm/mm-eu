// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_dharma.h"

void BgIkanaDharma_Init(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    BgIkanaDharma* this = (BgIkanaDharma*)thisx;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    this->dyna.actor.scale.x = 0.3f;
    this->dyna.actor.scale.y = 0.1f;
    this->dyna.actor.scale.z = 0.3f;
    DynaPolyActor_Init(&this->dyna, 0);
    DynaPolyActor_LoadMesh(play, &this->dyna, &gStoneTowerTemplePunchablePillarCol);
    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, &this->dyna.actor, &sCylinderInit);
    if (!BGIKANADHARMA_IS_CHILD(&this->dyna.actor)) {
        f32 segmentY = this->dyna.actor.world.pos.y;
        s32 numSegments = BGIKANADHARMA_NUM_SEGMENTS(&this->dyna.actor);
        s32 i;

        for (i = 0; i < numSegments; i++) {
            segmentY += 60.0f;
            Actor_SpawnAsChildAndCutscene(&play->actorCtx, play, ACTOR_BG_IKANA_DHARMA, this->dyna.actor.world.pos.x,
                                          segmentY, this->dyna.actor.world.pos.z, this->dyna.actor.shape.rot.x,
                                          this->dyna.actor.shape.rot.y, this->dyna.actor.shape.rot.z,
                                          BGIKANADHARMA_PARAMS(0, true, 0), this->dyna.actor.csId,
                                          this->dyna.actor.halfDaysBits, NULL);
        }

        this->dyna.actor.bgCheckFlags |= BGCHECKFLAG_GROUND;
    }

    BgIkanaDharma_SetupWaitForHit(this);
}
