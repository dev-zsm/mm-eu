// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_egblock.h"

void EnEgblock_DrawEffects(EnEgblock* this, PlayState* play) {
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    EnEgblockEffect* effect = this->effects;
    s16 i;

    OPEN_DISPS(gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    for (i = 0; i < ARRAY_COUNT(this->effects); i++, effect++) {
        if (effect->isActive) {
            switch (effect->type) {
                case EGBLOCK_EFFECT_DEBRIS_SOLID:
                case EGBLOCK_EFFECT_DEBRIS_FLAT:
                    Matrix_Push();

                    Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
                    Matrix_Scale(effect->scale, effect->scale, effect->scale, MTXMODE_APPLY);
                    Matrix_RotateYS(effect->rot.y, MTXMODE_APPLY);
                    Matrix_RotateXS(effect->rot.x, MTXMODE_APPLY);
                    Matrix_RotateZS(effect->rot.z, MTXMODE_APPLY);

                    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, gfxCtx);
                    gDPSetPrimColor(POLY_OPA_DISP++, 0x00, 0x80, 255, 255, 255, 255);
                    gDPSetEnvColor(POLY_OPA_DISP++, 255, 255, 255, effect->alpha);

                    if (effect->type == EGBLOCK_EFFECT_DEBRIS_SOLID) {
                        gSPDisplayList(POLY_OPA_DISP++, gEyegoreEffectSolidDebrisDL);
                    } else {
                        gSPDisplayList(POLY_OPA_DISP++, gEyegoreEffectFlatDebrisDL);
                    }

                    Matrix_Pop();
                    break;

                default:
                    break;
            }
        }
    }

    CLOSE_DISPS(gfxCtx);
}
