// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hakaisi.h"

void ObjHakaisi_Draw(Actor* thisx, PlayState* play) {
    ObjHakaisi* this = (ObjHakaisi*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    if (this->unk_194 == 0) {
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, object_hakaisi_DL_002650);
    } else if (this->unk_194 == 1) {
        Matrix_Scale(0.1f, 0.1f, 0.1f, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, object_hakaisi_DL_0029C0);
    } else {
        Matrix_Scale(0.1f, 0.1f, 0.1f, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, object_hakaisi_DL_002CC0);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
