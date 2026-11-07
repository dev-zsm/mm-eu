// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_WarpCsPart6(EnTest7* this, PlayState* play) {
    s32 sp2C = this->timer - 100;
    f32 envLerp;
    Color_RGB8 fogColor = { 64, 0, 0 };
    Color_RGB8 ambientColor = { 220, 220, 255 };

    if (R_PLAY_FILL_SCREEN_ON) {
        Audio_PlaySfx_AtPos(&this->actor.projectedPos, NA_SE_PL_WARP_WING_VANISH);
        R_PLAY_FILL_SCREEN_ON = false;
        R_PLAY_FILL_SCREEN_R = 0;
        R_PLAY_FILL_SCREEN_G = 0;
        R_PLAY_FILL_SCREEN_B = 0;
        R_PLAY_FILL_SCREEN_ALPHA = 0;
    }

    envLerp = 1.0f - (sp2C / (f32)(110 - 100));
    Environment_LerpAmbientColor(play, &ambientColor, envLerp);
    Environment_LerpFogColor(play, &fogColor, envLerp);
    Environment_LerpFog(play, 2000, 4000, envLerp);

    if (this->timer >= 110) {
        EnTest7_SetupAction(this, EnTest7_WarpCsWait);
    }
}
