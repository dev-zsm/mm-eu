// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_kakera.h"

void EffectSsKakera_CheckForObject(EffectSs* this, PlayState* play) {
    this->rObjectSlot = Object_GetSlot(&play->objectCtx, this->rObjectId);
    if ((this->rObjectSlot <= OBJECT_SLOT_NONE) || (!Object_IsLoaded(&play->objectCtx, this->rObjectSlot))) {
        this->life = 0;
        this->draw = NULL;
    }
}
