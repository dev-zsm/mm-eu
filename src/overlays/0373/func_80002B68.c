// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test6.h"

void EnTest6_DrawThreeDayResetSoTCutscene(EnTest6* this, PlayState* play) {
    s16 clock1Yaw;
    s16 clock2Yaw;
    s16 angle;
    s32 i;
    Vec3f clockPos;

    OPEN_DISPS(play->state.gfxCtx);

    this->gfx = POLY_OPA_DISP;
    clockPos.y = 0.0f;

    clock1Yaw = this->clockAngle;
    clock2Yaw = clock1Yaw + 0x4E20 + (s32)(0x2EE0 * Math_SinS(play->state.frames));
    
    angle = (play->state.frames & 0x3C) * 1024;
    angle *= this->clockSpeed / 200.0f;
    this->clockAngle += TRUNCF_BINANG(this->clockSpeed);
    this->clockRingRotZ = TRUNCF_BINANG((this->clockSpeed / 200.0f) * 256.0f);

    
    for (i = 0; i < (SOTCS_RESET_NUM_CLOCKS / 2); i++) {
        
        clock1Yaw += 0x1000;
        clockPos.x = Math_CosS(clock1Yaw) * this->clockDist;
        clockPos.z = Math_SinS(clock1Yaw) * this->clockDist;
        Matrix_Translate(clockPos.x, clockPos.y, clockPos.z, MTXMODE_NEW);
        Matrix_RotateXS(0x4000, MTXMODE_APPLY);
        Matrix_Scale(0.8f, 0.8f, 0.8f, MTXMODE_APPLY);
        Matrix_RotateZS(angle, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(this->gfx++, play->state.gfxCtx);
        gDPSetPrimColor(this->gfx++, 0, 0xFF, 28, 28, 28, 255);
        gDPSetEnvColor(this->gfx++, 255, 255, 255, 255);
        gDPSetRenderMode(this->gfx++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2);
        gSPDisplayList(this->gfx++, gSongOfTimeClockDL);

        
        clock2Yaw += 0x1000;
        clockPos.x = Math_CosS(clock2Yaw) * this->clockDist;
        clockPos.z = Math_SinS(clock2Yaw) * this->clockDist;
        Matrix_Translate(clockPos.x, clockPos.y, clockPos.z, MTXMODE_NEW);
        Matrix_RotateXS(0x4000, MTXMODE_APPLY);
        Matrix_Scale(0.8f, 0.8f, 0.8f, MTXMODE_APPLY);
        Matrix_RotateZS(-angle, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(this->gfx++, play->state.gfxCtx);
        gDPSetPrimColor(this->gfx++, 0, 0xFF, 28, 28, 28, 255);
        gDPSetEnvColor(this->gfx++, 255, 255, 255, 255);
        gDPSetRenderMode(this->gfx++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2);
        gSPDisplayList(this->gfx++, gSongOfTimeClockDL);

        clockPos.y -= this->speed;
        angle += this->clockRingRotZ;
    }

    POLY_OPA_DISP = this->gfx;

    for (i = 0; i < ARRAY_COUNT(sSoTCsAmmoDrops); i++) {
        if (sSoTCsAmmoDrops[i].scale > 0.0f) {
            sSoTCsAmmoDrops[i].draw(this, play, &sSoTCsAmmoDrops[i]);
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
