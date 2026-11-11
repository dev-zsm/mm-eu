// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft, bytes match; links once `gspS2DEX2_fifoDataStart` and the other symbols of the reference have names of ours
#include "generated/mm/z_visfbuf.h"

void VisFbuf_Draw(VisFbuf* this, Gfx** gfxP, void* img) {
    Gfx* gfx = *gfxP;

    gSPLoadUcodeL(gfx++, gspS2DEX2_fifo);

    switch (this->mode) {
        case VIS_FBUF_MODE_GENERAL:
            VisFbuf_DrawGeneral(this, &gfx, ref_D_0F000000, img, gScreenWidth, gScreenHeight);
            break;

        case VIS_FBUF_MODE_INTERPOLATE:
            VisFbuf_DrawInterpolate(this, &gfx, ref_D_0F000000, gScreenWidth, gScreenHeight);
            break;

        default:
            break;
    }

    gSPLoadUcode(gfx++, SysUcode_GetUCode(), SysUcode_GetUCodeData());

    *gfxP = gfx;
}
