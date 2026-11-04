// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_DrawSkyboxStarsImpl(PlayState* play, Gfx** gfxP) {
    static const Vec3s ref_D_801DD880[] = {
        { 0x0384, 0x2328, 0xD508 }, { 0x09C4, 0x2328, 0xDA1C }, { 0x0E74, 0x22D8, 0xDA1C }, { 0x1450, 0x2468, 0xD8F0 },
        { 0x1C84, 0x28A0, 0xCBA8 }, { 0x1F40, 0x2134, 0xD8F0 }, { 0x1F40, 0x28A0, 0xDAE4 }, { 0xE4A8, 0x4A38, 0x4A38 },
        { 0xD058, 0x4C2C, 0x3A98 }, { 0xD8F0, 0x36B0, 0x47E0 }, { 0xD954, 0x3264, 0x3E1C }, { 0xD8F0, 0x3070, 0x37DC },
        { 0xD8F0, 0x1F40, 0x5208 }, { 0xD760, 0x1838, 0x27D8 }, { 0x0000, 0x4E20, 0x4A38 }, { 0x076C, 0x2328, 0xDCD8 },
    };
    static const Color_RGBA8_u32 ref_D_801DD8E0[] = {
        { 65, 164, 255, 255 },  { 131, 164, 230, 255 }, { 98, 205, 255, 255 }, { 82, 82, 255, 255 },
        { 123, 164, 164, 255 }, { 98, 205, 255, 255 },  { 98, 164, 230, 255 }, { 255, 90, 0, 255 },
    };
    UNALIGNED static const Color_RGBA8_u32 ref_D_801DD900[] = {
        { 64, 80, 112, 255 },   { 96, 96, 128, 255 },   { 128, 112, 144, 255 }, { 160, 128, 160, 255 },
        { 192, 144, 168, 255 }, { 224, 160, 176, 255 }, { 224, 160, 176, 255 }, { 104, 104, 136, 255 },
        { 136, 120, 152, 255 }, { 168, 136, 168, 255 }, { 200, 152, 184, 255 }, { 232, 168, 184, 255 },
        { 224, 176, 184, 255 }, { 240, 192, 192, 255 }, { 232, 184, 192, 255 }, { 248, 200, 192, 255 },
    };
    Vec3f pos;
    f32 temp;
    f32 imgY;
    f32 imgX;
    Gfx* gfx;
    s32 phi_v1;
    s32 negateY;
    f32 invScale;
    f32 temp_f20;
    Gfx* gfxTemp;
    f32 scale;
    s32 i;
    u32 randInt;
    u32 imgWidth;
    f32* imgXPtr;
    f32* imgYPtr;
    Vec3f* posPtr;
    s32 pad[2];
    f32(*viewProjectionMtxF)[4];

    gfx = *gfxP;
    negateY = Environment_IsSceneUpsideDown(play);

    Matrix_MtxToMtxF(play->view.viewingPtr, &play->billboardMtxF);
    Matrix_MtxToMtxF(&play->view.projection, &play->viewProjectionMtxF);
    SkinMatrix_MtxFMtxFMult(&play->viewProjectionMtxF, &play->billboardMtxF, &play->viewProjectionMtxF);

    phi_v1 = 0;

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 255, 255, 255, 255.0f * ref_D_801F4F28);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, ENVIRONMENT, 0, PRIMITIVE, 0, ENVIRONMENT, 0, PRIMITIVE, 0, ENVIRONMENT, 0,
                      PRIMITIVE, 0, ENVIRONMENT, 0);
    gDPSetOtherMode(gfx++,
                    G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_POINT | G_TT_NONE | G_TL_TILE |
                        G_TD_CLAMP | G_TP_NONE | G_CYC_1CYCLE | G_PM_NPRIMITIVE,
                    G_AC_NONE | G_ZS_PRIM | G_RM_AA_XLU_LINE | G_RM_AA_XLU_LINE2);

    randInt = ((u32)gSaveContext.save.saveInfo.playerData.playerName[0] << 0x18) ^
              ((u32)gSaveContext.save.saveInfo.playerData.playerName[1] << 0x14) ^
              ((u32)gSaveContext.save.saveInfo.playerData.playerName[2] << 0x10) ^
              ((u32)gSaveContext.save.saveInfo.playerData.playerName[3] << 0xC) ^
              ((u32)gSaveContext.save.saveInfo.playerData.playerName[4] << 8) ^
              ((u32)gSaveContext.save.saveInfo.playerData.playerName[5] << 4) ^
              ((u32)gSaveContext.save.saveInfo.playerData.playerName[6] << 0) ^
              ((u32)gSaveContext.save.saveInfo.playerData.playerName[7] >> 4) ^
              ((u32)gSaveContext.save.saveInfo.playerData.playerName[7] << 0x1C);

    
    if (play->view.viewingPtr && play->view.viewingPtr && play->view.viewingPtr) {}

    for (i = 0; i < sEnvSkyboxNumStars; i++) {
        if (i < 16) {
            pos.x = play->view.eye.x + (s32)ref_D_801DD880[i].x;
            pos.y = play->view.eye.y + (s32)ref_D_801DD880[i].y;
            pos.z = play->view.eye.z + (s32)ref_D_801DD880[i].z;
            imgWidth = 8;
        } else {
            f32 temp_f22;
            f32 temp_f4;
            f32 temp_f2;

            
            randInt = (randInt * RAND_MULTIPLIER) + RAND_INCREMENT;
            gRandFloat.i = (randInt >> 9) | 0x3F800000;
            temp = gRandFloat.f;
            temp_f4 = temp - 1.0f;

            
            randInt = (randInt * RAND_MULTIPLIER) + RAND_INCREMENT;
            gRandFloat.i = (randInt >> 9) | 0x3F800000;
            temp_f20 = ((gRandFloat.f - 1.0f) + temp_f4) * 0.5f;

            
            randInt = (randInt * RAND_MULTIPLIER) + RAND_INCREMENT;

            
            pos.y = play->view.eye.y + (SQ(temp_f20) * SQ(128.0f)) - 1000.0f;
            pos.x = play->view.eye.x + (Math_SinS(randInt) * (1.2f - temp_f20) * SQ(128.0f));
            pos.z = play->view.eye.z + (Math_CosS(randInt) * (1.2f - temp_f20) * SQ(128.0f));

            
            randInt = (randInt * RAND_MULTIPLIER) + RAND_INCREMENT;
            gRandFloat.i = ((randInt >> 9) | 0x3F800000);
            temp_f2 = gRandFloat.f - 1.0f;

            
            imgWidth = (u32)((SQ(temp_f2) * 8.0f) + 2.0f);
        }

        if (negateY) {
            pos.y = -pos.y;
        }

        if ((i < 15) || ((i == 15) && ((((void)0, gSaveContext.save.day) % 7) == 0))) {
            gDPSetColor(gfx++, G_SETPRIMCOLOR, ref_D_801DD8E0[i % ARRAY_COUNTU(ref_D_801DD8E0)].rgba);
        } else if (((i & 0x3F) == 0) || (i == 16)) {
            gDPSetColor(gfx++, G_SETPRIMCOLOR, ref_D_801DD900[phi_v1 % ARRAY_COUNTU(ref_D_801DD900)].rgba);
            phi_v1++;
        }

        posPtr = &pos;
        imgXPtr = &imgX;
        imgYPtr = &imgY;
        viewProjectionMtxF = play->viewProjectionMtxF.mf;

        if (imgWidth >= 2) {
            
            scale = pos.x * play->viewProjectionMtxF.mf[0][3] + pos.y * play->viewProjectionMtxF.mf[1][3] +
                    pos.z * play->viewProjectionMtxF.mf[2][3] + play->viewProjectionMtxF.mf[3][3];
            if (scale >= 1.0f) {
                invScale = 1.0f / scale;
                
                imgX = (pos.x * viewProjectionMtxF[0][0] + pos.y * viewProjectionMtxF[1][0] +
                        pos.z * viewProjectionMtxF[2][0] + viewProjectionMtxF[3][0]) *
                       invScale;
                
                imgY = (((pos.x * viewProjectionMtxF[0][1]) + (pos.y * viewProjectionMtxF[1][1]) +
                         (pos.z * viewProjectionMtxF[2][1])) +
                        viewProjectionMtxF[3][1]) *
                       invScale;
            }

            if ((scale >= 1.0f) && (imgX > -1.0f) && (imgX < 1.0f) && (imgY > -1.0f) && (imgY < 1.0f)) {
                imgX = (imgX * (SCREEN_WIDTH / 2)) + (SCREEN_WIDTH / 2);
                imgY = (imgY * -(SCREEN_HEIGHT / 2)) + (SCREEN_HEIGHT / 2);

                gfxTemp = gfx;
                Environment_DrawSkyboxStar(&gfxTemp, imgX, imgY, imgWidth, 4);
                gfx = gfxTemp;
            }
            
            if (viewProjectionMtxF) {}
        }
    }

    gDPPipeSync(gfx++);
    *gfxP = gfx;
}
