// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_door_etc.h"

void EnDoorEtc_WaitForObject(EnDoorEtc* this, PlayState* play) {
    if (Object_IsLoaded(&play->objectCtx, this->knobDoor.objectSlot)) {
        this->knobDoor.dyna.actor.flags &= ~ACTOR_FLAG_UPDATE_CULLING_DISABLED;
        this->knobDoor.dyna.actor.objectSlot = this->knobDoor.objectSlot;
        this->actionFunc = ref_func_80AC2354;
        this->knobDoor.dyna.actor.draw = EnDoorEtc_Draw;
    }
}
