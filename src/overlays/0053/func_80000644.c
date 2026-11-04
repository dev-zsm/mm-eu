// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_file_copy_erase.h"

void FileSelect_SetupCopyDest1(GameState* thisx) {
    FileSelectState* this = (FileSelectState*)thisx;
    s32 yStep;
    s16 i;

    for (i = 0; i < 3; i++) {
        yStep = ABS_ALT(this->buttonYOffsets[i] - ref_D_8081424C[this->buttonIndex][i]) / this->actionTimer;

        if (ref_D_8081424C[this->buttonIndex][i] >= this->buttonYOffsets[i]) {
            this->buttonYOffsets[i] += yStep;
        } else {
            this->buttonYOffsets[i] -= yStep;
        }
    }

    this->titleAlpha[FS_TITLE_CUR] -= 255 / 4;
    this->titleAlpha[FS_TITLE_NEXT] += 255 / 4;
    this->nameBoxAlpha[this->buttonIndex] -= 200 / 4;

    this->actionTimer--;
    if (this->actionTimer == 0) {
        this->buttonYOffsets[this->buttonIndex] = ref_D_8081424C[this->buttonIndex][this->buttonIndex];
        this->titleLabel = this->nextTitleLabel;
        this->titleAlpha[FS_TITLE_CUR] = 255;
        this->titleAlpha[FS_TITLE_NEXT] = 0;
        this->actionTimer = 4;
        this->configMode++; 
    }
}
