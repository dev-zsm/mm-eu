// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test2.h"

void EnTest2_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    EnTest2* this = (EnTest2*)thisx;
    Gfx* dList = sModelInfo[ENTEST2_GET_TYPE(&this->actor)].dList2;

    if (this->animMat != NULL) {
        AnimatedMat_Draw(play, this->animMat);
    }

    if (CHECK_FLAG_ALL(this->actor.flags, ACTOR_FLAG_REACT_TO_LENS)) {
        OPEN_DISPS(play->state.gfxCtx);

        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);

        if (dList != NULL) {
            gSPDisplayList(POLY_XLU_DISP++, dList);
        }
        gSPDisplayList(POLY_XLU_DISP++, sModelInfo[ENTEST2_GET_TYPE(&this->actor)].dList1);

        CLOSE_DISPS(play->state.gfxCtx);
    } else {
        if (dList != NULL) {
            Gfx_DrawDListXlu(play, dList);
        }
        Gfx_DrawDListOpa(play, sModelInfo[ENTEST2_GET_TYPE(&this->actor)].dList1);
    }
}
