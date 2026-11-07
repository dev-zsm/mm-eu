// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_object_kankyo.h"

void ref_func_808DD3C8(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    ObjectKankyo* this = (ObjectKankyo*)thisx;
    Vec3f worldPos;
    Vec3f screenPos;
    s16 i;
    u8 pad2;
    u8 spB4;
    f32 temp_f0;
    u8 sp68;
    s32 pad;
    f32 temp_f2;
    f32 tempf;

    if ((play->cameraPtrs[CAM_ID_MAIN]->stateFlags & CAM_STATE_UNDERWATER) ||
        ((u8)play->envCtx.stormState == STORM_STATE_OFF)) {
        return;
    }

    OPEN_DISPS(play->state.gfxCtx);

    spB4 = false;

    if (this->actor.params == 3) {
        temp_f0 = ref_func_80173B48(&play->state) / 1.4e7f;
        temp_f0 = CLAMP(temp_f0, 0.0f, 1.0f);
        Math_SmoothStepToF(&ref_D_808DE5B0, temp_f0, 0.2f, 0.1f, 0.001f);

        sp68 = play->envCtx.precipitation[PRECIP_SNOW_CUR];
        sp68 *= ref_D_808DE5B0;

        if ((play->envCtx.precipitation[PRECIP_SNOW_CUR] >= 32) && (sp68 < 32)) {
            sp68 = 32;
        }
    } else {
        sp68 = play->envCtx.precipitation[PRECIP_SNOW_CUR];
    }

    for (i = 0; i < sp68; i++) {
        worldPos.x = this->unk_14C[i].unk_00 + this->unk_14C[i].unk_0C;
        worldPos.y = this->unk_14C[i].unk_04 + this->unk_14C[i].unk_10;
        worldPos.z = this->unk_14C[i].unk_08 + this->unk_14C[i].unk_14;

        Play_GetScreenPos(play, &worldPos, &screenPos);

        if ((screenPos.x >= 0.0f) && (screenPos.x < SCREEN_WIDTH) && (screenPos.y >= 0.0f) &&
            (screenPos.y < SCREEN_HEIGHT)) {
            if (!spB4) {
                spB4 = true;

                gDPPipeSync(POLY_XLU_DISP++);
                gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, 255);
                gSPClearGeometryMode(POLY_XLU_DISP++, G_LIGHTING);

                POLY_XLU_DISP = Gfx_SetupDL(POLY_XLU_DISP, SETUPDL_0);

                gDPSetRenderMode(POLY_XLU_DISP++, G_RM_FOG_SHADE_A, G_RM_ZB_CLD_SURF2);
                gSPSetGeometryMode(POLY_XLU_DISP++, G_FOG);
                gSPSegment(POLY_XLU_DISP++, 0x08, Lib_SegmentedToVirtual(gEffDust5Tex));
            }

            Matrix_Translate(worldPos.x, worldPos.y, worldPos.z, MTXMODE_NEW);
            tempf = (i & 7) * 0.008f;
            Matrix_Scale(0.05f + tempf, 0.05f + tempf, 0.05f + tempf, MTXMODE_APPLY);
            temp_f2 = Math_Vec3f_DistXYZ(&worldPos, &play->view.eye) / 300.0f;
            temp_f2 = ((1.0f < temp_f2) ? 0.0f : (((1.0f - temp_f2) > 1.0f) ? 1.0f : 1.0f - temp_f2));

            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (u8)(160.0f * temp_f2));

            Matrix_Mult(&play->billboardMtxF, MTXMODE_APPLY);

            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
            gSPDisplayList(POLY_XLU_DISP++, gEffDustDL);
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
