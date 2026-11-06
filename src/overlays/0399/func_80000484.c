// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_door_etc.h"

void ref_func_80AC2354(EnDoorEtc* this, PlayState* play) {
    Actor* door = play->actorCtx.actorLists[ACTORCAT_DOOR].first;

    while (door != NULL) {
        if ((door->id != ACTOR_EN_DOOR) ||
            !EnDoorEtc_IsDistanceGreater(&door->world.pos, &this->knobDoor.dyna.actor.world.pos, 10.0f)) {
            door = door->next;
        } else {
            this->knobDoor.dyna.actor.world.pos.x = door->world.pos.x;
            this->knobDoor.dyna.actor.world.pos.y = door->world.pos.y;
            this->knobDoor.dyna.actor.world.pos.z = door->world.pos.z;
            this->knobDoor.dyna.actor.shape.rot.y = door->shape.rot.y;
            this->knobDoor.dyna.actor.world.rot.y = door->world.rot.y;
            Actor_Kill(door);
            this->actionFunc = ref_func_80AC21A0;
            this->knobDoor.dyna.actor.textId = 0x239B;
            Actor_SetFocus(&this->knobDoor.dyna.actor, 70.0f);
            break;
        }
    }
}
