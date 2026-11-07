// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_stick.h"

void EffectSsStick_Draw(PlayState* play, u32 index, EffectSs* this) {
    s32 pad;
    GraphicsContext* gfxCtx = play->state.gfxCtx;

    OPEN_DISPS(gfxCtx);

    Matrix_Translate(this->pos.x, this->pos.y, this->pos.z, MTXMODE_NEW);
    Matrix_Scale(0.01f, 0.0025f, 0.01f, MTXMODE_APPLY);
    Matrix_RotateZYX(0, this->rYaw, 0, MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, gfxCtx);
    Gfx_SetupDL25_Opa(gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x06, play->objectCtx.slots[this->rObjectSlot].segment);
    gSPSegment(POLY_OPA_DISP++, 0x0C, gCullBackDList);
    gSPDisplayList(POLY_OPA_DISP++, gDekuStickDL);

    CLOSE_DISPS(gfxCtx);
}
