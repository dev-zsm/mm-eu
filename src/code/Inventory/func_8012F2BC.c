// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_inventory.h"

void Inventory_SetWorldMapCloudVisibility(s16 tingleIndex) {
    s16 i = 0;
    s16 index = 0;
    u16(*tingleMapSceneIds)[] = &sSceneIdsPerTingleMap[tingleIndex];

    if ((tingleIndex >= 0) && (tingleIndex < TINGLE_MAP_MAX)) {
        while (true) {
            if ((*tingleMapSceneIds)[i] == 0xFFFF) {
                break;
            }

             
            if (((s16)(*tingleMapSceneIds)[i]) < 0x20) {
                index = 0;
            } else if (((s16)(*tingleMapSceneIds)[i]) < 0x40) {
                index = 1;
            } else if (((s16)(*tingleMapSceneIds)[i]) < 0x60) {
                index = 2;
            } else if (((s16)(*tingleMapSceneIds)[i]) < 0x80) {
                index = 3;
            } else if (((s16)(*tingleMapSceneIds)[i]) < 0xA0) {
                index = 4;
            } else if (((s16)(*tingleMapSceneIds)[i]) < 0xC0) {
                index = 5;
            } else if (((s16)(*tingleMapSceneIds)[i]) < 0xE0) {
                index = 6;
            }

            gSaveContext.save.saveInfo.scenesVisible[index] = gSaveContext.save.saveInfo.scenesVisible[index] |
                                                              gBitFlags[(s16)(*tingleMapSceneIds)[i] - (index << 5)];
            i++;
        }

        if (*tingleMapSceneIds == sSceneIdsPerTingleMap[TINGLE_MAP_CLOCK_TOWN]) {
            gSaveContext.save.saveInfo.worldMapCloudVisibility |= 3;
        } else if (*tingleMapSceneIds == sSceneIdsPerTingleMap[TINGLE_MAP_WOODFALL]) {
            gSaveContext.save.saveInfo.worldMapCloudVisibility |= 0x1C;
        } else if (*tingleMapSceneIds == sSceneIdsPerTingleMap[TINGLE_MAP_SNOWHEAD]) {
            gSaveContext.save.saveInfo.worldMapCloudVisibility |= 0xE0;
        } else if (*tingleMapSceneIds == sSceneIdsPerTingleMap[TINGLE_MAP_ROMANI_RANCH]) {
            gSaveContext.save.saveInfo.worldMapCloudVisibility |= 0x100;
        } else if (*tingleMapSceneIds == sSceneIdsPerTingleMap[TINGLE_MAP_GREAT_BAY]) {
            gSaveContext.save.saveInfo.worldMapCloudVisibility |= 0x1E00;
        } else if (*tingleMapSceneIds == sSceneIdsPerTingleMap[TINGLE_MAP_STONE_TOWER]) {
            gSaveContext.save.saveInfo.worldMapCloudVisibility |= 0x6000;
        }
    }

    R_MINIMAP_DISABLED = false;
}
