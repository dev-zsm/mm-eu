// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_door_etc.h"

void EnDoorEtc_Init(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    s32 objectSlot;
    EnDoorEtcInfo* objectInfo = sObjectInfo;
    s32 i;
    EnDoorEtc* this = (EnDoorEtc*)thisx;

    Actor_ProcessInitChain(&this->knobDoor.dyna.actor, sInitChain);
    Actor_SetScale(&this->knobDoor.dyna.actor, 0.01f);
    this->knobDoor.dyna.actor.shape.rot.x = -0x4000;
    this->angle = 0;
    for (i = 0; i < 15; i++, objectInfo++) {
        if (play->sceneId == objectInfo->sceneId) {
            break;
        }
    }
    if ((i >= 15) && (Object_GetSlot(&play->objectCtx, GAMEPLAY_FIELD_KEEP) > OBJECT_SLOT_NONE)) {
        objectInfo++;
    }
    objectSlot = Object_GetSlot(&play->objectCtx, objectInfo->objectId);
    if (objectSlot <= OBJECT_SLOT_NONE) {
        Actor_Kill(&this->knobDoor.dyna.actor);
    } else {
        this->knobDoor.objectSlot = objectSlot;
        this->knobDoor.dlIndex = objectInfo->dListIndex;
        if (this->knobDoor.dyna.actor.objectSlot == this->knobDoor.objectSlot) {
            EnDoorEtc_WaitForObject(this, play);
        } else {
            this->actionFunc = EnDoorEtc_WaitForObject;
        }
    }
    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, &this->knobDoor.dyna.actor, &sCylinderInit);
    this->knobDoor.dyna.actor.colChkInfo.mass = MASS_IMMOVABLE;
}
