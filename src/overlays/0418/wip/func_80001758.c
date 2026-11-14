// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnOsn_Draw), score 1.00 (1 differ, size +0)
#include "generated/mm/z_en_osn.h"

void func_80001758(Actor* thisx, PlayState* play) {
    static TexturePtr sEyeClosedHappyTex = gHappyMaskSalesmanEyeClosedHappyTex;
    static TexturePtr sEyeOpenTex = gHappyMaskSalesmanEyeOpenTex;
    static TexturePtr sEyeClosedAngryTex = gHappyMaskSalesmanEyeClosedAngryTex;
    static TexturePtr sSmileTex = gHappyMaskSalesmanSmileTex;
    static TexturePtr sFrownTex = gHappyMaskSalesmanFrownTex;
    s32 pad;
    EnOsn* this = (EnOsn*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    if (this->alpha == 255) {
        Gfx_SetupDL25_Opa(play->state.gfxCtx);
        if ((this->animIndex == OSN_ANIM_CHOKE) || (this->animIndex == OSN_ANIM_DESPAIR) ||
            (this->animIndex == OSN_ANIM_HAND_OUT_2) || (play->msgCtx.currentTextId == 0x1FCA)) {
            gSPSegment(POLY_OPA_DISP++, 0x08, Lib_SegmentedToVirtual(sEyeOpenTex));
            gSPSegment(POLY_OPA_DISP++, 0x09, Lib_SegmentedToVirtual(sSmileTex));
        } else if ((this->animIndex == OSN_ANIM_SHAKE_HEAD) || (this->animIndex == OSN_ANIM_REMINISCE) ||
                   (this->animIndex == OSN_ANIM_FAST_BOWS)) {
            gSPSegment(POLY_OPA_DISP++, 0x08, Lib_SegmentedToVirtual(sEyeClosedAngryTex));
            gSPSegment(POLY_OPA_DISP++, 0x09, Lib_SegmentedToVirtual(sFrownTex));
        } else {
            gSPSegment(POLY_OPA_DISP++, 0x08, Lib_SegmentedToVirtual(sEyeClosedHappyTex));
            gSPSegment(POLY_OPA_DISP++, 0x09, Lib_SegmentedToVirtual(sSmileTex));
        }
        gDPSetEnvColor(POLY_OPA_DISP++, 255, 255, 255, 255);
        Scene_SetRenderModeXlu(play, 0, 1);
        POLY_OPA_DISP =
            SkelAnime_DrawFlex(play, this->skelAnime.skeleton, this->skelAnime.jointTable, this->skelAnime.dListCount,
                               EnOsn_OverrideLimbDraw, EnOsn_PostLimbDraw, &this->actor, POLY_OPA_DISP);
    } else {
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        gSPSegment(POLY_XLU_DISP++, 0x08, Lib_SegmentedToVirtual(sEyeClosedHappyTex));
        gSPSegment(POLY_XLU_DISP++, 0x09, Lib_SegmentedToVirtual(sSmileTex));
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, this->alpha);
        Scene_SetRenderModeXlu(play, 1, 2);
        POLY_XLU_DISP =
            SkelAnime_DrawFlex(play, this->skelAnime.skeleton, this->skelAnime.jointTable, this->skelAnime.dListCount,
                               EnOsn_OverrideLimbDraw, EnOsn_PostLimbDraw, &this->actor, POLY_XLU_DISP);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
