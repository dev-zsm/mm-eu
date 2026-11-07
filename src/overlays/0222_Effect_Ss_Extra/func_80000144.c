// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_extra.h"

void EffectSsExtra_Draw(PlayState* play, u32 index, EffectSs* this) {
    s32 pad;
    f32 scale;
    void* objectPtr;

    scale = this->rScale / 100.0f;
    objectPtr = play->objectCtx.slots[this->rObjectSlot].segment;

    OPEN_DISPS(play->state.gfxCtx);

    gSegments[0x06] = OS_K0_TO_PHYSICAL(objectPtr);

    gSPSegment(POLY_XLU_DISP++, 0x06, objectPtr);

    Matrix_Translate(this->pos.x, this->pos.y, this->pos.z, MTXMODE_NEW);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    Matrix_ReplaceRotation(&play->billboardMtxF);

    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);

    gSPSegment(POLY_XLU_DISP++, 0x08, Lib_SegmentedToVirtual(sPointTextures[this->rScoreIndex]));

    gSPDisplayList(POLY_XLU_DISP++, &gYabusamePointDL);

    CLOSE_DISPS(play->state.gfxCtx);
}
