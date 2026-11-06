// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lift.h"

void ref_func_8093DB90(ObjLift* this, PlayState* play) {
    if (this->timer <= 0) {
        Math_Vec3f_Copy(&this->dyna.actor.world.pos, &this->dyna.actor.home.pos);
        this->dyna.actor.world.rot = this->dyna.actor.shape.rot = this->dyna.actor.home.rot;
        DynaPoly_EnableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
        ref_func_8093D760(this);
    }
}
