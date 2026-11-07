// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bat.h"

void EnBat_SetupPerch(EnBat* this) {
    this->collider.base.acFlags |= AC_ON;
    this->collider.base.atFlags |= AT_ON;
    this->collider.dim.worldSphere.center.x = this->actor.focus.pos.x;
    this->collider.dim.worldSphere.center.y = this->actor.focus.pos.y;
    this->collider.dim.worldSphere.center.z = this->actor.focus.pos.z;
    this->actor.speed = 0.0f;
    this->actionFunc = EnBat_Perch;
}
