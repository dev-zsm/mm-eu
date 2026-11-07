// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_sda.h"

void ref_func_80947668(u8* shadowTexture, Player* player, PlayState* play) {
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    f32 tempx;
    f32 tempz;
    s16 i;

    OPEN_DISPS(gfxCtx);

    Gfx_SetupDL44_Xlu(play->state.gfxCtx);

    gDPSetPrimColor(POLY_XLU_DISP++, 0x00, 0x00, 0, 0, 0, (BREG(52) + 50));
    gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, 0);

    Matrix_Translate(player->actor.world.pos.x, player->actor.floorHeight, player->actor.world.pos.z, MTXMODE_NEW);
    Matrix_RotateYF(BREG(51) / 100.0f, MTXMODE_APPLY);
    Matrix_Scale(1.0f, 1.0f, (BREG(63) / 10.0f) + 1.0f, MTXMODE_APPLY);

    tempx = (BREG(62) / 10.0f) + 2.0f;
    tempz = ((player->actor.world.pos.y - player->actor.floorHeight + BREG(54)) * (BREG(55) - 5) / 10.0f) + BREG(58) -
            20.0f;

    Matrix_Translate(tempx, 0.0f, tempz, MTXMODE_APPLY);
    Matrix_Scale(((BREG(56) - 250) / 1000.0f) + 0.6f, 1.0f, ((BREG(59) - 250) / 1000.0f) + 0.6f, MTXMODE_APPLY);

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_XLU_DISP++, ovl_En_Sda_DL_1498);
    gDPLoadTextureBlock(POLY_XLU_DISP++, shadowTexture, G_IM_FMT_I, G_IM_SIZ_8b, 64, 64, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD);
    gSPDisplayList(POLY_XLU_DISP++, ovl_En_Sda_DL_14B8);

    for (i = 0; i < KREG(78); i++) {
        Matrix_Scale((KREG(79) / 100.0f) + 1.0f, 1.0f, (KREG(79) / 100.0f) + 1.0f, MTXMODE_APPLY);
        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, ovl_En_Sda_DL_14B8);
    }

    CLOSE_DISPS(gfxCtx);
}
