// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_skateblock.h"

void ref_func_80A21CD8(ObjSkateblock* this) {
    this->dyna.actor.velocity.y += this->dyna.actor.gravity;
    if (this->dyna.actor.velocity.y < this->dyna.actor.terminalVelocity) {
        this->dyna.actor.velocity.y = this->dyna.actor.terminalVelocity;
    }
    this->dyna.actor.world.pos.y += this->dyna.actor.velocity.y;
}
