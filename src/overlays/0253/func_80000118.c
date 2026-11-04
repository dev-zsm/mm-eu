// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_spiral.h"

void DoorSpiral_Init(Actor* thisx, PlayState* play) {
    DoorSpiral* this = (DoorSpiral*)thisx;
    s32 transitionId = DOOR_GET_TRANSITION_ID(thisx);
    s8 objectSlot;

    if (this->actor.room != play->transitionActors.list[transitionId].sides[0].room) {
        Actor_Kill(&this->actor);
        return;
    }
    Actor_ProcessInitChain(&this->actor, sInitChain);
    this->type = DOORSPIRAL_GET_TYPE(thisx);
    this->direction = DOORSPIRAL_GET_DIRECTION(thisx);
    this->unk147 = ref_func_809A2BF8(play);
    objectSlot = Object_GetSlot(&play->objectCtx, sSpiralObjectInfoTable[this->unk147].objectId);
    this->objectSlot = objectSlot;
    if (objectSlot <= OBJECT_SLOT_NONE) {
        Actor_Kill(&this->actor);
        return;
    }
    DoorSpiral_SetupAction(this, ref_func_809A2DB0);
    Actor_SetFocus(&this->actor, 60.0f);
}
