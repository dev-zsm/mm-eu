// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_m_thunder.h"

void EnMThunder_Draw(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnMThunder* this = (EnMThunder*)thisx;
    Player* player = GET_PLAYER(play);
    f32 scale;
    s32 y2Scroll;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    Matrix_Scale(0.02f, 0.02f, 0.02f, MTXMODE_APPLY);

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);

    switch (this->subtype) {
        case ENMTHUNDER_SUBTYPE_SPIN_GREAT:
        case ENMTHUNDER_SUBTYPE_SPIN_REGULAR:
            gSPSegment(POLY_XLU_DISP++, 0x08,
                       Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0xFF - ((u16)(s32)(this->scroll * 30.0f) & 0xFF), 0, 64,
                                        32, 1, 0xFF - ((u16)(s32)(this->scroll * 20.0f) & 0xFF), 0, 8, 8));
            break;

        case ENMTHUNDER_SUBTYPE_SWORDBEAM_GREAT:
        case ENMTHUNDER_SUBTYPE_SWORDBEAM_REGULAR:
            gSPSegment(POLY_XLU_DISP++, 0x08,
                       Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, 0, 16, 64, 1, 0,
                                        0x1FF - ((u16)(s32)(this->scroll * 10.0f) & 0x1FF), 32, 128));
            break;

        default:
            break;
    }

    switch (this->subtype) {
        case ENMTHUNDER_SUBTYPE_SPIN_GREAT:
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255, 255, 170, (u16)(this->alphaFrac * 255.0f));
            gSPDisplayList(POLY_XLU_DISP++, gGreatSpinAttackDiskDL);
            gSPDisplayList(POLY_XLU_DISP++, gGreatSpinAttackCylinderDL);
            break;

        case ENMTHUNDER_SUBTYPE_SPIN_REGULAR:
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 170, 255, 255, (u16)(this->alphaFrac * 255.0f));
            gSPDisplayList(POLY_XLU_DISP++, gSpinAttackDiskDL);
            gSPDisplayList(POLY_XLU_DISP++, gSpinAttackCylinderDL);
            break;

        case ENMTHUNDER_SUBTYPE_SWORDBEAM_REGULAR:
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 170, 255, 255, (u16)(this->alphaFrac * 255.0f));
            gDPSetEnvColor(POLY_XLU_DISP++, 0, 100, 255, 128);
            gSPDisplayList(POLY_XLU_DISP++, gSwordBeamDL);
            break;

        case ENMTHUNDER_SUBTYPE_SWORDBEAM_GREAT:
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 0, 255, 255, (u16)(this->alphaFrac * 255.0f));
            gDPSetEnvColor(POLY_XLU_DISP++, 200, 200, 200, 128);
            gSPDisplayList(POLY_XLU_DISP++, gSwordBeamDL);
            break;

        default:
            break;
    }

    Matrix_Mult(&player->leftHandMf, MTXMODE_NEW);

    if (this->type == ENMTHUNDER_TYPE_GILDED_SWORD) {
        Matrix_Translate(0.0f, 220.0f, 0.0f, MTXMODE_APPLY);
        Matrix_Scale(-1.2f, -0.8f, -0.6f, MTXMODE_APPLY);
        Matrix_RotateXS(0x4000, MTXMODE_APPLY);
    } else {
        Matrix_Translate(0.0f, 220.0f, 0.0f, MTXMODE_APPLY);
        Matrix_Scale(-0.7f, -0.6f, -0.4f, MTXMODE_APPLY);
        Matrix_RotateXS(0x4000, MTXMODE_APPLY);
    }

    if (this->unk1B0 >= 0.85f) {
        scale = (sScales[play->gameplayFrames & 7] * 6.0f) + 1.0f;
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255, 255, 170, this->chargingAlpha);
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 100, 0, 128);
        y2Scroll = 40;
    } else {
        scale = (sScales[play->gameplayFrames & 7] * 2.0f) + 1.0f;
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 170, 255, 255, this->chargingAlpha);
        gDPSetEnvColor(POLY_XLU_DISP++, 0, 100, 255, 128);
        y2Scroll = 20;
    }

    Matrix_Scale(1.0f, scale, scale, MTXMODE_APPLY);

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    gSPSegment(POLY_XLU_DISP++, 0x09,
               Gfx_TwoTexScroll(play->state.gfxCtx, 0, (play->gameplayFrames * 5) & 0xFF, 0, 32, 32, 1,
                                (play->gameplayFrames * 20) & 0xFF, (play->gameplayFrames * y2Scroll) & 0xFF, 8, 8));
    gSPDisplayList(POLY_XLU_DISP++, gSpinAttackChargingDL);

    CLOSE_DISPS(play->state.gfxCtx);
}
