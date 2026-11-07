// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_shutter.h"

s32 ref_func_808A0900(DoorShutter* this, PlayState* play) {
    TransitionActorEntry* transitionEntry =
        &play->transitionActors.list[DOOR_GET_TRANSITION_ID(&this->slidingDoor.dyna.actor)];
    s8 frontRoom = transitionEntry->sides[0].room;

    if (frontRoom == transitionEntry->sides[1].room) {
        if (ABS_ALT(BINANG_SUB(this->slidingDoor.dyna.actor.shape.rot.y,
                               this->slidingDoor.dyna.actor.yawTowardsPlayer)) < 0x4000) {
            frontRoom = -1;
        }
    }
    return frontRoom == this->slidingDoor.dyna.actor.room;
}
