// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

void EnFall_RisingDebris_Draw(Actor* thisx, PlayState* play) {
    static Gfx* sDebrisModelDLists[] = { gMoonDebrisModel1DL, gMoonDebrisModel2DL, gMoonDebrisModel3DL };
    EnFall* this = (EnFall*)thisx;
    f32 scale = this->scale * 0.06f;
    s32 i;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, gMoonDebrisMaterialDL);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);

    for (i = 0; i < ARRAY_COUNT(debrisEffects); i++) {
        if (debrisEffects[i].modelIndex < 3) {
            Matrix_Translate(debrisEffects[i].pos.x, debrisEffects[i].pos.y, debrisEffects[i].pos.z, MTXMODE_NEW);
            Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
            Matrix_RotateZYX(debrisEffects[i].rot.x, debrisEffects[i].rot.y, debrisEffects[i].rot.z, MTXMODE_APPLY);
            MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
            gSPDisplayList(POLY_OPA_DISP++, sDebrisModelDLists[debrisEffects[i].modelIndex]);
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
