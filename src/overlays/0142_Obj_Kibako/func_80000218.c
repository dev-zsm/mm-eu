// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kibako.h"

void ObjKibako_Init(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    ObjKibako* this = (ObjKibako*)thisx;
    s32 objectIndex;

    objectIndex = KIBAKO_BANK_INDEX(thisx);
    Actor_ProcessInitChain(&this->actor, sInitChain);
    Actor_SetScale(&this->actor, 0.15f);
    if (objectIndex == 0) {
        this->actor.cullingVolumeDistance = 4000.0f;
    } else {
        this->actor.cullingVolumeDistance = 800.0f;
    }
    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, &this->actor, &sCylinderInit);
    Collider_UpdateCylinder(&this->actor, &this->collider);
    this->actor.colChkInfo.mass = MASS_IMMOVABLE;
    this->objectSlot = Object_GetSlot(&play->objectCtx, sObjectIds[objectIndex]);
    if (this->objectSlot <= OBJECT_SLOT_NONE) {
        Actor_Kill(&this->actor);
        return;
    }
    this->unk199 = this->actor.room;
    ref_func_80926B40(this);
}
