// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kibako2.h"

void ObjKibako2_Init(Actor* thisx, PlayState* play) {
    ObjKibako2* this = (ObjKibako2*)thisx;
    s32 pad;
    s32 contents = KIBAKO2_CONTENTS(&this->dyna.actor);

    DynaPolyActor_Init(&this->dyna, 0);
    Collider_InitCylinder(play, &this->collider);
    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_LoadMesh(play, &this->dyna, &gLargeCrateCol);
    Collider_SetCylinder(play, &this->collider, &this->dyna.actor, &sCylinderInit);
    Collider_UpdateCylinder(&this->dyna.actor, &this->collider);
    this->dyna.actor.home.rot.z = 0;
    this->dyna.actor.world.rot.z = 0;
    this->dyna.actor.shape.rot.z = 0;
    this->dyna.actor.world.rot.x = 0;
    this->dyna.actor.shape.rot.x = 0;
    if (contents == OBJKIBAKO2_CONTENTS_COLLECTIBLE) {
        if (Item_CanDropBigFairy(play, KIBAKO2_COLLECTIBLE_ID(&this->dyna.actor),
                                 KIBAKO2_COLLECTIBLE_FLAG(&this->dyna.actor))) {
            this->unk_1AC = 1;
            this->dyna.actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
        }
    }
    if ((contents != OBJKIBAKO2_CONTENTS_SKULLTULA) || !ObjKibako2_ContainsSkulltula(this, play)) {
        this->skulltulaNoiseTimer = -1;
    }
    this->actionFunc = ObjKibako2_Idle;
}
