// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnOsn_InitCutscene), score 3.00 (3 differ, size +3)
#include "generated/mm/z_en_osn.h"

void func_80000B68(EnOsn* this) {
    this->csId = this->actor.csId;
    if ((gSaveContext.save.saveInfo.inventory.items[SLOT_OCARINA] == ITEM_NONE) ||
        (INV_CONTENT(ITEM_MASK_DEKU) == ITEM_MASK_DEKU)) {
        this->csId = CutsceneManager_GetAdditionalCsId(this->csId);

        if ((gSaveContext.save.saveInfo.inventory.items[SLOT_OCARINA] != ITEM_NONE) ||
            (INV_CONTENT(ITEM_MASK_DEKU) == ITEM_MASK_DEKU)) {
            this->csId = CutsceneManager_GetAdditionalCsId(this->csId);
        }
    }
}
