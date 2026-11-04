// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_oceff_storm.h"

void OceffStorm_Draw2(Actor* thisx, PlayState* play) {
    s32 scroll = play->state.frames & 0xFFF;
    OceffStorm* this = (OceffStorm*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    gDPPipeSync(POLY_XLU_DISP++);

    POLY_XLU_DISP = Gfx_SetupDL64(POLY_XLU_DISP);

    gDPSetAlphaDither(POLY_XLU_DISP++, G_AD_NOISE);
    gDPSetColorDither(POLY_XLU_DISP++, G_CD_NOISE);

    gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 200, 200, 150, this->primColorAlpha);

    gSPDisplayList(POLY_XLU_DISP++, &sSongOfStormsMaterialDL);
    gSPDisplayList(POLY_XLU_DISP++, Gfx_TwoTexScroll(play->state.gfxCtx, G_TX_RENDERTILE, scroll * 8, scroll * 4, 64,
                                                     64, 1, scroll * 4, scroll * 4, 64, 64));
    gSPTextureRectangle(POLY_XLU_DISP++, 0, 0, SCREEN_WIDTH << 2, SCREEN_HEIGHT << 2, G_TX_RENDERTILE, 0, 0,
                        (s32)(0.13671875f * (1 << 10)), (s32)(-0.13671875f * (1 << 10)));

    CLOSE_DISPS(play->state.gfxCtx);
}
