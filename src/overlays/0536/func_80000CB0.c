// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_mir_ray3.h"

void MirRay3_Draw(Actor* thisx, PlayState* play) {
    s32 pad[2];
    MirRay3* this = (MirRay3*)thisx;
    MirRay3Struct sp8C[6];
    Player* player = GET_PLAYER(play);
    s32 i;
    f32 temp;
    u16 time;

    if (!(this->unk_210 & 1) && Player_HasMirrorShieldEquipped(play)) {
        Matrix_Mult(&player->shieldMf, MTXMODE_NEW);
        ref_func_80B9E544(this, play);

        if (this->unk_214 <= 0.1f) {
            return;
        }

        OPEN_DISPS(play->state.gfxCtx);

        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        Matrix_Scale(1.0f, 1.0f, this->unk_214, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);

        if (MIRRAY3_GET_F(&this->actor) == MIRRAY3_F_1) {
            time = CURRENT_TIME;

            if (time > CLOCK_TIME(12, 0)) {
                time = (DAY_LENGTH - 1) - time;
            }

            temp = (time * (1.0f / 0x8000));
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x78, 255, 255, 255, (u8)(s8)(100 * this->unk_214));

            gDPSetEnvColor(POLY_XLU_DISP++, 218, 225, (u8)((100.0f * temp) + 105.0f), 255);
        } else {
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x78, 255, 255, 255, (u8)(s8)(100 * this->unk_214));
            gDPSetEnvColor(POLY_XLU_DISP++, 218, 225, 205, 255);
        }

        AnimatedMat_Draw(play, Lib_SegmentedToVirtual(object_mir_ray_Matanimheader_0003F8));

        gSPDisplayList(POLY_XLU_DISP++, object_mir_ray_DL_000168);

        ref_func_80B9E5F4(this, play, sp8C);
        ref_func_80B9E7D0(sp8C);
        ref_func_80B9E8D4(this, play, sp8C);

        if (sp8C[0].unk_4C == NULL) {
            sp8C[0].unk_50 = 0;
        }

        for (i = 1; i < ARRAY_COUNT(sp8C); i++) {
            if ((sp8C[i].unk_4C != NULL) && (sp8C[0].unk_50 < sp8C[i].unk_50)) {
                sp8C[0].unk_50 = sp8C[i].unk_50;
            }
        }

        gDPSetRenderMode(POLY_XLU_DISP++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_DECAL2);

        for (i = 0; i < ARRAY_COUNT(sp8C); i++) {
            if (sp8C[i].unk_4C != NULL) {
                Matrix_Translate(sp8C[i].unk_00.x, sp8C[i].unk_00.y, sp8C[i].unk_00.z, MTXMODE_NEW);
                Matrix_Scale(0.01f, 0.01f, 0.01f, MTXMODE_APPLY);
                Matrix_Mult(&sp8C[i].unk_0C, MTXMODE_APPLY);

                MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
                gDPPipeSync(POLY_XLU_DISP++);
                gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, sp8C[0].unk_50);
                gSPDisplayList(POLY_XLU_DISP++, object_mir_ray_DL_0004B0);
            }
        }

        this->unk_210 |= 1;

        CLOSE_DISPS(play->state.gfxCtx);
    }
}
