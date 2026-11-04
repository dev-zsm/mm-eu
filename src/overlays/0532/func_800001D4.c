// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_boat.h"

void ObjBoat_SetRotations(ObjBoat* this) {
    this->angle += 0x3E8;
    this->dyna.actor.world.pos.y = Math_SinS(this->angle) + this->dyna.actor.home.pos.y;
    this->dyna.actor.shape.rot.x = Math_SinS(this->angle) * 100.0f;
    this->dyna.actor.shape.rot.z = Math_SinS(this->angle * 2) * 50.0f;
}
