// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_file_copy_erase.h"

void FileSelect_SetupEraseConfirm2(GameState* thisx) {
    FileSelectState* this = (FileSelectState*)thisx;

    this->confirmButtonAlpha[FS_BTN_CONFIRM_YES] += 200 / 4;
    this->titleAlpha[FS_TITLE_CUR] -= 255 / 8;
    this->titleAlpha[FS_TITLE_NEXT] += 255 / 8;
    this->fileInfoAlpha[this->buttonIndex] += 200 / 4;
    this->actionTimer--;

    if (this->actionTimer == 0) {
        this->actionTimer = 4;
        this->titleLabel = this->nextTitleLabel;
        this->fileInfoAlpha[this->buttonIndex] = this->titleAlpha[FS_TITLE_CUR] = 255;
        this->titleAlpha[FS_TITLE_NEXT] = 0;
        this->confirmButtonAlpha[FS_BTN_CONFIRM_YES] = 200;
        this->buttonIndex = FS_BTN_CONFIRM_QUIT;
        this->configMode = CM_ERASE_CONFIRM;
    }
}
