// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_gamelupy.h"

void EnGamelupy_Idle(EnGamelupy* this, PlayState* play) {
    if (this->collider.base.ocFlags1 & OC1_HIT) {
        *this->minigameScore += ENGAMELUPY_POINTS;
        if (this->type == ENGAMELUPY_TYPE_BLUE) {
            Rupees_ChangeBy(5);
        } else {
            Rupees_ChangeBy(1);
        }
        EnGamelupy_SetupCollected(this);
    }
    this->actor.shape.rot.y += 0x1F4;
}
