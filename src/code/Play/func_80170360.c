// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_play_hireso.h"

void BombersNotebook_Draw(BombersNotebook* this, GraphicsContext* gfxCtx) {
    Gfx* gfx;
    s32 pad[2];

    ref_func_8012CF0C(gfxCtx, this->loadState != BOMBERS_NOTEBOOK_LOAD_STATE_DONE, false, 0, 0, 0);

    OPEN_DISPS(gfxCtx);

    gfx = POLY_OPA_DISP;

    if (this->loadState == BOMBERS_NOTEBOOK_LOAD_STATE_DONE) {
        gSPSegment(gfx++, 0x07, this->scheduleDmaSegment);
        gSPSegment(gfx++, 0x08, this->scheduleSegment);
        gfx = Gfx_SetupDL39(gfx);
        gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE,
                          ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetRenderMode(gfx++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 215, 255);
        gDPSetEnvColor(gfx++, 100, 100, 100, 255);
        gDPLoadTextureBlock(gfx++, gBombersNotebookBackgroundTex, G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

        BombersNotebook_DrawScisTexRect(&gfx, 0 * 4, 0 * 4, SCREEN_WIDTH_HIRES * 4, SCREEN_HEIGHT_HIRES * 4, 0, 0, 0,
                                        0x200, 0x200);

        gDPPipeSync(gfx++);
        gDPSetCombineMode(gfx++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

        BombersNotebook_DrawHeaders(&gfx);
        BombersNotebook_DrawColumns(&gfx);

        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 86, 600, 450);
        BombersNotebook_DrawRows(this, &gfx);

        gDPPipeSync(gfx++);
        gSPDisplayList(gfx++, ref_D_0E000000.setScissor);

        BombersNotebook_DrawTimeOfDay(&gfx);

        if (this->scrollAmount == 0) {
            BombersNotebook_DrawCursor(this, &gfx);
        }
        BombersNotebook_DrawArrows(this, &gfx);
    }
    POLY_OPA_DISP = gfx;

    CLOSE_DISPS(gfxCtx);
}
