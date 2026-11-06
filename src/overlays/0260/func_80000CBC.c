// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_grass_carry.h"

void ObjGrassCarry_Update(Actor* thisx, PlayState* play) {
    ObjGrassCarry* this = (ObjGrassCarry*)thisx;

    if (this->grassManager == NULL) {
        if ((this->actionFunc != ObjGrassCarry_LiftedUp) && (this->actionFunc != ObjGrassCarry_Fall)) {
            Actor_Kill(&this->actor);
            return;
        }
    }

    this->actionFunc(this, play);
}
