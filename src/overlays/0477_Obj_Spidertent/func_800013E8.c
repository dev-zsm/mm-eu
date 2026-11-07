// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_spidertent.h"

void ObjSpidertent_Draw(Actor* thisx, PlayState* play) {
    ObjSpidertent* this = (ObjSpidertent*)thisx;
    s32 params = OBJSPIDERTENT_GET_1(&this->dyna.actor);
    s32 temp_f18 = this->unk_3C5 * (29.0f / 51);
    Gfx* gfx;

    OPEN_DISPS(play->state.gfxCtx);

    gfx = POLY_XLU_DISP;

    gSPDisplayList(gfx++, gSetupDLs[SETUPDL_25]);
    MATRIX_FINALIZE_AND_LOAD(gfx++, play->state.gfxCtx);
    gDPSetPrimColor(gfx++, 0, 0xFF, this->unk_3C2, this->unk_3C3, this->unk_3C4, temp_f18);
    gSPDisplayList(gfx++, ref_D_80B31350[params].unk_00);

    POLY_XLU_DISP = gfx;
    CLOSE_DISPS(play->state.gfxCtx);
}
