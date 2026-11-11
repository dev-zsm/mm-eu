// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fbdemo_wipe5.h"

void TransitionWipe5_Draw(void* thisx, Gfx** gfxP) {
    Gfx* gfx = *gfxP;
    s32 width = gScreenWidth;
    s32 height = gScreenHeight;
    void* workBuffer = gWorkBuffer;
    TransitionWipe5* this = (TransitionWipe5*)thisx;
    s32 alpha = (1.0f - this->unk_0C) * 255.0f;

    gDPPipeSync(gfx++);
    gSPLoadUcodeL(gfx++, gspS2DEX2_fifo);
    if (this->unk_10 == 0) {
        gDPSetOtherMode(gfx++,
                        G_AD_PATTERN | G_CD_MAGICSQ | G_CK_NONE | G_TC_CONV | G_TF_POINT | G_TT_NONE | G_TL_TILE |
                            G_TD_CLAMP | G_TP_NONE | G_CYC_COPY | G_PM_NPRIMITIVE,
                        G_AC_NONE | G_ZS_PIXEL | G_RM_NOOP | G_RM_NOOP2);
        VisFbuf_SetBgSimple(&gfx, ref_D_0F000000, workBuffer, width, height, VIS_FBUF_BG_CYC_COPY);
    } else {
        if (alpha == 255) {
            gDPSetOtherMode(gfx++,
                            G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_POINT | G_TT_NONE | G_TL_TILE |
                                G_TD_CLAMP | G_TP_NONE | G_CYC_1CYCLE | G_PM_NPRIMITIVE,
                            G_AC_NONE | G_ZS_PRIM | G_RM_OPA_SURF | G_RM_OPA_SURF2);
        } else {
            gDPSetOtherMode(gfx++,
                            G_AD_NOISE | G_CD_NOISE | G_CK_NONE | G_TC_FILT | G_TF_POINT | G_TT_NONE | G_TL_TILE |
                                G_TD_CLAMP | G_TP_NONE | G_CYC_1CYCLE | G_PM_NPRIMITIVE,
                            G_AC_NONE | G_ZS_PRIM | G_RM_CLD_SURF | G_RM_CLD_SURF2);
        }
        gDPSetEnvColor(gfx++, 255, 255, 255, alpha);
        gDPSetCombineLERP(gfx++, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0,
                          ENVIRONMENT);
        VisFbuf_SetBgSimple(&gfx, workBuffer, ref_D_0F000000, width, height, VIS_FBUF_BG_CYC_1CYC);
    }
    gDPPipeSync(gfx++);
    gSPLoadUcode(gfx++, SysUcode_GetUCode(), SysUcode_GetUCodeData());
    *gfxP = gfx;
}
