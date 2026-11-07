// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

void EnFall_Fireball_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    EnFall* this = (EnFall*)thisx;
    u32 gameplayFrames = play->gameplayFrames;

    OPEN_DISPS(play->state.gfxCtx);

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    this->fireballYTexScroll1 += (s32)(4.0f + (this->fireballIntensity * 12.0f));
    this->fireballYTexScroll2 += (s32)(2.0f + (this->fireballIntensity * 6.0f));

    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80,
                    (s32)(((1.0f - this->fireballIntensity) * 160.0f) + (255.0f * this->fireballIntensity)),
                    (s32)((70.0f * (1.0f - this->fireballIntensity)) + (255.0f * this->fireballIntensity)),
                    (s32)(70.0f * (1.0f - this->fireballIntensity)), 255);
    gDPSetEnvColor(
        POLY_XLU_DISP++, (s32)(((1.0f - this->fireballIntensity) * 50.0f) + (200.0f * this->fireballIntensity)),
        (s32)(20.0f * (1.0f - this->fireballIntensity)), (s32)(20.0f * (1.0f - this->fireballIntensity)), 255);

    
    gSPSegment(POLY_XLU_DISP++, 0x09,
               Gfx_TwoTexScroll(play->state.gfxCtx, 0, gameplayFrames, -this->fireballYTexScroll2, 64, 64, 1,
                                -gameplayFrames, -this->fireballYTexScroll1, 64, 64));

    
    gSPSegment(POLY_XLU_DISP++, 0x0A,
               Gfx_TwoTexScroll(play->state.gfxCtx, 0, gameplayFrames * 2, -this->fireballYTexScroll1, 64, 64, 1,
                                -gameplayFrames * 2, -this->fireballYTexScroll1, 64, 64));

    gDPSetColorDither(POLY_XLU_DISP++, G_CD_NOISE);
    gDPSetAlphaDither(POLY_XLU_DISP++, G_AD_NOISE);
    gSPDisplayList(POLY_XLU_DISP++, gMoonFireballDL);

    CLOSE_DISPS(play->state.gfxCtx);
}
