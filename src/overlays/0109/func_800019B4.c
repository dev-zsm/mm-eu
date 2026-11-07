// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_kankyo.h"

void DemoKankyo_DrawMoonAndGiant(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    DemoKankyo* this = (DemoKankyo*)thisx;
    s16 i;
    f32 alphaScale;

    if (this->isSafeToDrawGiants != false) {
        Vec3f worldPos;
        Vec3f screenPos;
        s32 pad;
        GraphicsContext* gfxCtx = play->state.gfxCtx;

        OPEN_DISPS(gfxCtx);

        Gfx_SetupDL25_Xlu(gfxCtx);

        for (i = 0; i < play->envCtx.precipitation[PRECIP_SNOW_MAX]; i++) {
            worldPos.x = this->effects[i].posBase.x + this->effects[i].posOffset.x;
            worldPos.y = this->effects[i].posBase.y + this->effects[i].posOffset.y;
            worldPos.z = this->effects[i].posBase.z + this->effects[i].posOffset.z;

            Play_GetScreenPos(play, &worldPos, &screenPos);

            
            if ((screenPos.x >= 0.0f) && (screenPos.x < SCREEN_WIDTH) && (screenPos.y >= 0.0f) &&
                (screenPos.y < SCREEN_HEIGHT)) {
                Matrix_Translate(worldPos.x, worldPos.y, worldPos.z, MTXMODE_NEW);
                alphaScale = this->effects[i].alpha / 50.0f;
                if (alphaScale > 1.0f) {
                    alphaScale = 1.0f;
                }
                Matrix_Scale(this->effects[i].scale * alphaScale, this->effects[i].scale * alphaScale,
                             this->effects[i].scale * alphaScale, MTXMODE_APPLY);
                alphaScale = Math_Vec3f_DistXYZ(&worldPos, &play->view.eye) / 300.0f;
                alphaScale = CLAMP(1.0f - alphaScale, 0.0f, 1.0f);

                if (this->actor.params == DEMO_KANKYO_TYPE_GIANTS) {
                    this->effects[i].alpha = 255.0f * alphaScale;
                } else {
                    this->effects[i].alpha = 160.0f * alphaScale;
                }

                gDPPipeSync(POLY_XLU_DISP++);

                switch (i & 1) { 
                    case 0:
                        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 230, 230, 220, this->effects[i].alpha);
                        gDPSetEnvColor(POLY_XLU_DISP++, 230, 230, 30, this->effects[i].alpha);
                        break;

                    case 1:
                        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 200, 200, 190, this->effects[i].alpha);
                        gDPSetEnvColor(POLY_XLU_DISP++, 200, 200, 30, this->effects[i].alpha);
                        break;
                }

                gSPDisplayList(POLY_XLU_DISP++, gLightOrbMaterial1DL);

                Matrix_Mult(&play->billboardMtxF, MTXMODE_APPLY);

                Matrix_RotateZF(DEG_TO_RAD(play->state.frames * 20.0f), MTXMODE_APPLY);

                MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);

                if (this->actor.params == DEMO_KANKYO_TYPE_GIANTS) {
                    gSPDisplayList(POLY_XLU_DISP++, gBubbleDL);
                } else {
                    gSPDisplayList(POLY_XLU_DISP++, gLightOrbModelDL);
                }
            }
        }

        CLOSE_DISPS(gfxCtx);
    }
}
