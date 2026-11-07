// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_file_copy_erase.h"

void FileSelect_CopyAnim3(GameState* thisx) {
    FileSelectState* this = (FileSelectState*)thisx;
    Input* input = CONTROLLER1(&this->state);

    if (this->actionTimer == 38) {
        this->connectorAlpha[this->copyDestFileIndex] = 255;
        Audio_PlaySfx(NA_SE_EV_DIAMOND_SWITCH);
    }

    this->actionTimer--;

    if (this->actionTimer < 37) {
        if (CHECK_BTN_ANY(input->press.button, BTN_A | BTN_B | BTN_START) || (this->actionTimer == 0)) {
            this->actionTimer = 4;
            this->nextTitleLabel = FS_TITLE_SELECT_FILE;
            Audio_PlaySfx(NA_SE_SY_FSEL_DECIDE_L);
            this->configMode = CM_COPY_ANIM_4;
        }
    }
}
