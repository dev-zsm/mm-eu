// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_fireshield.h"

void ObjFireshield_Draw(Actor* thisx, PlayState* play) {
    ObjFireshield* this = (ObjFireshield*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 220, 0, this->unk_1A6);
    gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 0, 0);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(play->state.gfxCtx, 0, this->unk_1A4 & 0x7F, 0, 0x20, 0x40, 1, 0,
                                (this->unk_1A4 * -15) & 0xFF, 0x20, 0x40));
    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_XLU_DISP++, gameplay_keep_DL_02E510);

    CLOSE_DISPS(play->state.gfxCtx);
}
