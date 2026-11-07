// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_slime.h"

void EnSlime_IceBlock(EnSlime* this, PlayState* play) {
    if (this->iceBlockTimer == 0) {
        if ((this->actor.child == NULL) || (this->actor.child->update == NULL) ||
            !(this->actor.child->scale.y >= 0.1f)) {
            EnSlime_SetupIceBlockThaw(this);
        }
    } else {
        this->actor.colorFilterTimer = 10;
        this->iceBlockTimer = CLAMP_MIN(this->iceBlockTimer - 5, 0);
    }
}
