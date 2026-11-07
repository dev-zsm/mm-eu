// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_opstage.h"

void DmOpstage_Init(Actor* thisx, PlayState* play) {
    DmOpstage* this = (DmOpstage*)thisx;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DmOpstage_SetupAction(this, DmOpstage_HandleCutscene);
    Actor_SetScale(&this->dyna.actor, 0.1f);

    if (DMOPSTAGE_GET_TYPE(&this->dyna.actor) == DMOPSTAGE_TYPE_GROUND) {
        DynaPolyActor_Init(&this->dyna, 0);
        DynaPolyActor_LoadMesh(play, &this->dyna, &gKeikokuDemoFloorCol);
    }

    if (DMOPSTAGE_GET_TYPE(&this->dyna.actor) > DMOPSTAGE_TYPE_GROUND) {
        
        this->drawOffset.x = this->dyna.actor.world.pos.x;
        this->drawOffset.y = this->dyna.actor.world.pos.y;
        this->drawOffset.z = this->dyna.actor.world.pos.z;
        this->dyna.actor.world.pos.x = 0.0f;
        this->dyna.actor.world.pos.y = 0.0f;
        this->dyna.actor.world.pos.z = 0.0f;
    }
}
