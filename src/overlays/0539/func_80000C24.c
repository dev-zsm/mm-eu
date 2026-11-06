// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_nozoki.h"

void ref_func_80BA3044(ObjNozoki* this, PlayState* play) {
    Vec3f* sp1C = &this->dyna.actor.focus.pos;

    if (this->unk_15D == 0) {
        if (play->actorCtx.flags & ACTORCTX_FLAG_6) {
            this->unk_15D = 1;
            this->unk_15E = 20;
            Math_Vec3f_Copy(&this->dyna.actor.world.pos, sp1C);
        } else if (!(play->actorCtx.flags & ACTORCTX_FLAG_5) &&
                   Flags_GetSwitch(play, OBJNOZOKI_GET_SWITCH_FLAG1(&this->dyna.actor))) {
            sp1C = &this->dyna.actor.home.pos;
        }
    } else if (DECR(this->unk_15E) == 0) {
        sp1C = &this->dyna.actor.home.pos;
    }

    Math_Vec3f_StepToXZ(&this->dyna.actor.world.pos, sp1C, 8.0f);
}
