// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test6.h"

void EnTest6_DrawInvertedSoTCutscene(EnTest6* this, PlayState* play2) {
    PlayState* play = play2;
    Player* player = GET_PLAYER(play);
    f32 flashScale;
    s32 i;

    OPEN_DISPS(play->state.gfxCtx);

    switch (this->cueId) {
        case SOTCS_CUEID_INV_SETUP_CLOCKS:
        case SOTCS_CUEID_INV_UNUSED:
            Lights_PointSetPosition(&this->lights[0].info, player->actor.world.pos.x, player->actor.world.pos.y - 10.0f,
                                    player->actor.world.pos.z);
            Lights_PointSetColorAndRadius(&this->lights[0].info, 245, 245, 200, this->alpha);
            break;

        case SOTCS_CUEID_INV_CLOCKS:
            this->gfx = POLY_XLU_DISP;

            
            for (i = 0; i < ARRAY_COUNT(this->invSoTClockPos); i++) {
                Matrix_Translate(this->invSoTClockPos[i].x, this->invSoTClockPos[i].y, this->invSoTClockPos[i].z,
                                 MTXMODE_NEW);
                Matrix_Scale(0.3f, 0.3f, 0.3f, MTXMODE_APPLY);
                Matrix_RotateXS(-0x4000, MTXMODE_APPLY);
                Matrix_RotateZS(this->invSoTClockYaw, MTXMODE_APPLY);

                MATRIX_FINALIZE_AND_LOAD(this->gfx++, play->state.gfxCtx);
                gDPSetPrimColor(this->gfx++, 0, 0xFF, 28, 28, 28, 255);
                gDPSetEnvColor(this->gfx++, 245, 245, 200, this->alpha);
                gDPSetRenderMode(this->gfx++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2);
                gSPDisplayList(this->gfx++, gSongOfTimeClockDL);

                POLY_XLU_DISP = this->gfx;
            }

            
            if (this->invSoTParticles != NULL) {
                for (i = 0; i < SOTCS_NUM_PARTICLES; i++) {
                    flashScale = Rand_ZeroOne() * 0.0025f;
                    Matrix_Translate((*this->invSoTParticles)[i].x, (*this->invSoTParticles)[i].y,
                                     (*this->invSoTParticles)[i].z, MTXMODE_NEW);
                    Matrix_Scale(flashScale, flashScale, flashScale, MTXMODE_APPLY);

                    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 128, 128, 128, this->alpha >> 1);
                    gDPSetEnvColor(POLY_XLU_DISP++, 230, 230, 180, this->alpha);

                    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
                    Matrix_Mult(&play->billboardMtxF, MTXMODE_APPLY);
                    Matrix_RotateZS(this->invSoTClockYaw + (i << 2), MTXMODE_APPLY);

                    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
                    gSPDisplayList(POLY_XLU_DISP++, gEffFlash1DL);
                }
            }

            Lights_PointSetPosition(&this->lights[0].info, player->actor.world.pos.x, player->actor.world.pos.y - 10.0f,
                                    player->actor.world.pos.z);
            Lights_PointSetColorAndRadius(&this->lights[0].info, 250, 250, 100, this->alpha);
            break;

        case SOTCS_CUEID_INV_INIT:
        case SOTCS_CUEID_INV_END:
            break;
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
