// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_lights.h"

void Lights_DrawGlow(PlayState* play) {
    Gfx* gfx;
    LightPoint* params;
    LightNode* light = play->lightCtx.listHead;

    if (light != NULL) {
        OPEN_DISPS(play->state.gfxCtx);

        gfx = Gfx_SetupDL65_NoCD(POLY_XLU_DISP);

        gDPSetDither(gfx++, G_AD_PATTERN | G_CD_NOISE);

        gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE,
                          0);

        gSPDisplayList(gfx++, gameplay_keep_DL_029CB0);

        do {
            if (light->info->type == LIGHT_POINT_GLOW) {
                params = &light->info->params.point;
                if (params->drawGlow) {
                    f32 scale = SQ((f32)params->radius) * 2e-6f;

                    gDPSetPrimColor(gfx++, 0, 0, params->color[0], params->color[1], params->color[2], 50);

                    Matrix_Translate(params->x, params->y, params->z, MTXMODE_NEW);
                    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);

                    MATRIX_FINALIZE_AND_LOAD(gfx++, play->state.gfxCtx);

                    gSPDisplayList(gfx++, gameplay_keep_DL_029CF0);
                }
            }

            light = light->next;
        } while (light != NULL);

        POLY_XLU_DISP = gfx;

        CLOSE_DISPS(play->state.gfxCtx);
    }
}
