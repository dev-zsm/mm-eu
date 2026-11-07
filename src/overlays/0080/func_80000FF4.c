// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bubble.h"

void EnBubble_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    EnBubble* this = (EnBubble*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    if (this->actionFunc != EnBubble_Disappear) {
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        Math_SmoothStepToF(&this->modelRotSpeed, 16.0f, 0.2f, 1000.0f, 0.0f);
        Math_SmoothStepToF(&this->modelEllipticity, 0.08f, 0.2f, 1000.0f, 0.0f);
        Matrix_ReplaceRotation(&play->billboardMtxF);
        Matrix_Scale(this->modelWidth + 1.0f, this->modelHeight + 1.0f, 1.0f, MTXMODE_APPLY);
        Matrix_RotateZF(DEG_TO_RAD((f32)play->state.frames) * this->modelRotSpeed, MTXMODE_APPLY);
        Matrix_Scale(this->modelEllipticity + 1.0f, 1.0f, 1.0f, MTXMODE_APPLY);
        Matrix_RotateZF(DEG_TO_RAD(-(f32)play->state.frames) * this->modelRotSpeed, MTXMODE_APPLY);
        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);

        gSPDisplayList(POLY_XLU_DISP++, gBubbleDL);
    }

    CLOSE_DISPS(play->state.gfxCtx);

    if (this->actionFunc != EnBubble_Disappear) {
        this->actor.shape.shadowScale = (this->modelWidth + 1.0f) * 0.2f;
        ref_func_808A005C(this);
    }
}
