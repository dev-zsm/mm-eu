// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_paper.h"

void EnPaper_Draw(Actor* thisx, PlayState* play) {
    EnPaper* this = (EnPaper*)thisx;
    EnPaperConfetto* piece = this->pieces;
    s32 i;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL37_Opa(play->state.gfxCtx);

    gDPSetRenderMode(POLY_OPA_DISP++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2);
    gDPSetCombineLERP(POLY_OPA_DISP++, 0, 0, 0, SHADE, 0, 0, 0, SHADE, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED);
    gSPLoadGeometryMode(POLY_OPA_DISP++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH);

    for (i = 0; i < ARRAY_COUNT(this->pieces); i++, piece++) {
        
        if (i == 0) {
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, 255);
        } else if (i == 30) {
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 32, 32, 255);
        } else if (i == 40) {
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 64, 128, 255, 255);
        } else if (i == 50) {
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 64, 255, 128, 255);
        }

        if ((this->actor.floorHeight - 40.0f) < piece->pos.y) {
            Mtx* mtx = GRAPH_ALLOC(play->state.gfxCtx, sizeof(Mtx));

            Mtx_SetTranslationRotationScaleMtx(mtx, this->actor.scale.x, this->actor.scale.y, this->actor.scale.z,
                                               piece->angle, piece->rotAxis.x, piece->rotAxis.y, piece->rotAxis.z,
                                               piece->pos.x, piece->pos.y, piece->pos.z);

            gSPMatrix(POLY_OPA_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, gTingleConfettiDL);
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
