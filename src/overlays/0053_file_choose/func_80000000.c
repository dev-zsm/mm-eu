// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_file_copy_erase.h"

void FileSelect_SetupCopySource(GameState* thisx) {
    FileSelectState* this = (FileSelectState*)thisx;
    s32 yStep;
    s16 i;

    for (i = 0; i < 5; i++) {
        yStep = ABS_ALT(this->buttonYOffsets[i] - sChooseFileYOffsets[i]) / this->actionTimer;

        if (this->buttonYOffsets[i] >= sChooseFileYOffsets[i]) {
            this->buttonYOffsets[i] -= yStep;
        } else {
            this->buttonYOffsets[i] += yStep;
        }
    }

    this->actionButtonAlpha[FS_BTN_ACTION_COPY] -= 200 / 4;
    this->actionButtonAlpha[FS_BTN_ACTION_ERASE] -= 200 / 4;
    this->optionButtonAlpha -= 200 / 4;
    this->confirmButtonAlpha[FS_BTN_CONFIRM_QUIT] += 200 / 4;
    this->titleAlpha[FS_TITLE_CUR] -= 255 / 4;
    this->titleAlpha[FS_TITLE_NEXT] += 255 / 4;
    this->actionTimer--;

    if (this->actionTimer == 0) {
        this->actionTimer = 4;

        this->actionButtonAlpha[FS_BTN_ACTION_COPY] = this->actionButtonAlpha[FS_BTN_ACTION_ERASE] =
            this->optionButtonAlpha = 0;

        this->confirmButtonAlpha[FS_BTN_CONFIRM_QUIT] = 200;
        this->titleLabel = this->nextTitleLabel;

        this->titleAlpha[FS_TITLE_CUR] = 255;
        this->titleAlpha[FS_TITLE_NEXT] = 0;
        this->buttonIndex = FS_BTN_COPY_QUIT;
        this->configMode++; 
    }
}
