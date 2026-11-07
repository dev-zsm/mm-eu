// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_iknv_doukutu.h"

void BgIknvDoukutu_DrawCleansing(Actor* thisx, PlayState* play) {
    BgIknvDoukutu* this = (BgIknvDoukutu*)thisx;
    GraphicsContext* gfxCtx;
    f32 opacity;

    BgIknvDoukutu_DrawPurified(&this->dyna.actor, play);

    gfxCtx = play->state.gfxCtx;
    OPEN_DISPS(gfxCtx);
    Vec3f translationVec;
    s16 cameraYaw = Math_Vec3f_Yaw(&GET_ACTIVE_CAM(play)->eye, &GET_ACTIVE_CAM(play)->at);
    s16 cameraPitch = -Math_Vec3f_Pitch(&GET_ACTIVE_CAM(play)->eye, &GET_ACTIVE_CAM(play)->at);

    translationVec.x = -100.0f * Math_SinS(cameraYaw) * Math_CosS(cameraPitch);
    translationVec.y = Math_SinS(cameraPitch) * -100.0f;
    translationVec.z = -100.0f * Math_CosS(cameraYaw) * Math_CosS(cameraPitch);
    Matrix_Translate(translationVec.x, translationVec.y, translationVec.z, MTXMODE_APPLY);
    opacity = this->opacity;
    AnimatedMat_Draw(play, Lib_SegmentedToVirtual(gIkanaCaveInteriorTexAnim));

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);

    Gfx_SetupDL72(POLY_XLU_DISP++);
    Scene_SetRenderModeXlu(play, 1, 2);
    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    gDPSetEnvColor(POLY_XLU_DISP++, 0, 0, 0, (s32)(255.0f * opacity));
    gSPDisplayList(POLY_XLU_DISP++, gIkanaCaveCursedDL);
    gDPSetEnvColor(POLY_XLU_DISP++, 215, 42, 55, (s32)(120.0f * opacity));
    gSPDisplayList(POLY_XLU_DISP++, gIkanaCaveFogDL);

    CLOSE_DISPS(gfxCtx);
}
