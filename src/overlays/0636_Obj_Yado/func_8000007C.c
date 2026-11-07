// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_yado.h"

void ObjYado_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjYado* this = (ObjYado*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    if (this->isNight) {
        gSPSegment(POLY_XLU_DISP++, 0x09, Gfx_PrimColor(play->state.gfxCtx, 128, 95, 95, 70, 155));
        gSPSegment(POLY_OPA_DISP++, 0x0A, Gfx_PrimColor(play->state.gfxCtx, 128, 0, 40, 40, 255));
    } else {
        gSPSegment(POLY_XLU_DISP++, 0x09, Gfx_PrimColor(play->state.gfxCtx, 128, 255, 255, 215, 110));
        gSPSegment(POLY_OPA_DISP++, 0x0A, Gfx_PrimColor(play->state.gfxCtx, 128, 255, 255, 215, 255));
    }

    AnimatedMat_Draw(play, ref_D_80C16470);
    Gfx_DrawDListOpa(play, object_yado_obj_DL_000430);
    Gfx_DrawDListXlu(play, object_yado_obj_DL_000320);

    CLOSE_DISPS(play->state.gfxCtx);
}
