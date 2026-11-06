// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_nozoki.h"

void ref_func_80BA2AB4(ObjNozoki* this, PlayState* play) {
    this->dyna.actor.velocity.y = 30.0f;

    if (Math_StepToF(&this->dyna.actor.world.pos.y, this->dyna.actor.home.pos.y, 30.0f) && (ref_D_80BA36B0 == 0)) {
        ObjNozoki_SetupAction(this, ref_func_80BA27C4);
        ref_D_80BA36B0 = 1;
    }

    if (!(play->actorCtx.flags & ACTORCTX_FLAG_5)) {
        if (!(OBJNOZOKI_GET_200(&this->dyna.actor)) &&
            Flags_GetSwitch(play, OBJNOZOKI_GET_SWITCH_FLAG1(&this->dyna.actor))) {
            ref_func_80BA2790(this);
        }
    }
}
