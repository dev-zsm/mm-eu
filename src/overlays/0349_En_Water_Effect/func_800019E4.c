// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_water_effect.h"

void ref_func_80A5A184(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnWaterEffect* this = (EnWaterEffect*)thisx;
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    EnWaterEffectStruct* ptr = &this->unk_144[0];
    u8 flag = false;
    s16 i;

    OPEN_DISPS(gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    for (i = 0; i < ARRAY_COUNT(this->unk_144); i++, ptr++) {
        if (ptr->unk_00 == 4) {
            if (!flag) {
                gSPDisplayList(POLY_XLU_DISP++, object_water_effect_DL_004340);
                gDPSetEnvColor(POLY_XLU_DISP++, 255, 10, 0, 0);
                POLY_OPA_DISP = Gfx_SetFog(POLY_OPA_DISP, 255, 0, 0, 255, 500, 3600);
                flag++;
            }

            gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, (u8)ptr->unk_38, 0, 0, (u8)ptr->unk_3C);
            gSPSegment(POLY_XLU_DISP++, 0x08,
                       Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0, (ptr->unk_01 * -20) & 0x1FF,
                                        0x20, 0x80));

            Matrix_Translate(ptr->unk_04.x, ptr->unk_04.y, ptr->unk_04.z, MTXMODE_NEW);

            if (ptr->unk_2A >= 2) {
                Matrix_ReplaceRotation(&play->billboardMtxF);
            } else {
                Matrix_RotateYS(Camera_GetInputDirYaw(GET_ACTIVE_CAM(play)), MTXMODE_APPLY);
            }

            Matrix_Scale(ptr->unk_2C.x, ptr->unk_2C.y, 1.0f, MTXMODE_APPLY);

            if ((i & 1) != 0) {
                Matrix_RotateYF(M_PIf, MTXMODE_APPLY);
            }

            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
            gSPDisplayList(POLY_XLU_DISP++, object_water_effect_DL_0043E8);

            if ((ptr->unk_2A & 1) == 0) {
                Matrix_Translate(ptr->unk_04.x, ptr->unk_04.y + 5.0f, ptr->unk_04.z, MTXMODE_NEW);
                Matrix_RotateXS(ptr->unk_28, MTXMODE_APPLY);
                Matrix_Scale(ptr->unk_2C.z, ptr->unk_2C.z, ptr->unk_2C.z, MTXMODE_APPLY);

                MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
                gSPDisplayList(POLY_OPA_DISP++, gameplay_keep_DL_06AB30);
            }
        }
    }

    POLY_OPA_DISP = Play_SetFog(play, POLY_OPA_DISP);

    CLOSE_DISPS(gfxCtx);
}
