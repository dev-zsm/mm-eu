// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_file_copy_erase.h"

void FileSelect_EraseAnim1(GameState* thisx) {
    static s16 ref_D_80814E80;
    FileSelectState* this = (FileSelectState*)thisx;
    SramContext* sramCtx = &this->sramCtx;

    if (sEraseDelayTimer == 0) {
        if (this->actionTimer == 4) {
            ref_D_80814E80 = 1;
        }

        if (this->actionTimer != 0) {
            this->titleAlpha[FS_TITLE_CUR] -= 255 / 4;
            this->titleAlpha[FS_TITLE_NEXT] += 255 / 4;
            this->fileInfoAlpha[this->selectedFileIndex] -= 200 / 4;
            this->confirmButtonAlpha[FS_BTN_CONFIRM_YES] -= 200 / 4;
            this->confirmButtonAlpha[FS_BTN_CONFIRM_QUIT] -= 200 / 4;
        }

        this->fileNamesY[this->selectedFileIndex] -= ref_D_80814E80;
        ref_D_80814E80 += 2;

        this->actionTimer--;
        if (this->actionTimer == 0) {
            this->configMode = CM_ERASE_ANIM_2;
            this->titleLabel = this->nextTitleLabel;
            this->titleAlpha[FS_TITLE_CUR] = 255;
            this->titleAlpha[FS_TITLE_NEXT] = this->connectorAlpha[this->selectedFileIndex] = 0;

            
            this->confirmButtonAlpha[FS_BTN_CONFIRM_YES] = this->confirmButtonAlpha[FS_BTN_CONFIRM_QUIT] = 0;
            if (1) {}
            if (0) {}
            this->fileInfoAlpha[this->selectedFileIndex] = this->nameAlpha[this->selectedFileIndex] =
                this->nameBoxAlpha[this->selectedFileIndex] = this->confirmButtonAlpha[FS_BTN_CONFIRM_QUIT];

            this->actionTimer = 45;
        }
    } else {
        sEraseDelayTimer--;

        if (sEraseDelayTimer == 0) {
            Audio_PlaySfx(NA_SE_OC_ABYSS);
        }
    }
}
