// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_object_kankyo.h"

void ref_func_808DDE9C(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    ObjectKankyo* this = (ObjectKankyo*)thisx;
    Player* player = GET_PLAYER(play);
    s32 i;
    u8 phi_s5;
    u16 end = play->envCtx.precipitation[PRECIP_RAIN_CUR];
    f32 temp_f12;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f2;

    OPEN_DISPS(play->state.gfxCtx);

    if (end) {
        gDPPipeSync(POLY_XLU_DISP++);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 150, 255, 255, 25);
        POLY_XLU_DISP = Gfx_SetupDL(POLY_XLU_DISP, SETUPDL_20);
    }

    for (i = 0; i < end; i++) {
        temp_f20 = this->unk_14C[0].unk_00 + ((Rand_ZeroOne() - 0.7f) * this->unk_144);
        temp_f22 = this->unk_14C[0].unk_04 + ((Rand_ZeroOne() - 0.7f) * this->unk_144);
        temp_f2 = this->unk_14C[0].unk_08 + ((Rand_ZeroOne() - 0.7f) * this->unk_144);

        if (!((temp_f20 < -252.0f) && (temp_f20 > -500.0f) && (temp_f2 > 3820.0f) && (temp_f2 < 4150.0f))) {
            Matrix_Translate(temp_f20, temp_f22, temp_f2, MTXMODE_NEW);

            gSPMatrix(POLY_XLU_DISP++, &ref_D_01000000, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            Matrix_RotateYS(TRUNCF_BINANG(this->unk_14C[2].unk_04) + (s16)(i << 5), MTXMODE_APPLY);
            Matrix_RotateXS(TRUNCF_BINANG(this->unk_14C[2].unk_00) + (s16)(i << 5), MTXMODE_APPLY);

            if (this->unk_114C == 0) {
                Matrix_Scale(0.5f, 1.0f, 0.5f, MTXMODE_APPLY);
            } else {
                Matrix_Scale(2.0f, 4.0f, 2.0f, MTXMODE_APPLY);
            }

            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
            gSPDisplayList(POLY_XLU_DISP++, gFallingRainDropDL);
        }
    }

    phi_s5 = false;
    if (player->actor.floorHeight < play->view.eye.y) {
        for (i = 0; i < end; i++) {
            if (!phi_s5) {
                Gfx_SetupDL25_Xlu(play->state.gfxCtx);

                gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, 255);
                gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, 100);
                phi_s5++;
            }

            temp_f20 = this->unk_14C[1].unk_00 + (ref_func_808DDE74() * 220.0f);
            temp_f22 = player->actor.floorHeight + 2.0f;
            temp_f2 = this->unk_14C[1].unk_08 + (ref_func_808DDE74() * 220.0f);

            if (!((temp_f20 < -252.0f) && (temp_f20 > -500.0f) && (temp_f2 > 3820.0f) && (temp_f2 < 4150.0f))) {
                Matrix_Translate(temp_f20, temp_f22, temp_f2, MTXMODE_NEW);
                temp_f12 = (Rand_ZeroOne() * 0.05f) + 0.05f;
                Matrix_Scale(temp_f12, temp_f12, temp_f12, MTXMODE_APPLY);

                MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
                gSPDisplayList(POLY_XLU_DISP++, gEffShockwaveDL);
            }
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
