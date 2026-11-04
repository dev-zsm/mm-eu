// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokeidai.h"

s32 ObjTokeidai_IsPostFirstCycleFinalHours(ObjTokeidai* this, PlayState* play) {
    if (gSaveContext.save.saveInfo.inventory.items[SLOT_OCARINA] == ITEM_NONE) {
        return false;
    }
    if ((CURRENT_DAY == 3) && (CURRENT_TIME < CLOCK_TIME(6, 0))) {
        ObjTokeidai_SetupTowerOpening(this);
        return true;
    }
    return false;
}
