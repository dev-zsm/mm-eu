// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_oceff_wipe4.h"

void OceffWipe4_Update(Actor* thisx, PlayState* play) {
    OceffWipe4* this = (OceffWipe4*)thisx;

    this->actor.world.pos = GET_ACTIVE_CAM(play)->eye;
    if (this->counter < 50) {
        this->counter++;
    } else {
        Actor_Kill(&this->actor);
    }
}
