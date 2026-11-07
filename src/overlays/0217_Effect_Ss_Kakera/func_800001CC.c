// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_kakera.h"

void EffectSsKakera_Draw(PlayState* play, u32 index, EffectSs* this) {
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    s16 pad;
    f32 scale = this->rScale / 256.0f;
    s32 colorIndex = this->rColorIndex;

    OPEN_DISPS(gfxCtx);
    if (this->rObjectId != KAKERA_OBJECT_DEFAULT) {
        if ((((this->rReg4 >> 7) & 1) << 7) == 0x80) {
            gSPSegment(POLY_XLU_DISP++, 0x06, play->objectCtx.slots[this->rObjectSlot].segment);
        } else {
            gSPSegment(POLY_OPA_DISP++, 0x06, play->objectCtx.slots[this->rObjectSlot].segment);
        }
    }

    Matrix_Translate(this->pos.x, this->pos.y, this->pos.z, MTXMODE_NEW);
    Matrix_RotateYS(this->rYaw, MTXMODE_APPLY);
    Matrix_RotateXS(this->rPitch, MTXMODE_APPLY);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);

    if ((((this->rReg4 >> 7) & 1) << 7) == 0x80) {
        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, gfxCtx);
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        if (colorIndex >= 0) {
            gDPSetPrimColor(POLY_XLU_DISP++, 0, ref_D_8097EAD8[colorIndex].lod, ref_D_8097EAD8[colorIndex].color.r,
                            ref_D_8097EAD8[colorIndex].color.g, ref_D_8097EAD8[colorIndex].color.b, 255);
        }
        gSPDisplayList(POLY_XLU_DISP++, this->gfx);
    } else {
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, gfxCtx);
        Gfx_SetupDL25_Opa(play->state.gfxCtx);
        if (colorIndex >= 0) {
            gDPSetPrimColor(POLY_OPA_DISP++, 0, ref_D_8097EAD8[colorIndex].lod, ref_D_8097EAD8[colorIndex].color.r,
                            ref_D_8097EAD8[colorIndex].color.g, ref_D_8097EAD8[colorIndex].color.b, 255);
        }
        gSPDisplayList(POLY_OPA_DISP++, this->gfx);
    }
    CLOSE_DISPS(gfxCtx);
}
