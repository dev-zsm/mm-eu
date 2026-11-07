// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test6.h"

void EnTest6_EnableWhiteFillScreen(PlayState* play, f32 alphaRatio) {
    play->envCtx.fillScreen = true;
    play->envCtx.screenFillColor[0] = 250;
    play->envCtx.screenFillColor[1] = 250;
    play->envCtx.screenFillColor[2] = 250;
    play->envCtx.screenFillColor[3] = 255.0f * alphaRatio;
}
