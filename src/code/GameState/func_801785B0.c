// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/speed_meter.h"

void SpeedMeter_DrawTimeEntries(SpeedMeter* this, GraphicsContext* gfxCtx) {
    s32 pad[3];
    u32 baseX = 32;
    s32 width;
    s32 uly;
    s32 lry;
    s32 pad3;
    View view;
    s32 pad2[2];
    s32 i;
    Gfx* gfx;

    uly = this->y;
    lry = this->y + 2;

    OPEN_DISPS(gfxCtx);

     
    if (gIrqMgrRetraceTime == 0) {
        return;
    }

    sSpeedMeterTimeEntryPtr = &sSpeedMeterTimeEntryArray[0];
    for (i = 0; i < ARRAY_COUNT(sSpeedMeterTimeEntryArray); i++) {
        width = ((f64)*sSpeedMeterTimeEntryPtr->time / gIrqMgrRetraceTime) * 64.0;
        sSpeedMeterTimeEntryPtr->x = baseX + width;
        sSpeedMeterTimeEntryPtr++;
    }

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

    gDrawRect(gfx++, GPACK_RGBA5551(0, 0, 255, 1), baseX + 64 * 0, uly, baseX + 64 * 1, lry);
    gDrawRect(gfx++, GPACK_RGBA5551(0, 255, 0, 1), baseX + 64 * 1, uly, baseX + 64 * 2, lry);
    gDrawRect(gfx++, GPACK_RGBA5551(255, 0, 0, 1), baseX + 64 * 2, uly, baseX + 64 * 3, lry);
    gDrawRect(gfx++, GPACK_RGBA5551(255, 0, 255, 1), baseX + 64 * 3, uly, baseX + 64 * 4, lry);

    sSpeedMeterTimeEntryPtr = &sSpeedMeterTimeEntryArray[0];
    for (i = 0; i < ARRAY_COUNT(sSpeedMeterTimeEntryArray); i++) {
        gDrawRect(gfx++, sSpeedMeterTimeEntryPtr->color, baseX, lry + sSpeedMeterTimeEntryPtr->y,
                  sSpeedMeterTimeEntryPtr->x, lry + sSpeedMeterTimeEntryPtr->y + 1);
        sSpeedMeterTimeEntryPtr++;
    }
    gDPPipeSync(gfx++);

    OVERLAY_DISP = gfx;

    CLOSE_DISPS(gfxCtx);
}
