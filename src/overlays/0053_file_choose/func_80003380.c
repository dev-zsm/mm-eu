// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_file_copy_erase.h"

void FileSelect_EraseWaitForFlashSave(GameState* thisx) {
    FileSelectState* this = (FileSelectState*)thisx;
    SramContext* sramCtx = &this->sramCtx;
    u16 i;

    Sram_UpdateWriteToFlashDefault(sramCtx);

    if (sramCtx->status == 0) {
        this->configMode = CM_ERASE_ANIM_1;
        for (i = 0; i < 6; i++) {
            this->newf[this->selectedFileIndex][i] = gSaveContext.save.saveInfo.playerData.newf[i];
        }
    }
}
