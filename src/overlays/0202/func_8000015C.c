// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_d_fire.h"

void EffectSsDFire_Draw(PlayState* play, u32 index, EffectSs* this) {
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    s32 pad;
    void* objectPtr;
    f32 scale;

    if (EffectSsDFire_CheckForObject(this, play)) {
        objectPtr = play->objectCtx.slots[this->rObjectSlot].segment;

        OPEN_DISPS(gfxCtx);

        gSegments[0x06] = OS_K0_TO_PHYSICAL(objectPtr);
        gSPSegment(POLY_XLU_DISP++, 0x06, objectPtr);

        scale = this->rScale / 100.0f;

        Matrix_Translate(this->pos.x, this->pos.y, this->pos.z, MTXMODE_NEW);
        Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
        Matrix_Mult(&play->billboardMtxF, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, gfxCtx);
        Gfx_SetupDL60_XluNoCD(gfxCtx);
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 0, 0, 0);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 50, this->rAlpha);

        {
            TexturePtr* tex = sFireTextures[this->rTexIndex];

            gSPSegment(POLY_XLU_DISP++, 0x08, Lib_SegmentedToVirtual(tex));
        }

        gSPDisplayList(POLY_XLU_DISP++, this->gfx);

        CLOSE_DISPS(gfxCtx);
    }
}
