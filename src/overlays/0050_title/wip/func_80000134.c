// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (ConsoleLogo_Draw), score 5.00 (5 differ, size +2)
#include "generated/mm/z_title.h"

void func_80000134(GameState* thisx) {
    static s16 sTitleRotation = 0;
    static Lights1 sTitleLights = gdSPDefLights1(100, 100, 100, 255, 255, 255, 69, 69, 69);
    ConsoleLogoState* this = (ConsoleLogoState*)thisx;
    u16 y;
    u16 idx;
    Vec3f lightDir;
    Vec3f object;
    Vec3f eye;
    s32 pad[2];

    OPEN_DISPS(this->state.gfxCtx);

    lightDir.x = 69.0f;
    lightDir.y = 69.0f;
    lightDir.z = 69.0f;

    object.x = 0.0f;
    object.y = 0.0f;
    object.z = 0.0f;

    eye.x = -4949.148f;
    eye.y = 4002.5417f;
    eye.z = 1119.0837f;

    Hilite_DrawOpa(&object, &eye, &lightDir, this->state.gfxCtx);

    gSPSetLights1(POLY_OPA_DISP++, sTitleLights);

    ConsoleLogo_RenderView(this, 0.0f, 150.0f, 300.0f);
    Gfx_SetupDL25_Opa(this->state.gfxCtx);
    Matrix_Translate(-53.0f, -5.0f, 0.0f, MTXMODE_NEW);
    Matrix_Scale(1.0f, 1.0f, 1.0f, MTXMODE_APPLY);
    Matrix_RotateZYX(0, sTitleRotation, 0, MTXMODE_APPLY);

    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, this->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, gNintendo64LogoNDL);

    Gfx_SetupDL39_Opa(this->state.gfxCtx);

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetCycleType(POLY_OPA_DISP++, G_CYC_2CYCLE);
    gDPSetRenderMode(POLY_OPA_DISP++, G_RM_PASS, G_RM_CLD_SURF2);
    gDPSetCombineLERP(POLY_OPA_DISP++, TEXEL1, PRIMITIVE, ENV_ALPHA, TEXEL0, 0, 0, 0, TEXEL0, PRIMITIVE, ENVIRONMENT,
                      COMBINED, ENVIRONMENT, COMBINED, 0, PRIMITIVE, 0);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 170, 255, 255, 255);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 255, 128);
    gDPLoadMultiBlock(POLY_OPA_DISP++, gNintendo64LogoTextShineTex, 0x100, 1, G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0,
                      G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, 2, 11);

    for (idx = 0, y = 94; idx < 16; idx++, y += 2) {
        gDPLoadTextureBlock(POLY_OPA_DISP++, &((u8*)gNintendo64LogoTextTex)[0x180 * idx], G_IM_FMT_I, G_IM_SIZ_8b, 192,
                            2, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);

        gDPSetTileSize(POLY_OPA_DISP++, 1, this->uls, (this->ult & 0x7F) - idx * 4, 0, 0);
        gSPTextureRectangle(POLY_OPA_DISP++, 97 << 2, y << 2, (97 + 192) << 2, (y + 2) << 2, G_TX_RENDERTILE, 0, 0,
                            1 << 10, 1 << 10);
    }

    Environment_FillScreen(this->state.gfxCtx, 0, 0, 0, this->coverAlpha, FILL_SCREEN_XLU);

    sTitleRotation += 300;

    CLOSE_DISPS(this->state.gfxCtx);
}
