// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fbdemo_fade.h"

void TransitionFade_Update(void* thisx, s32 updateRate) {
    s32 alpha;
    s16 newAlpha;
    TransitionFade* this = (TransitionFade*)thisx;

    switch (this->type) {
        case TRANS_FADE_TYPE_NONE:
            break;

        case TRANS_FADE_TYPE_ONE_WAY:
            
            ((TransitionFade*)thisx)->timer += updateRate;

            if (this->timer >= ((void)0, gSaveContext.transFadeDuration)) {
                this->timer = ((void)0, gSaveContext.transFadeDuration);
                this->isDone = true;
            }

            alpha = (255.0f * this->timer) / ((void)0, gSaveContext.transFadeDuration);
            this->color.a = (this->direction != TRANS_FADE_DIR_IN) ? 255 - alpha : alpha;
            break;

        case TRANS_FADE_TYPE_FLASH:
            newAlpha = this->color.a;
            if (R_TRANS_FADE_FLASH_ALPHA_STEP != 0) {
                if (R_TRANS_FADE_FLASH_ALPHA_STEP < 0) {
                    if (Math_StepToS(&newAlpha, 255, 255)) {
                        R_TRANS_FADE_FLASH_ALPHA_STEP = 150;
                    }
                } else {
                    Math_StepToS(&R_TRANS_FADE_FLASH_ALPHA_STEP, 20, 60);
                    if (Math_StepToS(&newAlpha, 0, R_TRANS_FADE_FLASH_ALPHA_STEP)) {
                        R_TRANS_FADE_FLASH_ALPHA_STEP = 0;
                        this->isDone = true;
                    }
                }
            }
            this->color.a = newAlpha;
            break;

        default:
            break;
    }
}
