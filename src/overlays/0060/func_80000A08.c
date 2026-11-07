// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_light.h"

void EnLight_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    EnLight* this = (EnLight*)thisx;
    EnLightStruct* sp6C = &ref_D_808666D0[ENLIGHT_GET_F(&this->actor)];
    Gfx* sp68;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    if (this->actor.params >= 0) {
        gSPSegment(
            POLY_XLU_DISP++, 0x08,
            Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0, (this->unk_144 * -20) & 0x1FF, 0x20, 0x80));
        sp68 = gEffFire1DL;
        gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, sp6C->unk_00.r, sp6C->unk_00.g, sp6C->unk_00.b, sp6C->unk_00.a);
        gDPSetEnvColor(POLY_XLU_DISP++, sp6C->unk_04.r, sp6C->unk_04.g, sp6C->unk_04.b, 0);
    } else {
        gSPSegment(POLY_XLU_DISP++, 0x08,
                   Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, 0, 0x10, 0x20, 1, (this->unk_144 * 2) & 0x3F,
                                    (this->unk_144 * -6) & 0x7F, 0x10, 0x20));
        sp68 = gameplay_keep_DL_01ACF0;
        gDPSetPrimColor(POLY_XLU_DISP++, 0xC0, 0xC0, 255, 200, 0, 0);
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 0, 0);
    }

    Matrix_RotateYS(BINANG_ROT180(Camera_GetCamDirYaw(GET_ACTIVE_CAM(play)) - this->actor.shape.rot.y), MTXMODE_APPLY);

    if (ENLIGHT_GET_1(&this->actor)) {
        Matrix_RotateYF(M_PIf, MTXMODE_APPLY);
    }

    Matrix_Scale(1.0f, 1.0f, 1.0f, MTXMODE_APPLY);

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_XLU_DISP++, sp68);

    CLOSE_DISPS(play->state.gfxCtx);
}
