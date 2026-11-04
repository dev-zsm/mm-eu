// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_visfbuf.h"

void VisFbuf_DrawGeneral(VisFbuf* this, Gfx** gfxP, void* source, void* img, s32 width, s32 height) {
    if (this->scale < SCALE_MAX) {
        Gfx* gfx = *gfxP;
        u32 color;

        if (this->scale > SCALE_MIN) {
            VisFbuf_ApplyEffects(this, &gfx, source, img, width, height);
        } else {
            gDPPipeSync(gfx++);
            
            gDPSetOtherMode(gfx++,
                            G_AD_PATTERN | G_CD_MAGICSQ | G_CK_NONE | G_TC_CONV | G_TF_POINT | G_TT_NONE | G_TL_TILE |
                                G_TD_CLAMP | G_TP_NONE | G_CYC_FILL | G_PM_NPRIMITIVE,
                            G_AC_NONE | G_ZS_PIXEL | G_RM_NOOP | G_RM_NOOP2);
            color = GPACK_RGBA5551(this->primColor.r, this->primColor.g, (u32)this->primColor.b, 1);
            gDPSetFillColor(gfx++, (color << 0x10) | color);
            
            gDPFillRectangle(gfx++, 0, 0, width - 1, height - 1);

            gDPPipeSync(gfx++);
        }

        *gfxP = gfx;
    }
}
