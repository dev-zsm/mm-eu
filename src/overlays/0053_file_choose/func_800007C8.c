// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_file_copy_erase.h"

void FileSelect_SetupCopyDest2(GameState* thisx) {
    FileSelectState* this = (FileSelectState*)thisx;

    this->nameBoxAlpha[this->buttonIndex] -= 200 / 4;
    this->fileInfoAlpha[this->buttonIndex] += 200 / 4;
    this->actionTimer--;

    if (this->actionTimer == 0) {
        this->nameBoxAlpha[this->buttonIndex] = 0;
        this->fileInfoAlpha[this->buttonIndex] = 200;
        this->buttonIndex = FS_BTN_COPY_QUIT;
        this->actionTimer = 4;
        this->configMode = CM_SELECT_COPY_DEST;
    }
}
