// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_dust.h"

void ref_func_80919768(Actor* thisx, PlayState* play2) {
    EffDust* this = (EffDust*)thisx;
    PlayState* play = play2;
    GraphicsContext* gfxCtx = play2->state.gfxCtx;
    f32* distanceTraveled;
    Vec3f* initialPositions;
    s32 i;
    f32 aux;
    s16 sp92;
    Vec3f activeCamEye;

    activeCamEye = GET_ACTIVE_CAM(play)->eye;
    sp92 = Math_Vec3f_Yaw(&activeCamEye, &thisx->world.pos);

    OPEN_DISPS(gfxCtx);

    Gfx_SetupDL25_Opa(gfxCtx);

    gDPPipeSync(POLY_XLU_DISP++);

    initialPositions = this->initialPositions;
    distanceTraveled = this->distanceTraveled;

    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 255, 0);

    gSPSegment(POLY_XLU_DISP++, 0x08, ref_D_80919DB0);

    for (i = 0; i < ARRAY_COUNT(this->distanceTraveled); i++) {
        if (*distanceTraveled < 1.0f) {
            aux = 1.0f - SQ(*distanceTraveled);
            Matrix_Translate(thisx->world.pos.x, thisx->world.pos.y, thisx->world.pos.z, MTXMODE_NEW);
            Matrix_RotateYS(sp92, MTXMODE_APPLY);
            Matrix_Translate(initialPositions->x * ((this->dx * aux) + (1.0f - this->dx)),
                             initialPositions->y * ((this->dy * aux) + (1.0f - this->dy)),
                             initialPositions->z * ((this->dz * aux) + (1.0f - this->dz)), MTXMODE_APPLY);
            Matrix_Scale(this->scalingFactor, this->scalingFactor, this->scalingFactor, MTXMODE_APPLY);

            Matrix_ReplaceRotation(&play->billboardMtxF);

            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, gfxCtx);

            gSPClearGeometryMode(POLY_XLU_DISP++, G_FOG | G_LIGHTING);

            gSPDisplayList(POLY_XLU_DISP++, gEffSparklesDL);

            gSPSetGeometryMode(POLY_XLU_DISP++, G_FOG | G_LIGHTING);
        }
        initialPositions++;
        distanceTraveled++;
    }

    CLOSE_DISPS(gfxCtx);
}
