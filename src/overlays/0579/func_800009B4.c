// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_iknv_doukutu.h"

void BgIknvDoukutu_DrawSpringWater(Actor* thisx, PlayState* play) {
    BgIknvDoukutu* this = (BgIknvDoukutu*)thisx;
    f32 opacity = this->opacity;
    s32 pad;

    OPEN_DISPS(play->state.gfxCtx);

    AnimatedMat_Draw(play, Lib_SegmentedToVirtual(gIkanaCaveSpringWaterTexAnim));

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255, 255, 255, (s32)(140.0f * opacity));

    gSPDisplayList(POLY_XLU_DISP++, gIkanaCaveSpringWaterDL);

    CLOSE_DISPS(play->state.gfxCtx);
}
