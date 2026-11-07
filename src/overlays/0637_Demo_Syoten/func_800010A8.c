// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_syoten.h"

void DemoSyoten_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    DemoSyoten* this = (DemoSyoten*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    if (this->unk_3E4 & 4) {
        Matrix_RotateZS(-this->actor.shape.rot.z, MTXMODE_APPLY);
        Matrix_Mult(&play->billboardMtxF, MTXMODE_APPLY);
        Matrix_RotateZS(this->actor.shape.rot.z, MTXMODE_APPLY);
        Matrix_Scale(1.0f, 5.0f, 1.0f, MTXMODE_APPLY);
    }

    if (this->unk_3E4 & 1) {
        Matrix_Mult(&play->billboardMtxF, MTXMODE_APPLY);
    }

    if (this->unk_3E4 & 8) {
        ref_func_80C17468(play);
    }

    if (this->unk_3E0 != NULL) {
        if (this->unk_3E4 & 2) {
            AnimatedMat_DrawStepXlu(play, this->unk_3E0, this->unk_3E6);
        } else {
            AnimatedMat_DrawXlu(play, this->unk_3E0);
        }
    }

    if (this->unk_3DC != NULL) {
        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, this->unk_3DC);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
