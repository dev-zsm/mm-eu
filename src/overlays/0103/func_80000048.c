// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_keikoku_spr.h"

void BgKeikokuSpr_Draw(Actor* thisx, PlayState* play) {
    s32 pad;

    OPEN_DISPS(play->state.gfxCtx);

    AnimatedMat_Draw(play, Lib_SegmentedToVirtual(object_keikoku_obj_Matanimheader_0001F8));
    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_XLU_DISP++, object_keikoku_obj_DL_000100);

    AnimatedMat_Draw(play, Lib_SegmentedToVirtual(object_keikoku_obj_Matanimheader_0003F8));
    gSPDisplayList(POLY_XLU_DISP++, object_keikoku_obj_DL_000300);

    AnimatedMat_Draw(play, Lib_SegmentedToVirtual(object_keikoku_obj_Matanimheader_0005F8));
    gSPDisplayList(POLY_XLU_DISP++, object_keikoku_obj_DL_000500);

    CLOSE_DISPS(play->state.gfxCtx);
}
