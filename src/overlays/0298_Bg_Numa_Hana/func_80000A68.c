// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_numa_hana.h"

void BgNumaHana_Draw(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    BgNumaHana* this = (BgNumaHana*)thisx;
    WoodenFlowerPetalPosRot* innerPetalPosRot;
    WoodenFlowerPetalPosRot* outerPetalPosRot;
    s32 objectSlot;
    s32 i;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, gWoodenFlowerStalkDL);

    for (i = 0; i < ARRAY_COUNT(this->innerPetalPosRot); i++) {
        innerPetalPosRot = &this->innerPetalPosRot[i];
        outerPetalPosRot = &this->outerPetalPosRot[i];

        Matrix_SetTranslateRotateYXZ(innerPetalPosRot->pos.x, innerPetalPosRot->pos.y, innerPetalPosRot->pos.z,
                                     &innerPetalPosRot->rot);
        Matrix_Scale(0.1f, 0.1f, 0.1f, MTXMODE_APPLY);
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, gWoodenFlowerInnerPetalDL);

        Matrix_SetTranslateRotateYXZ(outerPetalPosRot->pos.x, outerPetalPosRot->pos.y, outerPetalPosRot->pos.z,
                                     &outerPetalPosRot->rot);
        Matrix_Scale(0.1f, 0.1f, 0.1f, MTXMODE_APPLY);
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, gWoodenFlowerOuterPetalDL);
    }

    objectSlot = Object_GetSlot(&play->objectCtx, OBJECT_SYOKUDAI);
    if ((objectSlot > OBJECT_SLOT_NONE) && Object_IsLoaded(&play->objectCtx, objectSlot)) {
        Matrix_SetTranslateRotateYXZ(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y - 64.5f,
                                     this->dyna.actor.world.pos.z, &this->dyna.actor.shape.rot);
        Matrix_Scale(1.5f, 1.5f, 1.5f, MTXMODE_APPLY);
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPSegment(POLY_OPA_DISP++, 0x06, play->objectCtx.slots[objectSlot].segment);
        gSPDisplayList(POLY_OPA_DISP++, gObjectSyokudaiTypeNoSwitchDL);
    }

    FireObj_Draw(play, &this->fire);

    CLOSE_DISPS(play->state.gfxCtx);
}
