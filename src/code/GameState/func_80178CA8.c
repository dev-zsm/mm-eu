// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/speed_meter.h"

void SpeedMeter_DrawAllocEntry(SpeedMeterAllocEntry* this, GraphicsContext* gfxCtx) {
    s32 usedOff;
    View view;
    Gfx* gfx;

    if (this->maxVal != 0) {
        OPEN_DISPS(gfxCtx);

        View_Init(&view, gfxCtx);
        view.flags = VIEW_VIEWPORT | VIEW_PROJECTION_ORTHO;

        SET_FULLSCREEN_VIEWPORT_DYNAMIC(&view);

        gfx = OVERLAY_DISP;
        View_ApplyTo(&view, &gfx);

        gDPPipeSync(gfx++);
        gDPSetOtherMode(gfx++,
                        G_AD_PATTERN | G_CD_MAGICSQ | G_CK_NONE | G_TC_CONV | G_TF_POINT | G_TT_NONE | G_TL_TILE |
                            G_TD_CLAMP | G_TP_NONE | G_CYC_FILL | G_PM_NPRIMITIVE,
                        G_AC_NONE | G_ZS_PIXEL | G_RM_NOOP | G_RM_NOOP2);

        usedOff = ((this->lrx - this->ulx) * this->val) / this->maxVal + this->ulx;
        gDrawRect(gfx++, this->backColor, usedOff, this->uly, this->lrx, this->lry);
        gDrawRect(gfx++, this->foreColor, this->ulx, this->uly, usedOff, this->lry);

        gDPPipeSync(gfx++);

        
        if (this && this && this) {}

        OVERLAY_DISP = gfx;
        CLOSE_DISPS(gfxCtx);
    }
}
