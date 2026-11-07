// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_holl.h"

void EnHoll_Draw(Actor* thisx, PlayState* play) {
    EnHoll* this = (EnHoll*)thisx;
    Gfx* gfx;
    u32 setupDListIndex;

    if (this->alpha != 0) {
        OPEN_DISPS(play->state.gfxCtx);

        if (this->alpha == 255) {
            gfx = POLY_OPA_DISP;
            setupDListIndex = SETUPDL_37;
        } else {
            gfx = POLY_XLU_DISP;
            setupDListIndex = SETUPDL_0;
        }
        gfx = Gfx_SetupDL(gfx, setupDListIndex);
        if (this->playerSide == EN_HOLL_BEHIND) {
            Matrix_RotateYF(M_PIf, MTXMODE_APPLY);
        }
        MATRIX_FINALIZE_AND_LOAD(gfx++, play->state.gfxCtx);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, this->alpha);
        gSPDisplayList(gfx++, gEnHollCentralPlaneDL);
        if (this->alpha == 255) {
            POLY_OPA_DISP = gfx;
        } else {
            POLY_XLU_DISP = gfx;
        }

        CLOSE_DISPS(play->state.gfxCtx);
    }
}
