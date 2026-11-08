// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fbdemo_wipe3.h"

void TransitionWipe3_Start(void* thisx) {
    TransitionWipe3* this = (TransitionWipe3*)thisx;

    this->isDone = false;
    this->curTexture = sTransWipe3Textures[this->texIndex % ARRAY_COUNTU(sTransWipe3Textures)];
    if (this->speedType == TRANS_WIPE3_SPEED_SLOW) {
        this->wipeSpeed = 20;
    } else {
        this->wipeSpeed = 10;
    }
    if (this->colorType == TRANS_WIPE3_COLOR_BLACK) {
        this->color.rgba = RGBA8(0, 0, 0, 255);
    } else if (this->colorType == TRANS_WIPE3_COLOR_WHITE) {
        this->color.rgba = RGBA8(255, 255, 255, 255);
    } else {
        this->color.rgba = RGBA8(160, 160, 160, 255);
    }
    if (this->dir != TRANS_WIPE3_DIR_IN) {
        this->scrollY = 0;
    } else {
        this->scrollY = 500;
        if (this->texIndex == 2) {
            Audio_PlaySfx_2(NA_SE_OC_SECRET_WARP_OUT);
        }
    }
    guPerspective(&this->projection, &this->normal, 60.0f, 4.0f / 3.0f, 10.0f, 12800.0f, 1.0f);
    guLookAt(&this->lookAt, 0.0f, 0.0f, 400.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
}
