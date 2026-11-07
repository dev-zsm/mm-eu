// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_water_effect.h"

void EnWaterEffect_Draw(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    EnWaterEffect* this = (EnWaterEffect*)thisx;
    s32 pad;
    EnWaterEffectStruct* backupPtr = &this->unk_144[0];
    EnWaterEffectStruct* ptr = backupPtr;
    u8 phi_s4 = false;
    s16 i;

    OPEN_DISPS(gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    for (i = 0; i < ARRAY_COUNT(this->unk_144) / 2; i++, ptr++) {
        if ((ptr->unk_00 == 1) || (ptr->unk_00 == 2)) {
            if (!phi_s4) {
                POLY_XLU_DISP = Gfx_SetupDL(POLY_XLU_DISP, SETUPDL_0);

                gSPSegment(POLY_XLU_DISP++, 0x08, Lib_SegmentedToVirtual(gEffDust1Tex));
                gSPDisplayList(POLY_XLU_DISP++, object_water_effect_DL_004260);
                gDPSetEnvColor(POLY_XLU_DISP++, 250, 250, 255, 0);
                phi_s4++;
            }

            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, (u8)ptr->unk_38, (u8)(((void)0, ptr->unk_38) + 55.0f), 225, 150);

            Matrix_Translate(ptr->unk_04.x, ptr->unk_04.y, ptr->unk_04.z, MTXMODE_NEW);

            if (ptr->unk_00 == 1) {
                Matrix_RotateYS(Camera_GetInputDirYaw(GET_ACTIVE_CAM(play)), MTXMODE_APPLY);
            } else {
                Matrix_ReplaceRotation(&play->billboardMtxF);
            }

            Matrix_Scale(ptr->unk_2C.x, ptr->unk_2C.y, 1.0f, MTXMODE_APPLY);
            Matrix_RotateZF(ptr->unk_2C.z, MTXMODE_APPLY);

            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, gfxCtx);
            gSPDisplayList(POLY_XLU_DISP++, object_water_effect_DL_0042B0);
        }
    }

    phi_s4 = false;
    ptr = backupPtr;

    for (i = 0; i < ARRAY_COUNT(this->unk_144) / 2; i++, ptr++) {
        if (ptr->unk_00 == 3) {
            if (!phi_s4) {
                Gfx_SetupDL44_Xlu(gfxCtx);

                gSPSegment(POLY_XLU_DISP++, 0x08, Lib_SegmentedToVirtual(gEffDust1Tex));
                gDPSetEnvColor(POLY_XLU_DISP++, 250, 250, 255, 0);
                gSPDisplayList(POLY_XLU_DISP++, object_water_effect_DL_004260);
                phi_s4++;
            }

            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, (u8)ptr->unk_38, (u8)(((void)0, ptr->unk_38) + 55.0f), 225,
                            ptr->unk_3C);

            Matrix_Translate(ptr->unk_04.x, ptr->unk_04.y, ptr->unk_04.z, MTXMODE_NEW);
            Matrix_Scale(ptr->unk_2C.x, 1.0f, ptr->unk_2C.x, MTXMODE_APPLY);
            Matrix_RotateYF(ptr->unk_2C.z, MTXMODE_APPLY);

            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, gfxCtx);
            gSPDisplayList(POLY_XLU_DISP++, object_water_effect_DL_0042F8);
        }
    }

    CLOSE_DISPS(gfxCtx);
}
