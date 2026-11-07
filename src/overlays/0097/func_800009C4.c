// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_syokudai.h"

void ObjSyokudai_Draw(Actor* thisx, PlayState* play) {
    ObjSyokudai* this = (ObjSyokudai*)thisx;
    s32 pad;
    s32 groupSize = OBJ_SYOKUDAI_GET_GROUP_SIZE(thisx);
    f32 flameScale;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, sDLists[OBJ_SYOKUDAI_GET_TYPE(thisx)]);
    if (this->snuffTimer != OBJ_SYOKUDAI_SNUFF_OUT) {
        s32 snuffTimerInitial = OBJ_SYOKUDAI_SNUFF_TIMER_INITIAL(groupSize);

        flameScale = 1.0f;
        if (snuffTimerInitial < this->snuffTimer) {
            flameScale = (f32)(snuffTimerInitial - this->snuffTimer + OBJ_SYOKUDAI_SNUFF_TIMER_JUST_LIT_BONUS) /
                         OBJ_SYOKUDAI_SNUFF_TIMER_JUST_LIT_BONUS;
        } else if ((this->snuffTimer > OBJ_SYOKUDAI_SNUFF_OUT) && (this->snuffTimer < OBJ_SYOKUDAI_SNUFF_DEFAULT)) {
            flameScale = (f32)this->snuffTimer / OBJ_SYOKUDAI_SNUFF_DEFAULT;
        }
        flameScale *= 0.0027f;
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        gSPSegment(POLY_XLU_DISP++, 0x08,
                   Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0,
                                    (this->flameTexScroll * -OBJ_SYOKUDAI_SNUFF_DEFAULT) & 0x1FF, 0x20, 0x80));
        gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 255, 0, 255);
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 0, 0);
        Matrix_Translate(0.0f, OBJ_SYOKUDAI_FLAME_HEIGHT, 0.0f, MTXMODE_APPLY);
        Matrix_RotateYS(BINANG_ROT180(Camera_GetCamDirYaw(GET_ACTIVE_CAM(play)) - thisx->shape.rot.y), MTXMODE_APPLY);
        Matrix_Scale(flameScale, flameScale, flameScale, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, gEffFire1DL);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
