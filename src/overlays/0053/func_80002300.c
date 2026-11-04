// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_file_copy_erase.h"

void FileSelect_EraseSelect(GameState* thisx) {
    FileSelectState* this = (FileSelectState*)thisx;
    SramContext* sramCtx = &this->sramCtx;
    Input* input = CONTROLLER1(&this->state);

    if (((this->buttonIndex == FS_BTN_COPY_QUIT) && CHECK_BTN_ANY(input->press.button, BTN_A | BTN_START)) ||
        CHECK_BTN_ALL(input->press.button, BTN_B)) {
        this->buttonIndex = FS_BTN_MAIN_ERASE;
        this->actionTimer = 4;
        this->nextTitleLabel = FS_TITLE_SELECT_FILE;
        this->configMode = CM_EXIT_ERASE_TO_MAIN;
        this->warningLabel = FS_WARNING_NONE;
        Audio_PlaySfx(NA_SE_SY_FSEL_CLOSE);
    } else if (CHECK_BTN_ANY(input->press.button, BTN_A | BTN_START)) {

        if (!gSaveContext.flashSaveAvailable) {
            if (NO_FLASH_SLOT_OCCUPIED(sramCtx, this->buttonIndex)) {
                this->actionTimer = 4;
                this->selectedFileIndex = this->buttonIndex;
                this->configMode = CM_SETUP_ERASE_CONFIRM_1;
                this->nextTitleLabel = FS_TITLE_ERASE_CONFIRM;
                Audio_PlaySfx(NA_SE_SY_FSEL_DECIDE_L);
            } else {
                Audio_PlaySfx(NA_SE_SY_FSEL_ERROR);
            }
        } else if (SLOT_OCCUPIED(this, this->buttonIndex)) {
            this->actionTimer = 4;
            this->selectedFileIndex = this->buttonIndex;
            this->configMode = CM_SETUP_ERASE_CONFIRM_1;
            this->nextTitleLabel = FS_TITLE_ERASE_CONFIRM;
            Audio_PlaySfx(NA_SE_SY_FSEL_DECIDE_L);
        } else {
            Audio_PlaySfx(NA_SE_SY_FSEL_ERROR);
        }
    } else {
        if (ABS_ALT(this->stickAdjY) >= 30) {
            Audio_PlaySfx(NA_SE_SY_FSEL_CURSOR);

            if (this->stickAdjY >= 30) {
                this->buttonIndex--;
                if (this->buttonIndex == FS_BTN_ERASE_FILE_3) {
                    this->buttonIndex = FS_BTN_ERASE_FILE_2;
                }
                if (this->buttonIndex < FS_BTN_ERASE_FILE_1) {
                    this->buttonIndex = FS_BTN_ERASE_QUIT;
                }
            } else {
                this->buttonIndex++;
                if (this->buttonIndex == FS_BTN_ERASE_FILE_3) {
                    this->buttonIndex = FS_BTN_ERASE_QUIT;
                }
                if (this->buttonIndex > FS_BTN_ERASE_QUIT) {
                    this->buttonIndex = FS_BTN_ERASE_FILE_1;
                }
            }
        }

        if (this->buttonIndex != FS_BTN_ERASE_QUIT) {
            if (!gSaveContext.flashSaveAvailable) {
                if (!NO_FLASH_SLOT_OCCUPIED(sramCtx, this->buttonIndex)) {
                    this->warningLabel = FS_WARNING_FILE_EMPTY;
                    this->warningButtonIndex = this->buttonIndex;
                    this->emptyFileTextAlpha = 255;
                } else {
                    this->warningLabel = FS_WARNING_NONE;
                }
            } else if (!SLOT_OCCUPIED(this, this->buttonIndex)) {
                this->warningLabel = FS_WARNING_FILE_EMPTY;
                this->warningButtonIndex = this->buttonIndex;
                this->emptyFileTextAlpha = 255;
            } else {
                this->warningLabel = FS_WARNING_NONE;
            }
        } else {
            this->warningLabel = FS_WARNING_NONE;
        }
    }
}
