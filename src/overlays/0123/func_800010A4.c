// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_mir_ray.h"

void MirRay_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    MirRay* this = (MirRay*)thisx;
    Player* player = GET_PLAYER(play);
    MirRayShieldReflection reflection[6];
    s32 i;

    this->reflectIntensity = 0.0f;

    if (!ref_D_808E3BF0 && !this->unLit && Player_IsHoldingMirrorShield(play)) {
        Matrix_Mult(&player->shieldMf, MTXMODE_NEW);
        MirRay_SetIntensity(this, play);

        if (this->reflectIntensity <= 0.0f) {
            return;
        }

        OPEN_DISPS(play->state.gfxCtx);

        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        Matrix_Scale(1.0f, 1.0f, this->reflectIntensity, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (u8)(s8)(this->reflectIntensity * 100.0f));

        AnimatedMat_Draw(play, Lib_SegmentedToVirtual(object_mir_ray_Matanimheader_0003F8));

        gSPDisplayList(POLY_XLU_DISP++, object_mir_ray_DL_000168);

        MirRay_SetupReflectionPolys(this, play, reflection);
        MirRay_RemoveSimilarReflections(reflection);
        MirRay_ReflectedBeam(this, play, reflection);

        if (reflection[0].reflectionPoly == NULL) {
            reflection[0].opacity = 0;
        }

        for (i = 1; i < ARRAY_COUNT(reflection); i++) {
            if (reflection[i].reflectionPoly != NULL) {
                if (reflection[0].opacity < reflection[i].opacity) {
                    reflection[0].opacity = reflection[i].opacity;
                }
            }
        }

        for (i = 0; i < ARRAY_COUNT(reflection); i++) {
            if (reflection[i].reflectionPoly != NULL) {
                Matrix_Translate(reflection[i].pos.x, reflection[i].pos.y, reflection[i].pos.z, MTXMODE_NEW);
                Matrix_Scale(0.01f, 0.01f, 0.01f, MTXMODE_APPLY);
                Matrix_Mult(&reflection[i].mtx, MTXMODE_APPLY);

                MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
                gDPSetRenderMode(POLY_XLU_DISP++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_DECAL2);
                gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, reflection[0].opacity);
                gSPDisplayList(POLY_XLU_DISP++, object_mir_ray_DL_0004B0);
            }
        }

        ref_D_808E3BF0 = true;

        CLOSE_DISPS(play->state.gfxCtx);
    }
}
