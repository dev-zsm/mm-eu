// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_en_ice_block.h"

u32 EffectEnIceBlock_CheckIceBlockObject(EffectSs* this, PlayState* play) {
    if (((this->rObjectSlot = Object_GetSlot(&play->objectCtx, OBJECT_ICE_BLOCK)) <= OBJECT_SLOT_NONE) ||
        (!Object_IsLoaded(&play->objectCtx, this->rObjectSlot))) {
        this->life = -1;
        this->draw = NULL;
        return false;
    } else {
        return true;
    }
}
