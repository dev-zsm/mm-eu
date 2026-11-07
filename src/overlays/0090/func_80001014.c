// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bombf.h"

void EnBombf_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    EnBombf* this = (EnBombf*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    if (ENBOMBF_GET(&this->actor) <= ENBOMBF_0) {
        Gfx_SetupDL25_Opa(play->state.gfxCtx);

        if (ENBOMBF_GET(&this->actor) != ENBOMBF_0) {
            MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
            gSPDisplayList(POLY_OPA_DISP++, gBombFlowerLeavesDL);
            gSPDisplayList(POLY_OPA_DISP++, gBombFlowerBaseLeavesDL);

            Matrix_Translate(0.0f, 1000.0f, 0.0f, MTXMODE_APPLY);
            Matrix_Scale(this->unk_204, this->unk_204, this->unk_204, MTXMODE_APPLY);
        }

        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 200, 255, 200, 255);
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetEnvColor(POLY_OPA_DISP++, (s8)this->unk_200, 20, 10, 0);
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);

        {
            Gfx* gfx = ref_func_808AF86C(play->state.gfxCtx, play);

            gSPSegment(POLY_OPA_DISP++, 0x08, Lib_SegmentedToVirtual(gfx));
        }

        gSPDisplayList(POLY_OPA_DISP++, gBombFlowerBombAndSparkDL);
    } else {
        Collider_UpdateSpheres(0, &this->colliderJntSph);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
