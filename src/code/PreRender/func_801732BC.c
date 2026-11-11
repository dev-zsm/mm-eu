// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/PreRender.h"

void Prerender_DrawBackground2DImpl(PreRenderBackground2DParams* bg2D, Gfx** gfxP) {
    Gfx* gfx;
    uObjBg* bg;
    u32 alphaCompare;
    Gfx* gfxTemp;
    u32 loadS2DEX2;

    loadS2DEX2 = (bg2D->flags & BG2D_FLAGS_LOAD_S2DEX2) != 0;
    alphaCompare = (bg2D->flags & BG2D_FLAGS_AC_THRESHOLD) ? G_AC_THRESHOLD : G_AC_NONE;

    gfxTemp = *gfxP;
    bg = Gfx_Alloc(&gfxTemp, sizeof(uObjBg));
    gfx = gfxTemp;

    bg->b.imageX = 0;
    bg->b.imageW = (bg2D->width * (1 << 2)) + 1;
    bg->b.frameX = bg2D->x * (1 << 2);

    bg->b.imageY = 0;
    bg->b.imageH = (bg2D->height * (1 << 2)) + 1;
    bg->b.frameY = bg2D->y * (1 << 2);

    bg->b.imagePtr = bg2D->timg;
    bg->b.imageLoad = G_BGLT_LOADTILE;
    bg->b.imageFmt = bg2D->fmt;
    bg->b.imageSiz = bg2D->siz;
    bg->b.imagePal = 0;
    bg->b.imageFlip = 0;

    if (loadS2DEX2) {
        gSPLoadUcodeL(gfx++, gspS2DEX2_fifo);
    }

    if ((bg2D->fmt == G_IM_FMT_CI) && (bg2D->tlut != NULL)) {
        gDPLoadTLUT(gfx++, bg2D->tlutCount, 256, bg2D->tlut);
    } else {
        gDPPipeSync(gfx++);
    }

    if (bg2D->flags & BG2D_FLAGS_COPY) {
        bg->b.frameW = bg2D->width * (1 << 2);
        bg->b.frameH = bg2D->height * (1 << 2);

        guS2DInitBg(bg);

        if (!(bg2D->flags & BG2D_FLAGS_1)) {
            gDPSetOtherMode(gfx++, bg2D->tt | G_CYC_COPY, alphaCompare);
        }

        gSPBgRectCopy(gfx++, bg);
    } else {
        bg->b.frameW = (u32)(bg2D->width * (1 << 2)) * bg2D->xScale;
        bg->b.frameH = (u32)(bg2D->height * (1 << 2)) * bg2D->yScale;
        bg->b.tmemW = (1 << 10) / bg2D->xScale;
        bg->b.tmemH = (1 << 10) / bg2D->yScale;
        bg->s.imageYorig = bg->b.imageY;

        if (!(bg2D->flags & BG2D_FLAGS_1)) {
            gDPSetOtherMode(gfx++, bg2D->tt | G_AD_DISABLE | G_CD_DISABLE | G_TC_FILT,
                            AA_EN | CVG_X_ALPHA | ALPHA_CVG_SEL |
                                GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_BL, G_BL_1MA) |
                                GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_BL, G_BL_1MA) | alphaCompare);
        }

        if (!(bg2D->flags & BG2D_FLAGS_2)) {
            gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, 0, 0, 0, 1, 0, 0, 0, TEXEL0, 0, 0, 0, 1);
        }

        gSPObjRenderMode(gfx++, G_OBJRM_ANTIALIAS | G_OBJRM_BILERP);
        gSPBgRect1Cyc(gfx++, bg);
    }

    gDPPipeSync(gfx++);

    if (loadS2DEX2) {
        gSPLoadUcode(gfx++, SysUcode_GetUCode(), SysUcode_GetUCodeData());
    }

    *gfxP = gfx;
}
