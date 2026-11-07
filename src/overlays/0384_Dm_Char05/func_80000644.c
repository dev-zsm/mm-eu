// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char05.h"

void ref_func_80AACBE4(DmChar05* this, PlayState* play) {
    static s16 sObjectIds[] = {
        OBJECT_GI_MASK17, OBJECT_GI_MASK14, OBJECT_GI_MASK10,     OBJECT_GI_MASK21,
        OBJECT_GI_MASK11, OBJECT_GI_MASK20, OBJECT_GI_RABIT_MASK, OBJECT_GI_MASK12,
    };
    s32 params = DMCHAR05_GET(&this->actor) - DMCHAR05_5;
    s32 objectSlot = Object_GetSlot(&play->objectCtx, sObjectIds[params]);

    if (objectSlot > OBJECT_SLOT_NONE) {
        this->objectSlot = objectSlot;
        this->actionFunc = ref_func_80AACD0C;
    }
}
