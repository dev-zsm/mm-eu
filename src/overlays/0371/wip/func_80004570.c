// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTrt_Draw), score 2.00 (2 differ, size +2)
#include "generated/mm/z_en_trt.h"

void func_80004570(Actor* thisx, PlayState* play) {
    static TexturePtr sEyeTextures[] = { gKotakeEyeOpenTex, gKotakeEyeHalfTex, gKotakeEyeClosedTex };
    EnTrt* this = (EnTrt*)thisx;
    s32 pad;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, Lib_SegmentedToVirtual(sEyeTextures[this->eyeTexIndex]));
    gSPSegment(POLY_OPA_DISP++, 0x09, Lib_SegmentedToVirtual(sEyeTextures[this->eyeTexIndex]));
    SkelAnime_DrawTransformFlexOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable,
                                   this->skelAnime.dListCount, EnTrt_OverrideLimbDraw, EnTrt_PostLimbDraw,
                                   EnTrt_TransformLimbDraw, &this->actor);
    EnTrt_DrawCursor(play, this, this->cursorPos.x, this->cursorPos.y, this->cursorPos.z, this->drawCursor);
    EnTrt_DrawStickDirectionPrompt(play, this);

    CLOSE_DISPS(play->state.gfxCtx);
}
