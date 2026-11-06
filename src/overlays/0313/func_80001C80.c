// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_slime.h"

void EnSlime_Stun(EnSlime* this, PlayState* play) {
    this->timer--;
    if (this->timer == 0) {
        EnSlime_Thaw(this, play);
        if (this->actor.colChkInfo.health == 0) {
            EnSlime_SetupDamaged(this, play, false);
        } else {
            this->actor.world.rot.y = this->actor.shape.rot.y;
            EnSlime_SetupMoveInDirection(this);
        }
    }
}
