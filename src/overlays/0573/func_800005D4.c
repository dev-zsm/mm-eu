// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_bombwall.h"

void BgIkanaBombwall_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    BgIkanaBombwall* this = (BgIkanaBombwall*)thisx;
    s32 sp2C = BGIKANABOMBWALL_GET_100(&this->dyna.actor);
    CollisionHeader* colHeader;
    ColliderCylinderInit* cylinderInit;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_Init(&this->dyna, 0);
    Collider_InitCylinder(play, &this->collider);

    if (Flags_GetSwitch(play, BGIKANABOMBWALL_GET_SWITCH_FLAG(&this->dyna.actor))) {
        Actor_Kill(&this->dyna.actor);
        return;
    }

    if (sp2C == 0) {
        colHeader = &object_ikana_obj_Colheader_000488;
        cylinderInit = &sCylinderInit1;
    } else {
        colHeader = &object_ikana_obj_Colheader_000128;
        cylinderInit = &sCylinderInit2;
    }

    DynaPolyActor_LoadMesh(play, &this->dyna, colHeader);
    Collider_SetCylinder(play, &this->collider, &this->dyna.actor, cylinderInit);
    Collider_UpdateCylinder(&this->dyna.actor, &this->collider);

    if (sp2C == 0) {
        ref_func_80BD4F18(this);
    } else {
        ref_func_80BD4F88(this);
    }
}
