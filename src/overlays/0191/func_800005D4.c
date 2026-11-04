// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_oceff_spot.h"

void OceffSpot_Draw(Actor* thisx, PlayState* play) {
    OceffSpot* this = (OceffSpot*)thisx;
    u32 scroll = play->state.frames & 0xFFFF;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_XLU_DISP++, &sSunSongEffectCylinderMaterialDL);
    gSPDisplayList(POLY_XLU_DISP++, Gfx_TwoTexScroll(play->state.gfxCtx, 0, scroll * 2, scroll * -2, 0x20, 0x20, 1, 0,
                                                     scroll * -8, 0x20, 0x20));
    gSPDisplayList(POLY_XLU_DISP++, &sSunSongEffectCylinderModelDL);

    CLOSE_DISPS(play->state.gfxCtx);
}
