// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_kankyo.h"

void DemoKakyo_DrawLostWoodsSparkle(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    DemoKankyo* this = (DemoKankyo*)thisx;
    s16 i;
    f32 scaleAlpha;
    Vec3f worldPos;
    Vec3f screenPos;

    
    if (!(play->cameraPtrs[CAM_ID_MAIN]->stateFlags & CAM_STATE_UNDERWATER)) {
        OPEN_DISPS(play->state.gfxCtx);

        POLY_XLU_DISP = Gfx_SetupDL(POLY_XLU_DISP, SETUPDL_20);

        gSPSegment(POLY_XLU_DISP++, 0x08, Lib_SegmentedToVirtual(gSun1Tex));
        gSPDisplayList(POLY_XLU_DISP++, gSunSparkleMaterialDL);

        for (i = 0; i < play->envCtx.precipitation[PRECIP_SNOW_MAX]; i++) {
            worldPos.x = this->effects[i].posBase.x + this->effects[i].posOffset.x;
            worldPos.y = this->effects[i].posBase.y + this->effects[i].posOffset.y;
            worldPos.z = this->effects[i].posBase.z + this->effects[i].posOffset.z;

            Play_GetScreenPos(play, &worldPos, &screenPos);

            
            if ((screenPos.x >= 0.0f) && (screenPos.x < SCREEN_WIDTH) && (screenPos.y >= 0.0f) &&
                (screenPos.y < SCREEN_HEIGHT)) {
                Matrix_Translate(worldPos.x, worldPos.y, worldPos.z, MTXMODE_NEW);
                scaleAlpha = this->effects[i].alpha / 50.0f;
                if (scaleAlpha > 1.0f) {
                    scaleAlpha = 1.0f;
                }

                Matrix_Scale(this->effects[i].scale * scaleAlpha, this->effects[i].scale * scaleAlpha,
                             this->effects[i].scale * scaleAlpha, MTXMODE_APPLY);

                
                if (i < 32) {
                    
                    if (this->effects[i].state != DEMO_KANKYO_STATE_SKYFISH) {
                        
                        if (this->effects[i].alpha > 0) { 
                            this->effects[i].alpha--;
                        }
                    } else if (this->effects[i].alpha < 100) {
                        this->effects[i].alpha++;
                    }
                } else if (this->effects[i].state != DEMO_KANKYO_STATE_SKYFISH) {
                    if ((this->effects[i].alphaClock & 31) < 16) {
                        if (this->effects[i].alpha < 235) {
                            this->effects[i].alpha += 20;
                        }
                    } else if (this->effects[i].alpha > 20) {
                        this->effects[i].alpha -= 20;
                    }
                } else if ((this->effects[i].alphaClock & 15) < 8) {
                    if (this->effects[i].alpha < 255) {
                        this->effects[i].alpha += 100;
                    }
                } else if (this->effects[i].alpha > 10) {
                    this->effects[i].alpha -= 10;
                }

                gDPPipeSync(POLY_XLU_DISP++);

                switch (i & 1) {
                    case 0: 
                        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 155, this->effects[i].alpha);
                        gDPSetEnvColor(POLY_XLU_DISP++, 250, 180, 0, this->effects[i].alpha);
                        break;

                    case 1: 
                        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, this->effects[i].alpha);
                        gDPSetEnvColor(POLY_XLU_DISP++, 0, 100, 255, this->effects[i].alpha);
                        break;
                }

                Matrix_Mult(&play->billboardMtxF, MTXMODE_APPLY);
                Matrix_RotateZF(DEG_TO_RAD(play->state.frames * 20.0f), MTXMODE_APPLY);

                MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
                gSPDisplayList(POLY_XLU_DISP++, gSunSparkleModelDL);
            }
        }

        CLOSE_DISPS(play->state.gfxCtx);
    }
}
