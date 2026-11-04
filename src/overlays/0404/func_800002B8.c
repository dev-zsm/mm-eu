// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fbdemo_wipe3.h"

void TransitionWipe3_Draw(void* thisx, Gfx** gfxP) {
    Gfx* gfx = *gfxP;
    Mtx* modelView = &((TransitionWipe3*)thisx)->modelView[((TransitionWipe3*)thisx)->frame];
    f32 scale = 14.8f;
    Gfx* texScroll;

    ((TransitionWipe3*)thisx)->frame ^= 1;
    gDPPipeSync(gfx++);
    texScroll =
        Gfx_BranchTexScroll(&gfx, ((TransitionWipe3*)thisx)->scrollX, ((TransitionWipe3*)thisx)->scrollY, 16, 64);
    gSPSegment(gfx++, 0x09, texScroll);
    gSPSegment(gfx++, 0x08, ((TransitionWipe3*)thisx)->curTexture);
    gDPSetColor(gfx++, G_SETPRIMCOLOR, ((TransitionWipe3*)thisx)->color.rgba);
    gDPSetColor(gfx++, G_SETENVCOLOR, ((TransitionWipe3*)thisx)->color.rgba);
    gSPMatrix(gfx++, &((TransitionWipe3*)thisx)->projection, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPPerspNormalize(gfx++, ((TransitionWipe3*)thisx)->normal);
    gSPMatrix(gfx++, &((TransitionWipe3*)thisx)->lookAt, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

    if (scale != 1.0f) {
        guScale(modelView, scale, scale, 1.0f);
        gSPMatrix(gfx++, modelView, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    }
    gSPDisplayList(gfx++, sTransWipe3DL);
    gDPPipeSync(gfx++);
    *gfxP = gfx;
}
