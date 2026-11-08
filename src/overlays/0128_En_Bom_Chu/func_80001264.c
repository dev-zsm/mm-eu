// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bom_chu.h"

void EnBomChu_Draw(Actor* thisx, PlayState* play) {
    EnBomChu* this = (EnBomChu*)thisx;
    f32 colorIntensity;
    s32 blinkHalfPeriod;
    s32 blinkTime;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    ref_func_800B8050(&this->actor, play, 0);

    if (this->timer >= 40) {
        blinkTime = this->timer % 20;
        blinkHalfPeriod = 10;
    } else if (this->timer >= 10) {
        blinkTime = this->timer % 10;
        blinkHalfPeriod = 5;
    } else {
        blinkTime = this->timer & 1;
        blinkHalfPeriod = 1;
    }

    if (blinkTime > blinkHalfPeriod) {
        blinkTime = 2 * blinkHalfPeriod - blinkTime;
    }

    colorIntensity = blinkTime / (f32)blinkHalfPeriod;
    gDPSetEnvColor(POLY_OPA_DISP++, (s32)(colorIntensity * 209.0f) + 9, (s32)(colorIntensity * 34.0f) + 9,
                   (s32)(colorIntensity * -35.0f) + 35, 255);
    Matrix_Translate(this->visualJitter * (1.0f / BOMBCHU_SCALE), 0.0f, 0.0f, MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, gBombchuDL);

    CLOSE_DISPS(play->state.gfxCtx);
}
