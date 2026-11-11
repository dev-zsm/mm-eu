// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fbdemo_fade.h"

void TransitionFade_Draw(void* thisx, Gfx** gfxP) {
    TransitionFade* this = (TransitionFade*)thisx;
    Gfx* gfx;
    Color_RGBA8_u32* color = &this->color;

    if (color->a != 0) {
        gfx = *gfxP;
        gSPDisplayList(gfx++, sTransFadeSetupDL);
        gDPSetPrimColor(gfx++, 0, 0, color->r, color->g, color->b, color->a);
        gSPDisplayList(gfx++, ref_D_0E000000.fillRect);
        *gfxP = gfx;
    }
}
