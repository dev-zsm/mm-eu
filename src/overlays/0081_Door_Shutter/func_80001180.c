// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_shutter.h"

s32 ref_func_808A1A70(DoorShutter* this) {
    if (this->unk_163 == 7) {
        if (this->unk_163 == 7) {
            Actor_PlaySfx_Flagged(&this->slidingDoor.dyna.actor, NA_SE_EV_IKANA_DOOR_CLOSE - SFX_FLAG);
        }

        Math_StepToF(&this->slidingDoor.dyna.actor.velocity.y, 5.0f, 0.5f);

        if (Math_Vec3f_StepToXZ(&this->slidingDoor.dyna.actor.world.pos, &this->slidingDoor.dyna.actor.home.pos,
                                this->slidingDoor.dyna.actor.velocity.y) == 0.0f) {
            return true;
        }
    } else {
        if (this->slidingDoor.dyna.actor.velocity.y < 20.0f) {
            Math_StepToF(&this->slidingDoor.dyna.actor.velocity.y, 20.0f, 8.0f);
        }

        if (Math_StepToF(&this->slidingDoor.dyna.actor.world.pos.y, this->slidingDoor.dyna.actor.home.pos.y,
                         this->slidingDoor.dyna.actor.velocity.y)) {
            return true;
        }
    }
    return false;
}
