// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_syoten.h"

void ref_func_80C17690(Actor* thisx, PlayState* play) {
    s32 pad;
    DemoSyoten* this = (DemoSyoten*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    Matrix_RotateYS(BINANG_ROT180(Camera_GetCamDirYaw(GET_ACTIVE_CAM(play))), MTXMODE_APPLY);

    if (this->unk_3E4 & 8) {
        ref_func_80C17468(play);
    }

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);

    AnimatedMat_DrawStepXlu(play, this->unk_3E0, this->unk_3E6);

    gSPDisplayList(POLY_XLU_DISP++, object_syoten_DL_002880);

    AnimatedMat_DrawStepXlu(play, this->unk_3E0, this->unk_3E6 + 5);

    gSPDisplayList(POLY_XLU_DISP++, object_syoten_DL_002A20);

    CLOSE_DISPS(play->state.gfxCtx);
}
