// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_object_kankyo.h"

void ref_func_808DD970(Actor* thisx, PlayState* play2) {
    f32 temp_f0;
    f32 temp_f20;
    Vec3f worldPos;
    Vec3f screenPos;
    f32 tempf;
    s16 i;
    f32 phi_f26;
    PlayState* play = play2;
    ObjectKankyo* this = (ObjectKankyo*)thisx;
    f32 tempA;

    if (play->sceneId == SCENE_KYOJINNOMA) {
        phi_f26 = 1.0f;
    } else {
        tempA = Camera_GetWaterYPos(GET_ACTIVE_CAM(play));
        if (tempA != BGCHECK_Y_MIN) {
            tempA -= play->view.eye.y;
            phi_f26 = tempA / 4000.0f;
        } else {
            phi_f26 = 0.0f;
        }

        phi_f26 = CLAMP_MAX(phi_f26, 1.0f);

        if (!(play->cameraPtrs[CAM_ID_MAIN]->stateFlags & CAM_STATE_UNDERWATER) || (phi_f26 == 0.0f)) {
            return;
        }
    }

    OPEN_DISPS(play->state.gfxCtx);

    for (i = 0; i < this->unk_114C; i++) {
        worldPos.x = this->unk_14C[i].unk_00 + this->unk_14C[i].unk_0C;
        worldPos.y = this->unk_14C[i].unk_04 + this->unk_14C[i].unk_10;
        worldPos.z = this->unk_14C[i].unk_08 + this->unk_14C[i].unk_14;

        Play_GetScreenPos(play, &worldPos, &screenPos);

        if ((screenPos.x >= 0.0f) && (screenPos.x < SCREEN_WIDTH) && (screenPos.y >= 0.0f) &&
            (screenPos.y < SCREEN_HEIGHT)) {
            Matrix_Translate(worldPos.x, worldPos.y, worldPos.z, MTXMODE_NEW);
            Matrix_Scale(0.03f, 0.03f, 0.03f, MTXMODE_APPLY);
            temp_f0 = Math_Vec3f_DistXYZ(&worldPos, &play->view.eye);
            temp_f0 = (u8)(255.0f * phi_f26) * (1.0f - (temp_f0 / 300.0f));

            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 55, temp_f0);
            gDPSetEnvColor(POLY_XLU_DISP++, 55, 50, 255, temp_f0);

            Matrix_Mult(&play->billboardMtxF, MTXMODE_APPLY);

            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
            gSPSegment(POLY_XLU_DISP++, 0x08, Lib_SegmentedToVirtual(gEffDust5Tex));
            gSPClearGeometryMode(POLY_XLU_DISP++, G_LIGHTING);

            POLY_XLU_DISP = Gfx_SetupDL(POLY_XLU_DISP, SETUPDL_0);

            gDPSetRenderMode(POLY_XLU_DISP++, G_RM_FOG_SHADE_A, G_RM_ZB_CLD_SURF2);
            gSPSetGeometryMode(POLY_XLU_DISP++, G_FOG);
            gSPDisplayList(POLY_XLU_DISP++, gEffDustDL);
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
