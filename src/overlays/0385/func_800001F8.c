// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char06.h"

void DmChar06_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    DmChar06* this = (DmChar06*)thisx;

    AnimatedMat_Draw(play, Lib_SegmentedToVirtual(object_yukiyama_Matanimheader_006868));

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    Scene_SetRenderModeXlu(play, 1, 2);
    gDPPipeSync(POLY_XLU_DISP++);
    gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, this->alpha);
    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_XLU_DISP++, object_yukiyama_DL_0013A8);

    CLOSE_DISPS(play->state.gfxCtx);
}
