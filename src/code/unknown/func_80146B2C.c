// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_sram_NES.h"

void Sram_CopySave(FileSelectState* fileSelect2, SramContext* sramCtx) {
    FileSelectState* fileSelect = fileSelect2;
    u16 i;
    s16 maskCount;

    if (gSaveContext.flashSaveAvailable) {
        if (fileSelect->isOwlSave[fileSelect->selectedFileIndex + 2]) {
            ref_func_80147414(sramCtx, fileSelect->selectedFileIndex, fileSelect->copyDestFileIndex);
            fileSelect->threeDayResetCount[fileSelect->copyDestFileIndex + 2] =
                gSaveContext.save.saveInfo.playerData.threeDayResetCount;

            for (i = 0; i < ARRAY_COUNT(gSaveContext.save.saveInfo.playerData.playerName); i++) {
                fileSelect->fileNames[fileSelect->copyDestFileIndex + 2][i] =
                    gSaveContext.save.saveInfo.playerData.playerName[i];
            }

            fileSelect->healthCapacity[fileSelect->copyDestFileIndex + 2] =
                gSaveContext.save.saveInfo.playerData.healthCapacity;
            fileSelect->health[fileSelect->copyDestFileIndex + 2] = gSaveContext.save.saveInfo.playerData.health;
            fileSelect->defenseHearts[fileSelect->copyDestFileIndex + 2] =
                gSaveContext.save.saveInfo.inventory.defenseHearts;
            fileSelect->questItems[fileSelect->copyDestFileIndex + 2] = gSaveContext.save.saveInfo.inventory.questItems;
            fileSelect->time[fileSelect->copyDestFileIndex + 2] = CURRENT_TIME;
            fileSelect->day[fileSelect->copyDestFileIndex + 2] = gSaveContext.save.day;
            fileSelect->isOwlSave[fileSelect->copyDestFileIndex + 2] = gSaveContext.save.isOwlSave;
            fileSelect->rupees[fileSelect->copyDestFileIndex + 2] = gSaveContext.save.saveInfo.playerData.rupees;
            fileSelect->walletUpgrades[fileSelect->copyDestFileIndex + 2] = CUR_UPG_VALUE(UPG_WALLET);

            for (i = 0, maskCount = 0; i < MASK_NUM_SLOTS; i++) {
                if (gSaveContext.save.saveInfo.inventory.items[i + ITEM_NUM_SLOTS] != ITEM_NONE) {
                    maskCount++;
                }
            }

            fileSelect->maskCount[fileSelect->copyDestFileIndex + 2] = maskCount;
            fileSelect->heartPieceCount[fileSelect->copyDestFileIndex + 2] = GET_QUEST_HEART_PIECE_COUNT;
        }

        
        bzero(sramCtx->saveBuf, SAVE_BUFFER_SIZE);
        
        if (SysFlashrom_Read(&sramCtx->saveBuf[0], gFlashSaveStartPages[fileSelect->selectedFileIndex * 2],
                             gFlashSaveNumPages[fileSelect->selectedFileIndex * 2])) {}

        if (SysFlashrom_Read(&sramCtx->saveBuf[0x2000], gFlashSaveStartPages[fileSelect->selectedFileIndex * 2 + 1],
                             gFlashSaveNumPages[fileSelect->selectedFileIndex * 2 + 1])) {}

        
        Lib_MemCpy(&gSaveContext.save, sramCtx->saveBuf, sizeof(Save));

        fileSelect->threeDayResetCount[fileSelect->copyDestFileIndex] =
            gSaveContext.save.saveInfo.playerData.threeDayResetCount;

        for (i = 0; i < ARRAY_COUNT(gSaveContext.save.saveInfo.playerData.playerName); i++) {
            fileSelect->fileNames[fileSelect->copyDestFileIndex][i] =
                gSaveContext.save.saveInfo.playerData.playerName[i];
        }

        fileSelect->healthCapacity[fileSelect->copyDestFileIndex] =
            gSaveContext.save.saveInfo.playerData.healthCapacity;
        fileSelect->health[fileSelect->copyDestFileIndex] = gSaveContext.save.saveInfo.playerData.health;
        fileSelect->defenseHearts[fileSelect->copyDestFileIndex] = gSaveContext.save.saveInfo.inventory.defenseHearts;
        fileSelect->questItems[fileSelect->copyDestFileIndex] = gSaveContext.save.saveInfo.inventory.questItems;
        fileSelect->time[fileSelect->copyDestFileIndex] = CURRENT_TIME;
        fileSelect->day[fileSelect->copyDestFileIndex] = gSaveContext.save.day;
        fileSelect->isOwlSave[fileSelect->copyDestFileIndex] = gSaveContext.save.isOwlSave;
        fileSelect->rupees[fileSelect->copyDestFileIndex] = gSaveContext.save.saveInfo.playerData.rupees;
        fileSelect->walletUpgrades[fileSelect->copyDestFileIndex] = CUR_UPG_VALUE(UPG_WALLET);

        for (i = 0, maskCount = 0; i < MASK_NUM_SLOTS; i++) {
            if (gSaveContext.save.saveInfo.inventory.items[i + ITEM_NUM_SLOTS] != ITEM_NONE) {
                maskCount++;
            }
        }

        fileSelect->maskCount[fileSelect->copyDestFileIndex] = maskCount;
        fileSelect->heartPieceCount[fileSelect->copyDestFileIndex] = GET_QUEST_HEART_PIECE_COUNT;
    }

    gSaveContext.save.time = ref_D_801F6AF0;
    gSaveContext.flashSaveAvailable = ref_D_801F6AF2;
}
