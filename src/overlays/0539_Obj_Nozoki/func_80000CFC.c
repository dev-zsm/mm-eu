// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_nozoki.h"

void ref_func_80BA311C(ObjNozoki* this, PlayState* play) {
    if (this->unk_15D == 0) {
        if (Flags_GetSwitch(play, OBJNOZOKI_GET_SWITCH_FLAG1(&this->dyna.actor))) {
            this->unk_15D = 1;
            this->unk_15E = 70;
        }
    } else if (this->unk_15D == 1) {
        if (ref_D_80BA36B8 > 40.0f) {
            this->unk_15D = 2;
            Actor_PlaySfx(&this->dyna.actor, NA_SE_PL_SIT_ON_HORSE);
        } else if (this->unk_15E != 0) {
            if (DECR(this->unk_15E) == 0) {
                Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_CONVEYOR_SHUTTER_OPEN);
            }
        } else {
            Math_StepToF(&this->dyna.actor.world.pos.y, this->dyna.actor.home.pos.y + 50.0f, 4.0f);
        }
    } else {
        Math_StepToF(&this->dyna.actor.world.pos.y, this->dyna.actor.home.pos.y, 4.0f);
    }
}
