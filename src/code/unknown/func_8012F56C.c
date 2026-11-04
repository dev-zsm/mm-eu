// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_inventory.h"

void Inventory_IncrementSkullTokenCount(s16 sceneIndex) {
    if (sceneIndex == SCENE_KINSTA1) {
        
        gSaveContext.save.saveInfo.skullTokenCount =
            ((u16)(((gSaveContext.save.saveInfo.skullTokenCount & 0xFFFF0000) >> 0x10) + 1) << 0x10) |
            (gSaveContext.save.saveInfo.skullTokenCount & 0xFFFF);
    } else {
        
        gSaveContext.save.saveInfo.skullTokenCount = (((u16)gSaveContext.save.saveInfo.skullTokenCount + 1) & 0xFFFF) |
                                                     (gSaveContext.save.saveInfo.skullTokenCount & 0xFFFF0000);
    }
}
