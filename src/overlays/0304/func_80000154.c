// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_en_ice_block.h"

void EffectEnIceBlock_Draw(PlayState* play, u32 index, EffectSs* this) {
    s32 pad;
    GraphicsContext* gfxCtx = play->state.gfxCtx;

    if (EffectEnIceBlock_CheckIceBlockObject(this, play)) {
        f32 scale = this->rScale * 0.1f * 0.01f;

        OPEN_DISPS(gfxCtx);

        
        gSPSegment(POLY_XLU_DISP++, 0x06, play->objectCtx.slots[this->rObjectSlot].segment);

        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        Matrix_Translate(this->pos.x, this->pos.y, this->pos.z, MTXMODE_NEW);
        Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
        Matrix_Mult(&play->billboardMtxF, MTXMODE_APPLY);
        Matrix_RotateZS(this->rRot, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, gfxCtx);

        gSPDisplayList(POLY_XLU_DISP++, &gIceBlockShardEffectDL);

        CLOSE_DISPS(gfxCtx);
    }
}
