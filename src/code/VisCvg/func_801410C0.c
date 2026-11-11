// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_viscvg.h"

void VisCvg_Draw(VisCvg* this, Gfx** gfxP) {
    Gfx* gfx = *gfxP;

    gDPPipeSync(gfx++);
    gDPSetPrimDepth(gfx++, -1, -1);

    if (this->vis.scissorType == VIS_SETSCISSOR) {
        gSPDisplayList(gfx++, ref_D_0E000000.setScissor);
    }

    switch (this->vis.type) {
        case VIS_CVG_TYPE_CVG_RGB:
            gSPDisplayList(gfx++, sCoverageRGBDL);
            break;

        case VIS_CVG_TYPE_CVG_RGB_UNIFORM:
            gDPSetColor(gfx++, G_SETPRIMCOLOR, this->vis.primColor.rgba);
            gSPDisplayList(gfx++, sCoverageRGBUniformDL);
            break;

        case VIS_CVG_TYPE_CVG_ONLY:
            gDPSetColor(gfx++, G_SETBLENDCOLOR, this->vis.primColor.rgba);
            gSPDisplayList(gfx++, sCoverageOnlyDL);
            break;

        case VIS_CVG_TYPE_CVG_RGB_FOG:
            gDPSetColor(gfx++, G_SETFOGCOLOR, this->vis.primColor.rgba);
            gSPDisplayList(gfx++, sCoverageRGBFogDL);
            break;

        default:
            break;
    }

    gDPPipeSync(gfx++);
    *gfxP = gfx;
}
