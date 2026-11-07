// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_gakufu.h"

void EnGakufu_Draw(Actor* thisx, PlayState* play) {
    s32 i;
    s32 pad;
    EnGakufu* this = (EnGakufu*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    gDPPipeSync(POLY_XLU_DISP++);
    gSPSegment(POLY_XLU_DISP++, 0x02, play->interfaceCtx.parameterSegment);

    for (i = 0; (i < ARRAY_COUNT(this->buttonIndex)) && (this->buttonIndex[i] != OCARINA_BTN_INVALID); i++) {
        Matrix_Push();
        Matrix_Translate(30 * i - 105, sOcarinaBtnWallYOffsets[this->buttonIndex[i]] * 7.5f, 1.0f, MTXMODE_APPLY);
        Matrix_Scale(0.6f, 0.6f, 0.6f, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gDPSetTextureLUT(POLY_XLU_DISP++, G_TT_NONE);
        gDPLoadTextureBlock(POLY_XLU_DISP++, sOcarinaBtnWallTextures[this->buttonIndex[i]], G_IM_FMT_IA, G_IM_SIZ_8b,
                            16, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD,
                            G_TX_NOLOD);

        if (this->buttonIndex[i] == OCARINA_BTN_A) {
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 80, 150, 255, 200);
        } else {
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 50, 200);
        }

        gSPDisplayList(POLY_XLU_DISP++, gGakufuButtonIndexDL);

        Matrix_Pop();
    }

    gSPSegment(POLY_XLU_DISP++, 0x02, play->sceneSegment);

    CLOSE_DISPS(play->state.gfxCtx);
}
