// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_shutter.h"

s32 ref_func_808A1340(DoorShutter* this, PlayState* play) {
    Vec3f sp2C;

    if (this->slidingDoor.dyna.actor.velocity.y == 0.0f) {
        ref_func_808A1288(this, play);
        if (this->unk_163 != 7) {
            Actor_PlaySfx(&this->slidingDoor.dyna.actor, NA_SE_EV_SLIDE_DOOR_OPEN);
        }
    }

    if (this->unk_163 == 7) {
        s32 pad;

        if (this->unk_163 == 7) {
            Actor_PlaySfx_Flagged(&this->slidingDoor.dyna.actor, NA_SE_EV_IKANA_DOOR_OPEN - SFX_FLAG);
        }

        Lib_Vec3f_TranslateAndRotateY(&this->slidingDoor.dyna.actor.home.pos, this->slidingDoor.dyna.actor.shape.rot.y,
                                      (this->unk_163 == 7) ? &ref_D_808A22C4 : &ref_D_808A22D0, &sp2C);
        Math_StepToF(&this->slidingDoor.dyna.actor.velocity.y, 5.0f, 0.5f);

        if (Math_Vec3f_StepToXZ(&this->slidingDoor.dyna.actor.world.pos, &sp2C,
                                this->slidingDoor.dyna.actor.velocity.y) == 0.0f) {
            return true;
        }
    } else {
        Math_StepToF(&this->slidingDoor.dyna.actor.velocity.y, 15.0f, 3.0f);

        if (Math_StepToF(&this->slidingDoor.dyna.actor.world.pos.y, this->slidingDoor.dyna.actor.home.pos.y + 200.0f,
                         this->slidingDoor.dyna.actor.velocity.y)) {
            return true;
        }
    }
    return false;
}
