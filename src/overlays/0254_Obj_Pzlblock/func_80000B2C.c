// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_pzlblock.h"

void ref_func_809A3F0C(Actor* thisx, PlayState* play) {
    ObjPzlblockStruct* sp2C = &ref_D_809A4060[OBJPZLBLOCK_GET_1000(thisx)];
    Color_RGB8* sp28 = &ref_D_809A4088[OBJPZLBLOCK_GET_700(thisx)];

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, sp28->r, sp28->g, sp28->b, 255);
    gSPDisplayList(POLY_OPA_DISP++, sp2C->unk_08);

    CLOSE_DISPS(play->state.gfxCtx);
}
