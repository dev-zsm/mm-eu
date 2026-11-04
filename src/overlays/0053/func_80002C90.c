// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_file_copy_erase.h"

void FileSelect_EraseConfirm(GameState* thisx) {
    FileSelectState* this = (FileSelectState*)thisx;
    SramContext* sramCtx = &this->sramCtx;
    Input* input = CONTROLLER1(&this->state);

    if (((this->buttonIndex != FS_BTN_CONFIRM_YES) && CHECK_BTN_ANY(input->press.button, BTN_A | BTN_START)) ||
        CHECK_BTN_ALL(input->press.button, BTN_B)) {
        this->buttonIndex = this->selectedFileIndex;
        this->nextTitleLabel = FS_TITLE_ERASE_FILE;
        this->configMode = CM_EXIT_TO_ERASE_SELECT_1;
        this->actionTimer = 4;
        Audio_PlaySfx(NA_SE_SY_FSEL_CLOSE);
    } else if (CHECK_BTN_ANY(input->press.button, BTN_A | BTN_START)) {
        Sram_EraseSave(this, sramCtx, this->selectedFileIndex);
        if (!gSaveContext.flashSaveAvailable) {
            this->configMode = CM_ERASE_ANIM_1;
        } else {
            Sram_SetFlashPagesDefault(sramCtx, gFlashSaveStartPages[this->selectedFileIndex * 2],
                                      gFlashSpecialSaveNumPages[this->selectedFileIndex * 2]);
            Sram_StartWriteToFlashDefault(sramCtx);
            this->configMode = CM_ERASE_WAIT_FOR_FLASH_SAVE;
        }
        this->connectorAlpha[this->selectedFileIndex] = 0;
        Audio_PlaySfx(NA_SE_EV_DIAMOND_SWITCH);
        this->actionTimer = 4;
        this->nextTitleLabel = FS_TITLE_ERASE_COMPLETE;
        Rumble_Request(200.0f, 255, 20, 150);
        sEraseDelayTimer = 15;
    } else if (ABS_ALT(this->stickAdjY) >= 30) {
        Audio_PlaySfx(NA_SE_SY_FSEL_CURSOR);
        this->buttonIndex ^= 1;
    }
}
