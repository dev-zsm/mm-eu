// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_jgame_light.h"

void ObjJgameLight_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjJgameLight* this = (ObjJgameLight*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, &gObjectSyokudaiTypeSwitchCausesFlameDL);
    if (this->alpha > 0) {
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        if (this->alpha > 255) {
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 210, 64, 32, 255);
        } else {
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 210, 64, 32, this->alpha);
        }
        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        if (this->signal == OBJJGAMELIGHT_CORRECT) {
            gSPDisplayList(POLY_XLU_DISP++, gObjJgameLightCorrectDL);
        } else if (this->signal == OBJJGAMELIGHT_INCORRECT) {
            gSPDisplayList(POLY_XLU_DISP++, gObjJgameLightIncorrectDL);
        }
    }
    if (this->flameScaleProportion != 0.0f) {
        f32 scale;

        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        scale = (this->flameScaleProportion * 27.0f) / 10000.0f;
        gSPSegment(POLY_XLU_DISP++, 0x08,
                   Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0, (this->flameScroll * -20) & 0x1FF,
                                    0x20, 0x80));
        gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 255, 0, 255);
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 0, 0);
        Matrix_Translate(0.0f, 52.0f, 0.0f, MTXMODE_APPLY);
        Matrix_RotateYS(((Camera_GetCamDirYaw(GET_ACTIVE_CAM(play)) - this->actor.shape.rot.y) + 0x8000),
                        MTXMODE_APPLY);
        Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, gEffFire1DL);
    }
    CLOSE_DISPS(play->state.gfxCtx);
}
