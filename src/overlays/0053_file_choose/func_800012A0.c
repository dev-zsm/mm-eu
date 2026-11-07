// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_file_copy_erase.h"

void FileSelect_CopyConfirm(GameState* thisx) {
    FileSelectState* this = (FileSelectState*)thisx;
    SramContext* sramCtx = &this->sramCtx;
    Input* input = CONTROLLER1(&this->state);
    u16 time;

    if (((this->buttonIndex != FS_BTN_CONFIRM_YES) && CHECK_BTN_ANY(input->press.button, BTN_A | BTN_START)) ||
        CHECK_BTN_ALL(input->press.button, BTN_B)) {
        this->actionTimer = 4;
        this->nextTitleLabel = FS_TITLE_COPY_TO;
        this->configMode = CM_RETURN_TO_COPY_DEST;
        Audio_PlaySfx(NA_SE_SY_FSEL_CLOSE);
    } else if (CHECK_BTN_ANY(input->press.button, BTN_A | BTN_START)) {
        gSaveContext.save.time = time = CURRENT_TIME; 
        this->nameAlpha[this->copyDestFileIndex] = 0;
        this->fileInfoAlpha[this->copyDestFileIndex] = this->nameAlpha[this->copyDestFileIndex];
        this->nextTitleLabel = FS_TITLE_COPY_COMPLETE;
        this->actionTimer = 4;
        Sram_CopySave(this, sramCtx);
        if (!gSaveContext.flashSaveAvailable) {
            this->configMode = CM_COPY_ANIM_1;
        } else {
            Sram_SetFlashPagesDefault(sramCtx, gFlashSaveStartPages[this->copyDestFileIndex * 2],
                                      gFlashSpecialSaveNumPages[this->copyDestFileIndex * 2]);
            Sram_StartWriteToFlashDefault(sramCtx);
            this->configMode = CM_COPY_WAIT_FOR_FLASH_SAVE;
        }
        Rumble_Request(300.0f, 180, 20, 100);
        Audio_PlaySfx(NA_SE_SY_FSEL_DECIDE_L);
    } else if (ABS_ALT(this->stickAdjY) >= 30) {
        Audio_PlaySfx(NA_SE_SY_FSEL_CURSOR);
        this->buttonIndex ^= 1;
    }
}
