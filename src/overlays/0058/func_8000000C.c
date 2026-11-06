// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_girla.h"

void EnGirlA_InitObjIndex(EnGirlA* this, PlayState* play) {
    s16 params = this->actor.params;

    if ((params >= SI_MAX) && (params < SI_POTION_RED_1)) {
        
        Actor_Kill(&this->actor);
        return;
    }

    this->objectSlot = Object_GetSlot(&play->objectCtx, sShopItemEntries[params].objectId);
    if (this->objectSlot <= OBJECT_SLOT_NONE) {
        Actor_Kill(&this->actor);
        return;
    }

    this->actor.params = params;
    this->mainActionFunc = EnGirlA_InitialUpdate;
}
