// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kujiya.h"

void EnKujiya_Draw(Actor* thisx, PlayState* play) {
    EnKujiya* this = (EnKujiya*)thisx;

    AnimatedMat_Draw(play, Lib_SegmentedToVirtual(gLotteryShopTexAnim));

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, gLotteryShopCylinderDL);
    gSPDisplayList(POLY_OPA_DISP++, gLotteryShopBackSignDL);
    gSPDisplayList(POLY_OPA_DISP++, gLotteryShopOpenBoxDL);
    gSPDisplayList(POLY_OPA_DISP++, gLotteryShopScrollingEffectsDL);
    gSPDisplayList(POLY_OPA_DISP++, gLotteryShopRedRupeesDL);
    gSPDisplayList(POLY_OPA_DISP++, gLotteryShopGreenRupeesDL);
    gSPDisplayList(POLY_OPA_DISP++, gLotteryShopBlueRupeesDL);
    gSPDisplayList(POLY_OPA_DISP++, gLotteryShopTargetArrowAndSignDL);
    gSPDisplayList(POLY_OPA_DISP++, gLotteryShopScrollingArrowDL);
    gSPDisplayList(POLY_OPA_DISP++, gLotteryShopMaskDL);

    CLOSE_DISPS(play->state.gfxCtx);
}
