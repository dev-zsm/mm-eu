// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_shutter.h"

void DoorShutter_SetupType(DoorShutter* this, PlayState* play) {
    if (Object_IsLoaded(&play->objectCtx, this->objectSlot) &&
        (!R_PLAY_FILL_SCREEN_ON || (R_PLAY_FILL_SCREEN_ALPHA == 0))) {
        this->slidingDoor.dyna.actor.objectSlot = this->objectSlot;
        this->slidingDoor.dyna.actor.draw = DoorShutter_Draw;
        DoorShutter_SetupDoor(this, play);
    }
}
