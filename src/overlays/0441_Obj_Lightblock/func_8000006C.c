// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lightblock.h"

void ObjLightblock_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjLightblock* this = (ObjLightblock*)thisx;
    LightblockTypeVars* typeVars = &sLightblockTypeVars[LIGHTBLOCK_TYPE(&this->dyna.actor)];

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    Actor_SetScale(&this->dyna.actor, typeVars->scale);
    DynaPolyActor_Init(&this->dyna, 0);
    Collider_InitCylinder(play, &this->collider);
    if (Flags_GetSwitch(play, LIGHTBLOCK_GET_DESTROYED_SWITCH_FLAG(&this->dyna.actor))) {
        Actor_Kill(&this->dyna.actor);
        return;
    }

    DynaPolyActor_LoadMesh(play, &this->dyna, &gSunBlockCol);
    Collider_SetCylinder(play, &this->collider, &this->dyna.actor, &sCylinderInit);
    Collider_UpdateCylinder(&this->dyna.actor, &this->collider);
    this->collider.dim.radius = typeVars->radius;
    this->collider.dim.height = typeVars->height;
    this->collider.dim.yShift = typeVars->yShift;
    this->alpha = 255;
    ObjLightblock_SetupWait(this);
}
