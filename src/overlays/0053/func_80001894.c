// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_file_copy_erase.h"

void FileSelect_CopyAnim1(GameState* thisx) {
    FileSelectState* this = (FileSelectState*)thisx;

    this->titleAlpha[FS_TITLE_CUR] -= 255 / 4;
    this->confirmButtonAlpha[FS_BTN_CONFIRM_YES] -= 200 / 4;
    this->confirmButtonAlpha[FS_BTN_CONFIRM_QUIT] -= 200 / 4;
    this->actionTimer--;

    if (this->actionTimer == 0) {
        this->titleAlpha[FS_TITLE_CUR] = 0;
        this->actionTimer = 4;
        this->configMode++; 
    }
}
