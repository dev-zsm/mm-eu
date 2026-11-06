// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_shutter.h"

s32 ref_func_808A1D68(DoorShutter* this, PlayState* play) {
    s32 temp_a0;
    s32 temp_a1;

    if (Player_InCsMode(play)) {
        return true;
    }

    temp_a0 = BINANG_SUB(Actor_WorldYawTowardPoint(&this->slidingDoor.dyna.actor, &play->view.eye),
                         this->slidingDoor.dyna.actor.shape.rot.y);
    temp_a1 = BINANG_SUB(this->slidingDoor.dyna.actor.yawTowardsPlayer, this->slidingDoor.dyna.actor.shape.rot.y);

    temp_a0 = ABS_ALT(temp_a0);
    temp_a1 = ABS_ALT(temp_a1);

    if (((temp_a1 < 0x4000) && (temp_a0 > 0x4000)) || ((temp_a1 > 0x4000) && (temp_a0 < 0x4000))) {
        return false;
    }
    return true;
}
