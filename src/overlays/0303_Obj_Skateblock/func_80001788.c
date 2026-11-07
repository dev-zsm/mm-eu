// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_skateblock.h"

void ObjSkateblock_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjSkateblock* this = (ObjSkateblock*)thisx;
    Color_RGB8* sp2C = &ref_D_80A22B08[OBJSKAEBLOCK_GET_F(&this->dyna.actor)];

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    AnimatedMat_DrawStep(play, ref_D_80A22A18, 0);

    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gDPSetPrimColor(POLY_OPA_DISP++, 0xFF, 0xFF, sp2C->r, sp2C->g, sp2C->b, 255);
    gSPDisplayList(POLY_OPA_DISP++, gameplay_dangeon_keep_DL_0182A8);

    ref_func_80A21E9C(this, play);

    CLOSE_DISPS(play->state.gfxCtx);
}
