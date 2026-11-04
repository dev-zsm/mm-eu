// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_file_copy_erase.h"

void FileSelect_CopyAnim4(GameState* thisx) {
    FileSelectState* this = (FileSelectState*)thisx;

    this->fileInfoAlpha[this->selectedFileIndex] -= 200 / 4;
    this->fileInfoAlpha[this->copyDestFileIndex] -= 200 / 4;
    this->nameBoxAlpha[this->selectedFileIndex] += 200 / 4;
    this->nameBoxAlpha[this->copyDestFileIndex] += 200 / 4;
    this->titleAlpha[FS_TITLE_CUR] -= 255 / 4;
    this->actionTimer--;

    if (this->actionTimer == 0) {
        this->fileNamesY[this->copyDestFileIndex] = this->buttonYOffsets[3] = 0;
        this->actionTimer = 4;
        this->titleAlpha[FS_TITLE_CUR] = 0;
        this->configMode++;
    }
}
