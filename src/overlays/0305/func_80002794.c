// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A25824(ObjIceblock* this) {
    this->actionFunc = ref_func_80A2586C;
    this->stateTimer = 2;
    Actor_SetScale(&this->dyna.actor, 0.01f);
    ref_func_80A2319C(this, this->dyna.actor.scale.x);
}
